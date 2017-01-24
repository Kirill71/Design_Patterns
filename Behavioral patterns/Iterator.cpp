#include<iostream>
#include<vector>
#include<memory>
#include<string>



template< typename Type>
using collection = std::vector<Type>;

template< typename T>
class Iterator
{   
public:
	virtual std::shared_ptr<T> first() const = 0;
	virtual std::shared_ptr<T> next() = 0;
	virtual bool isDone() = 0;
	virtual const T& currentItem() const  = 0;
};

template<typename T>
class Aggregate
{
public:
	virtual  std::shared_ptr<Iterator<T>> createIterator() const = 0;
	virtual int count() const = 0;
	virtual  const T& operator[] (int index) const = 0;
	virtual  T& operator[] (int index) = 0;
};


template<typename T>
class ConcreteIterator : public Iterator<T>
{
	Aggregate<T>* aggregate;
	int current = 0;
public:
	ConcreteIterator() :aggregate() {}
	explicit ConcreteIterator(const Aggregate<T>& _aggregate) :
		aggregate{ &const_cast<Aggregate<T>&>(_aggregate) } {}


	std::shared_ptr<T> first() const override
	{
		return std::make_shared<T>((*aggregate)[0]);
	}

	std::shared_ptr<T> next() override
	{
		return (current++ < aggregate->count() - 1) ? std::make_shared<T>((*aggregate)[current]) : nullptr;
	}

	const T& currentItem() const override
	{
		return (*aggregate)[current];
	}

	bool isDone()
	{
		if (current < aggregate->count())
			return false;

		current = 0;
		return true;
	}
};


template<typename T>
class ConcreteAggregate : public Aggregate<T>
{
	collection<T> items;
public:
	ConcreteAggregate():items(4) {};
	std::shared_ptr<Iterator<T>> createIterator()  const override
	{
		return std::make_shared<ConcreteIterator<T>>(*this);
	}
	int count() const override { return items.size(); }

	const T& operator[](int index) const override
	{
		return items[index];
	}

	T& operator[](int index) override
	{
		return const_cast<T&>(
			static_cast<const ConcreteAggregate<T>&>(*this)
			[index]
		);
	}
	void insert(const T& val) 
	{
		items.push_back(val);
	}
	void remove(const T& val)
	{
		items.erase(std::find(items.cbegin(), items.cend(), val));
	}
};


int main() 
{
	std::unique_ptr<Aggregate<std::string>> a {std::make_unique<ConcreteAggregate<std::string>>()};
	(*a)[0] = "Element A";
	(*a)[1] = "Element B";
	(*a)[2] = "Element C";
	(*a)[3] = "Element D";

	auto iter = a->createIterator();
	for (auto e = iter->first(); !iter->isDone(); e = iter->next())
		std::cout << *e << std::endl;



	system("Pause");
	return 0;
}
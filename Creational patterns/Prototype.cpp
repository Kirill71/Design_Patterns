#include<memory>
#include<iostream>

class Prototype
{
public:
	Prototype() {}
	virtual int get() const = 0;
	Prototype(const Prototype& rhs){}
	virtual ~Prototype(){}
	virtual std::shared_ptr<Prototype> clone()const = 0;
};

class ConcretePrototype1 : public Prototype
{
	int value1;
public:
	int get()const { return value1;}
	ConcretePrototype1(int i):value1(i) {}
	ConcretePrototype1(const ConcretePrototype1& rhs):Prototype(rhs),value1(rhs.value1) {}

	std::shared_ptr<Prototype> clone() const override
	{
		return std::make_shared<ConcretePrototype1>(*this);
	}
};


class ConcretePrototype2 : public Prototype
{
	int value2;
public:
	int get()const { return value2; }
	ConcretePrototype2(int f):value2(f) {}
	ConcretePrototype2(const ConcretePrototype2& rhs):Prototype(rhs), value2(rhs.value2){}

	std::shared_ptr<Prototype> clone()const  override
	{
		return std::make_shared<ConcretePrototype2>(*this);
	}
};

int main() 
{
	auto prototype(std::make_shared<ConcretePrototype1>(2));
	auto clone = prototype->clone();
	std::cout << clone->get();
	system("pause");

}
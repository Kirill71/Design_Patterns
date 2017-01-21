#include<map>
#include<string>
#include<iostream>
#include<memory>

class Flyweight
{
public:
	virtual void operation(int extrinsicState) = 0;
	virtual ~Flyweight() {  }
};

class ConcreteFlyweignt : public Flyweight
{
	int intrinsicState;
public:
	~ConcreteFlyweignt(){}
	void operation(int extrinsicState) override
	{
		intrinsicState = extrinsicState;
		std::cout << " Concrete Flyweight " << std::endl;
	}
};

class UnsharedConcreteFlyweight : public Flyweight
{
	int allState;

public:
	~UnsharedConcreteFlyweight(){}
	void operation(int extrinsicState) override
	{
		allState = extrinsicState;
		std::cout << "Unshared Concrete Flyweight "<< std::endl;
	}
};


class FlyweighFactory
{
	std::map<std::string, ConcreteFlyweignt> pool 
	{ 
		std::make_pair<std::string, ConcreteFlyweignt>("1",ConcreteFlyweignt()),
		std::make_pair<std::string, ConcreteFlyweignt>("2", ConcreteFlyweignt()),
		std::make_pair<std::string, ConcreteFlyweignt>("3", ConcreteFlyweignt())
	};
public:
	 Flyweight& get_flyweight(const std::string& key)
	{
		if (pool.find(key) == pool.cend())
			pool[key] = ConcreteFlyweignt();
		return pool[key];
	}
};

int main()
{
	int extrinsicState = 0;
	FlyweighFactory factory;
	Flyweight* flyweight{&factory.get_flyweight("1")};
	flyweight->operation(extrinsicState);
	flyweight = &factory.get_flyweight("10");
	flyweight->operation(extrinsicState);
	flyweight = new UnsharedConcreteFlyweight();
	flyweight->operation(extrinsicState);


	system("pause");
	delete flyweight;
	return 0;
}

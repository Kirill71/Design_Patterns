//Created by Kirill Zharenkov on 07.01.2017.
//It's simple implementation GoF design pattern Factory Method.

#include <memory>
#include <iostream>


class Product
{
protected:
	Product() {}
	virtual ~Product() {}
};

class ConcreteProduct : public Product
{
public:
	ConcreteProduct() { std::cout << "Concrete product" << std::endl; }
	~ConcreteProduct(){}
};


class Creator
{
public:
	virtual std::shared_ptr<Product> factoryMethod() = 0;
protected:
	Creator(){}
	virtual ~Creator() {}
};

class ConcreteCreator : public Creator
{
public:
	std::shared_ptr<Product> factoryMethod() override
	{
		return std::make_shared<ConcreteProduct>();
	}
};

int main()
{
	std::shared_ptr<Creator> creator{ std::make_shared<ConcreteCreator>() };
	auto product{ creator->factoryMethod()};
	system("pause");
	return 0;
}

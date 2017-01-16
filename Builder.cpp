//
// Created by Kirill Zharenkov on 06.01.2017.
//It's simple implementation GoF design pattern Builder.
//
#include<iostream>
#include <vector>
#include<string>
#include<memory>

class Product
{
	std::vector<std::string> parts;

public:

	Product() : parts() {}
	~Product() {}

	void add(const std::string& part)
	{
		parts.push_back(part);
	}

	void show()
	{
		for (std::string part : parts)
			std::cout << part << std::endl;
	}
};

class Builder
{
protected:
	std::shared_ptr<Product> product;
	Builder() : product{ std::make_shared<Product>() } {}
public:
	virtual ~Builder() {}
	virtual void buildPartA() = 0;
	virtual void buildPartB() = 0;
	virtual void buildPartC() = 0;
	 const std::shared_ptr<Product>&  getResult() const { return product; };
};

class ConcreteBuilder : public Builder
{
public:
	ConcreteBuilder() : Builder() {}
	~ConcreteBuilder() {}

	void buildPartA() override
	{
		product->add("Part A");
	}

	void buildPartB() override
	{
		product->add("Part B");
	}

	void buildPartC() override
	{
		product->add("Part C");
	}
};


class Director
{
public:
	Director(){}
	~Director(){}
	void construct(Builder& builder)
	{
		builder.buildPartA();
		builder.buildPartB();
		builder.buildPartC();
	}
};


int main()
{
	Director director;
	std::shared_ptr<Builder> builder{ std::make_shared<ConcreteBuilder>() };
	director.construct(*builder);
	std::shared_ptr<Product> product{ builder->getResult() };
	product->show();
	system("pause");
	return 0;
}

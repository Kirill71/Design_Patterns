#include<iostream>
#include<memory>

class Strategy
{
public:
	virtual void algorithmInterface() const = 0;
};

class ConcreteStrategyA : public Strategy
{	
public:
	void algorithmInterface() const override
	{
		std::cout << "Concrete Strategy A" << std::endl;
	}
};

class ConcreteStrategyB : public Strategy
{
public:
	void algorithmInterface() const override
	{
		std::cout << "Concrete Strategy B" << std::endl;
	}
};

class ConcreteStrategyC : public Strategy
{
public:
	void algorithmInterface() const override
	{
		std::cout << "Concrete Strategy C" << std::endl;
	}
};

class Context
{
	Strategy* strategy;
public:
	 explicit Context(const Strategy& strtgy) : strategy{&const_cast<Strategy&>(strtgy)} {}

	void setStrategy(const Strategy& strtgy)
	{
		strategy = &const_cast<Strategy&>(strtgy);
	}

	void contextInterface() const
	{
		strategy->algorithmInterface();
	}
};

int main()
{
	auto  context = std::make_shared<Context>(ConcreteStrategyA());
	context->contextInterface();

	context->setStrategy(ConcreteStrategyB());
	context->contextInterface();

	context->setStrategy(ConcreteStrategyC());
	context->contextInterface();

	system("pause");
	return 0;
}

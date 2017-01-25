#include<iostream>

class Strategy
{
public:
	virtual void algorithmInterface() const = 0;
};

class ConcreteStrategyA : public Strategy
{	
public:
	void algorithmInterface() const
	{
		std::cout << "Concrete Strategy A" << std::endl;
	}
};

class ConcreteStrategyB : public Strategy
{
public:
	void algorithmInterface() const
	{
		std::cout << "Concrete Strategy B" << std::endl;
	}
};

class ConcreteStrategyC : public Strategy
{
public:
	void algorithmInterface() const
	{
		std::cout << "Concrete Strategy C" << std::endl;
	}
};

class Context
{
	Strategy* strategy;
public:
	Context(const Strategy& strtgy) : strategy{&const_cast<Strategy&>(strtgy)} {}

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
	ConcreteStrategyA strategyA;
	ConcreteStrategyB strategyB;
	ConcreteStrategyC strategyC;
	Context context(strategyA);
	context.contextInterface();

	context.setStrategy(strategyB);
	context.contextInterface();

	context.setStrategy(strategyC);
	context.contextInterface();

	system("pause");
	return 0;
}
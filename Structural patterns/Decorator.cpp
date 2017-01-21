#include<iostream>
#include<memory>

class Component
{
public:
	virtual void operation() const = 0;
};

class ConcreteComponent : public Component
{
public:
	void operation() const override
	{
		std::cout << "ConcreteComponent" << std::endl;
	}
};

class Decorator: public Component
{
	const Component* component_;
public:
	void operation() const override
	{
		if (component_ != nullptr)
			component_->operation();
	}
	void component(const Component& _component)
	{
		component_ = &_component;
	}

};

class ConcreteDecoratorA : public Decorator
{
	const char * addedState = "Some State ";
public:
	void operation() const override
	{
		Decorator::operation();
		std::cout << addedState << std::endl;
	}
};

class ConcreteDecoratorB : public Decorator
{
public:
	void added_behavior() const
	{
		std::cout << "Behavier" << std::endl;
	}

	void operation() const override
	{
		Decorator::operation();
		added_behavior();
	}
};

int main()
{
	std::shared_ptr<Component> component  { std::make_shared<ConcreteComponent>()};
	std::shared_ptr<Decorator> decoratorA { std::make_shared<ConcreteDecoratorA>()};
	std::shared_ptr<Decorator> decoratorB { std::make_shared<ConcreteDecoratorB>()};
	decoratorA->component(*component);
	decoratorB->component(*decoratorA);
	decoratorB->operation();
	
	system("pause");
	return 0;
}


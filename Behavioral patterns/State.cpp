#include<iostream>

class Context;

class State
{
public:
	virtual void handle(Context& context) const = 0;
};

class Context
{
	State* state_;
public:
	explicit Context(const State& state):state_(&const_cast<State&>(state)) {}
	
	const State& state() const { return *state_;}
	State*& state() { return state_; }
	void request()
	{
		state_->handle(*this);
	}
};

class ConcreteStateA : public State
{	
public:
	ConcreteStateA() {}
	void handle(Context& context) const override;
};

class ConcreteStateB : public State
{
public:
	ConcreteStateB() {}
	void handle(Context& context) const  override
	{
		static ConcreteStateA stateA;
		context.state() = &stateA;
		std::cout << "Concrete State A " << std::endl;
	}
};

void ConcreteStateA::handle(Context& context) const 

{	static ConcreteStateB stateB;
	context.state() = &stateB;
	std::cout << "Concrete State B " << std::endl;
}

int main()
{
	ConcreteStateA state;
	Context context(state);
	context.request();
	context.request();

	system("pause");
	return 0;
}



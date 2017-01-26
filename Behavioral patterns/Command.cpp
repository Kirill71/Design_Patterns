#include<iostream>
#include<memory>

class Receiver
{
public: 
	void action() const
	{
		std::cout << "Reciever" << std::endl;
	}
};

class Command
{
protected:
	Receiver* reciever;
public:
	explicit Command(const Receiver& rhs): reciever(&const_cast<Receiver&>(rhs)) {}

	virtual void execute() const = 0;
};

class ConcreteCommand : public Command
{
public:
	explicit ConcreteCommand(const Receiver& rhs): Command(rhs) {}

	void execute() const  override
	{
		reciever->action();
	}
};

class Invoker
{
	Command* command;
public:
	Invoker(): command() {};

	void store_command(const Command& rhs)
	{
		command = &const_cast<Command&>(rhs);
	}

	void execute_command() const
	{
		command->execute();
	}
};

int main()
{
	Invoker invoker;
	std::shared_ptr<Command> command = std::make_shared<ConcreteCommand>(Receiver());
	invoker.store_command(*command);
	invoker.execute_command();

	system("pause");
	return 0;
}

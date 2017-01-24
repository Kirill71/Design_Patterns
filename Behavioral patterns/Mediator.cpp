#include<string>
#include<memory>
#include<iostream>
class Colleague;
class Colleague1;
class Colleague2;

class Mediator
{
public:
	virtual void send(const std::string& msg, const Colleague& colleague) = 0;
};

class Colleague
{
protected:
	std::unique_ptr<Mediator> mediator;
public:
	explicit Colleague(const Mediator& mediator_) :mediator{ &const_cast<Mediator&>(mediator_) } {}

	void notify(const std::string message) const
	{
		std::cout << message << std::endl;
	}
};

class ConcreteColleague1 : public Colleague
{
public:
	explicit ConcreteColleague1(const Mediator& mediator_) : Colleague(mediator_) {}

	void send(const std::string& message)
	{
		mediator->send(message, *this);
	}
};

class ConcreteColleague2 : public Colleague
{
public:
	explicit ConcreteColleague2(const Mediator& mediator_) : Colleague(mediator_) {}

	void send(const std::string& message)
	{
		mediator->send(message, *this);
	}
};


class ConcreteMediator : public Mediator
{
private:
	ConcreteColleague1* colleague1;
	ConcreteColleague2* colleague2;
public:
	void setColleague1(const ConcreteColleague1& c)
	{
		colleague1 = &const_cast<ConcreteColleague1&>(c);
	}

	void setColleague2(const ConcreteColleague2& c)
	{
		colleague2 = &const_cast<ConcreteColleague2&>(c);
	}

	void send(const std::string& msg, const Colleague& colleague) 
	{
		if (colleague1 == &colleague)
			colleague2->notify(msg);
		else 
			colleague1->notify(msg);
	}
};


int main()
{
	ConcreteMediator mediator;
	ConcreteColleague1 coleague1(mediator);
	ConcreteColleague2 coleague2(mediator);
	mediator.setColleague1(coleague1);
	mediator.setColleague2(coleague2);
	coleague1.send("Message1");
	coleague2.send("Message2");

	system("pause");
	return 0;
}
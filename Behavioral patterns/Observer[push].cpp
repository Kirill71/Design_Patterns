#include<list>
#include<memory>
#include<string>
#include<iostream>
class Observer
{
public:
	virtual void update(const std::string state) = 0;
};

class Subject
{
	std::list< Observer*> observers;
	std::string state_;
public:
	const std::string& state() const { return state_; }
	std::string& state() { return state_; }

	void attach(const Observer& observer)
	{
		observers.push_back(&const_cast<Observer&>(observer));
	}
	void detach(const Observer& observer)
	{
		observers.remove(&const_cast<Observer&>(observer));
	}
	void notify()
	{
		for (auto observer : observers)
			observer->update(state_);
	}
};

class ConcreteSubject : public Subject
{
	// some logic for less abstract example
};

class ConcreteObserver : public Observer
{
	std::string observerState;
	ConcreteSubject* subject_;
public:
	explicit ConcreteObserver(const ConcreteSubject& subject) :subject_{ &const_cast<ConcreteSubject&>(subject) } {}

	void update(const std::string state)
	{
		observerState = state;
		std::cout << " observer was update with state - " << observerState << std::endl;
	}
};

int main()
{
	ConcreteSubject subject;
	ConcreteObserver observer(subject);
	subject.attach(observer);
	subject.attach(observer);
	subject.state() = "Some State 1... ";
	subject.notify();

	system("pause");
	return 0;
}


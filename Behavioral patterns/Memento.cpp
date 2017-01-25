#include<string>
#include<memory>
#include<iostream>

class Memento
{
	std::string state_;
public:
	Memento(){}
	explicit Memento(const std::string& stt): state_(stt){}

	const std::string&  state() const { return state_; }
};

class Originator
{
	std::string state_;
public:
	Originator():state_(){}
	const std::string&  state() const { return state_; }
	
	std::string&  state() { return state_;}
	
	void setMemento(const Memento& memento)
	{
		state_ = memento.state();
	}

	auto createMemento() const
	{
		return  std::make_shared<Memento>(state_);
	}
};

class Caretaker
{
	std::shared_ptr<Memento> memento_;
public:
	Caretaker():memento_(){}

	auto memento() const ->decltype(memento_)
	{
		return memento_;
	}

	std::shared_ptr<Memento>& memento()
	{
		return memento_;
	}
};

auto main() -> int
{
	Originator originator;
	originator.state() = "On";
	Caretaker caretaker;
	std::cout << originator.state() << std::endl;
	caretaker.memento() = originator.createMemento();
	originator.state() = "Off";
	std::cout << originator.state() << std::endl;
	originator.setMemento(*caretaker.memento());
	std::cout << originator.state() << std::endl;

	system("pause");
	return 0;
}
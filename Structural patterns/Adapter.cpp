#include<memory>
#include<iostream>
class Target
{
public:
	virtual void request() const = 0;
};

class Adaptee
{
public:
	void specificRequest()
	{
		std::cout << "specific request" << std::endl;
	}
};
class Adapter : public Target
{
	std::shared_ptr<Adaptee> adaptee;
public:
	Adapter():adaptee(){}
	void request() const override
	{
		adaptee->specificRequest();
	}
};

int main()
{
	std::shared_ptr<Target> target(std::make_shared<Adapter>());
	target->request();
	system("pause");
}
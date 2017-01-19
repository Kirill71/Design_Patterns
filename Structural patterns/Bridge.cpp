#include<iostream>
#include<memory>

class Implementor
{
public:
	virtual void operationImpl() const  = 0;
};

class ConcreteImplementatorA: public Implementor
 {
 public:
	 void operationImpl() const override
	 {
		 std::cout << "Implementor A" << std::endl;
	 }
 };

class ConcreteImplementatorB : public Implementor
 {
 public:
	 void operationImpl() const override
	 {
		 std::cout << "Implementor B" << std::endl;
	 }
 };

class Abstraction
{
protected:
	Implementor* implementor;
public:
	Abstraction(Implementor& impl): implementor(&impl){}
	void operation()
	{
		implementor->operationImpl();
	}
};

class RefinedAbstraction : public Abstraction
{
public:
	RefinedAbstraction(Implementor& impl) : Abstraction(impl) {}
	void operation()
	{
		Abstraction::operation();
		std::cout << " Refined Abstraction" << std::endl;
 	}
};

int main()
{
	std::shared_ptr<Abstraction> abstraction(std::make_shared<RefinedAbstraction>(ConcreteImplementatorA()));
	abstraction->operation();
	abstraction.reset(new RefinedAbstraction(ConcreteImplementatorB()));
	abstraction->operation();
	system("pause");
}
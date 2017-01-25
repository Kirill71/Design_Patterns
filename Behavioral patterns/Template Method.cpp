#include<iostream>
#include<memory>
class AbstractClass 
{
protected:
	virtual void primitiveOperation1() const = 0;
	virtual void primitiveOperation2() const = 0;
public:
	void templateMethod() const
	{
		primitiveOperation1();
		primitiveOperation2();
	}
};


class ConcreteClass : public AbstractClass
{
	void primitiveOperation1() const override
	{
		std::cout << "Primitive Operation 1" << std::endl;
	}

	void primitiveOperation2() const override
	{
		std::cout << "Primitive Operation 2" << std::endl;
	}
};

int main()
{
	std::shared_ptr<AbstractClass> instance =  std::make_shared<ConcreteClass>();
	instance->templateMethod();

	system("pause");
	return 0;
}


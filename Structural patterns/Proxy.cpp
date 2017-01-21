#include<iostream>
#include<memory>
class Subject{
public:
	virtual void request() = 0;
};

class RealSubject : public Subject
{
public:
	void request() override
	{
		std::cout << "RealSubject" << std::endl;
	}
};

class Proxy : public Subject
{
	std::shared_ptr<RealSubject> realSubject;
public:
	void request() override
	{
		if (realSubject == nullptr)
			realSubject = std::make_shared<RealSubject>();
		realSubject->request();
	}	
};

int main()
{
	std::shared_ptr<Subject> subject{ std::make_shared<Proxy>() };
	subject->request();

	system("pause");
	return 0;
}


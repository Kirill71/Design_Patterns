#include<iostream>
#include<memory>


class SubSystem{};
class SubSystemA : public SubSystem
{
public:
	void operationA() 
	{
		std::cout << "SubSystem A" << std::endl;
	}
};

class SubSystemB : public SubSystem
{
public:
	void operationB()
	{
		std::cout << "SubSystem B" << std::endl;
	}
};

class SubSystemC : public SubSystem
{
public:
	void operationC()
	{
		std::cout << "SubSystem C" << std::endl;
	}
};

class Facade
{
	std::shared_ptr<SubSystemA> subsystemA;
	std::shared_ptr<SubSystemB> subsystemB;
	std::shared_ptr<SubSystemC> subsystemC;
public:
	Facade() : subsystemA(std::make_shared<SubSystemA>()),
		subsystemB(std::make_shared<SubSystemB>()),
		subsystemC(std::make_shared<SubSystemC>()){}

	void operationAB()
	{
		this->subsystemA->operationA();
		this->subsystemB->operationB();
	}

	void operationBC()
	{
		this->subsystemB->operationB();
		this->subsystemC->operationC();
	}
};


int main()
{
	auto facade{ std::make_shared<Facade>() };
	facade->operationAB();
	std::cout << " --------------------------------------" << std::endl;
	facade->operationBC();
	system("pause");

	return 0;
}

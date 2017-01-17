// 07.01.2017 Meyers Singleton implementation

#include <string>
#include <iostream>


class Singleton
{
	std::string singletonData;
protected:
	Singleton(): singletonData(){}
public:
	static  const Singleton& instance()
	{
		static Singleton uniqueInstanse;
		return  uniqueInstanse;
	}

	void singletonOperation()
	{
		singletonData = "Singleton Data";
	}
	 
	const std::string& getSingletonData() const 
	{
		return singletonData;
	}
};

int main()
{
	auto var = Singleton::instance();
	var.singletonOperation();
	std::cout<<var.getSingletonData();
	system("pause");
}
#include<iostream>
#include<memory>
class AbstractProductA {

};
class AbstractProductB {
public:
	virtual void interact(const AbstractProductA& apa) const = 0;
};

class ProductA1 : public AbstractProductA {

};

class ProductA2 : public AbstractProductA {

};

class ProductB1 : public AbstractProductB {
public:
	void interact(const AbstractProductA& apa) const override {
		std::cout <<  "interacts with " << "apa" << std::endl;
	}
};
class ProductB2 : public AbstractProductB {
public:
	void interact(const AbstractProductA& apa) const override {
		std::cout << "interacts with " << "apb" << std::endl;
	}
};


class AbstractFactory
{
public:
	virtual  std::shared_ptr<AbstractProductA> createProductA()const = 0;
	virtual std::shared_ptr<AbstractProductB>   createProductB() const = 0;
};

class Factory1 : public AbstractFactory
{
public:
	std::shared_ptr<AbstractProductA> createProductA() const override
	{
		return std::make_shared<ProductA1>();
	}

	std::shared_ptr<AbstractProductB> createProductB() const override
	{
		return std::make_shared<ProductB1>();
	}
};

class Factory2 : public AbstractFactory 
{

public:
	std::shared_ptr<AbstractProductA> createProductA()const override
	{
		return std::make_shared<ProductA2>();
	}

	std::shared_ptr<AbstractProductB> createProductB() const override
	{
		return std::make_shared<ProductB2>();
	}
};

class Client
{
	std::shared_ptr<AbstractProductA> apa;
	std::shared_ptr<AbstractProductB> apb;
public:
	Client(const AbstractFactory& afct): apa(),apb()
	{
		setFactory(afct);
	}

	void setFactory( const AbstractFactory& afct)
	{
		apa = afct.createProductA();
		apb = afct.createProductB();
	}
	void run()
	{
		apb->interact(*apa);
	}
};

int main()
{
	std::shared_ptr<Client> client = std::make_shared<Client>(*std::make_shared<Factory1>());
	client->run();
	client.reset(new Client(*std::make_shared<Factory2>()));
	client->run();
	system("pause");

	return 0;
}

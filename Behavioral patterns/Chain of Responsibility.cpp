#include<iostream>
#include<memory>

class Handler
{
	Handler* handler;
public:
	const Handler& successor() const 
	{ return *handler; }

	void successor(const Handler& scr)
	{handler = &const_cast<Handler&>(scr);}

	virtual void handle_request(int request) const = 0;
};

class ConcreteHandler1 : public Handler
{
public:
	void handle_request(int request) const override
	{
		if (request == 1)
			std::cout << "One" << std::endl;
		else 
			if (&successor() != nullptr)
				successor().handle_request(request);
	}
};

class ConcreteHandler2 : public Handler
{
public:
	void handle_request(int request) const override
	{
		if (request == 2)
			std::cout << "Two" << std::endl;
		if (&successor() != nullptr)
			successor().handle_request(request);
	}
};

int main()
{
	auto h1 = std::make_shared<ConcreteHandler1>();
	auto h2 = std::make_shared<ConcreteHandler2>();
	h1->successor(*h2);
	h1->handle_request(1);
	h1->handle_request(2);

	system("pause");
	
	return 0;
}
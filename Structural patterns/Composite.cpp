#include<iostream>
#include<stdexcept>
#include<vector>
#include<algorithm>
#include<memory>
#include<string>


class Component
{
private:
	const char* name_;
protected:
	const char* name() const { return name_;}
public:
	 Component() = delete;
	 virtual ~Component() {};
	explicit Component(const char* _name): name_(_name){}
	virtual void operation() const = 0;
	virtual void add( Component& _component) = 0 ;
	virtual void remove(const Component& _component) = 0;
	virtual const Component& get_child( int index) const = 0;
	friend bool operator== (const Component* lhs, const Component& rhs);
};

bool operator== (const Component* lhs, const Component& rhs)
{
	return (strcmp(lhs->name_, rhs.name_) == 0);
}
class Leaf : public Component
{
	
public:
	explicit Leaf(const char* _name): Component(_name){}
	void operation() const override
	{
		std::cout << name() << std::endl;
	}
	void add( Component& _component) throw(std::logic_error) override
	{
		throw new std::logic_error("It's leaf! You can't to add");
	}

	void remove( const Component& _component) throw(std::logic_error)  override
	{
		throw new std::logic_error("It's leaf! You can't to add");
	}

	const Component& get_child(int index)const throw(std::logic_error) override
	{
		throw new std::logic_error("It's leaf! You can't to add");
	}
};


class Composite: public Component
{
	std::vector<Component*> nodes;
public:
	explicit Composite(const char* _name) : Component(_name), nodes(){}
	void operation() const override
	{
		std::cout << name() << std::endl;
		for (Component* component : nodes)
			component->operation();
	}

	void add( Component& _component) override
	{
		nodes.push_back(&_component);
	}
	void remove(const Component& _component) override
	{
		nodes.erase(std::find(nodes.cbegin(), nodes.cend(), _component));
	}

	const Component& get_child(int index) const override 
	{
		return *nodes[index];
	}
};

int main()
{
	std::shared_ptr<Component> root{ std::make_shared<Composite>("root") };
	std::shared_ptr<Component> branch1{ std::make_shared<Composite>("br1") };
	std::shared_ptr<Component> branch2{ std::make_shared<Composite>("br2") };
	std::shared_ptr<Component> leaf1{ std::make_shared<Leaf>("l1") };
	std::shared_ptr<Component> leaf2{ std::make_shared<Leaf>("l2") };
	root->add(*branch1);
	root->add(*branch2);
	root->add(*leaf1);
	root->add(*leaf2);
	root->operation();
	system("pause");
	return 0;
	
}
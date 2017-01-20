#include<iostream>
#include<stdexcept>
#include<vector>
#include<algorithm>
#include<memory>
class Component
{
private:
	const char* name_;
protected:
	const char* name() const { return name_;}
public:
	 Component() = delete;
	virtual ~Component() = 0;
	explicit Component(const char* _name): name_(_name){}
	virtual void operation() const = 0;
	virtual void add( Component& _component) = 0 ;
	virtual void remove( Component& _component) = 0;
	virtual const Component& get_child( int index) const = 0;
};

class Leaf : public Component
{
	
public:
	explicit Leaf(const char* _name): Component(_name){}
	void operation() const override
	{
		std::cout << name() << std::endl;
	}
	void add( Component& _component) throw(std::logic_error)
	{
		throw new std::logic_error("It's leaf! You can't to add");
	}

	void remove(const Component& _component) throw(std::logic_error)  
	{
		throw new std::logic_error("It's leaf! You can't to add");
	}

	const Component& get_child(const Component& _component)const throw(std::logic_error) 
	{
		throw new std::logic_error("It's leaf! You can't to add");
	}
};


class Composite: public Component
{
	std::vector<Component&> nodes;
public:
	explicit Composite(const char* _name) : Component(_name), nodes(){}
	void operation() const override
	{
		std::cout << name() << std::endl;
		for (Component component : nodes)
			component.operation();
	}

	void add( Component& _component) override
	{
		nodes.push_back(_component);
	}
	void remove(Component& _component) override
	{
		nodes.erase(std::find(nodes.cbegin(), nodes.cend(), _component));
	}

	const Component& get_child(int index) const override 
	{
		return nodes[index];
	}
};

int main()
{
	/*std::shared_ptr<Component> root{ std::make_shared<Composite>("Root") };
	std::shared_ptr<Component> branch1{ std::make_shared<Composite>("BR1") };
	std::shared_ptr<Component> branch2{ std::make_shared<Composite>("BR2") };
	std::shared_ptr<Component> leaf1{ std::make_shared<Leaf>("L1") };
	std::shared_ptr<Component> leaf2{ std::make_shared<Leaf>("L2") };*/
	/*root->add(*branch1);
	root->add(*branch2);
	root->add(*leaf1);
	root->add(*leaf2);
	root->operation();*/

	return 0;
	system("pause");
}
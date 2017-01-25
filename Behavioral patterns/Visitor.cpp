#include<list>
#include<iostream>

class ElementA;
class ElementB;

class Visitor
{
public:
	virtual void visitElementsA(const ElementA& elementA) const = 0;
	virtual void visitElementsB(const ElementB& elementB) const = 0;
};

class Element
{
public:
	virtual void accept(const Visitor& visitor) const = 0;
};

class ElementA : public Element
{
public:
	void accept( const Visitor& visitor) const override
	{
		visitor.visitElementsA(*this);
	}
	void operationA() const
	{
		std::cout << "Operation A" << std::endl;
	}
};

class ElementB : public Element
{
public:
	void accept(const Visitor& visitor) const override
	{
		visitor.visitElementsB(*this);
	}
	void operationB() const
	{
		std::cout << "Operation B" << std::endl;
	}
};

class ConcreteVisitor1 : public Visitor
{
public:
	void visitElementsA(const ElementA& elementA) const override
	{
		elementA.operationA();
	}

	void visitElementsB(const ElementB& elementB) const override
	{
		elementB.operationB();
	}
};

class ConcreteVisitor2 : public Visitor
{
public:
	void visitElementsA(const ElementA& elementA) const override
	{
		elementA.operationA();
	}

	void visitElementsB(const ElementB& elementB) const override
	{
		elementB.operationB();
	}
};

class ObjectStructure
{
	std::list<Element*>elements;
public:
	ObjectStructure(): elements(){}

	void add( const Element& element)
	{
		elements.push_back(&const_cast<Element&>(element));
	}
	
	void remove(const Element& element)
	{
		elements.remove(&const_cast<Element&>(element));
	}

	void accept( const Visitor& visitor) const
	{
		for (auto element : elements)
			element->accept(visitor);
	}
};

int main()
{
	ObjectStructure structure;

	structure.add(ElementA());
	structure.add(ElementB());

	structure.accept(ConcreteVisitor1());
	structure.accept(ConcreteVisitor2());

	system("pause");
	return 0;
}
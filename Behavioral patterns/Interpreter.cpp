#include<memory>
#include<string>
#include<iostream>

class Context
{
	friend class TerminalExpression;
	friend class NonterminalExpression;
private:
	std::string source;
	char vocabulary;
	int position;
public:
	Context(const std::string& src, char voc) : source(src),
		vocabulary(voc),
		result(),
		position()
	{}
	bool result;
};


class AbstractExpression
{
public:
	virtual void interpret(Context& context) = 0;
};

class TerminalExpression : public AbstractExpression
{
public:
	void interpret(Context& context) override
	{
		context.result = context.source[context.position] == context.vocabulary;
	}
};

class NonterminalExpression: public AbstractExpression
{
public:
	void interpret(Context& context) override
	{
		auto terminalExpression{ std::make_unique<TerminalExpression>() };
		auto nonterminalExpression{ std::make_unique<NonterminalExpression>() };
		if (context.position < context.source.size())
		{
			terminalExpression->interpret(context);
			++context.position;
			if (context.result)
				nonterminalExpression->interpret(context);
		}
	}
};

int main()
{
	Context context("aaa",'a');
	NonterminalExpression expression;
	expression.interpret(context);

	std::cout << std::boolalpha << context.result << std::endl;
	system("pause");

	return 0;
}

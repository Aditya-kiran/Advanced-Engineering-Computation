#include <string>
#include <vector>



class AdvancedParser
{
public:
	class Term
	{
	public:
		std::string str;
		Term *parent,*next,*sub;

		inline Term()
		{
			parent=nullptr;
			next=nullptr;
			sub=nullptr;
		}
	};

	Term *head;

	AdvancedParser();
	~AdvancedParser();
	void CleanUp(void);
private:
	void DeleteTree(Term *t);

public:
	void Print(void) const;
	void Print(const Term *t,int level) const;

public:
	void Decompose(const char incoming[]);

	bool IsOperator(char c) const;
	void AddTermLinear(Term * &tail,std::string c);

public:
	void GroupByParenthesis(void);
	Term *GroupByParenthesis(Term *t);

	void Crunch(void);
	void Crunch(Term *head);

	void GroupByOperator(const char op[]);
	void GroupByOperator(Term *head,const char op[]);

	void GroupByLowPrirityOperator(void);
	void GroupByLowPrirityOperator(Term *head);

	double Evaluate(void) const;
	double Evaluate(Term *t) const;

	double EvaluateTerm(Term *t) const;
};

AdvancedParser::AdvancedParser()
{
	head=nullptr;
}

AdvancedParser::~AdvancedParser()
{
	CleanUp();
}

void AdvancedParser::CleanUp(void)
{
	DeleteTree(head);
}

void AdvancedParser::DeleteTree(Term *t)
{
	if(nullptr!=t)
	{
		DeleteTree(t->next);
		DeleteTree(t->sub);
		delete t;
	}
}

void AdvancedParser::Print(void) const
{
	Print(head,1);
}

void AdvancedParser::Print(const Term *head,int level) const
{
	for(auto t=head; nullptr!=t; t=t->next)
	{
		for(int i=0; i<level; ++i)
		{
			printf("  ");
		}
		printf("%s\n",t->str.c_str());
		Print(t->sub,level+2);
	}
}

void AdvancedParser::Decompose(const char incoming[])
{
	CleanUp();

	std::string current;

	Term *tail=nullptr;

	for(int i=0; 0!=incoming[i]; ++i)
	{
		if(true==IsOperator(incoming[i]))
		{
			if(0<current.size())
			{
				AddTermLinear(tail,current);
				current.clear();
			}
			current.push_back(incoming[i]);
			AddTermLinear(tail,current);
			current.clear();
		}
		else
		{
			current.push_back(incoming[i]);
		}
	}

	if(0<current.size())
	{
		AddTermLinear(tail,current);
	}
}

bool AdvancedParser::IsOperator(char c) const
{
	if('+'==c ||
	   '-'==c ||
	   '*'==c ||
	   '/'==c ||
	   '%'==c ||
	   '('==c ||
	   ')'==c)
	{
		return true;
	}
	return false;
}

void AdvancedParser::AddTermLinear(Term * &tail,std::string c)
{
	auto *newTerm=new Term;

	newTerm->str=c;

	if(nullptr==head)
	{
		head=newTerm;
		tail=newTerm;
	}
	else if(nullptr!=head)
	{
		tail->next=newTerm;
		tail=newTerm;
	}
}

void AdvancedParser::GroupByParenthesis(void)
{
	GroupByParenthesis(head);
}

AdvancedParser::Term *AdvancedParser::GroupByParenthesis(Term *t)
{
	while(nullptr!=t)
	{
		if("("==t->str)
		{
			auto closing=GroupByParenthesis(t->next);
			t->sub=t->next;
			t->sub->parent=t;
			t->next=closing;
		}
		else if(nullptr!=t->next && ")"==t->next->str)
		{
			auto tNext=t->next;
			t->next=nullptr;
			return tNext;
		}
		if(nullptr!=t)
		{
			t=t->next;
		}
	}
	return nullptr;
}

void AdvancedParser::Crunch(void)
{
	Crunch(head);
}

void AdvancedParser::Crunch(Term *head)
{
	while(nullptr!=head)
	{
		Crunch(head->sub);

		if(head->str=="(")
		{
			if(nullptr==head->next || head->next->str!=")")
			{
				fprintf(stderr,"Unclosed parenthesis!\n");
			}
			else
			{
				auto toDel=head->next;
				head->str="()";
				head->next=head->next->next;
				delete toDel;
			}
		}

		head=head->next;
	}
}

void AdvancedParser::GroupByOperator(const char op[])
{
	GroupByOperator(head,op);
}
void AdvancedParser::GroupByOperator(Term *head,const char op[])
{
	while(nullptr!=head)
	{
		GroupByOperator(head->sub,op);

		auto next=head->next;
		if(nullptr!=next)
		{
			auto nextNext=next->next;
			if(nullptr!=nextNext)
			{
				bool isOperaotr=false;
				for(int i=0; 0!=op[i]; ++i)
				{
					if(op[i]==next->str[0])
					{
						isOperaotr=true;
						break;
					}
				}

				if(true==isOperaotr)
				{
					Term *newTerm=new Term;
					newTerm->str=head->str;
					newTerm->next=next;

					head->next=nextNext->next;
					head->str="()";

					newTerm->sub=head->sub;
					head->sub=newTerm;

					nextNext->next=nullptr;
				}
			}
		}

		head=head->next;
	}
}

double AdvancedParser::Evaluate(void) const
{
	return Evaluate(head);
}
double AdvancedParser::Evaluate(Term *t) const
{
	if(nullptr!=t && nullptr!=t->next && nullptr!=t->next->next)
	{
		auto a=EvaluateTerm(t);
		auto b=EvaluateTerm(t->next->next);
		switch(t->next->str[0])
		{
		case '*':
			return a*b;
		case '/':
			return a/b;
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '%':
			return fmod(a,b);
		}
	}
	else if(nullptr!=t && nullptr==t->next)
	{
		return EvaluateTerm(t);
	}
}

double AdvancedParser::EvaluateTerm(Term *t) const
{
	if(t->str=="()")
	{
		return Evaluate(t->sub);
	}
	else
	{
		return atof(t->str.data());
	}
}

int main(void)
{
	AdvancedParser parser;

	// const char *str="123-11+(222+333*(77+99))*4444";
	const char *str="(10+2*(3+4))*2";


	parser.Decompose(str);

	parser.GroupByParenthesis();
	parser.Crunch();

	parser.GroupByOperator("*/%");
	parser.GroupByOperator("+-");

	parser.Print();

	printf("Evaluation %lf\n",parser.Evaluate());

	return 0;
}

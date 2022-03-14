#include<stdio.h>
#include"d_except.h"
#include"d_expsym.h"
#include"d_tnodel.h"
#include"d_tnode.h"
#include"inf2pstf.h"

void prefixoutput(tnode<char> *exp);
tnode<char> *buildExpTree(const string& exp);

int main(){
	puts("Lab 04: Tree Traversal");	
	std::string tree1="ab+cd-ef*+/"; 
	std::string tree2="hi/j-kl*m/+"; 
	std::string tree3="vw-x/yz+-";

	tnode<char>* one = buildExpTree(tree1);
	tnode<char>* two = buildExpTree(tree2);
	tnode<char>* three = buildExpTree(tree3);
	infix2Postfix ex1 = infix2Postfix("(a+b)/((c-d)+(e*f))");
	infix2Postfix ex2 = infix2Postfix("((h/i)-j)+((k*l)/m)");
	infix2Postfix ex3 = infix2Postfix("((v-w)/x)-(y+z)");

	puts("Example 1:");
	displayTree(one,3);
	std::cout<<"Prefix: ";
	prefixoutput(one);
	std::cout<<"\nPostfix: "<< ex1.postfix()<<std::endl;

	puts("\nExample 2:");
	displayTree(two,3);
	std::cout<<"Prefix: ";
	prefixoutput(two);
        std::cout<<"\nPostfix: "<< ex2.postfix()<<std::endl;

	puts("\nExample 3:");
	displayTree(three,3);
	std::cout<<"Prefix: ";
	prefixoutput(three);
        std::cout<<"\nPostfix: "<< ex3.postfix()<<std::endl;
	return 0;
}

void prefixoutput(tnode<char> *exp){
	if(exp){
		printf("%c ",exp->nodeValue);
		prefixoutput(exp->left);
		prefixoutput(exp->right);
	}
}

tnode<char> *buildExpTree(const string& exp)
{
	// newnode is the address of the root of subtrees we build
	tnode<char> *newnode, *lptr, *rptr;
	char token;
	// subtrees go into and off the stack
	stack<tnode<char> *> s;
	int i = 0;


	// loop until i reaches the end of the string
	while(i != exp.length())
	{
		// skip blanks and tabs in the expression
		while (exp[i] == ' ' || exp[i] == '\t')
			i++;

		// if the expression has trailing whitespace, we could
		// be at the end of the string
		if (i == exp.length())
			break;

		// extract the current token and increment i
		token = exp[i];
		i++;

		// see if the token is an operator or an operand
		if (token == '+' || token == '-' || token == '*' || token == '/')
		{
			// current token is an operator. pop two subtrees off
			// the stack.
			rptr = s.top();
			s.pop();
			lptr = s.top();
			s.pop();

			// create a new subtree with token as root and subtees
			// lptr and rptr and push it onto the stack
			newnode = new tnode<char>(token,lptr,rptr);
			s.push(newnode);
		}
		else // must be an operand
		{
			// create a leaf node and push it onto the stack
			newnode = new tnode<char>(token);
			s.push(newnode);
		}
	}

	// if the expression was not empty, the root of the expression
	// tree is on the top of the stack
	if (!s.empty())
		return s.top();
	else
		return NULL;
}

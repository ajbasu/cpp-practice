//***********************************************************************//
// Description: Check for balanced parentheses in an expression.         //
//              Checks for balanced (), {}, and [].                      //
//                                                                       //
// GitHub: https://github.com/ajbasu                                     //
//***********************************************************************//

#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool IsAPair(char,char);
bool IsAParentheses(char);

int main()
{
	string str;
	int str_size=0;
	stack<char> s;

	cout<<"Enter the string: ";
	getline (cin,str);
	str_size = str.size();

	for(int i=0; i<str_size; i++)
	{
		char current = str[i];

		if(!IsAParentheses(current)) continue;

		if(s.size() > 0)
			if(IsAPair(current,s.top()))
				s.pop();
			else
				s.push(current);
		else
			s.push(current);
	}

	if(s.size() == 0)
		cout<<"Balanced"<<endl;
	else
		cout<<"Not balanced"<<endl;

	return 0;
}

bool IsAPair(char a, char b)
{
	bool result = false;
	if( (a == ')' && b == '(') || (a == '}' && b == '{') || (a == ']' && b == '[') )
		result = true;
	return result;
}

bool IsAParentheses(char a)
{
	bool result = false;
	if( a == ')' || a == '(' || a == '}' || a == '{' || a == ']' || a == '[' )
		result = true;
	return result;
}

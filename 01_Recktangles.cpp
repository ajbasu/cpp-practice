//***********************************************************************//
// Description: Given a word, a width and a length, you must print a     //
//              rektangle with the word of the given dimensions.         //
//                                                                       //
// Reddit dailyprogrammer Challenge: https://redd.it/4tetif              //
//                        [2016-07-18] Challenge #276 [Easy] Recktangles //
//                                                                       //
// GitHub: https://github.com/ajbasu                                     //
//***********************************************************************//

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void printStr(const string str);
void shitPost(const string str, int width, int height);


int main()
{
	// Test inputs
	shitPost("REKT",1,1);
	shitPost("REKT",2,2);
	shitPost("REKT",3,4);

	return 0;
}

void printStr(const string str)
{
	int size = str.size();
	for(int i=0; i<size; i++)
		cout<<str.at(i)<<" ";
	cout<<endl;
}

void shitPost(const string str, int width, int height)
{
	string strOrg = str;
	string strRev = strOrg;
	reverse(strRev.begin(),strRev.end());
	int sizeOrg = strOrg.size();

	string newOrg = strOrg;
	string fauxOrg = strRev;

	if(width%2 == 0) { newOrg=strRev; fauxOrg=strOrg; strRev=strOrg; strOrg=newOrg;}

	for(int i=2; i<=width; i++)
	{
		if(i%2 == 0) { newOrg = newOrg + strRev.substr(1,sizeOrg-1); fauxOrg = fauxOrg + strOrg.substr(1,sizeOrg-1);}
		else         { newOrg = newOrg + strOrg.substr(1,sizeOrg-1); fauxOrg = fauxOrg + strRev.substr(1,sizeOrg-1);}
	}

	string newRev = newOrg;
	reverse(newRev.begin(),newRev.end());
	int size = newOrg.size();

	int matrixheight = sizeOrg*height - (height-1);

	for(int k=0, i=0, flag=0; k<matrixheight; k++)
	{
		if(k >= size) i = (k%size)+1;
		else i = k;

		if(flag == 0 && (i%(sizeOrg-1)) == 0) { printStr(newOrg); flag = 1;}
		else if(flag == 1 && (i%(sizeOrg-1)) == 0) { printStr(fauxOrg); flag = 0; }
		else
		{
			cout<<newOrg.at(i)<<" ";
			for(int j=1, flag2=0;j<size-1;j++)
			{
				if(flag2 == 0 && (j%(sizeOrg-1)) == 0) { cout<<fauxOrg.at(i)<<" "; flag2 = 1;}
				else if(flag2 == 1 && (j%(sizeOrg-1)) == 0) { cout<<newOrg.at(i)<<" "; flag2 = 0;}
				else cout<<"  ";
			}
			cout<<newRev.at(i)<<endl;
		}
	}
	cout<<endl;
}

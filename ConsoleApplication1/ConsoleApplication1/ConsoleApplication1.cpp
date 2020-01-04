// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include"string"

using namespace std;

void isDfa(string input)
{
	int length;

	length = input.length();

	bool flag = true;

	for (int i = 0; i < length; i++)
	{
		if ((input[i] != '0') && (input[i] != '1'))
		{
			//cout << "STOPPED WORKING UNKNOWN STRING" << endl;
			flag = false;
		}
		
	}

	if (flag==false)
	{
		cout << "STOPPED WORKING, STRING NOT RECOGNIZED" << endl;
	}



	else if (flag==true)
	{
		if ((length % 2 != 0) || (length == 0))
		{
			cout << "STRING REJECTED" << endl;
		}

		else
		{
			cout << "STRING ACCEPTED" << endl;

		}
	}	
}

void isDfa1(string input)
{
	int i = 0;
	int currentState = 0;//pointer
	int finalState = 2;
	
	for (int i = 0; i < input.length(); i++)
	
	{
		if (input[i] == '0' || input[i] == '1')// nothing except 0 or 1
		{
			if (currentState == 0)
			{
				currentState = 1;
			}

			else if (currentState == 1)
			{
				currentState = 2;
			}
			else if (currentState == 2)
			{
				currentState = 1;
			}

		}
		else
		{
			currentState = 0;
			break;
		}
		
	}


		if (currentState==finalState)
		{
			cout << "STRING "<<input<< " ACCEPTED" << endl;
		}
		else if (currentState==1)
		{
			cout << "STRING " << input << " REJECTED" << endl;
		}
		else if (currentState==0)
		{
			cout << "STOPPED WORKING, STRING "<<input<<" NOT RECOGNIZED" << endl;
		}

}

int _tmain(int argc, _TCHAR* argv[])
{
	string input;
	char choice;

	
		cout << "Enter your string:" << endl;
		getline(cin, input);	
		isDfa1(input);
		
	

	return 0;
}



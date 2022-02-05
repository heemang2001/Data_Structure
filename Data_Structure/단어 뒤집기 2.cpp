#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

string sInput;
string Answer;

int main()
{
	getline(cin, sInput);

	bool bArrow = false;
	bool bStk = false;
	stack<char> stkTemp;

	for (int i = 0; i < sInput.size(); i++)
	{
		if (sInput[i] == '<')
		{
			bArrow = true;

			if (bStk == false)
			{
				Answer += sInput[i];
			}		
		}

		else if (sInput[i] == '>')
		{
			bArrow = false;
			Answer += sInput[i];
		}

		else if (bArrow)
		{
			Answer += sInput[i];
		}

		else if (!bArrow && sInput[i] != ' ')
		{
			stkTemp.push(sInput[i]);
			bStk = true;
		}

		if (!stkTemp.empty() && (sInput[i] == ' '))
		{
			string sTemp = "";

			while (!stkTemp.empty())
			{
				sTemp += stkTemp.top();
				stkTemp.pop();
			}

			Answer += sTemp;
			Answer += ' ';
			bStk = false;
		}

		else if (!stkTemp.empty() && (sInput[i] == '<'))
		{
			string sTemp = "";

			while (!stkTemp.empty())
			{
				sTemp += stkTemp.top();
				stkTemp.pop();
			}

			Answer += sTemp;	
			Answer += '<';
			bStk = false;
		}

		// 문자열 끝이면
		else if (!stkTemp.empty() && (i == sInput.size() - 1))
		{
			string sTemp = "";

			while (!stkTemp.empty())
			{
				sTemp += stkTemp.top();
				stkTemp.pop();
			}

			Answer += sTemp;			
		}
	}

	cout << Answer << '\n';

	return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

int N;
vector<int> vecAnswer;

int main()
{
	cin >> N;

	stack<pair<int, int>> stkTower; // <�ε���, ����>

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;

		while (!stkTower.empty())
		{
			// ���� ž �߰�
			if (nTemp < stkTower.top().second)
			{
				vecAnswer.push_back(stkTower.top().first);
				break;
			}

			// ����ž ã�������� ��� 
			stkTower.pop();
		}

		// ���� ž ����
		if (stkTower.empty())
		{
			vecAnswer.push_back(0);			
		}

		stkTower.push({ i + 1, nTemp });
	}

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << " ";
	}

	return 0;
}
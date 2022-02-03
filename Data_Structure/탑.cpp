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

	stack<pair<int, int>> stkTower; // <인덱스, 높이>

	for (int i = 0; i < N; i++)
	{
		int nTemp;
		cin >> nTemp;

		while (!stkTower.empty())
		{
			// 수신 탑 발견
			if (nTemp < stkTower.top().second)
			{
				vecAnswer.push_back(stkTower.top().first);
				break;
			}

			// 수신탑 찾을때까지 계속 
			stkTower.pop();
		}

		// 수신 탑 없음
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
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int T;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int M;
		cin >> M;
		vector<int> vecAnswer;	
		int mid;
		priority_queue<int> left_pq;
		priority_queue<int, vector<int>, greater<int>> right_pq;

		for (int i = 1; i <= M; i++)
		{
			int nTemp;
			cin >> nTemp;

			if (i == 1)
			{
				mid = nTemp;				
			}

			else
			{
				if (nTemp <= mid)
				{
					left_pq.push(nTemp);
				}

				else
				{
					right_pq.push(nTemp);
				}
			}

			if (i % 2 == 1)
			{
				if (left_pq.size() > right_pq.size())
				{
					right_pq.push(mid);
					mid = left_pq.top();
					left_pq.pop();
				}

				else if(left_pq.size() < right_pq.size())
				{
					left_pq.push(mid);
					mid = right_pq.top();
					right_pq.pop();
				}

				vecAnswer.push_back(mid);
			}
		}

		cout << vecAnswer.size() << '\n';

		int nTemp2 = 0;
		for (int i = 0; i < vecAnswer.size(); i++)
		{
			cout << vecAnswer[i] << ' ';
			nTemp2++;

			if (nTemp2 >= 10)
			{
				nTemp2 = 0;
				cout << '\n';
			}
		}

		cout << '\n';
	}

	return 0;
}
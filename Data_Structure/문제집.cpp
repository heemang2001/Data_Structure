#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

#define MAX 32001

int N, M;
int Entry[MAX];
vector<int> vecProblem[MAX];

int main()
{
	cin >> N >> M;

	priority_queue<int> q;

	for (int i = 0; i < M; i++)
	{
		int A;
		int B;

		cin >> A >> B;

		vecProblem[A].push_back(B);
		Entry[B]++;
	}

	for (int i = 1; i <= N; i++)
	{
		if (Entry[i] == 0)
		{
			q.push(-i);
		}
	}

	while (!q.empty())
	{
		int cur_num = -q.top();
		q.pop();

		cout << cur_num << " ";

		for (int i = 0; i < vecProblem[cur_num].size(); i++)
		{
			int next_num = vecProblem[cur_num][i];
			Entry[next_num]--;

			if (Entry[next_num] == 0)
			{
				q.push(-next_num);
			}
		}
	}

	return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int N, P;
int Answer;
priority_queue<int> pq[500001];

int main()
{
	cin >> N >> P;

	for (int i = 0; i < N; i++)
	{
		int nLine;
		int nNumber;

		cin >> nLine >> nNumber;

		if (pq[nLine].empty())
		{
			Answer++;
			pq[nLine].push(nNumber);
		}

		else
		{
			bool bClear = false;

			while (1)
			{
				if (bClear == true)
				{
					break;
				}

				if (pq[nLine].empty())
				{
					bClear = true;
					pq[nLine].push(nNumber);
					Answer++;
				}

				if (pq[nLine].top() > nNumber)
				{
					pq[nLine].pop();
					Answer++;
				}

				else if (pq[nLine].top() < nNumber)
				{
					bClear = true;
					pq[nLine].push(nNumber);
					Answer++;
				}

				else if (pq[nLine].top() == nNumber)
				{
					bClear = true;
				}
			}


		}
	}

	cout << Answer << '\n';

	return 0;
}
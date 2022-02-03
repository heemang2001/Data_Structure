#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
vector<int> vecAnswer;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	vector<int> vecNum(N + 1);
	vector<pair<int, int>> vecQuestion(M + 1);

	for (int i = 1; i <= N; i++)
	{
		cin >> vecNum[i];
	}

	for (int i = 1; i <= M; i++)
	{
		pair<int, int> pTemp;
		cin >> pTemp.first >> pTemp.second;
		vecQuestion[i] = pTemp;
	}

	for (int i = 1; i <= M; i++)
	{
		int start = vecQuestion[i].first;
		int end = vecQuestion[i].second;


	}

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << '\n';
	}

	return 0;
}

//// 시간 초과
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	cin >> N >> M;
//
//	vector<int> vecNum(N+1);
//	vector<pair<int, int>> vecQuestion(M+1);
//
//	for (int i = 1; i <= N; i++)
//	{
//		cin >> vecNum[i];
//	}
//
//	for (int i = 1; i <= M; i++)
//	{
//		pair<int, int> pTemp;
//		cin >> pTemp.first >> pTemp.second;
//		vecQuestion[i] = pTemp;
//	}
//
//	for (int i = 1; i <= M; i++)
//	{
//		int start = vecQuestion[i].first;
//		int end = vecQuestion[i].second;
//
//		vector<int> vecTemp;
//
//		for (int j = start; j <= end; j++)
//		{
//			vecTemp.push_back(vecNum[j]);
//		}
//
//		sort(vecTemp.begin(), vecTemp.end());
//
//		vecAnswer.push_back(vecTemp.front());
//	}
//
//	for (int i = 0; i < vecAnswer.size(); i++)
//	{
//		cout << vecAnswer[i] << '\n';
//	}
//
//	return 0;
//}
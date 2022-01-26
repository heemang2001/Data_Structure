#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

int T;
vector<int> vecAnswer;

int main()
{
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int Answer = 0;
		int N;
		cin >> N;

		unordered_map<string, vector<string>> hashWear;

		for (int i = 0; i < N; i++)
		{
			string sTemp1;
			string sTemp2;

			cin >> sTemp1 >> sTemp2;

			hashWear[sTemp2].push_back(sTemp1);			
		}	

		int nTemp = 1;
		for (auto iter : hashWear)
		{
			nTemp *= (iter.second.size() + 1);
		}

		nTemp--;

		Answer = nTemp;

		vecAnswer.push_back(Answer);
	}

	for (int i = 0; i < vecAnswer.size(); i++)
	{
		cout << vecAnswer[i] << '\n';
	}

	return 0;
}
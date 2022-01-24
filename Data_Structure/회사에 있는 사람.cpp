#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

int N;

int main()
{
	cin >> N;

	vector<string> vecPeople;
	map<string, bool> mapPeople;

	for (int i = 0; i < N; i++)
	{
		string sName;
		string sCode;

		cin >> sName >> sCode;

		if (sCode == "enter")
		{
			mapPeople[sName] = true;
		}

		else if(sCode == "leave")
		{
			mapPeople[sName] = false;
		}
	}

	for (auto iter : mapPeople)
	{
		if (iter.second == true)
		{
			vecPeople.push_back(iter.first);
		}
	}

	sort(vecPeople.begin(), vecPeople.end(), greater<string>());

	for (int i = 0; i < vecPeople.size(); i++)
	{
		cout << vecPeople[i] << '\n';
	}
	
	return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int arrParent[1000001];

// �θ� ��� ã����
int Getparent(int num)
{
	if (arrParent[num] == num)
	{
		return num;
	}

	return arrParent[num] = Getparent(arrParent[num]);
}

// �� �θ� ��带 ��ħ
void Union(int num1, int num2)
{
	int Parent_a = Getparent(num1);
	int Parent_b = Getparent(num2);

	// ���� ���� �θ���� ����
	if (Parent_a > Parent_b)
	{
		arrParent[Parent_a] = Parent_b;
	}

	else
	{
		arrParent[Parent_b] = Parent_a;
	}
}

// �θ� ������?
void Find(int num1, int num2)
{
	int Parent_a = Getparent(num1);
	int Parent_b = Getparent(num2);

	if (Parent_a == Parent_b)
	{
		cout << "YES" << '\n';
	}

	else
	{
		cout << "NO" << '\n';
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		arrParent[i] = i;
	}

	for (int i = 0; i < M; i++)
	{
		int nOrder;
		int num_a;
		int num_b;

		cin >> nOrder >> num_a >> num_b;

		// Find
		if (nOrder == 1)
		{
			Find(num_a, num_b);
		}

		// Union
		else if(nOrder == 0)
		{
			Union(num_a, num_b);
		}
	}

	return 0;
}
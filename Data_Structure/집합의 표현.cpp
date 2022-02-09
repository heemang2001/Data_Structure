#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int arrParent[1000001];

// 부모 노드 찾아줌
int Getparent(int num)
{
	if (arrParent[num] == num)
	{
		return num;
	}

	return arrParent[num] = Getparent(arrParent[num]);
}

// 두 부모 노드를 합침
void Union(int num1, int num2)
{
	int Parent_a = Getparent(num1);
	int Parent_b = Getparent(num2);

	// 작은 값을 부모노드로 선택
	if (Parent_a > Parent_b)
	{
		arrParent[Parent_a] = Parent_b;
	}

	else
	{
		arrParent[Parent_b] = Parent_a;
	}
}

// 부모 같은가?
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
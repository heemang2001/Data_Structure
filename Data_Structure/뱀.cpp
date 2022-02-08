#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int Answer;
int N, K, L; // ���� ũ�� , ��� ����, ���� ���� ��ȯ Ƚ��
int arrMap[101][101];
vector<pair<pair<int, char>, bool>> vecMove;
queue<pair<int, int>> q_tail;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int cur_dx = dx[3];
int cur_dy = dy[3];

void CheckArrow(char direction)
{
	// ��
	if (cur_dx == 0 && cur_dy == 1)
	{
		if (direction == 'L')
		{
			cur_dx = -1;
			cur_dy = 0;
		}

		else if (direction == 'D')
		{
			cur_dx = 1;
			cur_dy = 0;
		}
	}

	// ��
	else if (cur_dx == 0 && cur_dy == -1)
	{
		if (direction == 'L')
		{
			cur_dx = 1;
			cur_dy = 0;
		}

		else if (direction == 'D')
		{
			cur_dx = -1;
			cur_dy = 0;
		}
	}

	// ��
	else if (cur_dx == -1 && cur_dy == 0)
	{
		if (direction == 'L')
		{
			cur_dx = 0;
			cur_dy = -1;
		}

		else if (direction == 'D')
		{
			cur_dx = 0;
			cur_dy = 1;
		}
	}

	// ��
	else if (cur_dx == 1 && cur_dy == 0)
	{
		if (direction == 'L')
		{
			cur_dx = 0;
			cur_dy = 1;
		}

		else if (direction == 'D')
		{
			cur_dx = 0;
			cur_dy = -1;
		}
	}
}

bool MoveSnake(int& x, int& y)
{
	Answer++;

	int next_x = x + cur_dx;
	int next_y = y + cur_dy;

	q_tail.push({ next_x,next_y });

	// ���� �̸����� ���ٴϴٰ� �� �Ǵ� �ڱ��ڽ��� ���� �ε����� ������ ������.
	if (next_x < 1 || next_y < 1 || next_x > N || next_y > N || arrMap[next_x][next_y] == 1)
	{
		return true;
	}

	// ���� �̵��� ĭ�� ����� �ִٸ�, �� ĭ�� �ִ� ����� �������� ������ �������� �ʴ´�.
	else if(arrMap[next_x][next_y] == 2)
	{
		arrMap[next_x][next_y] = 1;
	}

	// ���� �̵��� ĭ�� ����� ���ٸ�, �����̸� �ٿ��� ������ ��ġ�� ĭ�� ����ش�.��, �����̴� ������ �ʴ´�.
	else
	{
		arrMap[next_x][next_y] = 1;
		arrMap[q_tail.front().first][q_tail.front().second] = 0;
		q_tail.pop();
	}

	for (int i = 0; i < vecMove.size(); i++)
	{
		if (Answer == vecMove[i].first.first && vecMove[i].second == false)
		{
			CheckArrow(vecMove[i].first.second);
			vecMove[i].second = true;
			break;
		}
	}
	
	x = next_x;
	y = next_y;

	return false;
}

int main()
{
	int x = 1;
	int y = 1;	

	q_tail.push({ x,y });

	cin >> N >> K;

	arrMap[1][1] = 1; // �� ����

	for (int i = 0; i < K; i++)
	{
		int x, y;
		cin >> x >> y;
		arrMap[x][y] = 2;
	}

	cin >> L;
	for (int i = 0; i < L; i++)
	{
		pair<int, char> pTemp;
		cin >> pTemp.first >> pTemp.second;
		vecMove.push_back({ pTemp , false });
	}

	bool bGameOver = false;
	while (!bGameOver)
	{
		bGameOver = MoveSnake(x, y);
	}

	cout << Answer << '\n';

	return 0;
}
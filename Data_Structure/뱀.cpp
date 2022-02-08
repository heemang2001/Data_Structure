#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int Answer;
int N, K, L; // 보드 크기 , 사과 개수, 뱀의 방향 변환 횟수
int arrMap[101][101];
vector<pair<pair<int, char>, bool>> vecMove;
queue<pair<int, int>> q_tail;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };
int cur_dx = dx[3];
int cur_dy = dy[3];

void CheckArrow(char direction)
{
	// 우
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

	// 좌
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

	// 상
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

	// 하
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

	// 뱀이 이리저리 기어다니다가 벽 또는 자기자신의 몸과 부딪히면 게임이 끝난다.
	if (next_x < 1 || next_y < 1 || next_x > N || next_y > N || arrMap[next_x][next_y] == 1)
	{
		return true;
	}

	// 만약 이동한 칸에 사과가 있다면, 그 칸에 있던 사과가 없어지고 꼬리는 움직이지 않는다.
	else if(arrMap[next_x][next_y] == 2)
	{
		arrMap[next_x][next_y] = 1;
	}

	// 만약 이동한 칸에 사과가 없다면, 몸길이를 줄여서 꼬리가 위치한 칸을 비워준다.즉, 몸길이는 변하지 않는다.
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

	arrMap[1][1] = 1; // 뱀 시작

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
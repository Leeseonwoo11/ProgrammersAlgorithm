// Kakao Friends Coloring Book.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct vec
{
	int x;
	int y;
	int z;
};

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int a[4] = { -1,1,0,0 };
	int b[4] = { 0,0,-1,1 };

	bool visit[100][100] = { 0, };
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;

	int w = picture[0].size();
	int h = picture.size();
	vec temp;
	queue<vec> q;
	vector<int>maxArea;

	int idx;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			int area = 0;

			if (!visit[i][j] && picture[i][j] != 0)
			{
				idx = picture[i][j];
				temp.x = j;
				temp.y = i;
				q.push(temp);
				visit[i][j] = true;
				area++;
				number_of_area++;
			}
			while (!q.empty())
			{
				int x = q.front().x;
				int y = q.front().y;
				q.pop();
				for (int k = 0; k < 4; k++)
				{
					int newx = x + a[k];
					int newy = y + b[k];
					if (newx < 0 || newy < 0 || newx >= w || newy >= h)
						continue;
					if (!visit[newy][newx] && idx == picture[newy][newx])
					{
						visit[newy][newx] = true;
						temp.x = newx;
						temp.y = newy;
						q.push(temp);
						area++;
					}
				}
			}
			maxArea.push_back(area);
		}
	}
	answer[1] = *max_element(maxArea.begin(), maxArea.end());
	answer[0] = number_of_area;
	return answer;
}
int main()
{
	solution(6, 4, { {1, 1, 1, 0},{1, 2, 2, 0},{1, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 3},{0, 0, 0, 3} });
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.

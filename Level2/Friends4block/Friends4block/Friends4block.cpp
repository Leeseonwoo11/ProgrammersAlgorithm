// Friends4block.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swap(char& a, char& b)
{
	char temp = a;
	a = b;
	b = temp;
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;
	vector<vector<int>>checkboard;
	bool flag = true;
	while (flag)
	{
		flag = false;
		//체크보드 초기화
		checkboard.clear();
		checkboard.resize(m);
		for (int i = 0; i < checkboard.size(); i++)
		{
			checkboard[i].resize(n, 0);
		}
		// 사각형 찾에서 체크보드에 표시하기
		for (int i = 1; i < board.size(); i++)
		{
			for (int j = 1; j < board[i].length(); j++)
			{
				if (board[i][j] == board[i][j - 1] &&
					board[i][j - 1] == board[i - 1][j - 1] &&
					board[i - 1][j - 1] == board[i - 1][j] && board[i][j] != ' ')
				{
					checkboard[i][j] = 1;
					checkboard[i][j - 1] = 1;
					checkboard[i - 1][j] = 1;
					checkboard[i - 1][j - 1] = 1;
					flag = true;
				}
			}
		}
		// 체크보드 참고해서 지우기
		for (int i = 0; i < checkboard.size(); i++)
		{
			for (int j = 0; j < checkboard[i].size(); j++)
			{
				if (checkboard[i][j] == 1)
				{
					board[i][j] = ' ';
					answer++;
				}
			}
		}
		// 지운 칸에 윗블록 채우기
		for (int k = 0; k < m; k++)
		{
			for (int i = 0; i < board.size() - 1; i++)
			{
				for (int j = 0; j < board[i].size(); j++)
				{
					if (board[i][j] != ' ' && board[i + 1][j] == ' ')
					{
						swap(board[i][j], board[i + 1][j]);
					}
				}
			}
		}
		if (flag == false)
			break;
	}
	return answer;
}

int main()
{
	solution(6, 6, {"TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ"});
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

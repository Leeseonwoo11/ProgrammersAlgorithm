// n Game.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

string transnum(int num, int n)
{
	int j;
	vector<string> result;
	if (num == 0)
	{
		string a = "0";
		result.push_back(a);
	}
	while (num != 0)
	{
		string temp = "";
		j = num % n;
		num = num / n;
		if(j<10)
			temp += to_string(j);
		else
		{
			if (j == 10)
			{
				temp += 'A';
			}
			else if (j == 11)
			{
				temp += 'B';
			}
			else if (j == 12)
			{
				temp += 'C';

			}
			else if (j == 13)
			{
				temp += 'D';

			}
			else if (j == 14)
			{
				temp += 'E';

			}
			else if (j == 15)
			{
				temp += 'F';
			}
		}
		result.push_back(temp);
	}
	reverse(result.begin(), result.end());
	string s = "";
	for (int i = 0; i < result.size(); i++)
	{
		s += result[i];
	}
	return s;
}

string solution(int n, int t, int m, int p) 
{
	string answer = "";
	int num = n * t*m;
	string answerlist = "";
	for (int i = 0; i < num; i++)
	{
		answerlist += transnum(i, n);
	}
	int p1 = p-1;
	while (answer.size() != t)
	{
		answer += answerlist[p1];
		p1 += m;
	}

	return answer;
}
int main()
{
	solution(2, 4, 2, 1);
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

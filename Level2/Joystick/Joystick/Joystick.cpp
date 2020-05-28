// Joystick.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int mincount(char c)
{
	int upcount = 0;
	int downcount = 0;
	for (char i = 'A'; i <= 'Z'; i++)
	{
		if (c == i)
		{
			break;
		}
		upcount++;
	}
	for (char i = 'Z'; i >= 'A'; i--)
	{
		if (c == i)
		{
			downcount++;
			break;
		}
		downcount++;
	}
	if (downcount > upcount)
	{
		return upcount;
	}
	else
	{
		return downcount;
	}
}

int solution(string name)
{
	int answer = 0;
	int count = 0;
	int count2 = 0;
	string name1 = name;
	string name2 = name;
	string s = "";
	string s2 = "";
	int dig1 = 0;
	int dig2 = 0;
	bool flag = true;
	bool single = true;
	for (int i = 0; i < name.length(); i++)
	{
		s += 'A';
		s2 += 'A';
	}



	while (name1 != s)
	{
		while (single)
		{
			count2 += mincount(name1[dig2]);
			s2[dig2] = name1[dig2];
			if (name1 == s2)
			{
				single = false;
				break;
			}
			dig2++;
			count2++;
		}
		if (name1[dig1 + 1] == 'A')
		{
			flag = false;
		}
		count += mincount(name1[dig1]);
		name1[dig1] = s[dig1];
		if (name1 == s)
		{
			break;
		}
		if (flag)
		{
			dig1++;
			count++;
		}
		else
		{
			if (dig1 > 0)
			{
				dig1--;
				count++;
			}
			else
			{
				dig1 = name.length() - 1;
				count++;
			}
		}
	}

	if (count < count2)
	{
		answer = count;
	}
	else
	{
		answer = count2;
	}

	return answer;
}
int main()
{
	solution("JEROEN");
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

// Creating the JadenCase string.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
	string answer = "";
	bool flag1 = true;
	bool flag2 = false;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 'A'&& s[i] <= 'Z') // 알파벳이라면 소문자 바꿔준다.
		{
			s[i] -= 'A';
			s[i] += 'a';
		}
	}

	for (int i = 0; i < s.length(); i++)
	{
		if (flag2) // 알파벳 뒤 소문자로 만들어준다.
		{
			if (s[i] >= 'A'&& s[i] <= 'Z') // 알파벳이라면 소문자 바꿔준다.
			{
				s[i] -= 'A';
				s[i] += 'a';
				flag2 = false;
			}
			else if (s[i] >= 'a'&& s[i] <= 'z')
			{
				flag2 = false;
			}
		}
		if (flag1) // 공백이 발견되면 혹은 첫번째 단어에서 플래그가 켜지고 다음이 실행됨
		{
			if (s[i] >= 'a'&& s[i] <= 'z') // 알파벳이라면 대문자로 바꿔준다.
			{
				s[i] -= 'a';
				s[i] += 'A';
			}
			else if (s[i] >= '0'&& s[i] <= '9')// 숫자라면
			{
				flag2 = true; // 숫자 뒤 알파벳 소문자 만들기 플래그를 켜준다.
			}
			flag1 = false;
		}
		if (s[i] == ' ')
		{
			flag1 = true;
		}
	}
	answer = s;
	return answer;
}
int main()
{
	solution("3people unFollowed me");
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

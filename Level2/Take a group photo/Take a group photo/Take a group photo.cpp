// Take a group photo.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

bool check(string s, vector<string> data)
{
	bool result = false;
	int size = data.size();
	for (int i = 0; i < size; i++)
	{
		char owner = data[i][0];
		char customer = data[i][2];
		char oper = data[i][3];
		char charnum = data[i][4];
		int num = (charnum - '0');

		int cusloc = s.find(customer);
		int ownerloc = s.find(owner);
		int length = cusloc - ownerloc < 0 ? -(cusloc - ownerloc) : cusloc - ownerloc;
		length -= 1;
		if (oper == '<')
		{
			if (length < num)
				result = true;
			else
				return false;
		}
		else if (oper == '>')
		{
			if (length > num)
				result = true;
			else
				return false;
		}
		else
		{
			if (num == length)
				result = true;
			else
				return false;
		}
	}
	return result;
}

string origin = "ACFJMNRT";
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data)
{
	string original = origin;
	int answer = 0;
	vector<string> strlist;
	do
	{
		string temp = "";
		for (int i = 0; i < original.length(); i++)
		{
			temp += original[i];
		}
		if (check(temp, data))
			strlist.push_back(temp);
	} while (next_permutation(original.begin(), original.end()));

	answer = strlist.size();
	return answer;
}
int main()
{
	solution(2, { "N~F=0", "R~T>2" });
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

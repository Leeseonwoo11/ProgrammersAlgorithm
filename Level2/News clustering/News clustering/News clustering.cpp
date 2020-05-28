// News clustering.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> Intersection(vector<string> a, vector<string> b)
{
	vector<string> result;
	for (int i = 0; i < a.size(); i++)
	{
		string temp = "";
		for (int j = 0; j < b.size(); j++)
		{
			if (a[i] == b[j] && a[i] != "")
			{
				temp = b[j];
				result.push_back(temp);
				a[i] = "";
				b[j] = "";
				break;
			}
		}
	}
	return result;
}
vector<string> Union(vector<string> a, vector<string> b)
{
	vector<string> result;
	for (int i = 0; i < a.size(); i++)
	{
		result.push_back(a[i]);
	}
	for (int i = 0; i < b.size(); i++)
	{
		result.push_back(b[i]);
	}
	vector<string>Intersectionvec = Intersection(a, b);
	for (int i = 0; i < Intersectionvec.size(); i++)
	{
		for (int j = 0; j < result.size(); j++)
		{
			if (Intersectionvec[i] == result[j])
			{
				result.erase(result.begin() + j);
				break;
			}
		}
	}
	return result;
}

int solution(string str1, string str2)
{
	int answer = 0;
	vector<string> STR1;
	vector<string> STR2;
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] >= 'a' && str1[i] <= 'z')
		{
			str1[i] -= 'a';
			str1[i] += 'A';
		}
	}
	for (int i = 0; i < str2.length(); i++)
	{
		if (str2[i] >= 'a' && str2[i] <= 'z')
		{
			str2[i] -= 'a';
			str2[i] += 'A';
		}
	}

	for (int i = 0; i < str1.length() - 1; i++)
	{
		string temp = "";
		for (int j = i + 1; j < str1.length(); j++)
		{
			temp += str1[i];
			temp += str1[j];
			if (str1[i] >= 'A' && str1[i] <= 'Z')
			{
				if (str1[j] >= 'A' && str1[j] <= 'Z')
				{
					STR1.push_back(temp);
					break;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
	}
	for (int i = 0; i < str2.length() - 1; i++)
	{
		string temp = "";
		for (int j = i + 1; j < str2.length(); j++)
		{
			temp += str2[i];
			temp += str2[j];
			if (str2[i] >= 'A' && str2[i] <= 'Z')
			{
				if (str2[j] >= 'A' && str2[j] <= 'Z')
				{
					STR2.push_back(temp);
					break;
				}
				else
					break;
			}
			else
				break;
		}
	}
	double Intersize = Intersection(STR1, STR2).size();
	double Unionsize = Union(STR1, STR2).size();
	if (Unionsize <= 0)
	{
		return 65536;
	}
	answer = Intersize / Unionsize * 65536;
	return answer;
}
int main()
{
	solution("handshake", "shake hands");
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

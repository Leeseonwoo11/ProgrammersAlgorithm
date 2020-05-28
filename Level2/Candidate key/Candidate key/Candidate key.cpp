// ConsoleApplication4.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isin(vector<int>a, int b)
{
	for (int i = 0; i < a.size(); i++)
	{
		if (a[i] == b)
		{
			return true;
		}
	}
	return false;
}

vector<vector<int>>func(vector<int>a, int size)
{
	vector<vector<int>> result;
	do
	{
		vector<int>temp;
		for (int i = 0; i < a.size(); i++)
		{
			if (temp.size() == size)
			{
				break;
			}
			else if (temp.empty())
			{
				temp.push_back(a[i]);
			}
			else if (!temp.empty() && temp.back() < a[i])
			{
				temp.push_back(a[i]);
			}

		}
		if (temp.size() == size)
		{
			result.push_back(temp);
		}
	} while (next_permutation(a.begin(), a.end()));
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());
	return result;
}

bool check(vector<vector<int>> tupleidx, vector<int> temptuple)
{
	bool result = false;
	for (int i = 0; i < tupleidx.size(); i++)
	{
		int count = 0;
		for (int k = 0; k < temptuple.size(); k++)
		{
			if (isin(tupleidx[i], temptuple[k]))
			{
				count++;
			}
		}
		if (count == tupleidx[i].size())
		{
			return true;
		}
	}
	return result;
}


int solution(vector<vector<string>> relation)
{
	int answer = 0;
	int col = relation.size();
	int row = relation[0].size();
	vector<vector<int>> tupleidx;

	vector<int> order;
	for (int i = 0; i < relation[0].size(); i++)
	{
		order.push_back(i);
	}
	vector<vector<int>> combinations;
	for (int i = 1; i <= relation[0].size(); i++)
	{
		vector<vector<int>> tempcombi = func(order, i);
		while (!tempcombi.empty())
		{
			combinations.push_back(tempcombi.back());
			tempcombi.pop_back();
		}
	}
	int i1;
	int j1;
	int k1;
	for (i1 = 0; i1 < combinations.size(); i1++)
	{
		vector<string> tstr;

		for (k1 = 0; k1 < relation.size(); k1++)
		{
			string temp = "";
			for (j1 = 0; j1 < combinations[i1].size(); j1++)
			{
				temp += relation[k1][combinations[i1][j1]];
			}
			tstr.push_back(temp);
		}
		sort(tstr.begin(), tstr.end());
		tstr.erase(unique(tstr.begin(), tstr.end()), tstr.end());
		if (tstr.size() == relation.size())
		{
			vector<int> idx = combinations[i1];
			if (check(tupleidx, idx) == false)// 튜플인덱스백터에 포함되어있지않은 조합이라면 false가 리턴된다.
			{
				tupleidx.push_back(idx);
			}
		}
	}
	answer = tupleidx.size();
	return answer;
}

int main()
{
	solution(
		{ {"100", "ryan", "music", "2"},
		{"200", "apeach", "math", "2" },
		{"300", "tube", "computer", "3"},
		{"400", "con", "computer", "4"},
		{"500", "muzi", "music", "3"},
		{"600", "apeach", "music", "2"} });


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

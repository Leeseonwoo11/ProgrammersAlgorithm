// That song.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
	
using namespace std;
// musicinfos에는 시작시간 끝나는시간은 순서대로 표시되어있다. 
// 곡의 이름에는 공백이 포함되어있을 수 있다.( 이 부분을 간과하고 모든 ',' 를 ' '로 바꾸어 isstringstream을 이용해 파싱해서 사용하려고 했는데 곡명에 띄어쓰기가 있을 수 있어서 해맸다.) 
// 결국 공백으로 파싱하는 방법이 아니라 getline을 이용해서 ','를 이용하여 파싱하여 해결함
// 가사의 멜로디의 #은 소문자 알파벳으로 치환해서 사용하면 편하다.

bool func(pair<string, int>a, pair<string, int> b)
{
	if (a.second < b.second)
	{
		return true;
	}
	else
		return false;

}

string EditSong(string a)
{
	string result = "";

	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '#')
		{
			result.back() -= 'A';
			result.back() += 'a';
		}
		else
		{
			result += a[i];
		}
	}
	return result;
}
int strtime_to_inttime(string a)
{
	bool check = false;
	string hour = "";
	string min = "";
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == ':')
		{
			check = true;
			continue;
		}
		if (check)
		{
			min += a[i];
		}
		else
		{
			hour += a[i];
		}
	}
	int num = stoi(hour);
	num *= 60;
	num += stoi(min);
	return num;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "";

	m = EditSong(m);
	vector<int> s;
	vector<int> e;
	vector<string> name;
	vector<string> content;
	// 시작시각, 끝난시각, 제목, 악보별 정리

	for (int i = 0; i < musicinfos.size(); i++)
	{
		istringstream iss(musicinfos[i]);
		string pre, next, na, song;
		bool bpre = true;
		bool bnext = false;
		bool bna = false;
		bool bsong = false;
		string temp;
		while (getline(iss, temp, ','))
		{
			if (bpre)
			{
				bpre = false;
				bnext = true;
				pre = temp;
			}
			else if (bnext)
			{
				bnext = false;
				bna = true;
				next = temp;
			}
			else if (bna)
			{
				bna = false;
				bsong = true;
				na = temp;
			}
			else if (bsong)
			{
				bsong = false;
				song = temp;
			}
		}
		song = EditSong(song);

		s.push_back(strtime_to_inttime(pre));
		e.push_back(strtime_to_inttime(next));
		name.push_back(na);
		song = EditSong(song);
		content.push_back(song);
	}
	int maxplaytime = 0;
	vector<pair<string, int>> rightsong;
	for (int i = 0; i < s.size(); i++)
	{
		int playtime = e[i] - s[i];

		string melody = "";
		for (int j = 0; j < playtime; j++)
		{
			melody += content[i][j%content[i].length()];
		}
		if (melody.find(m) != string::npos)
		{
			if (maxplaytime < playtime)
			{
				maxplaytime = playtime;
				rightsong.clear();
				rightsong.push_back({ name[i],i });
			}
			else if (maxplaytime == playtime)
			{
				rightsong.push_back({ name[i],i });
			}
		}
	}
	if (rightsong.size() == 0)
	{
		answer = "(None)";
	}
	else if (rightsong.size() == 1)
	{
		answer = rightsong[0].first;
	}
	else
	{
		sort(rightsong.begin(), rightsong.end(), func);
		answer = rightsong[0].first;
	}
	return answer;
}


int main()
{
	solution("ABC", { "12:00,12:14,HELLO,C#DEFGAB", "13:00,13:05,WORLD,ABCDEF","13:06,13:15,WORLD2,ABCDEF" });
	return 0;
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

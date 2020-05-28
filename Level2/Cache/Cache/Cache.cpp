// Cache.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <string>
#include <vector>
#include <queue>
using namespace std;


bool isIn(queue<string> a, string b)
{
	bool result = false;
	while (!a.empty())
	{
		if (a.front() == b)
		{
			result = true;
			break;
		}
		else
		{
			a.pop();
		}
	}
	return result;
}
queue<string> updatingqueue(queue<string> a, string b)
{
	vector<string> temp;
	while (!a.empty())
	{
		temp.push_back(a.front());
		a.pop();
	}
	for (int i = 0; i < temp.size(); i++)
	{
		if (temp[i] == b)
		{
			temp.erase(temp.begin() + i);
			break;
		}
	}
	temp.push_back(b);
	queue<string> result;
	for (int i = 0; i < temp.size(); i++)
	{
		result.push(temp[i]);
	}
	return result;
}

int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	queue<string> cachequeue;
	for (int i = 0; i < cities.size(); i++)
	{
		for (int j = 0; j < cities[i].length(); j++)
		{
			if (cities[i][j] >= 'a'&&cities[i][j] <= 'z')
			{
				cities[i][j] -= 'a';
				cities[i][j] += 'A';
			}
		}
	}
	for (int i = 0; i < cities.size(); i++)
	{
		if (isIn(cachequeue, cities[i]))
		{
			cachequeue = updatingqueue(cachequeue, cities[i]);
			answer += 1;
		}
		else
		{
			cachequeue.push(cities[i]);
			answer += 5;
			if (cachequeue.size() > cacheSize)
			{
				cachequeue.pop();
			}
		}
	}
	return answer;
}
int main()
{
	solution( 3,{ "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"} );
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

// Find prime numbers.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> getChe(int num)
{
	vector<int>arr;
	vector<int>ans;

	int i = 2;

	for (i = 0; i <= num; i++)
	{
		arr.push_back(i);
	}
	for (i = 2; i <= num; i++)
	{
		if (arr[i] == 0)
			continue;
		for (int j = i + i; j <= num; j += i)
		{
			arr[j] = 0;
		}
	}
	for (i = 0; i < arr.size(); i++)
	{

		if (arr[i] != 0 && arr[i] != 1)
			ans.push_back(arr[i]);
	}
	return ans;
}

vector<int> permutation(string str, int r)
{
	vector<int> result;
	vector<int> vec;
	for (int i = 0; i < str.length(); i++)
	{
		vec.push_back((str[i] - '0'));
	}
	sort(vec.begin(), vec.end());
	while (1)
	{
		string temp = "";
		for (int i = 0; i < r; i++)
			temp += to_string(vec[i]);
		result.push_back(stoi(temp));

		reverse(vec.begin() + r, vec.end());

		if (!next_permutation(vec.begin(), vec.end()))
			break;
	}

	return result;
}


int solution(string numbers) {
	int answer = 0;
	sort(numbers.begin(), numbers.end());
	reverse(numbers.begin(), numbers.end());
	int num = stoi(numbers);
	vector<int> sosu = getChe(num);

	vector<int> temp;
	for (int i = 1; i <= numbers.size(); i++)
	{
		vector<int> temp2 = permutation(numbers, i);
		for (int j = 0; j < temp2.size(); j++)
		{
			temp.push_back(temp2[j]);
		}
	}
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());
	for (int i = 0; i < sosu.size(); i++)
	{
		for (int j = 0; j < temp.size(); j++)
		{
			if (sosu[i] == temp[j])
			{
				answer++;
			}
		}
	}
	return answer;
}
int main()
{
	solution("17");
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

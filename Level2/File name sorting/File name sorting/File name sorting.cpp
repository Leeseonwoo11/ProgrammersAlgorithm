// File name sorting.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

	#include <string>
	#include <vector>
	#include <sstream>
	#include <iostream>
	#include <algorithm>
	using namespace std;


	bool func(vector<string> a, vector<string> b)
	{
		string a1;
		string b1;
		for (int i = 0; i < a[0].length(); i++)
		{
			if (a[0][i] >= 'A' && a[0][i] <= 'Z')
				a1 += (a[0][i] - 'A' + 'a');
			else
				a1 += a[0][i];
		}
		for (int i = 0; i < b[0].length(); i++)
		{
			if (b[0][i] >= 'A' && b[0][i] <= 'Z')
				b1 += (b[0][i] - 'A' + 'a');
			else
				b1 += b[0][i];
		}
		int ai = stoi(a[1]);
		int bi = stoi(b[1]);
		if (a1 == b1)
		{
			if (ai == bi)
			{
				return false;
			}
			else if (ai < bi)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else if(a1 < b1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	vector<string> solution(vector<string> files) {
		vector<string> answer;
	
		vector<vector<string>> data;
		for (int i = 0; i < files.size(); i++)
		{
			int j;
			vector<string> temp;
			string head, num, tail;
			for (j = 0; files[i][j] < '0'|| files[i][j] > '9'; j++)
			{
				head += files[i][j];
			}
			for (; files[i][j] >= '0' && files[i][j] <= '9'; j++)
			{
				num += files[i][j];
			}
			for (; j < files[i].size(); j++)
			{
				tail += files[i][j];
			}
			temp.push_back(head);
			temp.push_back(num);
			temp.push_back(tail);

			data.push_back(temp);
		}
		stable_sort(data.begin(), data.end(),func);
		for (int i = 0; i < data.size(); i++)
		{
			string temp = "";
			for(int j = 0;j<data[i].size();j++)
			{
				temp += data[i][j];
			}
			answer.push_back(temp);
		}
		return answer;
	}
int main()
{
	solution({ "F-5 Freedom Fighter", "B-50 Superfortress", "A-10 Thunderbolt II", "F-14 Tomcat"});

	
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

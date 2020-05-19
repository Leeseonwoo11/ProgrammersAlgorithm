// ConsoleApplication3.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <time.h>
#include <sstream>
#include <map>

using namespace std;

vector<string> solution(vector<string> record)
{
	vector<string> answer;
	vector<vector<string>> log(record.size(), vector<string>(3)); // 바깥백터의 크기를 record의 크기로 만들고 안쪽백터(vector<string>)의 크기를 3으로 조정한다.(입출여부, 아이디, 이름 의 공간)
	map<string, string> player;

	for (int i = 0; i < record.size(); i++)
	{
		istringstream iss(record[i]);
		string head;
		string mid;
		string tail;
		iss >> head >> mid >> tail;
		log[i][0] = head;
		log[i][1] = mid;
		log[i][2] = tail;
		if (head == "Enter" || head == "Change")
		{
			player[mid] = tail;
		}

	}
	for (int i = 0; i < log.size(); i++)
	{
		if (log[i][0] == "Enter")
		{
			answer.push_back("님이 들어왔습니다.");
			answer.back().insert(0, player[log[i][1]]);
		}
		else if (log[i][0] == "Leave")
		{
			answer.push_back("님이 나갔습니다.");
			answer.back().insert(0, player[log[i][1]]);
		}

	}
	return answer;

}

int main()
{


	// ostringstream 사용 예 (공부한것)
	std::ostringstream oss;
	int inta = 10;
	std::string str = " test_string";
	oss << "test " << inta << str << std::endl;
	string temp = oss.str();
	cout << temp << endl;
	

	solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" });
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
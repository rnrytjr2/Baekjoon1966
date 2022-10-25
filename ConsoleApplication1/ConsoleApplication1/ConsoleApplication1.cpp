// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <queue>
using namespace std;
int main()
{
	int testcasecount, N, M;
	queue<pair<int, int>> datas;
	cin >> testcasecount;
	for (int i = 0; i < testcasecount; i++)
	{
		int importance[10]{ 0,0,0,0,0,0,0,0,0,0 };
		datas = queue<pair<int, int>>();
		bool check = true;
		int currentimportance = 0, answer = 0;
		cin >> N;
		cin >> M;
		for (int j = 0; j < N; j++)
		{
			pair<int, int> value;
			cin >> value.second;
			value.first = j;
			datas.push(value);
			importance[value.second]++;
			currentimportance = max(value.second, currentimportance);
		}
		while (check)
		{
			if (importance[currentimportance] > 0)
			{
				pair<int, int>front = datas.front();
				if (currentimportance != front.second)
				{
					datas.push(datas.front());
					datas.pop();
				}
				else
				{
					answer++;
					if (front.first == M)
					{
						cout << answer << '\n';
						check = false;
					}
					datas.pop();
					importance[currentimportance]--;
				}
			}
			else
			{
				currentimportance--;
			}
		}
	}
}

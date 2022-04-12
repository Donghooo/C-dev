#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int skybridge(int bridge[], int end)
{
	int cnt = 0;
	int current = 0;

 	while (current < end)
	{
		current = bridge[current] + current;
		cnt++;
	}
	return cnt;
}
int main()
{
	//1번문제
	/*
	srand((unsigned int)time(NULL));
	int rnum[3];
	int tmp = 0;
	for (int i = 0; i < 3; i++)
	{
		rnum[i] = rand() % 100 + 1;
		cout << "랜덤숫자" << i + 1 << " : " << rnum[i] << endl;
	}
	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if (rnum[i] > rnum[j])
			{
				tmp = rnum[i];
				rnum[i] = rnum[j];
				rnum[j] = tmp;
			}
		}
	}
	cout << "2번째값은 " << rnum[1] << " 입니다." << endl;
	*/

	//2번문제
	/*
	int arr[5] = { 1,1,2,3,5 };
	cout << "구름다리숫자: ";

	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << "점프횟수: " << skybridge(arr, 5) << endl;
	*/

	return 0;

}
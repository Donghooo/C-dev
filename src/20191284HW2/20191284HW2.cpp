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
	//1������
	/*
	srand((unsigned int)time(NULL));
	int rnum[3];
	int tmp = 0;
	for (int i = 0; i < 3; i++)
	{
		rnum[i] = rand() % 100 + 1;
		cout << "��������" << i + 1 << " : " << rnum[i] << endl;
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
	cout << "2��°���� " << rnum[1] << " �Դϴ�." << endl;
	*/

	//2������
	/*
	int arr[5] = { 1,1,2,3,5 };
	cout << "�����ٸ�����: ";

	for (int i = 0; i < 5; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << "����Ƚ��: " << skybridge(arr, 5) << endl;
	*/

	return 0;

}
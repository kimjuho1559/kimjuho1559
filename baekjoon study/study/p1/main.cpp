#include <iostream>
#include <string>
using namespace std;

int main() {
	int H, W;
	cin >> H >> W;
	char arr[100][100];
//	char** arr = new char*[H];
//	for (int i = 0; i < H; i++)
//	{
//		*arr = new char[W];
//	}
	for (int i = 0; i < H; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < H; i++)
	{
		int count = 0;
		bool num = false;
		for (int j = 0; j < W; j++)
		{
			if (arr[i][j] == 'c') {
				num = true;
				count = 0;
				arr[i][j] = count;
				count++;
			}
			else if (arr[i][j] == '.') {
				if (num == true) {
					arr[i][j] = count;
					count++;
				}
				else
					arr[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			cout << (int)arr[i][j] << " ";
		}
		cout << endl;
	}
}
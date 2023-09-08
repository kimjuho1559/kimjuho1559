#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N, M, count = 0;
	int* x, * y;
	int** a;
	char d[4];
	scanf("%d %d", &N, &M);
	x = (int)malloc(sizeof(int) * N);
	y = (int)malloc(sizeof(int) * N);
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &x[i], &y[i]);
		getchar();
		scanf("%c", &d[i]);
		getchar();
	}
	a = (int**)malloc(sizeof(int*) * N);
	for (int i = 0; i < N; i++)
	{
		a[i] = (int*)malloc(sizeof(int) * N);
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < M; i++)
	{
		if (d[i] == 'U') {
			for (int j = x[i]-1; j >= 0; j--)
			{
				if (a[j][y[i]] == 1) {
					count++;
				}
				a[j][y[i]] = 1;
			}
		}
		else if (d[i] == 'D') {
			for (int j = x[i]-1; j < N; j++)
			{
				if (a[j][y[i]] == 1) {
					count++;
				}
				a[j][y[i]] = 1;
			}
		}
		else if (d[i] == 'L') {
			for (int j = y[i]-1; j >= 0 ; j--)
			{
				if (a[x[i]][j] == 1) {
					count++;
				}
				a[x[i]][j] = 1;
			}
		}
		else if (d[i] == 'R') {
			for (int j = y[i]-1; j < N; j++)
			{
				if (a[x[i]][j] == 1) {
					count++;
				}
				a[x[i]][j] = 1;
			}
		}
	}
	printf("%d\n", count);
}

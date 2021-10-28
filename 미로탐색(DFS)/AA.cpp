#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>
using namespace std;

int dx[4] = {-1, 0, 1, 0}; // »óÇÏÁÂ¿ì
int dy[4] = {0, 1, 0, -1};
int cnt = 0;
void DFS(int x, int y, int board[][7]) {
	//cout << x << " " << y << endl;
	if (x == 6 && y == 6) {
		cnt++;
		//return 1;
	}
	else {
		for (int i = 0; i < 4; i++) {
			int nx, ny;
			nx = x + dx[i];
			ny = y + dy[i];
			if (0<=nx && nx<=6 && 0<=ny && ny<=6 && board[nx][ny] == 0) {
				board[nx][ny] = 1;
				DFS(nx, ny, board);
				board[nx][ny] = 0;
			}
		}
	}
}
int main(int argc, char* argv[]) {
	int b[7][7];
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++) {
			cin >> b[i][j];
		}
	}
	b[0][0] = 1;
	DFS(0, 0, b);
	cout << cnt << endl;

}
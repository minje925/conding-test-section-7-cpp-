#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <queue>
using namespace std;

// ÁÂ¿ì»óÇÏ
int dx[4] = {-1, 1, 0, 0};
int dy[4] = { 0, 0, 1, -1 };

void BFS(int board[][7], int check[][7], queue<pair<int, int>> q) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx <= 6 && ny >= 0 && ny <= 6 && board[nx][ny] == 0) {
				board[nx][ny] = 1;
				check[nx][ny] = check[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}
int main(int argc, char* argv[]) {
	int board[7][7] = { 0, };
	int check[7][7] = { 0, };
	queue<pair<int, int>> q;
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++)
			cin >> board[i][j];
	}
	q.push(make_pair(0, 0));
	board[0][0] = 1;
	BFS(board, check, q);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < 7; j++)
			cout << check[i][j]<< " ";
		cout << endl;
	}
	if (check[6][6] == 0)
		cout << -1 << endl;
	else
		cout << check[6][6] << endl;

}
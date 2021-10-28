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

int dx[8] = {-1, 1, 0, 0, -1, 1, 1, -1}; // ÁÂ¿ì»óÇÏ
int dy[8] = { 0, 0, 1, -1, 1, 1, -1, -1};
int n;
vector<vector<int>> board;
int BFS(queue<pair<int, int>> q) {
	int ch = 0;
	while (!q.empty()) {
		cout << "Å½»ö" << endl;
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= n - 1 && board[nx][ny] == 1) {
				board[nx][ny] = 0;
				q.push(make_pair(nx, ny));
			}
		}
	}
	return ch;
}

int main(int argc, char* argv[]) {
	cin >> n;
	vector<int> tv;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			tv.push_back(temp);
		}
		board.push_back(tv);
		tv.clear();
	}
	cout << "Å½»ö ½ÃÀÛ" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] == 1) {
				queue<pair<int, int>> q;
				q.push(make_pair(i, j));
				board[i][j] = 0;
				BFS(q);
				cnt++;
			}
		}
	}
	cout << "cnt : " << cnt << endl;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

}
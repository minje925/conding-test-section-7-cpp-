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
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int n;
vector<vector<int>> check;
void BFS(vector<vector<int>> board, queue<pair<int, int>> q) {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx <= n - 1 && ny >= 0 && ny <= n - 1 && board[nx][ny] > board[x][y]) {
				cout << "check : "<<check[x][y]+1 << endl;
				check[nx][ny] = check[x][y] + 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main(int argc, char* argv[]) {
	cin >> n;
	vector<vector<int>> board;
	vector<int> tv, tc;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			tv.push_back(temp);
			tc.push_back(0);
		}
		board.push_back(tv);
		check.push_back(tc);
		tv.clear();
		tc.clear();
	}
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	BFS(board, q);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << check[i][j] << " ";
		}
		cout << endl;
	}
	

}
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

int dx[4] = { -1, 0, 1, 0 }; // »óÇÏÁÂ¿ì
int dy[4] = { 0, 1, 0, -1 };
int n, res = 0;
int m = -214700000;
vector<vector<int>> main_board, board;
vector<int> tv, result;

void BFS(queue<pair<int, int>> q, int rain) {
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] >= rain) {
				board[nx][ny] = m;
				q.push(make_pair(nx, ny));
				cnt++;
			}
		}
	}
	if (cnt != 0) {
		res++;
	}
}
int main(int argc, char* argv[]) {
	cin >> n;
	int max = -2147000000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			tv.push_back(temp);
			if (temp > max)
				max = temp;
		}
		main_board.push_back(tv);
		tv.clear();
	}
	for (int k = 1; k < max; k++) {
		board.assign(main_board.size(), vector<int>(main_board.size()));
		copy(main_board.begin(), main_board.end(), board.begin());

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				queue<pair<int, int>> q;
				board[i][j] = m;
				q.push(make_pair(i, j));
				BFS(q, k);
			}
		}
		board.clear();
		result.push_back(res);
		//cout << "res : " << res << endl;
		res = 0;
	}
	max = -2147000000;
	for (int i = 0; i < result.size(); i++) {
		if (result[i] > max)
			max = result[i];
	}
	cout << "result : " << max << endl;
}
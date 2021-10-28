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
int n, cnt, d = 1;
vector<vector<int>> board, check;
vector<int> tv,res;

void BFS(queue<pair<int, int>> q) {
	cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n && board[nx][ny] == 1) {
				board[nx][ny] = 0;
				check[nx][ny] = d;
				cnt++;
				q.push(make_pair(nx, ny));
			}
		}
		
	}
	if (cnt != 0) {
		res.push_back(cnt);
		d++;
	}
	
	//cnt++;
}


int main(int argc, char* argv[]) {
	cin >> n;
	vector<int> t(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int temp;
			cin >> temp;
			tv.push_back(temp);
		}
		board.push_back(tv);
		check.push_back(t);
		tv.clear();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			queue<pair<int, int>> q;
			q.push(make_pair(i, j));
			BFS(q);
		}
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << check[i][j] << " ";
		}
		cout << endl;
	}
	cout << res.size() << endl;
	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << endl;
	}

}
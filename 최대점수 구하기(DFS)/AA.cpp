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

int n, m;
vector<pair<int, int>> v;
vector<int> res;
int DFS(int L, int score, int time) {
	if (time > m)
		return 0;
	if (L == n) {
		cout << score<<endl;
		return 1;
	}
	else {
		DFS(L + 1, score + v[L].first, time+v[L].second); // 풀었을 때
		DFS(L + 1, score, time); // 안 풀었을 때
	}
}
int main(int argc, char* argv[]) {

	cin >> n>>m;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
		res.push_back(0);
	}
	DFS(0, 0, 0);
	/*
	for (int i = 0; i < n; i++) {
		cout << v[i].first << " " << v[i].second << endl;
	}
	*/


}
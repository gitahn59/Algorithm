/*
boj_1799_비숍(난이도 : 골드2)
Backtracking
대각선의 성질에 따라, 후보군을 두개로 나누어
따로 최대값을 찾으면
주어진 시간안에 후보집합을 탐색할 수 있음
*/

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <cmath>
#include <set>
#include <bitset>
#include <climits>
#include <functional>

#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> LL;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef deque<int> di;
typedef pair<int, ii> iii;
typedef set<int> si;

int N, M;
int arr[10][10];
int visited[10][10];
vii candidate;
vii snd;
int myMax;
int ni[] = { 1,1,-1,-1 };
int nj[] = { -1,1,-1,1 };
int BISHOP = 100;

bool check(ii now) {
	for (int k = 0; k < 4; k++) {
		int i = now.first;
		int j = now.second;
		while (true) {
			i += ni[k];
			j += nj[k];
			if (i < 0 || i == N || j < 0 || j == N) break;
			if (visited[i][j] == BISHOP) return false;
		}
	}
	return true;
}

void backtrack(int now, int cnt) {
	myMax = max(myMax, cnt);
	if (now == M) {
		return;
	}
	if (check(candidate[now])) {
		visited[candidate[now].first][candidate[now].second] = BISHOP;
		backtrack(now + 1, cnt + 1);
		visited[candidate[now].first][candidate[now].second] = 0;
	}
	if (cnt + M - now + 1 < myMax) return;
	backtrack(now + 1, cnt);
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	bool turn = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j]) {
				if (turn) candidate.push_back({ i,j });
				else snd.push_back({ i,j });
			}
			turn = !turn;
		}
		if (N % 2 == 0)
			turn = !turn;
	}

	int rst = 0;
	M = candidate.size();
	backtrack(0, 0);
	rst += myMax;

	myMax = 0;
	candidate = snd;
	M = candidate.size();
	backtrack(0, 0);
	rst += myMax;

	cout << rst << "\n";

	return 0;
}


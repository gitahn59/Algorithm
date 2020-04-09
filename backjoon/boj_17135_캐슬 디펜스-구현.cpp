/*
boj_17135_캐슬 디펜스(난이도 : 골드4)
구현
주의) 턴이 경과함에 따라 사라지는 병사를 고려해야 함
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
#include <tuple>

#define PRIME 1000000007

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

int N, M, D;
int arr[21][21];
int selected[16];
int cpy[21][21];

int len(int r1, int c1, int r2, int c2) {
	return abs(r1 - r2) + abs(c1 - c2);
}

int bf() {
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			cpy[n][m] = arr[n][m];
		}
	}

	ii e[4];

	int sum = 0;

	int c = 0;
	for (int n = N; n >= 1; n--, c++) {
		for (int s = 1; s <= 3; s++) {
			int man = selected[s];
			ii enemy = { 20,20 };
			int minlen = 300;
			for (int i = n; i >= 1; i--) {
				for (int j = 1; j <= M; j++) {
					if (cpy[i][j] == 1) {
						int l = len(i, j, N + 1, man);
						if (l > D + c) continue;
						if (l < minlen) {
							enemy = { i,j };
							minlen = l;
						}
						else if (l == minlen) {
							if (enemy.second > j) {
								enemy = { i,j };
								minlen = l;
							}
						}
					}
				}
			}
			e[s] = enemy;
		}
		for (int s = 1; s <= 3; s++) {
			if (cpy[e[s].first][e[s].second] == 1) {
				cpy[e[s].first][e[s].second] = 0;
				sum++;
			}
		}
	}

	return sum;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> D;
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			cin >> arr[n][m];
		}
	}

	int cnt = 0;
	int myMax = 0;
	int end = 1 << M;
	for (int i = 7; i < end; i++) {
		for (int j = 0; j <= 15; j++) {
			if (i & 1 << j) {
				selected[++cnt] = j + 1;
			}
		}
		if (cnt == 3) {
			myMax = max(myMax, bf());
		}
		cnt = 0;
	}

	cout << myMax << "\n";

	return 0;
}


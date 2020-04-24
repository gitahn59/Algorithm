/*
boj_1987_알파벳(난이도 : 골드4)
Backtracking
dfs를 통해 행렬을 탐색하며 가지치기
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

int R, C;
int arr[22][22];
int selected[27];
int myMax = 0;
int ni[] = { 1,-1,0,0 };
int nj[] = { 0,0, 1,-1 };

void dfs(int w, int h, int cnt) {
	myMax = max(myMax, cnt);

	for (int k = 0; k < 4; k++) {
		int i = w + ni[k];
		int j = h + nj[k];
		if (i<1 || i>R || j <1 || j > C) continue;
		if (selected[arr[i][j]] == 0) {
			selected[arr[i][j]] = 1;
			dfs(i, j, cnt + 1);
			selected[arr[i][j]] = 0;
		}
	}
	return;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> R >> C;
	char str[25];
	for (int r = 1; r <= R; r++) {
		cin >> str + 1;
		for (int c = 1; c <= C; c++) {
			arr[r][c] = str[c] - 'A';
		}
	}

	selected[arr[1][1]] = 1;
	dfs(1, 1, 1);

	cout << myMax << "\n";

	return 0;
}


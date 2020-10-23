/*
boj_14716_현수막(난이도 : 골드5)
dfs
dfs를 사용한 연결 요소 탐색
bfs를 통해서도 같은 결과 생성 가능
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

int N, M;

int arr[250][250];
bool visited[250][250];
int ni[] = { 1,-1,0,0,1,-1,1,-1 };
int nj[] = { 0,0,1,-1,1,-1,-1,1 };

void dfs(int i, int j) {
	for (int k = 0; k < 8; k++) {
		int h = i + ni[k];
		int w = j + nj[k];
		if (h < 0 || h == N || w < 0 || w == M) continue;
		if (visited[h][w]) continue;
		visited[h][w] = 1;
		if (arr[h][w] == 1)
			dfs(h, w);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j]) continue;
			visited[i][j] = 1;
			if (arr[i][j] == 1) {
				cnt++;
				dfs(i, j);
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}

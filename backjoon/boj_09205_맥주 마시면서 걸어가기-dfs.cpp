/*
boj_9205_맥주 마시면서 걸어가기(난이도 : 실버1)
dfs
좌표상의 노드들의 관계를 그래프 구조로 모델링하여
dfs로 탐색하는 문제
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

int T;
int N, M;
ii pos[110];

bool dfs(vi* adj, bool* visited, int now) {
	for (auto i : adj[now]) {
		if (visited[i] == 1) {
			continue;
		}
		else {
			visited[i] = 1;
			if (i == M)
				return true;
			else {
				if (dfs(adj, visited, i))
					return true;
			}
		}
	}
	return false;
}

bool solve() {
	vi adj[110];
	for (int n = 0; n <= M; n++) {
		for (int i = 0; i <= M; i++) {
			if (n == i) continue;
			int len = abs(pos[n].first - pos[i].first) + abs(pos[n].second - pos[i].second);
			if (len <= 1000) {
				adj[n].push_back(i);
			}
		}
	}
	bool visited[110];
	for (int m = 0; m <= M; m++) {
		visited[m] = 0;
	}

	return dfs(adj, visited, 0);
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		M = N + 1;
		for (int n = 0; n <= N + 1; n++) {
			cin >> pos[n].first >> pos[n].second;
		}

		if (solve()) {
			cout << "happy\n";
		}
		else {
			cout << "sad\n";
		}
	}

	return 0;
}

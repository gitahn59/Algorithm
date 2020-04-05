/*
boj_11404_플로이드(난이도 : 골드4)
기본적인 플로이드 와샬 알고리즘
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

typedef struct edge {
	int from, to, cost;
}Edge;

int N, M;
int cost[101][101];
int INF = 100000000;
int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int from, to, cst;

	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= N; i++) {
			if (n == i) continue;
			else cost[n][i] = INF;
		}
	}

	for (int m = 1; m <= M; m++) {
		cin >> from >> to >> cst;
		cost[from][to] = min(cost[from][to], cst);
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (cost[i][j] > cost[i][k] + cost[k][j]) {
					cost[i][j] = cost[i][k] + cost[k][j];
				}
			}
		}
	}

	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= N; i++) {
			if (cost[n][i] == INF) cout << 0 << " ";
			else cout << cost[n][i] << " ";
		}
		cout << "\n";
	}

	return 0;
}

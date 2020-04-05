/*
boj_11657_타임머신(난이도 : 골드4)
기본적인 벨만포드 알고리즘
2중 for문으로 갱신과정에서 INT 범위를 벗어날 수 있으므로
LL을 사용해야 함
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

int V, E;
ll dist[501];
Edge edges[6001];
ll INF = LLONG_MAX;

bool bellman_ford(int start) {
	fill(dist, dist + V + 1, INF);
	dist[1] = 0;
	for (int v = 1; v < V; v++) {
		for (int e = 1; e <= E; e++) {
			Edge now = edges[e];
			ll cost = dist[now.from] + now.cost;
			if (dist[now.from] != INF && dist[now.to] > cost) {
				dist[now.to] = cost;
			}
		}
	}

	for (int e = 1; e <= E; e++) {
		if (dist[edges[e].from] == INF) continue;
		if (dist[edges[e].to] > dist[edges[e].from] + edges[e].cost) {
			return true;
		}
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E;

	int a, b, c;
	for (int e = 1; e <= E; e++) {
		cin >> edges[e].from >> edges[e].to >> edges[e].cost;
	}

	if (bellman_ford(1)) {
		cout << -1 << "\n";
	}
	else {
		for (int v = 2; v <= V; v++) {
			if (dist[v] == INF) cout << -1 << "\n";
			else cout << dist[v] << "\n";
		}
	}

	return 0;
}

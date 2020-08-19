/*
boj_01753_최단경로(난이도 : 골드5)
다익스트라
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

int V, E, K;
int INF = 200000000;
bool visited[20001];
int dist[20001];
vii adj[20001];

void dijkstra() {
	for (int v = 1; v <= V; v++) {
		dist[v] = INF;
	}
	dist[K] = 0;
	priority_queue<ii> q;
	q.push({ 0,K });
	while (!q.empty()) {
		ii now = q.top();
		q.pop();
		int cost = -now.first;
		int k = now.second;

		if (visited[k]) continue;
		visited[k] = 1;

		for (ii i : adj[k]) {
			int c = cost + i.first;
			int to = i.second;
			if (dist[to] > c) {
				q.push({ -c, to });
				dist[to] = c;
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> V >> E >> K;
	int u, v, w;
	for (int i = 0; i < E; i++) {
		cin >> u >> v >> w;
		adj[u].push_back({ w, v });
	}

	dijkstra();
	for (int v = 1; v <= V; v++) {
		if (dist[v] == INF) cout << "INF\n";
		else cout << dist[v] << "\n";
	}

	return 0;
}



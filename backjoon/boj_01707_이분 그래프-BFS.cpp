/*
boj_1707_이분 그래프(난이도 : 골드3)
BFS
이분그래프 : 모든 정점에 대하여 
현재 정점을 RED로 색칠했을 때 인접한 모든 정점은 BLUE, 
또는 그 역이 성립하는 그래프
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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> LL;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

int T;
int V, E;
vi adj[20001];
int visited[20001];

int RED = 100;
int BLUE = -100;
int FIRST = 0;

bool bfs(int v) {
	queue<int> q;
	visited[v] = RED;
	q.push(v);

	while (!q.empty()) {
		int now = q.front();
		q.pop();
		int next_color = visited[now] * -1;

		for (int i : adj[now]) {
			if (visited[i] == FIRST) {
				visited[i] = next_color;
				q.push(i);
			}
			else if (visited[i] != next_color) {
				return false;
			}
			else {
				continue;
			}
		}
	}

	return true;
}

void solution() {
	cin >> V >> E;
	for (int v = 1; v <= V; v++) {
		adj[v].clear();
		visited[v] = FIRST;
	}

	int from, to;
	for (int e = 0; e < E; e++) {
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	bool result = true;
	for (int v = 1; result && v <= V; v++) {
		if (visited[v] == FIRST)
			result = result && bfs(v);
	}

	if (result) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}

}


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++) {
		solution();
	}

	return 0;
}
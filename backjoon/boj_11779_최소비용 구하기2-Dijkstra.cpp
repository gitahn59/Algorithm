/*
boj_11779_최소비용 구하기 2(난이도 : 골드3)
Dijkstra
경로 출력이 추가된 다익스트라 알로기름
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
vii adj[1001];
int dist[1001];
int path[1001];
bool visited[1001];
int INF = 2000000000;

int dijkstra(int start, int end) {
	for (int n = 1; n <= N; n++) {
		dist[n] = INF;
	}

	priority_queue<ii> pq;
	pq.push({ 0,start });
	dist[start] = 0;

	while (!pq.empty()) {
		ii now = pq.top();
		pq.pop();
		int d = -now.first;
		int num = now.second;

		if (visited[num]) continue;
		visited[num] = 1;
		for (ii nxt : adj[num]) {
			int len = d - nxt.first;
			if (dist[nxt.second] > len) {
				dist[nxt.second] = len;
				path[nxt.second] = num;
				pq.push({ -len, nxt.second });
			}
		}
	}

	return dist[end];
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int a, b, c;
	for (int m = 0; m < M; m++) {
		cin >> a >> b >> c;
		adj[a].push_back({ -c, b });
	}

	int start, end;
	cin >> start >> end;
	cout << dijkstra(start, end) << "\n";
	vi rst;
	int now = end;
	rst.push_back(now);
	while (now != start) {
		rst.push_back(path[now]);
		now = path[now];
	}

	cout << rst.size() << "\n";
	reverse(rst.begin(), rst.end());
	for (int i : rst) {
		cout << i << " ";
	}
	cout << "\n";

	return 0;
}

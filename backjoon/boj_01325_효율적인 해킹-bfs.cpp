/*
boj_01325_효율적인 해킹(난이도 : 실버2)
bfs, bf
시작점에 따라 bfs의 결과가 항상 달라질 수 있으므로 모든 경우의 수에 대해
bfs를 수행햐여야 함
따라서 효율적인 bfs가 수행되어야 하며, 조건 검사를 미리하여
최적화 해야 함
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

int N, M;
int dist[10001];
vi adj[10001];
bool visited[10001];
int bfs(int start) {
	queue<int> qi;
	qi.push(start);
	int cnt = 1;
	visited[start] = 1;
	while (!qi.empty()) {
		int now = qi.front();
		qi.pop();
		cnt++;
		for (int next : adj[now]) {
			if (visited[next]) continue;
			visited[next] = 1;
			qi.push(next);
		}
	}
	return cnt;
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int a, b;
	for (int m = 1; m <= M; m++) {
		cin >> a >> b;
		adj[b].push_back(a);
	}

	int myMax = 0;
	for (int n = 1; n <= N; n++) {
		dist[n] = bfs(n);
		memset(visited, 0, sizeof(visited));
		myMax = max(myMax, dist[n]);
	}

	for (int n = 1; n <= N; n++) {
		if (dist[n] == myMax) cout << n << " ";
	}
	cout << "\n";
	return 0;
}


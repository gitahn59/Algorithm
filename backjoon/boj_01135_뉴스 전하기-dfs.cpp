/*
boj_1135_뉴스 전하기(난이도 : 플레5)
dfs
dfs를 통해 트리를 탐색하면서
자식 노드들의 걸린시간을 고려하여
자신의 걸린시간을 구해 위쪽으로 전파

자식노드들은 걸린시간에 대해 내림차순으로 정렬하고
한 노드를 지나갈때마다 도달시간을 1씩 증가시켜
(n번째 자식을 탐색하려면 미리 n-1번째까지 자식노드가 탐색되어야함)
더해주고 종합적인 최대 시간을 계산
int cnt = 0;
while (!q.empty()) {
	ii top = q.top();
	q.pop();
	t = max(t, cnt + top.first);
	cnt++;
}
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

int N;

vi adj[50];
int dist[50];

int dfs(int now) {
	if (adj[now].size() == 0) return dist[now] = 1;
	int t = 0;

	priority_queue<ii> q;
	for (int i : adj[now]) {
		q.push({ dfs(i),i });
	}

	int cnt = 0;
	while (!q.empty()) {
		ii top = q.top();
		q.pop();
		t = max(t, cnt + top.first);
		cnt++;
	}

	return dist[now] = t + 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int p;
	cin >> p;

	for (int i = 1; i < N; i++) {
		cin >> p;
		adj[p].push_back(i);
	}

	cout << dfs(0) - 1 << "\n";
	return 0;
}



/*
boj_01162_��������(���̵� : ���1)
����ũ��Ʈ�� + dp ����
������ cost�� K�� 0���� ���� �� ���� ��, �ִܰŸ��� ���ϴ� ����
����ũ��Ʈ�� ���� �������� 
dp�� ����Ͽ� k�� ��ŭ 0���� ������� ���� �Ÿ��� �����ϸ� ���
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

int N, M, K;
vii adj[10001];
ll dist[10001][21];
bool visited[10001][21];

typedef struct edge {
	int node, cnt;
	ll cost;

	bool operator < (const edge& a) const {
		return cost > a.cost;
	}
}Edge;

void dijkstra() {
	for (int n = 1; n <= N; n++) {
		for (int k = 0; k <= K; k++) {
			dist[n][k] = 500000000000;
		}
	}

	priority_queue<Edge> pq;
	pq.push({ 1,0,0 });
	dist[1][0] = 0;

	while (!pq.empty()) {
		Edge now = pq.top();
		pq.pop();

		if (visited[now.node][now.cnt]) continue;
		else visited[now.node][now.cnt] = 1;

		for (ii to : adj[now.node]) {
			ll d = now.cost + to.second;
			if (dist[to.first][now.cnt] > d) {
				dist[to.first][now.cnt] = d;
				pq.push({ to.first,now.cnt,d });
			}
			if (now.cnt + 1 <= K && dist[to.first][now.cnt + 1] > now.cost) {
				dist[to.first][now.cnt + 1] = now.cost;
				pq.push({ to.first,now.cnt + 1, now.cost });
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;

	int from, to, cost;
	for (int m = 1; m <= M; m++) {
		cin >> from >> to >> cost;
		adj[from].push_back({ to, cost });
		adj[to].push_back({ from, cost });
	}

	dijkstra();
	ll myMin = 500000000000;
	for (int k = 0; k <= K; k++) {
		myMin = min(myMin, dist[N][k]);
	}

	cout << myMin << "\n";

	return 0;
}

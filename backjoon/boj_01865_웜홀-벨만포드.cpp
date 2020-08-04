/*
boj_1865_웜홀(난이도 : 골드4)
벨만포드
최단거리가 아니라 음수사이클의 존재여부가 해답인 문제
그래프의 연결여부도 상관없으며
어느 점에서 시작하든 음수사이클만 존재하면 됨
따라서 거리 dist를 적당히 큰 값으로 초기화하고
벨만포드 알고리즘을 돌려 음수 사이클만 확인하면 됨
이때 INF를 생략하지 않고 모두 계산하여
사이클이 발생하는지 확인해야 함
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

typedef struct node {
	int s, e, t;
}Node;
typedef vector<Node> vn;

int TC;
int N, M, W;
int INF = 10000 * 10000;

bool bf(vn& adj) {
	int dist[501];
	for (int n = 1; n <= N; n++) {
		dist[n] = INF;
	}

	for (int n = 1; n <= N; n++) {
		for (Node now : adj) {
			int cost = dist[now.s] + now.t;
			if (dist[now.e] > cost) {
				dist[now.e] = cost;
			}
		}
	}

	int nxt[501];
	for (int n = 1; n <= N; n++) {
		nxt[n] = dist[n];
	}
	for (Node now : adj) {
		int cost = nxt[now.s] + now.t;
		if (nxt[now.e] > cost) {
			nxt[now.e] = cost;
			return true;
		}
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> TC;
	for (int tc = 0; tc < TC; tc++) {
		cin >> N >> M >> W;
		vn adj;
		int s, e, t;
		for (int m = 0; m < M; m++) {
			cin >> s >> e >> t;
			adj.push_back({ s, e, t });
			adj.push_back({ e, s, t });
		}
		for (int w = 0; w < W; w++) {
			cin >> s >> e >> t;
			adj.push_back({ s, e, -t });
		}

		if (bf(adj)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}


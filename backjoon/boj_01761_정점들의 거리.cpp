/*
boj_01761_정점들의 거리(난이도 : 플레5)
dfs를 통해 트리를 구성
최소 공통 조상(LCA)를 이용한 트리 내부의 두 노드 사이의 거리 계산
두 노드에 대해 최소 공통 조상까지의 각 거리를 계산하여 더함
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
typedef vector<vi> G;
typedef deque<int> di;
typedef pair<int, ii> iii;
typedef set<int> si;

int N, M;

vii adj[40001];
int rnk[40001];
ii parentList[40001][20];

void dfs(int now, int dist, int parent, int h) {
	parentList[now][0] = { parent, dist };
	rnk[now] = h;
	for (int i = 1; i < 20; i++) {
		ii p = parentList[now][i - 1];
		ii pp = parentList[p.first][i - 1];

		parentList[now][i] = { pp.first,p.second + pp.second };
	}

	for (ii child : adj[now]) {
		if (child.first == parent) continue;
		dfs(child.first, child.second, now, h + 1);
	}
}

int lca(int a, int b) {
	int sum = 0;
	if (rnk[a] != rnk[b]) {
		if (rnk[a] > rnk[b]) swap(a, b);
		int diff = rnk[b] - rnk[a];
		for (int i = 0; diff; i++) {
			if (diff & 1) {
				sum += parentList[b][i].second;
				b = parentList[b][i].first;
			}
			diff = diff >> 1;
		}
	}

	if (a == b) return sum;
	if (parentList[a][0].first == parentList[b][0].first) {
		return sum + parentList[a][0].second + parentList[b][0].second;
	}
	for (int i = 1; i < 20; i++) {
		if (parentList[a][i].first == parentList[b][i].first) {
			return sum + lca(parentList[a][i - 1].first, parentList[b][i - 1].first)
				+ parentList[a][i - 1].second + parentList[b][i - 1].second;
		}
	}
	return 0;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int a, b, c;

	cin >> N;
	for (int n = 1; n < N; n++) {
		cin >> a >> b >> c;
		adj[a].push_back({ b,c });
		adj[b].push_back({ a,c });
	}
	for (int i = 0; i < 20; i++) {
		parentList[0][i] = { 1,0 };
	}

	dfs(1, 0, 1, 0);

	cin >> M;
	for (int m = 1; m <= M; m++) {
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}
}
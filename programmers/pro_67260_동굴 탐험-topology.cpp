/*
pro_67260_동굴 탐험(난이도 : level 4)
topology sort
동굴의 각 방을 선후관계가 있는 트리로 모델링 할 수 있음
1. 따라서 dfs를 돌면서 트리를 구성하여 우선순위를 갱신하고
2. order 배열의 우선순위 역시 갱신하면
3. topology sort를 위한 우선순위를 전부 구할 수 있음

4 마지막으로 topology sort를 돌려보고
각 노드의 cnt가 전부 0이 되었는지 확인하면 됨
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
vi adj[200000];
int cnt[200000];
vi post[200000];

void dfs(int now, int p) {
	for (int child : adj[now]) {
		if (child == p) continue;
		cnt[child]++;
		post[now].push_back(child);
		dfs(child, now);
	}
}

bool topology_sort() {
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int now = q.front();
		q.pop();

		for (int nxt : post[now]) {
			cnt[nxt]--;
			if (cnt[nxt] == 0) q.push(nxt);
		}
	}
	for (int n = 0; n < N; n++) {
		if (cnt[n]) return false;
	}
	return true;
}

bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
	N = n;
	bool answer = true;
	for (vi v : path) {
		adj[v[0]].push_back(v[1]);
		adj[v[1]].push_back(v[0]);
	}
	dfs(0, -1);
	for (vi v : order) {
		post[v[0]].push_back(v[1]);
		cnt[v[1]]++;
	}
	answer = topology_sort();

	return answer;
}



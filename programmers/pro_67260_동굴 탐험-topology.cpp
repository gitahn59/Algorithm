/*
pro_67260_���� Ž��(���̵� : level 4)
topology sort
������ �� ���� ���İ��谡 �ִ� Ʈ���� �𵨸� �� �� ����
1. ���� dfs�� ���鼭 Ʈ���� �����Ͽ� �켱������ �����ϰ�
2. order �迭�� �켱���� ���� �����ϸ�
3. topology sort�� ���� �켱������ ���� ���� �� ����

4 ���������� topology sort�� ��������
�� ����� cnt�� ���� 0�� �Ǿ����� Ȯ���ϸ� ��
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



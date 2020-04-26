/*
boj_11725_Ʈ���� �θ� ã��(���̵� : �ǹ�2)
dfs
��������Ʈ�� dfs�� �̿��� Ʈ�� Ž��
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

int N;
vi adj[100001];
int prnt[100001];

void dfs(int now, int p) {
	prnt[now] = p;
	for (int child : adj[now]) {
		if (child == p) continue;
		dfs(child, now);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int from, to;
	for (int n = 1; n <= N - 1; n++) {
		cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	dfs(1, 0);
	for (int n = 2; n <= N; n++) {
		cout << prnt[n] << "\n";
	}

	return 0;
}


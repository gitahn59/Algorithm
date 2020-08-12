/*
boj_2533_사회망 서비스(SNS)(난이도 : 골드2)
DFS
1. 잎노드이면 노말 노드로 선정하고, 부모 노드가 얼리어댑터이면 
 최소가 된다.
2. 자식 노드들 중에 하나라도 노말 노드가 있으면 부모노드는
   얼리어댑터가 된다.

위 두 성질만 만족하도록 DFS 를 구현하면 O(N)에 문제를 해결 할 수 있음
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

int N;
vi adj[1000001];
int rst;
bool dfs(int prnt, int now) {
	bool flag = false;
	int len = 0;
	for (int i : adj[now]) {
		if (i == prnt) continue;
		bool normal = dfs(now, i);
		flag = (normal || flag);
		len++;
	}
	// leaf is normal
	if (len == 0) return true;

	// must be eraly
	if (flag) {
		rst++;
	}
	return !flag;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int s, e;
	for (int n = 0; n < N - 1; n++) {
		cin >> s >> e;
		adj[s].push_back(e);
		adj[e].push_back(s);
	}

	dfs(0, 1);
	cout << rst << "\n";

	return 0;
}



/*
boj_1167_트리의 지름(난이도 : 골드3)
dfs
boj_1967과 동일
단, 건선의 정보가 양방향 전부 들어오므로 
한 번만 넣어주면 됨
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
vii adj[100001];

ii dfs(int now, int cost, int p) {
	ii myMax = { now,-1 };

	for (ii child : adj[now]) {
		if (child.first == p) continue;
		ii node = dfs(child.first, cost + child.second, now);
		if (myMax.second < node.second) {
			myMax = node;
		}
	}

	if (myMax.second == -1) return { now, cost };
	else return myMax;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int from, to, cost;
	for (int n = 1; n <= N; n++) {
		cin >> from;
		while (true) {
			cin >> to;
			if (to == -1) break;
			cin >> cost;
			adj[from].push_back({ to, cost });
		}
	}

	ii rst = dfs(1, 0, 0);
	ii rt = dfs(rst.first, 0, 0);

	cout << rt.second << "\n";

	return 0;
}


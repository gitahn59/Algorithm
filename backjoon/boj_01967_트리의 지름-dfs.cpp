/*
boj_1967_Ʈ���� ����(���̵� : ���4)
Ʈ���� ����
A�������� ��� �������� ���̸� ���� ���� �� ��� A ����
������ ���� ���� �ٸ� ��� �������� �Ÿ��� ���� ���� �� ��� B ����
Ʈ���� ���� = B������ �Ÿ�
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

vii adj[10001];

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
	for (int n = 1; n <= N - 1; n++) {
		cin >> from >> to >> cost;
		adj[from].push_back({ to, cost });
		adj[to].push_back({ from,cost });
	}

	ii rst = dfs(1, 0, 0);
	ii rt = dfs(rst.first, 0, 0);

	cout << rt.second << "\n";

	return 0;
}




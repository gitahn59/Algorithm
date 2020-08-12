/*
boj_2533_��ȸ�� ����(SNS)(���̵� : ���2)
DFS
1. �ٳ���̸� �븻 ���� �����ϰ�, �θ� ��尡 �󸮾�����̸� 
 �ּҰ� �ȴ�.
2. �ڽ� ���� �߿� �ϳ��� �븻 ��尡 ������ �θ����
   �󸮾���Ͱ� �ȴ�.

�� �� ������ �����ϵ��� DFS �� �����ϸ� O(N)�� ������ �ذ� �� �� ����
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



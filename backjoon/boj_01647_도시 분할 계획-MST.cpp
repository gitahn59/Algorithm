/*
boj_01647_도시 분할 계획(난이도 : 골드4)
mst
mst를 구하고 간선중에서 최댓값을 제외
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

typedef struct unionfind {
	int prnt[100001];

	unionfind(int size) {
		for (int i = 1; i <= size; i++) {
			prnt[i] = i;
		}
	}

	int getParent(int a) {
		if (a == prnt[a]) return a;
		else return prnt[a] = getParent(prnt[a]);
	}

	bool isSet(int a, int b) {
		a = getParent(a);
		b = getParent(b);
		return a == b;
	}

	void mearge(int a, int b) {
		a = getParent(a);
		b = getParent(b);
		prnt[a] = b;
	}
}UnionFind;

int N, M;

typedef struct node {
	int from, to, cost;
}Node;

Node edges[1000001];
int cst[100010];

bool myCmp(Node a, Node b) {
	return a.cost < b.cost;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int a, b, c;
	for (int m = 1; m <= M; m++) {
		cin >> a >> b >> c;
		edges[m] = { a,b,c };
	}
	sort(edges + 1, edges + M + 1, myCmp);

	UnionFind uf(N);
	int cnt = 0;
	for (int m = 1; m <= M; m++) {
		Node now = edges[m];
		if (uf.isSet(now.from, now.to)) continue;
		uf.mearge(now.from, now.to);
		cst[++cnt] = now.cost;
	}

	int sum = 0;
	int myMax = 0;
	for (int c = 1; c <= cnt; c++) {
		sum += cst[c];
		myMax = max(myMax, cst[c]);
	}

	cout << sum - myMax << "\n";
	return 0;
}


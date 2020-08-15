/*
boj_17619_개구리 점프(난이도 : 골드3)
서로소집합, 스위핑
서로소집합을 이용해 겹치는 선분 영역들의
집합을 관리함
나머지는 선분 스위핑 알고리즘과 동일함
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

typedef struct node {
	int a, b, id;
}Node;


int N, Q;
int p[100001];
void init(int n) {
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
}
int getp(int a) {
	if (a == p[a]) return a;
	else return p[a] = getp(p[a]);
}

bool isUnion(int a, int b) {
	return getp(a) == getp(b);
}

void merge(int a, int b) {
	a = getp(a);
	b = getp(b);
	p[a] = b;
}

Node arr[100001];
bool myCmp(Node a, Node b) {
	if (a.a == b.a) return a.b < b.a;
	return a.a < b.a;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> Q;
	int a, b, y;
	for (int n = 1; n <= N; n++) {
		cin >> a >> b >> y;
		arr[n] = { a,b, n };
	}

	init(N);

	sort(arr + 1, arr + N + 1, myCmp);
	Node now = arr[1];
	int root = arr[1].id;
	for (int n = 2; n <= N; n++) {
		if (now.b < arr[n].a) {
			now = arr[n];
			root = arr[n].id;
		}
		else {
			now.b = max(now.b, arr[n].b);
			merge(root, arr[n].id);
		}
	}

	int l, r;
	for (int q = 0; q < Q; q++) {
		cin >> l >> r;
		if (isUnion(l, r)) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}



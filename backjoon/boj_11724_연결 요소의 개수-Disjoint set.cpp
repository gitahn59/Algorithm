/*
boj_11724_연결 요소의 개수(난이도 : 실버3)
서로소 집합
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

int N, M;
int prnt[1001];
bool visited[1001];

void init(int size) {
	for (int i = 1; i <= size; i++) {
		prnt[i] = i;
	}
}

int getPrnt(int a) {
	if (a == prnt[a]) return a;
	else return prnt[a] = getPrnt(prnt[a]);
}

bool isSet(int a, int b) {
	a = getPrnt(a);
	b = getPrnt(b);
	return a == b;
}

void merage(int a, int b) {
	a = getPrnt(a);
	b = getPrnt(b);

	prnt[a] = b;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	init(N);

	int a, b;
	for (int m = 1; m <= M; m++) {
		cin >> a >> b;
		if (isSet(a, b)) continue;
		merage(a, b);
	}

	int cnt = 0;
	for (int n = 1; n <= N; n++) {
		int a = getPrnt(n);
		if (visited[a]) continue;
		visited[a] = 1;
		cnt++;
	}

	cout << cnt << "\n";

	return 0;
}


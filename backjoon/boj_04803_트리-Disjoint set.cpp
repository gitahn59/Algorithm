/*
boj_04803_트리(난이도 : 골드4)
서로소 집합
서로소 집합을 통해 트리의 개수 계산
사이클 없이 연결되면 트리,
사이클이 존재하면 그래프
노드 하나도 트리
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
typedef set<int> si;
typedef vector<string> vs;

int N, M;
int prnt[501];
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
	if (b < a) {
		prnt[a] = b;
	}
	else prnt[b] = a;

}

bool visited[501];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int t = 1; true; t++) {
		cin >> N >> M;
		if (N == 0 && M == 0) break;
		memset(visited, 0, sizeof(visited));
		init(N);
		int a, b;
		for (int m = 1; m <= M; m++) {
			cin >> a >> b;
			if (!isSet(a, b)) {
				merage(a, b);
			}
			else {
				merage(a, 0);
			}
		}

		for (int n = 1; n <= N; n++) {
			visited[getPrnt(n)] = 1;
		}
		int cnt = 0;
		for (int n = 1; n <= N; n++) {
			if (visited[n]) cnt++;
		}

		cout << "Case " << t << ": ";
		if (cnt > 1) {
			cout << "A forest of " << cnt << " trees.\n";
		}
		else if (cnt == 1) {
			cout << "There is one tree.\n";
		}
		else {
			cout << "No trees.\n";
		}
	}

	return 0;
}



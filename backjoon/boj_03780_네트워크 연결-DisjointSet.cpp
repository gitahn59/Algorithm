/*
boj_03780_네트워크 연결(난이도 : 골드1)
Disjoint set
경로 압축과정에서 dist도 같이 압축해
시간복잡도를 줄임
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

int T, N;
int pnt[20001];
int dist[20001];

ii compress(int a) {
	if (a == pnt[a])
		return { a,0 };
	ii rst = compress(pnt[a]);
	pnt[a] = rst.first;
	dist[a] += rst.second;
	return { rst.first, dist[a] };
}

void merge(int a, int b) {
	pnt[a] = b;
	dist[a] = abs(b - a) % 1000;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int n = 1; n <= N; n++) {
			pnt[n] = n;
			dist[n] = 0;
		}

		char str[5];
		int l, j;
		while (true) {
			cin >> str;
			if (str[0] == 'O') break;
			else if (str[0] == 'E') {
				cin >> l;
				compress(l);
				cout << dist[l] << "\n";
			}
			else {
				cin >> l >> j;
				merge(l, j);
			}
		}
	}

	return 0;
}


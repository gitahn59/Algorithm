/*
boj_2600_구슬게임(난이도 : 골드4)
DP
일반적인 topdown 게임 DP
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

int b1, b2, b3;
int dist[501][501]; // 0이면 내가승, 1이면 상대가 승

int topdown(int k1, int k2) {
	int& ref = dist[k1][k2];
	if (ref != -1) return ref;

	vi rst;
	if (k1 >= b3) {
		if (topdown(k1 - b3, k2) == 1) return ref = 0;
	}

	if (k1 >= b2) {
		if (topdown(k1 - b2, k2) == 1) return ref = 0;
	}

	if (k1 >= b1) {
		if (topdown(k1 - b1, k2) == 1) return ref = 0;
	}



	if (k2 >= b3) {
		if (topdown(k1, k2 - b3) == 1) return ref = 0;
	}

	if (k2 >= b2) {
		if (topdown(k1, k2 - b2) == 1) return ref = 0;
	}

	if (k2 >= b1) {
		if (topdown(k1, k2 - b1) == 1) return ref = 0;
	}

	return ref = 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> b1 >> b2 >> b3;
	int k1, k2;
	for (int i = 0; i <= 500; i++) {
		for (int j = 0; j <= 500; j++) {
			dist[i][j] = -1;
		}
	}

	for (int i = 0; i < 5; i++) {
		cin >> k1 >> k2;
		cout << (char)(topdown(k1, k2) + 'A') << "\n";
	}

	return 0;
}



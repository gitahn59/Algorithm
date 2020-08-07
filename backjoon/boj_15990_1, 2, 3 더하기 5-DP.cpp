/*
boj_15990_1, 2, 3 더하기 5(난이도 : 실버 3)
DP
기본적인 bottomup dp 문제
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

int dist[4][100010];
int prime = 1000000009;
int T;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	// base
	dist[1][1] = 1;
	dist[2][2] = 1;
	dist[3][3] = 1;
	dist[2][3] = 1;
	dist[1][3] = 1;

	for (int n = 4; n <= 100000; n++) {
		dist[1][n] = (dist[2][n - 1] + dist[3][n - 1]) % prime;
		dist[2][n] = (dist[1][n - 2] + dist[3][n - 2]) % prime;
		dist[3][n] = (dist[1][n - 3] + dist[2][n - 3]) % prime;
	}

	cin >> T;
	int num;
	for (int t = 0; t < T; t++) {
		cin >> num;
		ll rst = 0;
		rst += (dist[1][num] + dist[2][num]) % prime;
		rst += dist[3][num];
		cout << rst % prime << "\n";
	}

	return 0;
}


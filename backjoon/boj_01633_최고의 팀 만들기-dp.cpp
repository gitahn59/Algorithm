/*
boj_1633_최고의 팀 만들기(난이도 : 실버2)
bottomup dp
일반적인 bottom up dp
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
ii arr[1001];
int mem[1001][16][16];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int a, b;
	while (cin >> a >> b) {
		arr[++N] = mp(a, b);
	}

	mem[1][0][0] = 1;
	mem[1][1][0] = 1 + arr[1].first;
	mem[1][0][1] = 1 + arr[1].second;

	for (int n = 2; n <= N; n++) {
		for (int l = 0; l <= 15; l++) {
			for (int r = 0; r <= 15; r++) {
				mem[n][l][r] = max(mem[n - 1][l][r], mem[n][l][r]);
				if (mem[n - 1][l][r] != 0) {
					if (l + 1 <= 15) mem[n][l + 1][r] = max(mem[n][l + 1][r], mem[n - 1][l][r] + arr[n].first);
					if (r + 1 <= 15) mem[n][l][r + 1] = max(mem[n][l][r + 1], mem[n - 1][l][r] + arr[n].second);
				}
			}
		}
	}

	cout << mem[N][15][15] - 1 << "\n";

	return 0;
}

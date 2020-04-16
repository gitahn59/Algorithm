/*
boj_10422_°ýÈ£(³­ÀÌµµ : °ñµå 5)
¼öÇÐ : Ä«Å»¶õ ¼ö
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

ll mem[5001];
bool visited[5001];
int mod = 1000000007;

ll topdown(int n) {
	ll& ref = mem[n];
	if (visited[n]) return ref;

	ll cnt = 0;
	for (int i = 0; i <= (n - 1); i++) {
		ll left = topdown(i);
		ll right = topdown((n - 1) - i);
		cnt += ((left * right) % mod);
	}

	visited[n] = 1;
	return ref = cnt % mod;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	mem[0] = 1; visited[0] = 1;
	mem[1] = 1; visited[1] = 1;

	for (int t = 1; t <= T; t++) {
		cin >> N;
		if (N % 2 != 0) {
			cout << "0\n";
			continue;
		}
		cout << topdown(N >> 1) << "\n";
	}

	return 0;
}


/*
boj_16975_수열과 쿼리21(난이도 : 플레4)
lazy propagation 기본형
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

ll N, K;

ll getCnt(ll num) {
	ll sum = 0;
	for (ll i = 1; i <= N; i++) {
		sum += min(N, num / i);
	}
	return sum;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	ll l = 1;
	ll r = N * N;
	while (l < r) {
		ll mid = (l + r) >> 1;
		if (getCnt(mid) >= K) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}

	cout << l << "\n";
	return 0;
}

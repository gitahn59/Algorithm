/*
boj_15712_등비수열(난이도 : 골드3)
등비수열의 합을 계산
결합법칙이 성립하므로 분할정복을 통해 해결할 수 있음
ex)
S2 = A1 + A2
A3 + A4 = A2 * S2

위의 성질을 이용하여 SB의 최단 경로를 미리 계산하고
경로에 따라 분할 정복함
S10 = S5 + S5
S5 = S2 + A2*S2 + A5
S2 = A1 + A2

주의 : % 연산이 모든 계산에서 수행되아야 long long의 범위를 벗어나지 않음
참고 : 첫 항을 제거하고 계산하면 계산이 간단해짐
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

ll A, R, N, MOD;

vi make_path(ll num) {
	vi path;
	while (num > 1) {
		if (num % 2) {
			path.push_back(1);
		}
		else {
			path.push_back(0);
		}
		num /= 2;
	}
	reverse(path.begin(), path.end());
	return path;
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> A >> R >> N >> MOD;
	if (N == 1) {
		cout << (A) % MOD << "\n";
		return 0;
	}

	vi path = make_path(N - 1);
	R = R % MOD;
	A = A % MOD;
	ll S = R;
	ll r = R;

	for (int task : path) {
		if (task) {
			ll left = S;
			ll right = (S * r) % MOD;
			r = (((r * r) % MOD) * R) % MOD;
			S = (left + right) % MOD;
			S = (S + r) % MOD;
		}
		else {
			S = (S + ((S * r) % MOD)) % MOD;
			r = (r * r) % MOD;
		}
	}
	S = (S * A) % MOD;
	cout << (S + A) % MOD << "\n";
	return 0;
}
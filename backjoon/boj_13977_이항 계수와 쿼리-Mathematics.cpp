/*
boj_13977_이항 계수와 쿼리 (난이도 : 골드1)
boj_11401_이항 계수 3의 확장 문제
페르마의 소정리를 이용한 고속 이항 계수의 모듈러 계산
페르마의 소정리
a^p-1 === 1 (mod p) (p는 소수)

nCr = n! / r!(n-r)! 이고
A = n!, B = r!(n-r)! 이라 하자.

nCr === AB^-1 (mod p)이다

페르마의 소정리에 의해
B^p-1 === 1(mod p)이고 이를 nCr에 곱해주면
nCr = AB^-1 * B^p-1 = AB^p-2 이다.

따라서 A와 B^p-2을 빠르게 구해주면 된다.
p-2제곱은 logP 시간에 계산 가능하므로
O(lgP)에 계산할 수 있다.

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

int N, K;
int mod = 1000000007;
ll fact[4000001];
vi path;

void preprocessing() {
	ll temp = 1;
	fact[0] = 1;
	for (int now = 1; now <= 4000000; now++) {
		temp *= now;
		temp = temp % mod;
		fact[now] = temp;
	}

	int p = mod - 2;
	path;
	while (p != 1) {
		if (p % 2 == 0) path.push_back(0);
		else path.push_back(1);
		p = p >> 1;
	}
	reverse(path.begin(), path.end());
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	preprocessing();

	int M;
	cin >> M;
	while (M--) {
		cin >> N >> K;

		ll A = fact[N];
		ll b = (fact[N - K] * fact[K]) % mod;
		ll B = b;
		for (int i : path) {
			if (i) B = (((B * B) % mod) * b) % mod;
			else B = (B * B) % mod;
		}

		ll rst = (A * B) % mod;
		cout << rst << "\n";
	}

	return 0;
}



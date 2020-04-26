/*
boj_1016_제곱 ㄴㄴ수(난이도 : 골드1)
수학 : 에라토스테네스의 채
min-max의 길이 최대 백만 이므로
에라토스테네스의 채의 원리를 이용하여
min 값과 다른 값의 나머지 관계를 이용하여
제곱수를 걸러낼 수 있음
ex)
min % 5 = 3 이면
min+2 % 5 = 0 임
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

bool mem[1000001];
ll A, B;
ll len;
int solve() {
	ll start = 2;
	ll end = sqrt(B);

	for (ll i = start; i <= end; i++) {
		ll num = i * i;
		ll j;
		if (num > A) {
			j = num - A;
		}
		else if (num == A) {
			mem[0] = 1;
			j = num;
		}
		else {
			if (A % num == 0) {
				mem[0] = 1;
				j = num;
			}
			else {
				j = num - A % num;
			}
		}

		for (; j <= len; j += num) {
			mem[j] = 1;
		}
	}

	int cnt = 0;
	for (int i = 0; i <= len; i++) {
		if (!mem[i]) cnt++;
	}
	return cnt;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> A >> B;
	len = B - A;

	cout << solve() << "\n";

	return 0;
}




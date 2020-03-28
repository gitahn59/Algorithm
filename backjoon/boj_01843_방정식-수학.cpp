/*
boj_01843_������(���̵� : ���3)
�⺻���� ���� ������ �̿��� ����
����)
A : ���������� ��
B : ������� �� O(K^2) ( N = n^2 �� ��� �˻簡 �ߺ� �� �� �����Ƿ� ������ �ߺ��� �����ؾ� ��)
C : �Ҽ��� �� ( 2�� �ƴ� �� �Ҽ��� ���� ¦���̱� ������, x + y�� ���� �Ҽ��� �Ƿ��� x�� �׻� 2���� ��)
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

//y�� x �̻�

int N;
bool prime[500001];
bool factor[1000002];

void make_prime() {
	prime[1] = prime[0] = 1;
	for (int i = 4; i <= N; i += 2) {
		prime[i] = 1;
	}
	for (int len = 3; len <= N; len += 2) {
		if (prime[len]) continue;
		for (int i = len << 1; i <= N; i += len) {
			prime[i] = 1;
		}
	}
}

ll solve_A() {
	if (N == 3) return 1;
	else if (N <= 2) return 0;

	ll l = N - 2;
	ll a = N % 2;
	ll n = (l + 2 - a) / 2;

	return (a + l) * n / 2;
}

ll solve_B() {
	vi num;
	int end = sqrt(N);
	if (N / end == end) {
		num.push_back(end);
		factor[end] = 1;
		end--;
	}

	for (int i = 1; i <= end; i++) {
		if (N % i == 0) {
			factor[i] = factor[N / i] = 1;
			num.push_back(i);
			num.push_back(N / i);
		}
	}

	ll cnt = 0;
	sort(num.begin(), num.end());
	for (int i = 0; i < num.size(); i++) {
		for (int j = i; j < num.size(); j++) {
			if (factor[num[i] + num[j]]) cnt++;
		}
	}

	return cnt;
}

int solve_C() {
	int cnt = 0;

	for (int i = 3; i <= N - 2; i += 2) {
		if (prime[i]) continue;
		if (prime[i + 2] == 0) cnt++;
	}
	return cnt;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	make_prime();
	cout << solve_A() << "\n";
	cout << solve_B() << "\n";
	cout << solve_C() << "\n";

	return 0;
}
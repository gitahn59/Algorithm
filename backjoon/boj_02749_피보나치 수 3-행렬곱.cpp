/*
boj_2749_피보나치 수 3(난이도 : 골드 2)
수학
피보나치수를 행렬로 표현할 수 있고,
N^k을 O(lgK) 시간안에 곱할 수 있다는 성질을 이용한 문제
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

typedef struct matrix {
	ll a, b, c, d;
}Matrix;
int prime = 1000000;
ll N;

Matrix mul(Matrix l, Matrix r) {
	Matrix rst;
	rst.a = (l.a * r.a + l.b * r.c) % prime;
	rst.b = (l.a * r.b + l.b * r.d) % prime;
	rst.c = (l.c * r.a + l.d * r.c) % prime;
	rst.d = (l.c * r.b + l.d * r.d) % prime;
	return rst;
}

ll solve(ll num) {
	vi v;
	while (num != 1) {
		if (num % 2 == 0) v.push_back(0);
		else v.push_back(1);
		num = num >> 1;
	}
	reverse(v.begin(), v.end());
	Matrix E = { 1,1,1,0 };
	Matrix m = { 1,1,1,0 };
	for (int i : v) {
		if (i == 0) m = mul(m, m);
		else m = mul(mul(m, m), E);
	}

	return m.c;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cout << solve(N) << "\n";

	return 0;
}


/*
boj_2086_피보나치 수의 합(난이도 : 골드2)
행렬곱

1. 피보나치 수의 합
피보나치 수를 전개해보면
f10 = (f8 + f7 ... f2 + f1) + f1 의 성질을 가짐
이는 홀수, 짝수번째 피보나치수를 f0까지 전개해보면 확인할 수 있음
f9 = f8 + f7 = (f8 + f6) + f5 = (f8 + f6 + f4) + f3 = (f8 + f6 + f4 + f2) + f1
f8 = f7 + f6 = (f7 + f5) + f4 = (f7 + f5 + f3) + f2 = (f7 + f5 + f3 + f1)
f9 + f8 = f10 = (f8 + ... f1) f1

2. 피보나치 수 빠르게 구하기
행렬 곱을 통해 O(logN)시간에 피보나치 수의 값을 구할 수 있음
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

typedef struct matrix {
	ll a, b, c, d;
}Matrix;

ll mod = 1000000000;
ll A, B;

Matrix mul(Matrix l, Matrix r) {
	Matrix rst;
	rst.a = (l.a * r.a + l.b * r.c) % mod;
	rst.b = (l.a * r.b + l.b * r.d) % mod;
	rst.c = (l.c * r.a + l.d * r.c) % mod;
	rst.d = (l.c * r.b + l.d * r.d) % mod;
	return rst;
}

ll fibo(ll num) {
	if (num == 0) {
		return 0;
	}

	ll n = num;
	vi path;
	while (n != 1) {
		if (n % 2 == 0) path.push_back(0);
		else path.push_back(1);
		n >>= 1;
	}
	reverse(path.begin(), path.end());

	Matrix temp = { 1,1,1,0 };
	Matrix base = temp;

	for (int i : path) {
		if (i) temp = mul(mul(temp, temp), base);
		else temp = mul(temp, temp);
	}
	return temp.c;
}

ll fiboSum(ll num) {
	if (num == 0) return 0;
	return (mod + fibo(num + 2) - 1) % mod;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;
	cout << (mod + fiboSum(B) - fiboSum(A - 1)) % mod << "\n";

	return 0;
}



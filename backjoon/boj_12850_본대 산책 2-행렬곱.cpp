/*
boj__(난이도 : )
행렬곱
boj_12849의 확장 문제, 행렬 곱을 통해 더 큰 범위의 DP를 계산한다.

연산을 Fn = A * Fn-1 (A는 행렬)으로 나타낼 수 있다면
Fn = A^(n-1) * F1으로 일반화 할 수 있고
A^(n-1) 은 O(lgN)안에 계산할 수 있으므로
이 문제의 시간 복잡도는 O(lgN * M * M) 이 된다.(M은 행렬의 크기)

분대 산책 1 문제를 통해 각 노드간의 관계를 파악할 수 있다.
이를 행렬식으로 나타 내면
| F'0 |	  {0,1,0,1,0,0,0,0}   | F0 |
| F'1 |	  {1,0,1,1,0,0,0,0}   | F1 |
| F'2 |	  {0,1,0,1,1,1,0,0}   | F2 |
| F'3 |	= {1,1,1,0,0,1,0,0} X | F3 |
| F'4 |	  {0,0,1,0,0,1,1,0}   | F4 |
| F'5 |	  {0,0,1,1,1,0,0,1}   | F5 |
| F'6 |	  {0,0,0,0,1,0,0,1}   | F6 |
| F'7 |	  {0,0,0,0,0,1,1,0}   | F7 |
으로 나타낼 수 있으며 
이는 F(n) = A F(n-1) 이다
따라서
F(n) = A^(n-1) X F1이 된다.
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
	ll mem[8][8];
}Matrix;

int D;
ll mod = 1000000007;

Matrix mul(Matrix& a, Matrix& b) {
	Matrix rst;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			// a의 i행, b의 j열
			ll sum = 0;
			for (int k = 0; k < 8; k++) {
				ll ij = (a.mem[i][k] * b.mem[k][j]) % mod;
				sum = (sum + ij) % mod;
			}
			rst.mem[i][j] = sum;
		}
	}
	return rst;
}

int arr[8][8] = {
	 {0,1,0,1,0,0,0,0}, //0 13
	 {1,0,1,1,0,0,0,0}, //1 023
	 {0,1,0,1,1,1,0,0}, //2 1345
	 {1,1,1,0,0,1,0,0}, //3 0125
	 {0,0,1,0,0,1,1,0}, //4 256
	 {0,0,1,1,1,0,0,1}, //5 2347
	 {0,0,0,0,1,0,0,1}, //6 47
	 {0,0,0,0,0,1,1,0}  //7 56
};

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> D;
	if (D == 1) {
		cout << "0\n";
		return 0;
	}

	int now = D - 1;
	vi path;
	while (now != 1) {
		if (now % 2 == 0) path.push_back(0);
		else path.push_back(1);
		now /= 2;
	}
	reverse(path.begin(), path.end());

	Matrix fn;
	Matrix f1;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			fn.mem[i][j] = arr[i][j];
			f1.mem[i][j] = arr[i][j];
		}
	}

	for (int i : path) {
		if (i == 0) {
			fn = mul(fn, fn);
		}
		else {
			fn = mul(fn, fn);
			fn = mul(fn, f1);
		}
	}

	cout << ((fn.mem[0][1] + fn.mem[0][3]) % mod) << "\n";

	return 0;
}


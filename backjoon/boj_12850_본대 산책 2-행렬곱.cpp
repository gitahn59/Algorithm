/*
boj__(���̵� : )
��İ�
boj_12849�� Ȯ�� ����, ��� ���� ���� �� ū ������ DP�� ����Ѵ�.

������ Fn = A * Fn-1 (A�� ���)���� ��Ÿ�� �� �ִٸ�
Fn = A^(n-1) * F1���� �Ϲ�ȭ �� �� �ְ�
A^(n-1) �� O(lgN)�ȿ� ����� �� �����Ƿ�
�� ������ �ð� ���⵵�� O(lgN * M * M) �� �ȴ�.(M�� ����� ũ��)

�д� ��å 1 ������ ���� �� ��尣�� ���踦 �ľ��� �� �ִ�.
�̸� ��Ľ����� ��Ÿ ����
| F'0 |	  {0,1,0,1,0,0,0,0}   | F0 |
| F'1 |	  {1,0,1,1,0,0,0,0}   | F1 |
| F'2 |	  {0,1,0,1,1,1,0,0}   | F2 |
| F'3 |	= {1,1,1,0,0,1,0,0} X | F3 |
| F'4 |	  {0,0,1,0,0,1,1,0}   | F4 |
| F'5 |	  {0,0,1,1,1,0,0,1}   | F5 |
| F'6 |	  {0,0,0,0,1,0,0,1}   | F6 |
| F'7 |	  {0,0,0,0,0,1,1,0}   | F7 |
���� ��Ÿ�� �� ������ 
�̴� F(n) = A F(n-1) �̴�
����
F(n) = A^(n-1) X F1�� �ȴ�.
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
			// a�� i��, b�� j��
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


/*
boj_13977_���� ����� ���� (���̵� : ���1)
boj_11401_���� ��� 3�� Ȯ�� ����
�丣���� �������� �̿��� ��� ���� ����� ��ⷯ ���
�丣���� ������
a^p-1 === 1 (mod p) (p�� �Ҽ�)

nCr = n! / r!(n-r)! �̰�
A = n!, B = r!(n-r)! �̶� ����.

nCr === AB^-1 (mod p)�̴�

�丣���� �������� ����
B^p-1 === 1(mod p)�̰� �̸� nCr�� �����ָ�
nCr = AB^-1 * B^p-1 = AB^p-2 �̴�.

���� A�� B^p-2�� ������ �����ָ� �ȴ�.
p-2������ logP �ð��� ��� �����ϹǷ�
O(lgP)�� ����� �� �ִ�.

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



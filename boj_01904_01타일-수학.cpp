/*
boj_01904_01Ÿ��(���̵� : �ǹ�3)
��Ģ�� �Ǻ���ġ ������ �̷�� ����
cnt(N) = cnt(N-2) + cnt(N-1)
N��° ����� ���� cnt(N-2)�� 00Ÿ���� ���� ����� �� + cnt(N-1)�� 1�� ���� ����� ��
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

int N;

int fibo(int num) {
	if (num == 1) return 1;
	else if (num == 2) return 2;

	int pp = 1;
	int p = 2;
	int now;
	for (int i = 3; i <= num; i++) {
		now = (pp + p) % 15746;
		pp = p;
		p = now;
	}
	return now;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cout << fibo(N) << "\n";

	return 0;
}

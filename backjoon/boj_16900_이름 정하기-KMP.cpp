/*
boj_16900_�̸� ���ϱ�(���̵� : ���1)
KMP �˰���
Ư�� �ܾ N�� �����ϴ� �ּұ����� ���ڿ��� �����ؾ� �ϴ� ����
Ư�� �ܾ �ݺ��Ǵ� �κ��� �ִٸ� �̸� ����ؼ� ���ڿ��� �����ؾ���

1. ���� �ߺ��� �ִ� ���̸� �ľ��ϱ� ���� KMP �˰����� ���̻� �Լ��� ����
2. ��� = M + (M-�ߺ�����) * (N-1)  : M�� �ܾ��� ����

O(M)�� �ð����⵵�� ������ �ذ��� �� ����
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

int N, M;
int p[500001];
string src;

void makep(string& target) {
	M = target.size();
	for (int m = 1, j = 0; m < M; m++) {
		while (j > 0 && target[m] != target[j]) {
			j = p[j - 1];
		}
		if (target[m] == target[j]) {
			j++;
			p[m] = j;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> src >> N;
	makep(src);

	int hover = p[M - 1];
	int add = M - hover;
	ll rst = (ll)(N - 1) * add + M;
	cout << rst << "\n";

	return 0;
}



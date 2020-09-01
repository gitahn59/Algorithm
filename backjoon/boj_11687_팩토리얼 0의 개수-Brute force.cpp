/*
boj_11687_���丮�� 0�� ����(���̵� : ���4)
���� ���� 0�� ������ 2, 5�� ���� ���� ������
���� 2�� �׻� 5�� �������� ���� ������(�ڸ���)

���� 5�� ����� �˻��ϸ鼭 5�� ������ ���ʴ��
��� �����Ǿ����� O(NlogN) �ð��� �˻��ϸ� ��
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

int M;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> M;

	ll now = 1;
	int m = 0;
	while (1) {
		int cnt = 1;
		ll temp = now;
		while (temp % 5 == 0) {
			temp /= 5;
			cnt++;
		}
		m += cnt;
		if (m >= M) break;
		now += 1;
	}

	if (m == M) {
		cout << now * 5 << "\n";
	}
	else {
		cout << "-1\n";
	}

	return 0;
}



/*
boj_2470_�� ���(���̵� : ���5)
����Ž��
�� ���� ���� 0�� ���� ����� �� ���� ã�� ����
���� �� ����Ž���� ���� O(NlogN)�� �ذ� ������ ����

�ĺ��� ���, ������ �̵�� �Ͽ� �˻��ϸ�
Ž���ð��� ���� �ð����� �̵��� �� �� ����
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

vi a, b;
int N;
int rst = 2100000000;
ii numbers;

void preprocessing() {
	cin >> N;
	int num;
	for (int n = 0; n < N; n++) {
		cin >> num;
		if (num < 0) a.push_back(-num);
		else b.push_back(num);
	}

	sort(a.begin(), a.end());
	if (a.size() >= 2) {
		int temp = a[0] + a[1];
		if (temp < rst) {
			numbers.first = -a[0];
			numbers.second = -a[1];
			rst = temp;
		}
	}
	sort(b.begin(), b.end());
	if (b.size() >= 2) {
		int temp = b[0] + b[1];
		if (temp < rst) {
			numbers.first = b[0];
			numbers.second = b[1];
			rst = temp;
		}
	}
}

void solve(vi& l, vi& r, int type) {
	if (r.size() != 0) {
		for (int i : l) {
			int idx = lower_bound(r.begin(), r.end(), i) - r.begin();
			int candidate[] = { idx, idx - 1, idx + 1 };

			for (int k = 0; k < 3; k++) {
				if (candidate[k] >= 0 && candidate[k] < r.size()) {
					int temp = abs(i - r[candidate[k]]);
					if (temp < rst) {
						if (type == -1) {
							numbers.first = -i;
							numbers.second = r[candidate[k]];
						}
						else {
							numbers.first = i;
							numbers.second = -r[candidate[k]];
						}
						rst = temp;
					}
				}
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	preprocessing();
	solve(a, b, -1);
	solve(b, a, 1);

	if (numbers.first > numbers.second) {
		swap(numbers.first, numbers.second);
	}
	cout << numbers.first << " " << numbers.second << "\n";

	return 0;
}



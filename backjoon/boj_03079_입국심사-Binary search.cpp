/*
boj_3079_�Ա��ɻ�(���̵� : ���5)
Binary search
�Ϲ����� ����Ž�� ��������
������ �˻��ϴ� �ܰ迡�� �ܼ� ���� ���ϸ� long long ������ �ʰ��� �� ����
���� ���ǿ��� �Ѱ��� ���鼭 �˻��ϸ� �����÷ο� ���� �ذ��� �� ����
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

ll N, M;
ll arr[100000];

bool getCnt(ll t) {
	ll cnt = M;
	for (int n = 0; n < N; n++) {
		cnt -= (t / arr[n]);
		if (cnt <= 0) {
			return true;
		}
	}
	return false;
}

ll myMin;
void binSearch(ll i, ll j) {
	if (i > j) return;
	ll mid = (i + j) >> 1;
	if (getCnt(mid)) {
		myMin = min(mid, myMin);
		binSearch(i, mid - 1);
	}
	else {
		binSearch(mid + 1, j);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int n = 0; n < N; n++) {
		cin >> arr[n];
	}
	sort(arr, arr + N);

	myMin = LLONG_MAX;
	binSearch(1, 1000000000000000001);
	cout << myMin << "\n";

	return 0;
}



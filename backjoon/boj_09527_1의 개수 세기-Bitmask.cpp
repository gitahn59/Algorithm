/*
boj_09527_1�� ���� ����(���̵� : ���2)
�ִ� ��Ʈ�� �ڸ����� ���� ������ ��Ʈ�� ������ ������ �ִ�
1�� ������ �޶���
��ó���� �ϰ�
�ִ� �ڸ����� ��Ʈ�� ���� ���� �и��Ͽ�
�и��� ���� ���� 1��Ʈ�� ���� ī����

���� ) ��Ʈ ����� long long�� �������
������ ����� �Ǵ� ���� ���� ll���� ����ؾ�
�����÷ο츦 ���� �� �� ����
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

ll dist[56];
ll acc[56];

void preprocessing() {
	dist[0] = 1;
	for (int i = 1; i < 56; i++) {
		ll sum = 0;
		sum += ((ll)1 << i);
		for (int j = 0; j < i; j++) {
			sum += dist[j];
		}
		dist[i] = sum;
	}

	acc[0] = 1;
	for (int i = 1; i < 56; i++) {
		acc[i] = acc[i - 1] + dist[i];
	}
}

int myidx = 0;
void binSearch(ll num, int a, int b) {
	if (a > b) return;
	int mid = (a + b) >> 1;
	ll shift = ((ll)1 << mid);
	if (num >= shift) {
		myidx = max(myidx, mid);
		binSearch(num, mid + 1, b);
	}
	else {
		binSearch(num, a, mid - 1);
	}
}

ll getCnt(ll num) {
	if (num <= 0) return 0;
	ll sum = 0;
	int idx = 0;
	myidx = 0;
	binSearch(num, 0, 56);
	idx = myidx;
	ll left = ((ll)1 << idx);
	ll cnt = num - left + 1;
	sum += cnt;
	if (idx >= 1)
		sum += acc[idx - 1];
	sum += getCnt(num - left);
	return sum;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	preprocessing();
	ll A, B;
	cin >> A >> B;
	ll left = getCnt(B);
	ll right = getCnt(A - 1);
	cout << left - right << "\n";

	return 0;
}

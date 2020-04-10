/*
boj_1756_���ڱ���(���̵� : ���5)
lower bound
���� ���� ������ �Ʒ��� ���� ���� ���� ������ 
���� ���� �������� �Ʒ��� ���� ������ �����ϸ�
���ĵ�

�� ���¿��� lower bound�� ���� ���� ��ġ Ž��
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
#include <tuple>

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

int D, N;
int arr[300001];
int pizza[300001];

int solve() {
	int pre = 0;
	for (int n = 1; n <= N; n++) {
		int l = pre + 1;
		int r = D + 1;
		while (l < r) {
			int mid = (l + r) >> 1;
			if (arr[mid] >= pizza[n]) {
				r = mid;
			}
			else l = mid + 1;
		}
		if (l > D) return 0;
		pre = l;
	}
	return D - pre + 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> D >> N;
	arr[0] = 1000000000;
	for (int d = 1; d <= D; d++) {
		cin >> arr[d];
		arr[d] = min(arr[d], arr[d - 1]);
	}
	reverse(arr + 1, arr + 1 + D);

	for (int n = 1; n <= N; n++) {
		cin >> pizza[n];
	}

	cout << solve() << "\n";

	return 0;
}


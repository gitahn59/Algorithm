/*
boj_2594_���̰���(���̵� : �ǹ�3)
Sweeping
�� �׸��� ����
���� ���� �������� ������ �׸� ����
1. ���� �� �ȿ� ���Ե�
=> ���鵵 ����, ���缱 �״��
2. ���� ���� ������
=> ������� ���� ���� ����
3. ���� ������ ������ ����
=> ������ �����Ƿ� ����
�� �з��Ͽ� ���ǿ� �°� ó���ϸ� ��
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

int N;
ii arr[50];

bool myCmp(ii a, ii b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int a, b;
	for (int n = 0; n < N; n++) {
		cin >> a >> b;
		arr[n].first = ((a / 100) * 60) + (a % 100) - 10;
		arr[n].second = ((b / 100) * 60) + (b % 100) + 10;
	}
	sort(arr, arr + N, myCmp);

	int start = 10 * 60;
	int end = 22 * 60;
	ii now = { start, arr[0].second };
	int rst = arr[0].first - start;
	for (int n = 1; n < N; n++) {
		if (arr[n].first >= now.second) {
			rst = max(rst, arr[n].first - now.second);
			now.second = arr[n].second;
		}
		else {
			if (arr[n].second > now.second) {
				now.second = arr[n].second;
			}
		}
	}
	rst = max(rst, end - now.second);
	cout << rst << "\n";
	return 0;
}



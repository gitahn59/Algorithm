/*
boj_17611_�����ٰ���(���̵� : ���1)
Sweeping
1. 
�����ٰ����� �� ������ x�� ����, y�� �������� ����
2.
boj_1689_������ ���� ������ �����Ͽ�
���� ������ ������ ���� 
1���� ���� �������� ������ ������ �ִ� ������ ���ϸ� ��
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

int N;
ii arr[100002];
bool myCmp(ii a, ii b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

int getCnt(vii& data) {
	int k = 0;
	int rst = 0;
	for (ii now : data) {
		if (now.second == 1) k++;
		else k--;
		rst = max(rst, k);
	}
	return rst;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> arr[n].first >> arr[n].second;
	}

	vii x, y;
	arr[N] = arr[0];
	for (int n = 0; n < N; n++) {
		if (arr[n].first == arr[n + 1].first) {
			int a = min(arr[n].second, arr[n + 1].second);
			int b = max(arr[n].second, arr[n + 1].second);
			y.push_back({ a, 1 });
			y.push_back({ b,-1 });
		}
		else {
			int a = min(arr[n].first, arr[n + 1].first);
			int b = max(arr[n].first, arr[n + 1].first);
			x.push_back({ a, 1 });
			x.push_back({ b,-1 });
		}
	}
	sort(x.begin(), x.end(), myCmp);
	sort(y.begin(), y.end(), myCmp);

	cout << max(getCnt(x), getCnt(y)) << "\n";

	return 0;
}



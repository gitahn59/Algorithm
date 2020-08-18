/*
boj_2631_�ټ����(���̵� : ���5)
Segment
������ ������ �ּ��� ���Ҹ� �̵����� ���ĵ� ������ �ٲپ�� ��
-> �̹� ���ĵǾ��ִºκ��� �ǵ� �ʿ� ����
-> ���������̶��, �����ϴ� �κ� ������ �ǵ� �ʿ� ����
-> �� �����ϴ� �κ� ������ �ִ� ���̸� ���ϸ�
�� ���� ���Ҹ� �̵��ϸ� �ּ� �̵����� �� �� ����

=> �����ϴ� �κ� ������ �ִ� ���� ������ ġȯ��
�̴� DP, Segment�� ���� ����
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
int arr[201];
int seg[801];

int getMax(int node, int start, int end, int i, int j) {
	if (start > j || end < i) return 0;
	if (i <= start && end <= j) return seg[node];
	int mid = (start + end) >> 1;
	return max(getMax(node << 1, start, mid, i, j), getMax((node << 1) + 1, mid + 1, end, i, j));
}

int update(int node, int start, int end, int idx, int dist) {
	if (start > idx || idx > end) return seg[node];
	else {
		if (start == end) return seg[node] += dist;
		else {
			int mid = (start + end) >> 1;
			int a = update(node << 1, start, mid, idx, dist);
			int b = update((node << 1) + 1, mid + 1, end, idx, dist);
			return seg[node] = max(a, b);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int num;
	for (int n = 1; n <= N; n++) {
		cin >> num;
		arr[num] = n;
	}

	int myMax = 0;
	for (int n = 1; n <= N; n++) {
		int cnt = getMax(1, 0, N, 1, arr[n]) + 1;
		myMax = max(myMax, cnt);
		update(1, 0, N, arr[n], cnt);
	}

	cout << N - myMax << "\n";

	return 0;
}



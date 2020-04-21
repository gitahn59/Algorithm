/*
boj_02568_������ - 2(���̵� : ��� 2)
LIS using Segmant Tree

LIS �� ���� :
1 2 3 4 5 6 7 8 9 10
8 2 9 1 0 4 6 0 7 10
������� �����ϰ� �����ϴ� ������ ��������
���� ��ġ�� �ʴ� ���� Ȯ���� �� ����
���� ��ġ�� �ʴ� �ִ� ������ �������� ���Ϸ���
���� ���� ������ ã�ƾ� ��
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

int N;
int arr[500001];
int segment[2000001];
int rst[500001];

int getCnt(int node, int start, int end, int left, int right) {
	if (start > right || end < left) return 0;
	if (left <= start && end <= right) return segment[node];

	int mid = (start + end) >> 1;
	return max(getCnt(node << 1, start, mid, left, right), getCnt((node << 1) + 1, mid + 1, end, left, right));
}

void update(int node, int start, int end, int idx, int diff) {
	if (idx<start || idx>end) return;
	segment[node] = max(diff, segment[node]);
	if (start != end) {
		int mid = (start + end) >> 1;
		update(node << 1, start, mid, idx, diff);
		update((node << 1) + 1, mid + 1, end, idx, diff);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int from, to;
	int M = 1;
	for (int n = 1; n <= N; n++) {
		cin >> from >> to;
		arr[from] = to;
		int m = max(from, to);
		M = max(m, M);
	}

	int myMax = 0;
	for (int m = 1; m <= M; m++) {
		if (arr[m] == 0) continue;
		int cnt = getCnt(1, 1, 500000, 1, arr[m] - 1) + 1;
		update(1, 1, 500000, arr[m], cnt);
		rst[m] = cnt;
		myMax = max(myMax, cnt);
	}

	vi rm;
	for (int m = M; m >= 1; m--) {
		if (arr[m] == 0) continue;
		if (rst[m] != myMax) rm.push_back(m);
		else myMax--;
	}

	sort(rm.begin(), rm.end());
	cout << rm.size() << "\n";
	for (int i : rm) {
		cout << i << "\n";
	}

	return 0;
}


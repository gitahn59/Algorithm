/*
pro_64062_¡�˴ٸ�(���̵� : level3)
����Ž��
����Ž���� ���� ������ �����ϴ� ����
�ִ��� ���ϴ� ����
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
int arr[200001];
int cnt;
bool isCross(int num, int k) {
	int gap = 0;
	for (int i = 1; i <= cnt; i++) {
		if (arr[i] - num >= 0) {
			gap = 0;
		}
		else {
			gap++;
			if (gap >= k) return false;
		}
	}
	return true;
}

int solution(vector<int> stones, int k) {
	for (int i : stones) {
		N = max(i, N);
		arr[++cnt] = i;
	}

	int pre = 0;
	int l = 0, r = N;
	while (true) {
		int mid = (l + r) >> 1;
		if (isCross(mid, k)) {
			pre = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}

		if (l > r) break;
	}

	return pre;
}
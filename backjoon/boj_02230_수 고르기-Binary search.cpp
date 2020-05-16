/*
boj_2230_�� ����(���̵� : ���5)
Binary search
���� �� lowerbound�� ���� �ּ��� ���̸� ������ �ĺ� Ž��
O(NlogN)�� �ذ� ����
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
typedef set<int> si;
typedef vector<string> vs;

ll N, M;
ll arr[100001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}

	sort(arr + 1, arr + 1 + N);
	ll myMin = -1;
	for (int n = 1; n < N; n++) {
		ll target = M + arr[n];
		int idx = lower_bound(arr + n + 1, arr + 1 + N, target) - arr;
		if (idx == N + 1) continue;
		if (myMin == -1) {
			myMin = arr[idx] - arr[n];
		}
		else {
			myMin = min(myMin, arr[idx] - arr[n]);
		}
	}

	cout << myMin << "\n";

	return 0;

}


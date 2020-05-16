/*
boj_2230_수 고르기(난이도 : 골드5)
Binary search
정렬 후 lowerbound를 통해 최소의 차이를 가지는 후보 탐색
O(NlogN)에 해결 가능
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


/*
boj_2473_세 용액(난이도 : 골드4)
Sorting, Binary search
boj_2476의 확장문제

문제의 범위가 작아 O(N^2logN) 풀이가 가능
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
ll arr[5010];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}

	sort(arr + 1, arr + 1 + N);

	ll myMin = abs(arr[1] + arr[2] + arr[3]);
	ll a = arr[1], b = arr[2], c = arr[3];

	for (int i = 1; i <= N - 2; i++) {
		for (int j = i + 1; j <= N - 1; j++) {
			ll now = arr[i] + arr[j];
			auto it = lower_bound(arr + j + 1, arr + N + 1, -now);
			int idx = it - arr;

			if (idx != N + 1) {
				ll temp = abs(now + *it);
				if (myMin > temp) {
					myMin = temp;
					a = arr[i]; b = arr[j]; c = *it;
				}
			}

			if (idx - 1 > j) {
				it--;
				ll temp = abs(now + *it);
				if (myMin > temp) {
					myMin = temp;
					a = arr[i]; b = arr[j]; c = *it;
				}
			}
		}
	}

	cout << a << " " << b << " " << c << "\n";

	return 0;
}




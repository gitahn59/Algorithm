/*
boj_3079_입국심사(난이도 : 골드5)
Binary search
일반적인 이진탐색 문제지만
조건을 검사하는 단계에서 단순 합을 구하면 long long 범위를 초과할 수 있음
따라서 조건에서 한개씩 빼면서 검사하면 오버플로우 없이 해결할 수 있음
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

ll N, M;
ll arr[100000];

bool getCnt(ll t) {
	ll cnt = M;
	for (int n = 0; n < N; n++) {
		cnt -= (t / arr[n]);
		if (cnt <= 0) {
			return true;
		}
	}
	return false;
}

ll myMin;
void binSearch(ll i, ll j) {
	if (i > j) return;
	ll mid = (i + j) >> 1;
	if (getCnt(mid)) {
		myMin = min(mid, myMin);
		binSearch(i, mid - 1);
	}
	else {
		binSearch(mid + 1, j);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int n = 0; n < N; n++) {
		cin >> arr[n];
	}
	sort(arr, arr + N);

	myMin = LLONG_MAX;
	binSearch(1, 1000000000000000001);
	cout << myMin << "\n";

	return 0;
}



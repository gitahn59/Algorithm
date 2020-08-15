/*
boj_1689_겹치는 선분(난이도 : 골드4)
Greedy
시작하는 지점에서는 1을 더함
끝나는 지점에서는 1을 빼줌

선분의 정보를 정렬하고 나면
임의의 지점에서 존재하는 선분이 몇개인지
O(N)시간에 검사할 수 있다.
단 끝나는 선분과 새로 시작하는 선분의 값이
같은 경우를 잘 고려해야 한다.

이 문제의 경우 단순히 최댓값을 찾으면 되므로
끝나는 선분을 먼저 빼주면 된다.
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
ii arr[2000000];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	int M = N << 1;
	int a, b;
	for (int m = 0; m < M; m += 2) {
		cin >> a >> b;
		arr[m] = { a,1 };
		arr[m + 1] = { b,-1 };
	}

	sort(arr, arr + M);
	int rst = 0;
	int now = 0;
	for (int m = 0; m < M; m++) {
		now += arr[m].second;
		rst = max(rst, now);
	}
	cout << rst << "\n";

	return 0;
}



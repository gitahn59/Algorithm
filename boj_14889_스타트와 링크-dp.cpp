/*
boj_14889_스타트와 링크(난이도 : 실버3)
비트마스킹과 dp를 활용하여 가능한 선수쌍에 대한 모든 값을 계산
(dfs도 가능함)
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
int arr[21][21];
int mem[2097153];
int FIRST = -1;

int topdown(int selected) {
	int& ref = mem[selected];
	if (ref != FIRST) {
		return ref;
	}

	int bit = selected & -selected;
	selected -= bit;
	for (int i = 1; i <= N; i++) {
		if (bit & (1 << i)) {
			bit = i;
			break;
		}
	}

	int sum = 0;
	for (int i = 1; i <= N; i++) {
		if (selected & (1 << i)) {
			sum += arr[bit][i];
			sum += arr[i][bit];
		}
	}
	sum += topdown(selected);
	return ref = sum;
}

int cntOf(int num) {
	int cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (num & 1 << i) cnt++;
	}
	return cnt;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= N; i++) {
			cin >> arr[n][i];
		}
	}

	fill(mem, mem + 2097152, FIRST);
	mem[0] = 0;

	int end = (1 << N + 1) - 2;
	int myMin = 20000;
	for (int i = 2; i < end; i++) {
		if (i & 1) continue;
		if (cntOf(i) == N >> 1) {
			int left = i;
			int right = end - i;

			left = topdown(left);
			right = topdown(right);
			myMin = min(myMin, abs(left - right));
		}
	}

	cout << myMin << "\n";
	return 0;
}

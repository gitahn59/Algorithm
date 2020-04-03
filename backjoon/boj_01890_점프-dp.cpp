/*
boj_01890_점프(난이도 : 실버2)
기본적인 2차원 배열을 탐색하는 topdown dp
주의) 미탐색 상태와 탐색 실패의 값을 잘 할당해야 함
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

int arr[101][101];
ll mem[101][101];
ll FIRST = -1000;

ll topdown(int i, int j) {
	ll& ref = mem[i][j];
	if (i == N && j == N) {
		return 1;
	}

	if (ref != FIRST) {
		return ref;
	}

	ll bottom;
	ll right;

	if (arr[i][j] != 0 && i + arr[i][j] <= N) {
		bottom = topdown(i + arr[i][j], j);
	}
	else {
		bottom = -1;
	}

	if (arr[i][j] != 0 && j + arr[i][j] <= N) {
		right = topdown(i, j + arr[i][j]);
	}
	else {
		right = -1;
	}

	if (bottom == -1 && right == -1) {
		return ref = -1;
	}
	else if (bottom == -1) {
		return ref = right;
	}
	else if (right == -1) {
		return ref = bottom;
	}
	else {
		return ref = right + bottom;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int n = 1; n <= N; n++) {
		fill(mem[n] + 1, mem[n] + N + 1, FIRST);
		for (int i = 1; i <= N; i++) {
			cin >> arr[n][i];
		}
	}

	ll result = topdown(1, 1);
	if (result == -1) {
		cout << 0 << "\n";
	}
	else {
		cout << result << "\n";
	}

	return 0;
}

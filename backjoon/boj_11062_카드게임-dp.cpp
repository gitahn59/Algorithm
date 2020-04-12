/*
boj_11062_카드게임(난이도 : 골드 3)
turn이 있는 dp
turn이 0일때는 최대값을 구하고
turn이 1일때는 최소값을 구함
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

int T, N;
int arr[1001];
int mem[1001][1001][2];
int FIRST = 0;

int topdown(int i, int j, int turn) {
	if (i == j) {
		if (turn == 1) return 0;
		else return arr[i];
	}

	int& ref = mem[i][j][turn];
	if (ref != FIRST) return ref;

	if (turn == 0) {
		int left = topdown(i + 1, j, turn + 1) + arr[i];
		int right = topdown(i, j - 1, turn + 1) + arr[j];
		return ref = max(left, right);
	}
	else {
		int left = topdown(i + 1, j, turn - 1);
		int right = topdown(i, j - 1, turn - 1);
		return ref = min(left, right);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		memset(mem, 0, sizeof(mem));
		for (int n = 1; n <= N; n++) {
			cin >> arr[n];
		}
		cout << topdown(1, N, 0) << "\n";
	}

	return 0;
}


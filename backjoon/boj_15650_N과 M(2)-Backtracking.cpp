/*
boj_15650_N과 M(2)(난이도 : 실버3)
backtracking
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
typedef deque<int> di;
typedef pair<int, ii> iii;
typedef set<int> si;

int N, M;
int candidate[8];
void backtrack(int now, int cnt) {
	if (cnt == M) {
		for (int m = 0; m < M; m++) {
			cout << candidate[m] + 1 << " ";
		}
		cout << "\n";
		return;
	}

	if (now < N) {
		candidate[cnt] = now;
		backtrack(now + 1, cnt + 1);
		backtrack(now + 1, cnt);
	}
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	backtrack(0, 0);

	return 0;
}

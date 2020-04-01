/*
boj_1757_달려달려(난이도 : 실버1)
휴식 mem와 달리기 mem를 두 개 두어 직관적으로 풀이
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

int N, M;

int len[10001];
int mem[10001][501];
int rest[10001][501];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int n = 1; n <= N; n++) {
		cin >> len[n];
	}
	rest[0][0] = 0;

	int over = 0;

	for (int n = 1; n <= N; n++) {
		mem[n][1] = max(mem[n][1], rest[n - 1][0] + len[n]);
		rest[n][0] = max(rest[n][0], rest[n - 1][0]);
		for (int m = 1; m <= M; m++) {
			if (mem[n - 1][m] != 0) {
				if (m < M) {
					mem[n][m + 1] = max(mem[n][m + 1], mem[n - 1][m] + len[n]);
				}
				else if (m == M) {
					if ((M + 1) - (N - n) <= 0) {
						over = max(over, mem[n - 1][m] + len[n]);
					}
				}
				rest[n][m - 1] = max(rest[n][m - 1], mem[n - 1][m]);
			}
			if (rest[n - 1][m] != 0) {
				rest[n][m - 1] = max(rest[n][m - 1], rest[n - 1][m]);
			}
		}
	}

	cout << max(rest[N][0], over) << "\n";

	return 0;
}

/*
boj_01535_(난이도 : 실버2)
bottom up dp
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
int L[21];
int J[21];

// mem[i][j]
// i : 현재까지 인사한 사람
// j : 남아있는 체력
// value : 얻은 기쁨
int mem[21][101];
bool visited[101];
bool visited_next[101];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> L[n];
	}
	for (int n = 1; n <= N; n++) {
		cin >> J[n];
	}

	visited[100] = 1;
	for (int n = 1; n <= N; n++) {
		for (int j = 1; j <= 100; j++) {
			if (!visited[j]) continue;
			int next = j - L[n];
			if (next <= 0) continue;
			mem[n][next] = max(mem[n][next], mem[n - 1][j] + J[n]);
			visited_next[next] = 1;
		}

		for (int j = 1; j <= 100; j++) {
			if (visited_next[j] || visited[j]) {
				visited[j] = 1;
			}
			visited_next[j] = 0;
			mem[n][j] = max(mem[n][j], mem[n - 1][j]);
		}
	}

	int myMax = 0;
	for (int j = 1; j <= 100; j++) {
		myMax = max(myMax, mem[N][j]);
	}

	cout << myMax << "\n";

	return 0;
}



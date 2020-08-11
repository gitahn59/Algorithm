/*
boj_11048_이동하기(난이도 : 실버1)
Topdown DP
기본적인 탑다운 DP
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
int arr[1001][1001];
int dist[1001][1001];
bool visited[1001][1001];

int ni[] = { -1,-1,0 };
int nj[] = { -1,0,-1 };

int topdown(int n, int m) {
	int& ref = dist[n][m];
	if (visited[n][m]) return ref;

	int sum = 0;
	for (int k = 0; k < 3; k++) {
		int i = n + ni[k];
		int j = m + nj[k];
		if (i<1 || i> N || j<1 || j> M) continue;
		sum = max(sum, topdown(i, j));
	}
	visited[n][m] = 1;
	return ref = sum + arr[n][m];
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			cin >> arr[n][m];
		}
	}

	cout << topdown(N, M) << "\n";

	return 0;
}



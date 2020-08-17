/*
boj_7579_앱(난이도 : 골드3)
Knapsack
기본적인 bottom up knapsack 문제
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

int N, M, C;
ii arr[100];

int dist[100][10010];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int n = 0; n < N; n++) {
		cin >> arr[n].first;
	}

	for (int n = 0; n < N; n++) {
		cin >> arr[n].second;
		C += arr[n].second;
		dist[n][0] = 1;
	}

	int rst = C;
	dist[0][arr[0].second] = arr[0].first + 1;
	if (arr[0].first >= M) rst = arr[0].second;

	for (int n = 1; n < N; n++) {
		for (int c = arr[n].second; c <= C; c++) {
			int pre = c - arr[n].second;
			if (dist[n - 1][pre]) {
				dist[n][c] = max(dist[n][c], dist[n - 1][pre] + arr[n].first);
				if (dist[n][c] - 1 >= M) {
					rst = min(rst, c);
				}
			}
		}
		for (int c = 0; c <= C; c++) {
			dist[n][c] = max(dist[n][c], dist[n - 1][c]);
		}
	}

	cout << rst << "\n";

	return 0;
}



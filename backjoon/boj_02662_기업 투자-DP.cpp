/*
boj_2662_기업투자(난이도 : 골드3)
DP
경로 관리가 필요한 knapsack 문제
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

int N, M;
int arr[21][301];
int dist[21][301]; // dist[m][n] : m : 현재 보고있는 기업, n : 투자비용
ii path[21][301];
int rst[21];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int cost;
	for (int n = 1; n <= N; n++) {
		cin >> cost;
		int gain;
		for (int m = 1; m <= M; m++) {
			cin >> gain;
			arr[m][cost] = gain;
		}
	}

	dist[0][0] = 1;
	path[0][0] = { 0, 1 };
	for (int m = 1; m <= M; m++) {
		for (int n = 1; n <= N; n++) {
			for (int i = n; i <= N; i++) {
				int pre = i - n;
				if (dist[m - 1][pre] == 0) continue;
				else {
					int gain = dist[m - 1][pre] + arr[m][n];
					if (dist[m][i] < gain) {
						dist[m][i] = gain;
						path[m][i] = { m, n };
					}
				}

			}
		}

		for (int i = 0; i <= N; i++) {
			if (dist[m][i] < dist[m - 1][i]) {
				dist[m][i] = dist[m - 1][i];
				path[m][i] = path[m - 1][i];
			}
		}
	}

	int myMax = 1;
	int idx = 1;
	for (int i = 1; i <= N; i++) {
		if (dist[M][i] > myMax) {
			myMax = dist[M][i];
			idx = i;
		}
	}

	cout << dist[M][idx] - 1 << "\n";

	cost = idx;
	int m = M;
	while (cost != 0) {
		rst[path[m][cost].first] = path[m][cost].second;
		int c = path[m][cost].second;
		m = path[m][cost].first - 1;
		cost -= c;
	}


	for (int m = 1; m <= M; m++) {
		cout << rst[m] << " ";
	}
	cout << "\n";

	return 0;
}



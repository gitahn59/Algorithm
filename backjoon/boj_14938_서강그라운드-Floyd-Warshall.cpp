/*
boj_14938_서강그라운드(난이도 : 골드3)
Floyd-Warshall
문제의 크기가 작아 모든 정점에서 모든 정점까지의 최단 거리를 구하는
플로이드 워셜 알고리즘을 적용할 수 있음
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

int N, M, R;
int arr[101];

vii adj[101];
int dist[101][101];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> R;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
		for (int i = 1; i <= N; i++) {
			dist[n][i] = 15000000;
		}
		dist[n][n] = 0;
	}

	int a, b, l;
	for (int r = 1; r <= R; r++) {
		cin >> a >> b >> l;
		dist[a][b] = min(dist[a][b], l);
		dist[b][a] = min(dist[b][a], l);
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}

	int myMax = 0;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			if (dist[i][j] <= M) {
				sum += arr[j];
			}
		}
		myMax = max(sum, myMax);
	}

	cout << myMax << "\n";

	return 0;
}

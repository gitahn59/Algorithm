/*
boj_16933_벽 부수고 이동하기3(난이도 : 골드1)
BFS
boj_14442의 확장 문제
기존 조건에 낮, 밤 조건까지 추가로 고려해야 하는 문제
차원을 추가하여 각 조건의 상태를 모두 검사하여
최단 거리를 계산 할 수 있다.
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
typedef set<int> si;
typedef struct i4 {
	int d, k, i, j;
}iiii;

int N, M, K;
int arr[1001][1001];
int visited[2][11][1001][1001];
int INF = 100000000;
int ni[] = { 1,-1,0,0, 0 };
int nj[] = { 0,0,1,-1, 0 };

int bfs() {
	if (N == 1 && M == 1) return 1;
	queue<iiii> q;
	q.push({ 0, 0, 1, 1 });
	for (int n = 0; n <= N; n++) {
		for (int m = 0; m <= M; m++) {
			for (int k = 0; k <= K; k++) {
				visited[0][k][n][m] = INF;
				visited[1][k][n][m] = INF;
			}
		}
	}

	visited[0][0][1][1] = 0;
	int t = 0; // even is day
	for (; !q.empty(); t++) {
		int end = q.size();
		for (int start = 0; start != end; start++) {
			iiii now = q.front();
			q.pop();
			for (int k = 0; k < 5; k++) {
				int i = ni[k] + now.i;
				int j = nj[k] + now.j;
				if (i<1 || i>N || j<1 || j>M) continue;
				if (arr[i][j] == 1) {
					if (k == 4) {
						if (visited[(t + 1) % 2][now.k][i][j] > t + 1) {
							visited[(t + 1) % 2][now.k][i][j] = t + 1;
							q.push({ (t + 1) % 2, now.k,i,j });
						}
					}
					else if (k != 4 && (t % 2 == 0)) {
						if (now.k < K && visited[1][now.k + 1][i][j] > t + 1) {
							visited[1][now.k + 1][i][j] = t + 1;
							q.push({ 1, now.k + 1,i,j });
							if (i == N && j == M) return t + 2;
						}
					}
				}
				else {
					if (visited[(t + 1) % 2][now.k][i][j] > t + 1) {
						visited[(t + 1) % 2][now.k][i][j] = t + 1;
						q.push({ (t + 1) % 2, now.k,i,j });
						if (i == N && j == M) return t + 2;
					}
				}
			}
		}
	}

	return -1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> K;
	string str;
	for (int n = 1; n <= N; n++) {
		cin >> str;
		for (int m = 1; m <= M; m++) {
			arr[n][m] = str[m - 1] - '0';
		}
	}

	cout << bfs() << "\n";

	return 0;
}

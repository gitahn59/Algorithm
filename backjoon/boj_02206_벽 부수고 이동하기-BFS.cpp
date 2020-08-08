/*
boj_2206_벽 부수고 이동하기(난이도 : 골드 4)
BFS
기본적인 BFS에 차원을 추가하여
벽을 부수는 동작도 포함하여 관리
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
typedef struct i3 {
	int a, i, j;
}iii;

int N, M;
int arr[1001][1001];
int visited[2][1001][1001];
int INF = 100000000;
int ni[] = { 1,-1,0,0 };
int nj[] = { 0,0,1,-1 };

int bfs() {
	if (N == 1 && M == 1) return 1;
	queue<iii> q;
	q.push({ 0, 1, 1 });
	for (int n = 0; n <= N; n++) {
		for (int m = 0; m <= M; m++) {
			visited[0][n][m] = INF;
			visited[1][n][m] = INF;
		}
	}

	visited[0][1][1] = 0;
	int t = 1;
	for (; !q.empty(); t++) {
		int end = q.size();
		for (int start = 0; start != end; start++) {
			iii now = q.front();
			q.pop();
			for (int k = 0; k < 4; k++) {
				int i = ni[k] + now.i;
				int j = nj[k] + now.j;
				if (i<1 || i>N || j<1 || j>M) continue;
				if (arr[i][j] == 1) {
					if (now.a == 0 && visited[1][i][j] > t + 1) {
						visited[1][i][j] = t + 1;
						q.push({ 1,i,j });
						if (i == N && j == M) return t + 1;
					}
				}
				else {
					if (visited[now.a][i][j] > t + 1) {
						visited[now.a][i][j] = t + 1;
						q.push({ now.a,i,j });
						if (i == N && j == M) return t + 1;
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

	cin >> N >> M;
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

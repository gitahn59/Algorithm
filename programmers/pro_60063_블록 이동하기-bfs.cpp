/*
pro_60063_블록 이동하기(난이도 : level 3)
bfs
일반적인 이동 방법과 회전을 고려해야 하는 bfs 문제
회전에 대한 조건 검사가 까다로움
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
int arr[102][102];

int hor = 0;
int ver = 1;
int dist[102][102][2];
int ni[] = { -1,1,0,0 };
int nj[] = { 0,0,-1,1 };

// hor to ver
int mi[] = { -1,-1,0,0 };
int mj[] = { 0,1,0,1 };
ii ban[] = { {-1,1},{-1,0},{1,1},{1,0} };

// ver to hor
int vhi[] = { 0,1,0,1 };
int vhj[] = { -1,-1,0,0 };
ii vh[] = { {1,-1},{0,-1},{1,1},{0,1} };

typedef struct node {
	int h, w, d;
}Node;

int bfs() {
	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j <= 1; j++) {
				dist[n][i][j] = INT_MAX;
			}
		}
	}

	queue<Node> q;
	q.push({ 1,1,hor });
	dist[1][1][hor] = 0;

	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		for (int qs = 1; qs <= qsize; qs++) {
			Node now = q.front();
			q.pop();

			if (now.h == N && now.w == N)
				return t;
			else if (now.d == hor && now.h == N && now.w + 1 == N)
				return t;
			else if (now.d == ver && now.h + 1 == N && now.w == N)
				return t;

			for (int k = 0; k < 4; k++) {
				int i = now.h + ni[k];
				int j = now.w + nj[k];
				if (i<1 || i> N || j<1 || j>N) continue;
				if (arr[i][j] == 1) continue;
				if (now.d == hor) {
					if (j + 1 > N) continue;
					if (arr[i][j + 1] == 1) continue;
				}
				else if (now.d == ver) {
					if (i + 1 > N) continue;
					if (arr[i + 1][j] == 1) continue;
				}
				if (dist[i][j][now.d] > t + 1) {
					dist[i][j][now.d] = t + 1;
					q.push({ i,j,now.d });
				}
			}

			if (now.d == hor) {
				for (int k = 0; k < 4; k++) {
					int i = now.h + mi[k];
					int j = now.w + mj[k];
					if (i<1 || i> N || j<1 || j>N) continue;
					if (arr[i][j] == 1) continue;
					if (i + 1 > N) continue;
					if (arr[i + 1][j] == 1) continue;
					ii b = { now.h + ban[k].first, now.w + ban[k].second };
					if (arr[b.first][b.second]) continue;
					if (dist[i][j][ver] > t + 1) {
						dist[i][j][ver] = t + 1;
						q.push({ i,j,ver });
					}
				}
			}
			else if (now.d == ver) {
				for (int k = 0; k < 4; k++) {
					int i = now.h + vhi[k];
					int j = now.w + vhj[k];
					if (i<1 || i> N || j<1 || j>N) continue;
					if (arr[i][j] == 1) continue;
					if (j + 1 > N) continue;
					if (arr[i][j + 1] == 1) continue;
					ii b = { now.h + vh[k].first, now.w + vh[k].second };
					if (arr[b.first][b.second]) continue;
					if (dist[i][j][hor] > t + 1) {
						dist[i][j][hor] = t + 1;
						q.push({ i,j,hor });
					}
				}
			}
		}
	}

	return -1;
}

int solution(vector<vector<int>> board) {
	N = board.size();
	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= N; i++) {
			arr[n][i] = board[n - 1][i - 1];
		}
	}

	int answer = bfs();
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution({ {0, 0, 0, 1, 1},{0, 0, 0, 1, 0},{0, 1, 0, 1, 1},{1, 1, 0, 0, 1},{0, 0, 0, 0, 0} });


	return 0;
}

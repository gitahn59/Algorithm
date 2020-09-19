/*
boj_16988_Baduk2 (Easy) (난이도 : 골드3)
bfs
후보중에 두 개를 골라
backtracking과 bfs를 통해 최적해 계산
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

int N, M, K;
bool visited[20][20];
int arr[20][20];
vii candidiate;
int ni[] = { 1,-1,0,0 };
int nj[] = { 0,0,1,-1 };

int bfs(int a, int b) {
	queue<ii> q;
	vii path;

	visited[a][b] = 1;
	q.push({ a,b });
	path.push_back({ a,b });

	while (!q.empty()) {
		ii now = q.front();
		q.pop();

		for (int k = 0; k < 4; k++) {
			int i = now.first + ni[k];
			int j = now.second + nj[k];
			if (i < 0 || i >= N || j < 0 || j >= M) continue;
			if (visited[i][j] || arr[i][j] != 2) continue;
			visited[i][j] = 1;
			path.push_back({ i,j });
			q.push({ i,j });
		}
	}

	for (ii now : path) {
		for (int k = 0; k < 4; k++) {
			int i = now.first + ni[k];
			int j = now.second + nj[k];
			if (i < 0 || i >= N || j < 0 || j >= M) continue;
			if (arr[i][j] == 0) return 0;
		}
	}
	return path.size();
}

int getCnt(int a, int b) {
	ii A = candidiate[a];
	ii B = candidiate[b];

	arr[A.first][A.second] = 1;
	arr[B.first][B.second] = 1;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visited[i][j] = 0;
		}
	}

	int cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == 0 && arr[i][j] == 2) {
				cnt += bfs(i, j);
			}
		}
	}

	arr[A.first][A.second] = 0;
	arr[B.first][B.second] = 0;

	return cnt;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 0) candidiate.push_back({ i,j });
		}
	}

	K = candidiate.size();
	int myMax = 0;
	for (int i = 0; i < K - 1; i++) {
		for (int j = i + 1; j < K; j++) {
			myMax = max(myMax, getCnt(i, j));
		}
	}

	cout << myMax << "\n";

	return 0;
}



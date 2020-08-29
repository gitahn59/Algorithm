/*
pro_67259_경주로 건설(난이도 : level 3)
BFS
방향이 있는 BFS
변수를 통해 방향을 관리하면서 BFS를 돌리면 됨
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

typedef struct node {
	int i, j;
	int dir; // 0 : 가로, 1 : 세로
	int cost;
}Node;

int N;
int visited[25][25][2];
int ni[2][4] = { {1,-1,0, 0 },{1,-1,0,0} };
int nj[2][4] = { { 0,0,1,-1 },{0,0,1,-1} };
int ndir[2][4] = { { 1,1,0,0 },{1,1,0,0} };
int ncst[2][4] = { { 600,600,100,100 },{100,100,600,600} };

int bfs(vvi& board) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j][0] = INT_MAX;
			visited[i][j][1] = INT_MAX;
		}
	}

	queue<Node> q;
	q.push({ 0,0,0,0 });
	q.push({ 0,0,1,0 });
	visited[0][0][0] = 0;
	visited[0][0][1] = 0;

	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		for (int qs = 0; qs < qsize; qs++) {
			Node now = q.front();
			q.pop();
			for (int k = 0; k < 4; k++) {
				int i = now.i + ni[now.dir][k];
				int j = now.j + nj[now.dir][k];
				if (i < 0 || i >= N || j < 0 || j >= N) continue;
				if (board[i][j] == 1) continue;
				int dir = ndir[now.dir][k];
				int cst = ncst[now.dir][k];
				int c = now.cost + cst;
				if (visited[i][j][dir] > c) {
					visited[i][j][dir] = c;
					q.push({ i,j,dir, c });
				}
			}
		}
	}

	return min(visited[N - 1][N - 1][0], visited[N - 1][N - 1][1]);
}

int solution(vector<vector<int>> board) {
	N = board.size();
	int answer = bfs(board);
	return answer;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cout << solution({ {0, 0, 0, 0, 0, 0, 0, 1}, {0, 0, 0, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 1, 0, 0, 0}, {0, 0, 0, 1, 0, 0, 0, 1}, {0, 0, 1, 0, 0, 0, 1, 0}, {0, 1, 0, 0, 0, 1, 0, 0}, {1, 0, 0, 0, 0, 0, 0, 0} });

	return 0;
}





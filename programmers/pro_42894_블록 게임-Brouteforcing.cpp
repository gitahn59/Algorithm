/*
pro_42894_블록게임(난이도 : level4)
완전탐색
문제의 크기가 크지 않아 경우의 수를 전부 탐색
블록의 모양을 미리구해두어
각 블록의 type을 구하고
큐를 이용하여 변화가 생기면 계속 조건을 검사하고
변화가 없으면 빠져나와 cnt를 리턴
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
int arr[52][52];

typedef struct node {
	int type, i, j;
}Node;

queue<Node> qn;

ii bsize[12] = {
	{2,3}, {3,2}, {2,3}, {3,2},
	{2,3}, {3,2}, {2,3}, {3,2},
	{2,3}, {3,2}, {2,3}, {3,2}
};

int block[12][3][3] = {
	{ {1, 1, 1}, {0,0,1} },
	{ {1, 1}, {1,0},{1,0} },
	{ {1,0,0} , {1, 1, 1} },
	{ {0, 1}, {0,1},{1,1} },

	{ {1, 1, 1}, {1,0,0} },
	{ {1, 0}, {1,0},{1,1} },
	{ {0,0,1} , {1, 1, 1} },
	{ {1, 1}, {0,1},{0,1} },

	{ {0, 1, 0}, {1,1,1} },
	{ {1, 0}, {1,1},{1,0} },
	{ {1, 1, 1}, {0,1,0} },
	{ {0, 1}, {1,1},{0,1} }
};

bool myCheck(int i, int j, int type) {
	int num = -1;
	si s;
	for (int h = 0; h < bsize[type].first; h++) {
		for (int w = 0; w < bsize[type].second; w++) {
			if (block[type][h][w] == 1) {
				if (arr[i + h][j + w] == 0) return false;
				s.insert(arr[i + h][j + w]);
			}
		}
	}
	if (s.size() == 1)
		return true;
	else return false;
}

void getType() {
	for (int type = 0; type < 12; type++) {
		for (int i = 1; i + bsize[type].first - 1 <= N; i++) {
			for (int j = 1; j + bsize[type].second - 1 <= N; j++) {
				if (myCheck(i, j, type)) {
					qn.push({ type,i,j });
				}
			}
		}
	}
}

bool myRemove(Node now) {
	int i = now.i;
	int j = now.j;
	int type = now.type;
	if (type == 0 || type == 1 || type == 4 || type == 7 || type == 9 || type == 10 || type == 11)
		return false;

	for (int h = 0; h < bsize[type].first; h++) {
		for (int w = 0; w < bsize[type].second; w++) {
			if (block[type][h][w] == 0) {
				if (arr[h + i][w + j] == 0) {
					for (int k = 1; k < h + i; k++) { // 윗부분 확인
						if (arr[k][w + j] != 0)
							return false;
					}
				}
				else {
					return false;
				}
			}
		}
	}

	for (int h = 0; h < bsize[type].first; h++) {
		for (int w = 0; w < bsize[type].second; w++) {
			if (block[type][h][w] == 1) {
				arr[i + h][j + w] = 0;
			}
		}
	}

	return true;
}

int solve() {
	int cnt = 0;
	int pre;

	do {
		pre = qn.size();
		for (int qs = 1; qs <= pre; qs++) {
			Node now = qn.front();
			qn.pop();
			if (myRemove(now)) {
				cnt++;
			}
			else {
				qn.push(now);
			}
		}
	} while (pre != qn.size()); // 변화 없으면 빠져나옴

	return cnt;
}


int solution(vector<vector<int>> board) {
	N = board.size();
	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= N; i++) {
			arr[n][i] = board[n - 1][i - 1];
		}
	}
	getType();
	int answer = solve();
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution({
		{0,0,0,0},
		{3,0,1,0},
		{3,0,1,0},
		{3,3,1,1}
		});

	return 0;
}

/*
boj_13460_구슬 탈출2(난이도 : 골드3)
bfs, 구현 문제
구슬들이 서로 겹칠 수 없음에 유의해야함
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

int N, M;

int arr[12][12];

int vacant = '.';
int wall = '#';
int hole = 'O';
ii red, blue;

typedef struct node {
	int cnt;
	int rx, ry, bx, by;
}Node;

int ni[] = { -1,1,0,0 };
int nj[] = { 0,0,-1,1 };

int move(Node node, int k, Node& temp) {
	temp = node;
	bool flag = false;
	while (arr[temp.rx + ni[k]][temp.ry + nj[k]] != wall) {
		temp.rx += ni[k];
		temp.ry += nj[k];
		if (arr[temp.rx][temp.ry] == hole) {
			flag = true;
			break;
		}
	}

	bool fail = false;
	while (arr[temp.bx + ni[k]][temp.by + nj[k]] != wall) {
		temp.bx += ni[k];
		temp.by += nj[k];
		if (arr[temp.bx][temp.by] == hole) {
			fail = true;
			break;
		}
	}

	if (temp.bx == temp.rx && temp.by == temp.ry) {
		if (k == 0) {
			if (node.bx < node.rx) {
				temp.rx -= ni[k];
			}
			else {
				temp.bx -= ni[k];
			}
		}
		else if (k == 1) {
			if (node.bx > node.rx) {
				temp.rx -= ni[k];
			}
			else {
				temp.bx -= ni[k];
			}
		}
		else if (k == 2) {
			if (node.by < node.ry) {
				temp.ry -= nj[k];
			}
			else {
				temp.by -= nj[k];
			}
		}
		else if (k == 3) {
			if (node.by > node.ry) {
				temp.ry -= nj[k];
			}
			else {
				temp.by -= nj[k];
			}
		}
	}

	if (fail) return -1;
	else if (flag) return 100;
	else {
		if (temp.bx == node.bx && temp.by == node.by &&
			temp.rx == node.rx && temp.ry == node.ry
			)
			return 0;
		else return 1;
	}
}

int bfs(int cnt, ii r, ii b) {

	queue<Node> q;
	q.push({ 0,r.first,r.second,b.first,b.second });

	int myMin = 11;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();

		if (now.cnt == 10) continue;

		for (int k = 0; k < 4; k++) {
			Node dest;
			int result = move(now, k, dest);
			if (result == -1) continue;
			else if (result == 100) {
				myMin = min(myMin, now.cnt + 1);
			}
			else if (result == 1) {
				dest.cnt++;

				q.push(dest);
			}
		}
	}

	if (myMin == 11) return -1;
	else return myMin;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	char str[20];
	for (int n = 1; n <= N; n++) {
		cin >> str + 1;
		for (int m = 1; m <= M; m++) {
			arr[n][m] = str[m];
			if (arr[n][m] == 'R') {
				red = { n,m };
				arr[n][m] = '.';
			}
			else if (arr[n][m] == 'B') {
				blue = { n,m };
				arr[n][m] = '.';
			}
		}
	}

	cout << bfs(0, red, blue) << "\n";

	return 0;
}

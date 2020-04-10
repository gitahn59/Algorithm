/*
boj_2174_로봇 시뮬레이션(난이도 : 골드5)
시뮬레이션
주의) 명령의 반복횟수 만큼 같은 명령을 반복해야함
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

typedef struct rbt {
	int h, w, d;
}Robot;

typedef struct od {
	int num, type, cnt;
}Order;

int A, B, N, M;
int H, W;
int arr[102][102];
int ni[] = { -1,1,0,0 };
int nj[] = { 0,0,-1,1 };
//n 0 s 1 w 2 e 3

Robot robot[101];
Order order[101];

int left(int from) {
	if (from == 0) return 2;
	else if (from == 1) return 3;
	else if (from == 2) return 1;
	else return 0;
}

int right(int from) {
	if (from == 0) return 3;
	else if (from == 1) return 2;
	else if (from == 2) return 0;
	else return 1;
}

string simulation() {
	for (int m = 1; m <= M; m++) {
		int r = order[m].num;
		if (order[m].type == 1) {
			for (int c = 1; c <= order[m].cnt; c++)
				robot[r].d = left(robot[r].d);
		}
		else if (order[m].type == 2) {
			for (int c = 1; c <= order[m].cnt; c++)
				robot[r].d = right(robot[r].d);
		}
		else {
			int h = robot[r].h;
			int w = robot[r].w;
			arr[h][w] = 0;
			for (int c = 1; c <= order[m].cnt; c++) {
				int i = h + ni[robot[r].d];
				int j = w + nj[robot[r].d];
				if (i<1 || i>H || j<1 || j>W) {
					return "Robot " + to_string(r) + " crashes into the wall";
				}
				if (arr[i][j] != 0) {
					return "Robot " + to_string(r) + " crashes into robot " + to_string(arr[i][j]);
				}
				h = i; w = j;
			}
			robot[r].h = h;
			robot[r].w = w;
			arr[h][w] = r;
		}
	}

	return "OK";
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B >> N >> M;
	H = B;
	W = A;
	int x, y;
	char d[3];
	for (int n = 1; n <= N; n++) {
		cin >> x >> y;
		cin >> d + 1;
		int dir;
		if (d[1] == 'N') dir = 0;
		else if (d[1] == 'S') dir = 1;
		else if (d[1] == 'W') dir = 2;
		else if (d[1] == 'E') dir = 3;
		robot[n] = { H + 1 - y,x,dir };
		arr[robot[n].h][robot[n].w] = n;
	}

	int r, l;
	char o[3];
	for (int m = 1; m <= M; m++) {
		cin >> r;
		cin >> o + 1;
		cin >> l;
		int opcode;
		if (o[1] == 'L') opcode = 1;
		else if (o[1] == 'R') opcode = 2;
		else if (o[1] == 'F') opcode = 3;

		order[m] = { r,opcode,l };
	}

	cout << simulation() << "\n";

	return 0;
}


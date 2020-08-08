/*
boj_17143_낚시왕(난이도 : 골드2)
시뮬레이션
상어의 움직임을 시뮬레이션 하는 과정이 복잡한
시뮬레이션 문제

로직이 복잡하다면, 미리 전부 계산해두는게 
참조하는 방법이 구현 시간을 아낄 수 있음
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

typedef struct s {
	int id, h, w, s, d, z;
}Shark;

int H, W, M;

bool alive[10001];
Shark info[10001];
int arr[101][101];

int moved[5][101][205];
int movedD[5][101][205];
int gapW;
int gapH;

void move(Shark& src) {
	int speed = src.s;
	if (src.d <= 2) { // up
		speed %= gapH;
		int h = moved[src.d][src.h][speed];
		int d = movedD[src.d][src.h][speed];
		src.h = h;
		src.d = d;
	}
	else {
		speed %= gapW;
		int w = moved[src.d][src.w][speed];
		int d = movedD[src.d][src.w][speed];
		src.w = w;
		src.d = d;
	}
}

int bfs(queue<Shark>& q, int pos) {
	int size = 0;
	for (int h = 1; h <= H; h++) {
		if (arr[h][pos] != 0) {
			int m = arr[h][pos];
			arr[h][pos] = 0;
			alive[m] = true;
			size += info[m].z;
			break;
		}
	}

	int nxt[101][101];
	for (int h = 1; h <= H; h++) {
		for (int w = 1; w <= W; w++) {
			nxt[h][w] = 0;
		}
	}

	int qsize = q.size();
	for (int qs = 0; qs < qsize; qs++) {
		Shark now = q.front();
		q.pop();
		if (alive[now.id]) continue;
		if (now.s != 0)
			move(now);
		if (!nxt[now.h][now.w]) nxt[now.h][now.w] = now.id;
		else {
			int pre = nxt[now.h][now.w]; // 이전게 큼
			if (info[pre].z > info[now.id].z) {
				alive[now.id] = 1;
			}
			else { // 지금게 큼
				nxt[now.h][now.w] = now.id;
				alive[pre] = 1;
			}
		}
		q.push(now);
	}
	for (int h = 1; h <= H; h++) {
		for (int w = 1; w <= W; w++) {
			arr[h][w] = nxt[h][w];
		}
	}

	return size;
}

void preprocessing() {
	for (int w = 1; w <= W; w++) {
		int now = w;
		int d = 1;
		if (w == W) d = -1;
		for (int s = 0; s <= gapW; s++) {
			moved[3][w][s] = now;
			if (now == W && d == 1) d = -1;
			else if (now == 1 && d == -1) d = 1;
			if (d == 1) movedD[3][w][s] = 3;
			else movedD[3][w][s] = 4;
			now += d;
		}
	}

	for (int w = 1; w <= W; w++) {
		int now = w;
		int d = -1;
		if (w == 1) d = 1;
		for (int s = 0; s <= gapW; s++) {
			moved[4][w][s] = now;
			if (now == W && d == 1) d = -1;
			else if (now == 1 && d == -1) d = 1;
			if (d == 1) movedD[4][w][s] = 3;
			else movedD[4][w][s] = 4;
			now += d;
		}
	}

	for (int h = 1; h <= H; h++) {
		int now = h;
		int d = 1;
		if (h == H) d = -1;
		for (int s = 0; s <= gapH; s++) {
			moved[2][h][s] = now;
			if (now == H && d == 1) d = -1;
			else if (now == 1 && d == -1) d = 1;
			if (d == 1) movedD[2][h][s] = 2;
			else movedD[2][h][s] = 1;
			now += d;
		}
	}

	for (int h = 1; h <= H; h++) {
		int now = h;
		int d = -1;
		if (h == 1) d = 1;
		for (int s = 0; s <= gapH; s++) {
			moved[1][h][s] = now;
			if (now == H && d == 1) d = -1;
			else if (now == 1 && d == -1) d = 1;
			if (d == 1) movedD[1][h][s] = 2;
			else movedD[1][h][s] = 1;
			now += d;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> H >> W >> M;
	int r, c, s, d, z;
	queue<Shark> q;
	for (int m = 1; m <= M; m++) {
		cin >> r >> c >> s >> d >> z;
		if (r == 1 && d == 1) d = 2;
		else if (r == H && d == 2) d = 1;
		if (c == 1 && d == 3) d = 4;
		else if (c == W && d == 4) d = 3;
		info[m] = { m, r, c, s, d, z };

		q.push(info[m]);
		arr[r][c] = m;
	}

	gapW = (W << 1) - 2;
	gapH = (H << 1) - 2;
	preprocessing();

	int rst = 0;
	for (int w = 1; w <= W; w++) {
		rst += bfs(q, w);
	}

	cout << rst << "\n";

	return 0;
}


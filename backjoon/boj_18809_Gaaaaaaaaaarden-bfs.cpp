/*
boj_18809_Gaaaaaaaaaarden(난이도 : 골드2)
backtrack 으로 bfs의 시작점을 구하고
그 시작점을 기반으로 시작점이 2 종류인 bfs를 수행
두 시작 점이 만나서 꽃이 피는 지점에서 파생되는 node는 더 이상 탐색하지 않아야 함
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
typedef vector<vi> adj;
typedef deque<int> di;
typedef pair<int, ii> iii;
typedef set<int> si;

int ni[] = { -1,1,0,0 };
int nj[] = { 0,0,-1,1 };

int H, W, G, R;
int grd[52][52];
int red = 3;
int green = 4;
int flower = 5;
int can = 1;
ii plant[11];
int length;
ii selected[11];
int myMax;


typedef struct node {
	int now, pre, time, color;
}Node;

void bfs() {
	int time[52][52];
	int copy[52][52];
	for (int h = 1; h <= H; h++) {
		for (int w = 1; w <= W; w++) {
			time[h][w] = 10000000;
			copy[h][w] = grd[h][w];
		}
	}

	queue<Node> q;
	for (int i = 1; i <= G + R; i++) {
		q.push({ selected[i].first, selected[i].first, 1, selected[i].second });
	}

	int myCnt = 0;
	while (!q.empty()) {
		Node now = q.front();
		q.pop();
		int h = now.now / 100;
		int w = now.now % 100;
		int t = now.time;

		int preh = now.pre / 100;
		int prew = now.pre % 100;
		int color = now.color;

		if (copy[preh][prew] == flower)
			continue;

		if (t == time[h][w] && (copy[h][w] == green && color == red)) {
			copy[h][w] = flower;
			myCnt++;
			continue;
		}
		if (t == time[h][w] && (copy[h][w] == red && color == green)) {
			copy[h][w] = flower;
			myCnt++;
			continue;
		}

		if (time[h][w] <= t) continue;


		time[h][w] = t;
		copy[h][w] = color;
		for (int k = 0; k < 4; k++) {
			int i = h + ni[k];
			int j = w + nj[k];
			if (i<1 || i>H || j<1 || j>W) continue;
			if (copy[i][j] == can) {
				q.push({ i * 100 + j, h * 100 + w, t + 1, color });
			}
		}
	}

	myMax = max(myMax, myCnt);
}

void backtrack(int now, int g, int r, int cnt) {
	if (g == 0 && r == 0) {
		bfs();
		if (myMax == 10)
			bfs();

	}
	if (now > length) return;

	backtrack(now + 1, g, r, cnt);

	int idx = plant[now].first * 100 + plant[now].second;
	if (g > 0) {
		selected[cnt] = { idx, green };
		backtrack(now + 1, g - 1, r, cnt + 1);
		selected[cnt] = { 0, 0 };
	}
	if (r > 0) {
		selected[cnt] = { idx, red };
		backtrack(now + 1, g, r - 1, cnt + 1);
		selected[cnt] = { idx, 0 };
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> H >> W >> G >> R;
	for (int h = 1; h <= H; h++) {
		for (int w = 1; w <= W; w++) {
			cin >> grd[h][w];
			if (grd[h][w] == 2) {
				plant[++length] = { h,w };
				grd[h][w] = can;
			}
		}
	}

	backtrack(1, G, R, 1);

	cout << myMax << "\n";

}
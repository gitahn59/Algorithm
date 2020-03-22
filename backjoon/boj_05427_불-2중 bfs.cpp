/*
boj_05427_불(난이도 : 골드4)
시작점이 2개인 bfs
첫번 째 시작점에 대해 먼저 bfs를 시행해 지나갈 수 없는 길을 판정하고
두번 째 시작점부터 bfs를 수행해 최단시간을 계산
(boj_4179_불! 도 동일)
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

int T, W, H;

int myMap[1002][1002];

int wall = '#';
int epty = '.';
int start = '@';
int fire = '*';

ii base;
queue<ii> fireq;
int time[1002][1002];
int visited[1002][1002];

int bfs() {	
	for (int i = 0; i <= 1001; i++) {
		for (int j = 0; j <= 1001; j++) {
			time[i][j] = 10000000;
			visited[i][j] = 10000000;
		}
	}

	while (!fireq.empty()) {
		ii now = fireq.front();
		int h = now.first / 10000;
		int w = now.first % 10000;
		int t = now.second;
		fireq.pop();
		
		if (time[h][w] > t)
			time[h][w] = t;
		else continue;

		for (int k = 0; k < 4; k++) {
			int i = h + ni[k];
			int j = w + nj[k];
			if (i<1 || i>H || j<1 || j>W) continue;
			if (myMap[i][j] != epty) continue;
			fireq.push({i*10000+j,t+1});
		}
	}

	queue<ii> qi;
	qi.push({base.first*10000+base.second,0});
	while (!qi.empty()) {
		ii now = qi.front();
		int h = now.first / 10000;
		int w = now.first % 10000;
		int t = now.second;
		qi.pop();

		if (visited[h][w] > t)
			visited[h][w] = t;
		else continue;
		if (time[h][w] <= t) continue;
		if (h == 1 || h == H || w == 1 || w == W) return t+1;

		for (int k = 0; k < 4; k++) {
			int i = h + ni[k];
			int j = w + nj[k];
			if (i<1 || i>H || j<1 || j>W) continue;
			if (myMap[i][j] != epty) continue;
			qi.push({ i * 10000 + j,t + 1 });
		}
	}
	return -1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T;

	for (int t = 1; t <= T; t++) {
		char str[1010];
		cin >> W >> H;
		for (int h = 1; h <= H; h++) {
			cin >> str+1;
			for (int w = 1; w <= W; w++) {
				myMap[h][w] = str[w];
				if (str[w] == start) {
					base = { h,w };
					myMap[h][w] = epty;
				}
				if (str[w] == fire) fireq.push({h*10000+w,0});
			}
		}
		int result = bfs();
		if (result == -1) cout << "IMPOSSIBLE" << "\n";
		else cout << result << "\n";
	}
}
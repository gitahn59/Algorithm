/*
boj_02589_보물섬(난이도 : 골드5)
일반적인 미로찾기 bfs
시작 점에 따라 최단경로가 다르기 때문에 모든 정점에서 bfs를 수행해봐야 함
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

int myMap[52][52];
bool visited[52][52];
int H, W;
int land = 'L';
int water = 'W';

int bfs(int start) {
	int time[52][52];
	for (int h = 1; h <= H; h++) {
		for (int w = 1; w <= W; w++) {
			time[h][w] = 1000000;
		}
	}

	queue<ii> qii;
	qii.push({ start,0 });
	while (!qii.empty()) {
		ii now = qii.front();
		qii.pop();
		int h = now.first / 100;
		int w = now.first % 100;
		int t = now.second;

		if (time[h][w] <= t) continue;
		else time[h][w] = t;

		for (int k = 0; k < 4; k++) {
			int i = h + ni[k];
			int j = w + nj[k];
			if (i<1 || i>H || j<1 || j>W) continue;
			if (myMap[i][j] == water) continue;
			qii.push({ i * 100 + j,t + 1 });
		}
	}

	int myMax = 0;
	for (int h = 1; h <= H; h++) {
		for (int w = 1; w <= W; w++) {
			if (time[h][w] != 1000000)
				myMax = max(myMax, time[h][w]);
		}
	}

	return myMax;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> H >> W;
	char str[60];
	for (int h = 1; h <= H; h++) {
		cin >> str + 1;
		for (int w = 1; w <= W; w++) {
			myMap[h][w] = str[w];
		}
	}

	int myMax = 0;
	for (int h = 1; h <= H; h++) {
		for (int w = 1; w <= W; w++) {
			if (myMap[h][w] == water) continue;
			myMax = max(myMax, bfs(h * 100 + w));
		}
	}

	cout << myMax << "\n";
}
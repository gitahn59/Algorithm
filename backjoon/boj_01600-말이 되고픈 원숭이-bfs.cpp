/*
boj_01600_말이 되고픈 원숭이(난이도 : 골드5)
bfs 문제
visit배열의 차원을 늘려 k번 사용했을 때의 방문 여부를 같이 탐색함
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

typedef struct node {
	int i, j, k;
}Node;

int K, W, H;
bool visited[201][201][31];
int arr[201][201];

int ni[] = { 1, -1, 0, 0 };
int nj[] = { 0, 0, 1, -1 };
int hi[] = { -1,-2,-2,-1,1,2,2,1 };
int hj[] = { -2,-1,1,2,2,1,-1,-2 };

int hurdle = 1;

int bfs() {
	queue<Node> q;
	q.push({ 1,1,0 });
	visited[1][1][0] = 1;

	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		for (int s = 1; s <= qsize; s++) {
			Node now = q.front();
			q.pop();

			if (now.i == H && now.j == W) {
				return t;
			}

			for (int idx = 0; idx < 4; idx++) {
				int i = now.i + ni[idx];
				int j = now.j + nj[idx];
				if (i<1 || i> H || j<1 || j>W) continue;
				if (arr[i][j] == hurdle) continue;
				if (visited[i][j][now.k] == 1) continue;
				q.push({ i,j, now.k });
				visited[i][j][now.k] = 1;
			}

			if (now.k == K) continue;

			for (int idx = 0; idx < 8; idx++) {
				int i = now.i + hi[idx];
				int j = now.j + hj[idx];
				if (i<1 || i> H || j<1 || j>W) continue;
				if (arr[i][j] == hurdle) continue;
				if (visited[i][j][now.k + 1] == 1) continue;
				q.push({ i,j, now.k + 1 });
				visited[i][j][now.k + 1] = 1;
			}
		}
	}
	return -1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> K >> W >> H;
	for (int h = 1; h <= H; h++) {
		for (int w = 1; w <= W; w++) {
			cin >> arr[h][w];
		}
	}

	cout << bfs() << '\n';

	return 0;
}


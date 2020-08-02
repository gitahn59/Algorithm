/*
boj_2638_치즈(난이도 : 골드4)
BFS
내부공기에 대한 판별을 위해 별도의 BFS를 
한 개 더 돌려줘야하는 BFS 문제
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

int N, M;
int arr[102][102];
int state[102][102];
int visited[102][102];
int ni[] = { 1,-1,0,0 };
int nj[] = { 0,0,1,-1 };

void updateAirState(int sticker) {
	for (int i = 0; i <= N + 1; i++) {
		for (int j = 0; j <= M + 1; j++) {
			visited[i][j] = 0;
		}
	}

	queue<ii> q;
	q.push({ 0,0 });
	state[0][0] = sticker;
	visited[0][0] = 1;

	for (; !q.empty(); ) {
		int qsize = q.size();
		for (int qs = 0; qs < qsize; qs++) {
			ii now = q.front();
			q.pop();
			for (int k = 0; k < 4; k++) {
				int i = now.first + ni[k];
				int j = now.second + nj[k];
				if (i<0 || i>N + 1 || j<0 || j>M + 1) continue;
				if (visited[i][j]) continue;
				visited[i][j] = 1;
				if (arr[i][j] == 0) {
					state[i][j] = sticker;
					q.push({ i,j });
				}
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	queue<ii> q;
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			cin >> arr[n][m];
			if (arr[n][m]) {
				q.push({ n,m });
			}
		}
	}

	int t = 0;
	int sticker = 1000;
	for (; !q.empty(); t++) {
		int qsize = q.size();
		queue<ii> removed;
		updateAirState(sticker);
		for (int qs = 0; qs < qsize; qs++) {
			ii now = q.front();
			q.pop();

			int touch = 0;
			for (int k = 0; k < 4; k++) {
				int i = now.first + ni[k];
				int j = now.second + nj[k];
				if (i<0 || i>N + 1 || j<0 || j>M + 1) continue;
				if (arr[i][j] == 0 && state[i][j] == sticker)
					touch++;
			}
			if (touch >= 2) {
				removed.push(now);
			}
			else {
				q.push(now);
			}
		}
		while (!removed.empty()) {
			ii now = removed.front();
			removed.pop();
			arr[now.first][now.second] = 0;
		}
		sticker++;
	}

	cout << t << "\n";

	return 0;
}

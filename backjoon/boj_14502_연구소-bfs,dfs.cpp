/*
boj_14502_연구소(난이도 : 골드5)
dfs로 후보를 결정하고
각 후보에 대해 bfs로 counting
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
vii space;
vii gas;
int arr[10][10];
ii selected[4];
int myMax;

int ni[] = { -1,1,0,0 };
int nj[] = { 0,0,-1,1 };

int count_empty() {
	int cnt = 0;
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			if (arr[n][m] == 0) cnt++;
		}
	}
	return cnt;
}

int bfs() {
	queue<ii> qii;
	for (ii clear : space) {
		arr[clear.first][clear.second] = 0;
	}

	for (ii g : gas) {
		qii.push(g);
		arr[g.first][g.second] = 0;
	}

	for (int i = 1; i <= 3; i++) {
		arr[selected[i].first][selected[i].second] = 1;
	}

	while (!qii.empty()) {
		ii now = qii.front();
		qii.pop();

		if (arr[now.first][now.second] != 0) continue;
		else arr[now.first][now.second] = 2;

		for (int k = 0; k < 4; k++) {
			int i = ni[k] + now.first;
			int j = nj[k] + now.second;
			if (i<1 || i>N || j<1 || j>M) continue;
			qii.push({ i,j });
		}
	}

	return count_empty();
}

void dfs(int cnt, int now) {
	if (cnt == 3) {
		myMax = max(myMax, bfs());
		return;
	}
	if (now + 1 > space.size())
		return;
	selected[cnt + 1] = space[now];
	dfs(cnt + 1, now + 1);
	dfs(cnt, now + 1);
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			cin >> arr[n][m];
			if (arr[n][m] == 0) {
				space.push_back({ n,m });
			}
			else if (arr[n][m] == 2) {
				gas.push_back({ n,m });
				arr[n][m] = 0;
			}
		}
	}
	dfs(0, 0);
	cout << myMax << "\n";

	return 0;
}

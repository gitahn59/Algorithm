/*
boj_7562_나이트의 이동(난이도 : 실버2)
BFS
이동방법이 다양한 BFS 문제
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

int T, L;
ii S, E;
bool visited[300][300];
int ni[] = { -2,-1,1,2,2,1,-1,-2 };
int nj[] = { -1,-2,-2,-1,1,2,2,1 };

int bfs() {
	for (int i = 0; i < L; i++) {
		for (int j = 0; j < L; j++) {
			visited[i][j] = 0;
		}
	}

	queue<ii> q;
	q.push(S);
	visited[S.first][S.second] = 0;

	for (int t = 1; !q.empty(); t++) {
		int qsize = q.size();
		for (int qs = 0; qs < qsize; qs++) {
			ii now = q.front();
			q.pop();

			for (int k = 0; k < 8; k++) {
				int i = ni[k] + now.first;
				int j = nj[k] + now.second;
				if (i < 0 || i >= L || j < 0 || j >= L) continue;
				if (visited[i][j] == 0) {
					if (i == E.first && j == E.second) return t;
					visited[i][j] = 1;
					q.push({ i,j });
				}
			}
		}
	}
	return -1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> L;
		cin >> S.first >> S.second;
		cin >> E.first >> E.second;
		if (S == E) cout << "0\n";
		else {
			int rst = bfs();
			cout << rst << "\n";
		}
	}

	return 0;
}



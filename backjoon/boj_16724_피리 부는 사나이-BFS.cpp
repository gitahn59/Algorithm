/*
boj_16724_피리 부는 사나이(난이도 : 골드2)
BFS
각 방향에 따라 BFS로 
연결되는 요소들을 식별하여
총 연결요소의 개수를 출력하는 문제
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
int trans[100];
int arr[1000][1000];
int visited[1000][1000];
int INF = 100000000;
int ni[] = { -1,1,0,0 };
int nj[] = { 0,0,-1,1 };

bool label(int h, int w, int tag) {
	queue<ii> q;
	queue<ii> candidate;
	q.push({ h,w });
	visited[h][w] = tag;
	candidate.push({ h,w });

	int pre = 0;
	for (; !q.empty() && pre == 0;) {
		int qsize = q.size();
		for (int qs = 0; qs < qsize; qs++) {
			ii pos = q.front();
			q.pop();
			int type = arr[pos.first][pos.second];
			int i = pos.first + ni[type];
			int j = pos.second + nj[type];
			if (i < 0 || i == N || j < 0 || j == M) continue;
			if (visited[i][j] > tag) {
				visited[i][j] = tag;
				candidate.push({ i,j });
				q.push({ i,j });
			}
			else if (visited[i][j] < tag) {
				pre = visited[i][j];
				break;
			}
		}
	}

	if (pre != 0) {
		while (!candidate.empty()) {
			ii pos = candidate.front();
			candidate.pop();
			visited[pos.first][pos.second] = pre;
		}
		return false;
	}
	else {
		return true;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	string line;
	trans['U'] = 0;
	trans['D'] = 1;
	trans['L'] = 2;
	trans['R'] = 3;

	for (int n = 0; n < N; n++) {
		cin >> line;
		for (int m = 0; m < M; m++) {
			arr[n][m] = trans[line[m]];
			visited[n][m] = INF;
		}
	}

	int now = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visited[i][j] == INF) {
				if (label(i, j, now)) now++;
			}
		}
	}

	cout << now - 1 << "\n";

	return 0;
}




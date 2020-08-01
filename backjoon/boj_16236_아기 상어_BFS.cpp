/*
boj_16236_아기상어(난이도 : 골드5)
bfs
조건에 맞게 그래프를 탐색하는 BFS 문제
상어의 시작위치를 0으로 미리 초기화하는 것에 주의
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

int arr[25][25];
int N;
int SHARK = 9;
ii pos;
int ni[] = { 1,-1,0,0 };
int nj[] = { 0,0,1,-1 };

int search(int size) {
	int visited[25][25];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visited[i][j] = 0;
		}
	}

	queue<ii> q;
	q.push(pos);
	visited[pos.first][pos.second] = 1;
	int t = 1;
	for (; !q.empty(); t++) {
		int qsize = q.size();
		queue<ii> candidate;
		for (int qs = 0; qs < qsize; qs++) {
			ii now = q.front();
			q.pop();

			for (int k = 0; k < 4; k++) {
				int i = ni[k] + now.first;
				int j = nj[k] + now.second;
				if (i < 0 || i == N || j < 0 || j == N) continue;
				if (visited[i][j] == 1) continue;
				visited[i][j] = 1;
				if (arr[i][j] == 0) {
					q.push({ i,j });
				}
				else if (arr[i][j] < size) {
					candidate.push({ i,j });
				}
				else if (arr[i][j] == size) {
					q.push({ i,j });
				}
				else {
					continue;
				}
			}
		}

		if (!candidate.empty()) {
			ii myMax = candidate.front();
			while (!candidate.empty()) {
				ii c = candidate.front();
				candidate.pop();
				if (myMax.first > c.first) {
					myMax = c;
				}
				else if (myMax.first == c.first) {
					if (c.second < myMax.second) {
						myMax = c;
					}
				}
			}
			arr[myMax.first][myMax.second] = 0;
			pos = { myMax.first, myMax.second };
			return t;
			break;
		}
	}

	return 0;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == SHARK) {
				pos = { i,j };
				arr[i][j] = 0;
			}
		}
	}

	int size = 2;
	int rst = 0;
	int eat = 0;
	vii path;
	vi stamp;
	path.push_back(pos);
	stamp.push_back(0);
	while (true) {
		int t = search(size);
		if (t == 0) break;
		else {
			rst += t;
			eat++;
			if (eat == size) {
				size++;
				eat = 0;
			}
		}
		path.push_back(pos);
		stamp.push_back(t);
	}

	cout << rst << "\n";

	return 0;
}

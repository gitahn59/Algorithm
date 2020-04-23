/*
boj_9328_열쇠(난이도 : 골드1)
bfs
시작점이 정해지지 않은 bfs
visit 체크를 정확히 해주어야 하며, 
이미 지나간 문도, 나중에 열쇠가 발견되면 다시 큐에 집어넣고
다시 탐색을 진행해야 함(문의 종류는 알파벳 26개)

탐색의 편의를 위해 0,0에서 시작하여 
빌딩의 가장자리 바깥에 테두리를 새로 두르고
탐색 할 수 있음
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

int arr[102][102];
int EMPTY = '.', WALL = '*', D = '$';
int T, H, W;
int key;
bool visited[102][102];
int ni[] = { 1,-1,0,0 };
int nj[] = { 0,0,1,-1 };

typedef struct node {
	int i, j, key;
}Node;

bool isDoor(int i, int j) {
	if ('A' <= arr[i][j] && arr[i][j] <= 'Z') return true;
	return false;
}

bool isKey(int i, int j) {
	if ('a' <= arr[i][j] && arr[i][j] <= 'z') return true;
	return false;
}

bool hasKey(char door) {
	int num = 1 << (door - 'A');
	if (num & key) return true;
	return false;
}

int bfs() {
	queue<ii> q;
	q.push({ 0,0 });

	vii door[26];
	int cnt = 0;
	while (!q.empty()) {
		int qsize = q.size();
		for (int s = 1; s <= qsize; s++) {
			ii now = q.front();
			q.pop();

			for (int k = 0; k < 4; k++) {
				int i = now.first + ni[k];
				int j = now.second + nj[k];
				if (i<0 || i>H + 1 || j<0 || j>W + 1) continue;
				if (arr[i][j] == WALL) continue;

				if (visited[i][j]) continue;
				else visited[i][j] = 1;

				if (isDoor(i, j)) {
					if (hasKey(arr[i][j])) {
						arr[i][j] = 0;
						q.push({ i,j });
						continue;
					}
					else {
						door[arr[i][j] - 'A'].push_back({ i,j });
					}
					continue;
				}

				if (arr[i][j] == 0) {
					q.push({ i,j });
				}
				else if (isKey(i, j)) {
					int num = arr[i][j] - 'a';
					int newKey = 1 << num;
					key = key | newKey;
					arr[i][j] = 0;
					while (!door[num].empty()) {
						q.push(door[num].back());
						door[num].pop_back();
					}
					q.push({ i,j });
				}
				else {
					cnt++;
					arr[i][j] = 0;
					q.push({ i,j });
				}
			}
		}
	}

	return cnt;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> H >> W;
		char str[110];
		for (int h = 1; h <= H; h++) {
			cin >> str + 1;
			for (int w = 1; w <= W; w++) {
				if (str[w] == EMPTY) continue;
				arr[h][w] = str[w];
			}
		}
		string K;
		cin >> K;
		if (K != "0") {
			for (char k : K) {
				key += 1 << (k - 'a');
			}
		}
		cout << bfs() << "\n";

		for (int h = 0; h <= H + 1; h++) {
			for (int w = 0; w <= W + 1; w++) {
				visited[h][w] = 0;
				arr[h][w] = 0;
			}
		}
		key = 0;
	}


	return 0;
}


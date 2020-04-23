/*
boj_9328_����(���̵� : ���1)
bfs
�������� �������� ���� bfs
visit üũ�� ��Ȯ�� ���־�� �ϸ�, 
�̹� ������ ����, ���߿� ���谡 �߰ߵǸ� �ٽ� ť�� ����ְ�
�ٽ� Ž���� �����ؾ� ��(���� ������ ���ĺ� 26��)

Ž���� ���Ǹ� ���� 0,0���� �����Ͽ� 
������ �����ڸ� �ٱ��� �׵θ��� ���� �θ���
Ž�� �� �� ����
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


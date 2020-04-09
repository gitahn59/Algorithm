/*
boj_01035_조각 움직이기(난이도 : 골드1)
bfs 문제
bitmask를 통해 조각의 모든 위치를 기록하여 중복 방문을 방지
5by5행렬에서 조각은 25가지의 위치를 가질 수 있음

조각들의 연결 여부 역시 bfs를 통해 선형시간에 검사
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

typedef tuple<string, int, int, int> Node;

int N;
bitset<(1 << 26) + 1> visited;
int len;

int getPos(int i, int j) {
	int num = (i - 1) * 5 + j;
	return num;
}

ii getCor(int num) {
	int i = num / 5;
	int j = num % 5;
	if (j == 0) return { i,5 };
	else return { i + 1,j };
}

int ni[] = { 1,-1,0,0 };
int nj[] = { 0,0,1,-1 };

int myMap[6][6];

bool myCheck(int now) {
	int cnt = 1;
	ii arr[6];
	for (int i = 1; i <= 25; i++) {
		if (now & 1 << i) {
			arr[cnt] = getCor(i);
			myMap[arr[cnt].first][arr[cnt].second] = 1;
			cnt++;
		}
	}

	queue<ii> qi;
	qi.push(arr[1]);
	while (!qi.empty()) {
		ii now = qi.front();
		qi.pop();
		myMap[now.first][now.second] = 2;
		for (int k = 0; k < 4; k++) {
			int i = now.first + ni[k];
			int j = now.second + nj[k];
			if (i < 1 || i>5 || j < 1 || j>5) continue;
			if (myMap[i][j] == 1) {
				qi.push({ i,j });
			}
		}
	}

	bool flag = true;
	for (int i = 1; i <= len; i++) {
		if (myMap[arr[i].first][arr[i].second] != 2) {
			flag = false;
			break;
		}
	}

	for (int i = 1; i <= len; i++) {
		myMap[arr[i].first][arr[i].second] = 0;
	}

	return flag;
}

int bfs(int start) {
	queue<int> qi;
	qi.push(start);
	visited[start] = 1;

	for (int t = 0; !qi.empty(); t++) {
		int qsize = qi.size();
		for (int i = 1; i <= qsize; i++) {
			int now = qi.front();
			qi.pop();

			if (myCheck(now)) {
				return t;
			}

			for (int i = 1; i <= 25; i++) {
				if (now & 1 << i) {
					ii from = getCor(i);
					for (int k = 0; k < 4; k++) {
						int h = from.first + ni[k];
						int w = from.second + nj[k];
						if (h < 1 || h>5 || w < 1 || w>5) continue;
						int next = getPos(h, w);
						if (now & (1 << next)) continue;
						int temp = now - (1 << i) + +(1 << next);
						if (visited[temp]) continue;
						visited[temp] = 1;
						qi.push(temp);
					}
				}
			}
		}
	}

	return 0;
}



int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int start = 0;
	char str[10];
	for (int n = 1; n <= 5; n++) {
		cin >> str + 1;
		for (int m = 1; m <= 5; m++) {
			if (str[m] == '*') {
				start += (1 << getPos(n, m));
				len++;
			}
		}
	}

	if (len == 1) {
		cout << "0\n";
	}
	else {
		cout << bfs(start) << "\n";
	}

	return 0;
}


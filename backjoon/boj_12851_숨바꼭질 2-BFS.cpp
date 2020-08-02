/*
boj_12851_숨바꼭질 2(난이도 : 골드5)
BFS
방문 시간과 횟수를 기록해두고
최단시간과 동시에 개수까지 구하는 문제
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

int N, K;
int visited[200000];
int rst = 0;

ii bfs() {
	for (int i = 0; i < 200000; i++) {
		visited[i] = 999999;
	}

	queue<int> q;
	q.push(N);

	ii myMax = { 999999,0 };
	ii rst = { 999999,0 };

	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		int flag = 0;
		for (int qs = 0; qs < qsize; qs++) {
			int now = q.front();
			q.pop();

			if (visited[now + 1] >= t + 1) {
				visited[now + 1] = t + 1;
				q.push(now + 1);
				if (now + 1 == K) flag++;
			}
			if (now - 1 >= 0 && visited[now - 1] >= t + 1) {
				visited[now - 1] = t + 1;
				q.push(now - 1);
				if (now - 1 == K) flag++;
			}

			int d = now << 1;
			if (visited[d] >= t + 1) {
				visited[d] = t + 1;
				if (d < K) q.push(d);
				else if (d == K) flag++;
				else {
					int gap = t + 1 + d - K;
					if (myMax.first > gap) {
						myMax = { gap , 1 };
					}
					else if (myMax.first == gap) {
						myMax.second++;
					}
				}
			}
		}

		if (flag) {
			rst = { t + 1,flag };
			break;
		}
	}
	if (myMax.first == rst.first) {
		return { rst.first, rst.second + myMax.second };
	}
	else if (myMax.first < rst.first) {
		return myMax;
	}
	else {
		return rst;
	}
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	if (N >= K) {
		cout << N - K << "\n1\n";
	}
	else {
		ii rst = bfs();
		cout << rst.first << "\n" << rst.second << "\n";
	}

	return 0;
}

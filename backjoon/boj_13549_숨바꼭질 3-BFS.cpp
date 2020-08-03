/*
boj_13549_숨바꼭질 3(난이도 : 골드5)
BFS
순간이동을 하는 경우는 시간 증가가 없으므로
다른 동작에 포함시켜 계산
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
int visited[200010];

int bfs() {
	int ni[] = { 1,-1 };

	for (int i = 0; i <= 200000; i++) {
		visited[i] = INT_MAX;
	}

	queue<int> q;
	q.push(N);
	visited[N] = 0;
	int pre = N;
	while (pre != 0 && pre <= 100000) {
		pre = pre << 1;
		visited[pre] = 0;
		q.push(pre);
		if (pre == K)
			return 0;
	}

	int t = 0;
	for (; !q.empty(); t++) {
		int qsize = q.size();
		for (int qs = 0; qs < qsize; qs++) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < 2; i++) {
				int nxt = now + ni[i];
				if (nxt < 0 || nxt>200000) continue;
				if (nxt == K) return t + 1;
				else {
					if (visited[nxt] > t + 1) {
						visited[nxt] = t + 1;
						q.push(nxt);

						int pre = nxt;
						while (pre != 0 && pre <= 100000) {
							pre = pre << 1;
							if (visited[pre] > t + 1) {
								visited[pre] = t + 1;
								q.push(pre);
								if (pre == K)
									return t + 1;
							}
						}
					}
				}
			}
		}
	}
	return t;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	if (N >= K) {
		cout << N - K << "\n";
	}
	else {
		cout << bfs() << "\n";
	}

	return 0;
}

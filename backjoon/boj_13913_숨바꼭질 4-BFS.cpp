/*
boj_13913_숨바꼭질4(난이도 : 골드4)
BFS
경로를 기록하는 BFS
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
int visited[200001];
int path[200001];

std::function<int(int)> fc[3];
int _plus(int a) { return a + 1; };
int _subj(int a) { return a - 1; };
int _mul(int a) { return a << 1; };

int bfs() {
	int t = 0;
	queue<int> q;
	q.push(N);
	for (int i = 0; i <= 200000; i++) {
		visited[i] = INT_MAX;
	}

	for (t = 0; !q.empty(); t++) {
		int qsize = q.size();
		for (int qs = 0; qs < qsize; qs++) {
			int now = q.front();
			q.pop();

			for (int k = 0; k < 3; k++) {
				int nxt = fc[k](now);
				if (nxt < 0 || nxt>200000) continue;
				if (visited[nxt] > t + 1) {
					visited[nxt] = t + 1;
					path[nxt] = now;
					q.push(nxt);
					if (nxt == K) return t + 1;
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
		while (N != K) {
			cout << N << " ";
			N--;
		}
		cout << K << "\n";
	}
	else {
		fc[0] = _plus;
		fc[1] = _subj;
		fc[2] = _mul;
		cout << bfs() << "\n";
		vi rst;
		rst.push_back(K);
		int now = K;
		while (now != N) {
			now = path[now];
			rst.push_back(now);
		}
		reverse(rst.begin(), rst.end());
		for (int i : rst) {
			cout << i << " ";
		}
		cout << "\n";
	}

	return 0;
}

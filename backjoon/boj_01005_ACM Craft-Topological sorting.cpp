/*
boj_1005_ACM Craft(난이도 : 골드3)
Topological sorting
일반적인 위상정렬에 cost 계산이 첨가된 문제
노드에 대해 들어오는 라인의 최댓값을 고려해야 함
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


int N, K, W;

int cost[1001];
vi adj[1001];
int cnt[1001];
int least[1001];

int topologicalSort() {
	queue<ii> qii;
	for (int n = 1; n <= N; n++) {
		if (cnt[n] == 0) {
			qii.push({ n,cost[n] });
			if (n == W) {
				return cost[n];
			}
		}
	}

	while (!qii.empty()) {
		ii now = qii.front();
		qii.pop();

		for (int child : adj[now.first]) {
			cnt[child]--;
			least[child] = max(now.second + cost[child], least[child]);
			if (cnt[child] == 0) {
				if (child == W) {
					return least[child];
				}
				qii.push({ child, least[child] });
			}
		}
	}
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N >> K;
		//init
		{
			for (int n = 1; n <= N; n++) {
				adj[n].clear();
				cnt[n] = 0;
				least[n] = 0;
			}
		}

		for (int n = 1; n <= N; n++) {
			cin >> cost[n];
		}

		int from, to;
		for (int k = 1; k <= K; k++) {
			cin >> from >> to;
			adj[from].push_back(to);
			cnt[to] ++;
		}
		cin >> W;
		cout << topologicalSort() << "\n";

	}

	return 0;
}


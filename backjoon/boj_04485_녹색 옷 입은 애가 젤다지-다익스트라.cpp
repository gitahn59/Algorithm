/*
boj_04485_녹색 옷 입은 애가 젤다지?(난이도 : 골드4)
간단한 2차원 -> 1차원 좌표 변환이 필요한 다익스트라 문제
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

int N;
int arr[126][126];

int dist[15626];
bool visited[15625];

int getPos(int i, int j) {
	int now = (i - 1) * N;
	return now + j;
}

void dijkstra(int start, vii* adj) {
	fill(visited + 1, visited + 1 + N * N, 0);
	fill(dist + 1, dist + 1 + N * N, 9999999);
	dist[1] = arr[1][1];
	priority_queue<ii> pq;
	pq.push({ -arr[1][1],1 });

	while (!pq.empty()) {
		ii now = pq.top();
		pq.pop();

		if (visited[now.second]) continue;
		else visited[now.second] = 1;

		for (ii to : adj[now.second]) {
			int d = -now.first + to.first;
			if (d < dist[to.second]) {
				dist[to.second] = d;
				pq.push({ -d,to.second });
			}
		}
	}
}

int ni[] = { 1,-1,0,0 };
int nj[] = { 0,0,-1,1 };

int solve() {
	vii adj[15626];

	for (int h = 1; h <= N; h++) {
		for (int w = 1; w <= N; w++) {
			for (int k = 0; k < 4; k++) {
				int i = h + ni[k];
				int j = w + nj[k];
				if (i<1 || i>N || j<1 || j>N) continue;
				int from = getPos(h, w);
				int to = getPos(i, j);
				adj[from].push_back({ arr[i][j] , to });
			}
		}
	}

	dijkstra(1, adj);
	return dist[N * N];
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int t = 1;
	while (true) {
		cin >> N;
		if (N == 0) break;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> arr[i][j];
			}
		}
		cout << "Problem " << t << ": " << solve() << "\n";
		t++;
	}


	return 0;
}

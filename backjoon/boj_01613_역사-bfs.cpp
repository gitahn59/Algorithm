/*
boj_01613_역사(난이도 : 골드3)
여러 쿼리를 수행하는 bfs
다수의 쿼리가 수행 되므로 각각 bfs의 결과를 기록하여 시간을 단축해야 함
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
typedef vector<vi> adj;
typedef deque<int> di;
typedef pair<int, ii> iii;
typedef set<int> si;

int N, K, S;

vi acc[401];
int isFast[401][401];

int bfs(int from, int to) {
	bool visited[401];
	memset(visited, 0, sizeof(visited));

	queue<int> qi;
	for (int next : acc[from]) {
		qi.push(next);
	}

	while (!qi.empty()) {
		int now = qi.front();
		qi.pop();

		if (visited[now]) continue;
		else visited[now] = 1;
		isFast[from][now] = -1;

		if (now == to) return -1;
		for (int next : acc[now]) {
			qi.push(next);
		}
	}

	return 0;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= N; i++) {
			isFast[n][i] = 100;
		}
	}

	int pre, next;
	for (int k = 1; k <= K; k++) {
		cin >> pre >> next;
		acc[pre].push_back(next);
		isFast[pre][next] = -1;
		isFast[next][pre] = 1;
	}

	cin >> S;
	int a, b;
	for (int s = 1; s <= S; s++) {
		cin >> a >> b;
		if (isFast[a][b] != 100) {
			cout << isFast[a][b] << "\n";
			continue;
		}

		int rst = bfs(a, b);
		if (rst == -1) {
			cout << "-1\n";
			isFast[a][b] = -1;
		}
		else {
			rst = bfs(b, a);
			if (rst == -1) {
				cout << "1\n";
				isFast[a][b] = 1;
			}
			else {
				cout << "0\n";
				isFast[a][b] = 0;
			}
		}
	}
}}
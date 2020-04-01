/*
boj_1766_문제집(난이도 : 골드2)
boj_2252_줄 세우기 의 확장 문제
기본적인 위상정렬이지만
우선순위 큐를 사용해 출력순서 조정
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

int N, M;

int degree[32001];
vi adj[32001];
int result[32001];

void topologicalSort() {
	priority_queue<int> qi;

	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0)
			qi.push(-i);
	}
	int n = 0;
	while (!qi.empty()) {
		int now = -qi.top();
		qi.pop();
		result[++n] = now;
		for (int next : adj[now]) {
			degree[next]--;
			if (degree[next] == 0)
				qi.push(-next);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int a, b;
	for (int m = 1; m <= M; m++) {
		cin >> a >> b;
		degree[b]++;
		adj[a].push_back(b);
	}

	topologicalSort();

	for (int n = 1; n <= N; n++) {
		cout << result[n] << " ";
	}
	cout << "\n";

	return 0;
}

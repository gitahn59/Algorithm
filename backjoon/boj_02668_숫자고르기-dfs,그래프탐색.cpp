/*
boj_02668_숫자고르기(난이도 : 골드4)
dfs를 통해 사이클을 이루는 그래프의 노드 수를 탐색
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
int arr[101];
bool check[101];
bool visited[101];

bool dfs(int start, int now) {
	if (start == now) return true;
	if (visited[now] == 0) {
		visited[now] = 1;
		bool result = dfs(start, arr[now]);
		visited[now] = 0;
		if (result) check[now] = 1;
		return result;
	}
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
		if (arr[n] == n) check[n] = 1;
	}

	for (int n = 1; n <= N; n++) {
		if (check[n] == 1) continue;
		visited[n] = 1;
		if (dfs(n, arr[n])) check[n] = 1;
		visited[n] = 0;
	}

	int cnt = 0;
	for (int n = 1; n <= N; n++) {
		if (check[n]) cnt++;
	}
	cout << cnt << "\n";
	for (int n = 1; n <= N; n++) {
		if (check[n]) cout << n << "\n";
	}

	return 0;
}

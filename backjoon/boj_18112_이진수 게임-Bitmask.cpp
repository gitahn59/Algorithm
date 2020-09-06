/*
boj_18112_이진수 게임(난이도 : 실버1)
Bitmask
Bitmask 통해 보수연산을 처리한다.
수에 변화에 따른 최단 거리는
BFS를 통해 간단하게 계산할 수 있다.
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

int N, M, K;
bool visited[1024];

bool convert(int num, queue<int>& q) {
	if (num == 1 || num == 0) return false;
	int end = 1;
	for (int i = 1; i <= 9; i++) {
		if ((1 << i) & num) end = i;
	}
	for (int i = 0; i < end; i++) {
		int temp = num ^ (1 << i);
		if (temp == M) return true;
		if (visited[temp]) continue;
		else {
			q.push(temp);
			visited[temp] = 1;
		}
	}

	return false;
}

int bfs() {
	if (N == M) return 0;

	queue<int> q;
	q.push(N);
	visited[N] = 1;
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		for (int qs = 0; qs < qsize; qs++) {
			int now = q.front();
			q.pop();
			if (convert(now, q)) return t + 1;
			if ((now + 1 <= K) && (visited[now + 1] == 0)) {
				visited[now + 1] = 1;
				q.push(now + 1);
				if (now + 1 == M) return t + 1;
			}
			if ((now - 1 >= 0) && (visited[now - 1] == 0)) {
				visited[now - 1] = 1;
				q.push(now - 1);
				if (now - 1 == M) return t + 1;
			}
		}
	}
	return 0;
}

int mystoi(string s) {
	int rst = 0;
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '1') {
			rst += (1 << i);
		}
	}
	return rst;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string a, b;
	cin >> a >> b;
	N = mystoi(a);
	M = mystoi(b);
	K = 1023;

	cout << bfs() << "\n";
	return 0;
}



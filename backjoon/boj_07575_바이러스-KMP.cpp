/*
boj_7575_바이러스(난이도 : 골드1)
KMP알고리즘을 이용한
정수 수열 검색

정수 수열로 p함수를 생성하고, 마찬가지로 KMP를 통해
O(N+M)에 수열이 존재하는지 확인할 수 있음
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

int N, K;
vi candidate[100];
int sz[100];
int p[1000];

void makep(vi& v) {
	int j = 0;
	for (int m = 1; m < v.size(); m++) {
		while (j > 0 && v[m] != v[j]) {
			j = p[j - 1];
		}
		if (v[m] == v[j]) {
			j++;
			p[m] = j;
		}
	}
}

bool kmp(vi& key, vi& src) {
	int M = src.size();
	for (int m = 0, j = 0; m < M; m++) {
		while (j > 0 && src[m] != key[j]) {
			j = p[j - 1];
		}
		if (src[m] == key[j]) {
			j++;
			if (j == K) {
				return true;
			}
		}
	}
	return false;
}

bool solve(int idx) {
	bool virus = 0;

	for (int i = K; i <= sz[idx]; i++) { //1000
		vi key;
		for (int j = i - K; j < i; j++) { // K
			key.push_back(candidate[idx][j]);
		}
		makep(key);

		bool rst[100];
		for (int n = 0; n < N; n++) { // N 100
			rst[n] = 0;
		}
		rst[idx] = 1;

		for (int n = 0; n < N; n++) { // 100
			if (n == idx) continue;
			bool f = kmp(key, candidate[n]); // 1000
			rst[n] = (rst[n] || f);
		}

		reverse(key.begin(), key.end());
		makep(key);
		for (int n = 0; n < N; n++) {
			if (n == idx || rst[n]) continue;
			bool f = kmp(key, candidate[n]);
			rst[n] = (rst[n] || f);
		}

		int j = 0;
		for (j; j < N; j++) {
			if (!rst[j]) break;
		}
		if (j == N) return 1;
	}
	return 0;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	int idx = 1;
	int min_size = 2000;
	for (int n = 0; n < N; n++) {
		cin >> sz[n];
		int num;
		for (int i = 0; i < sz[n]; i++) {
			cin >> num;
			candidate[n].push_back(num);
		}
		if (sz[n] < min_size) {
			idx = n;
			min_size = sz[n];
		}
	}

	bool rst = solve(idx);
	if (rst) cout << "YES\n";
	else cout << "NO\n";

	return 0;
}



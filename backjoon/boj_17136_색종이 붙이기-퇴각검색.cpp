/*
boj_17136_색종이 붙이기(난이도 : 골드3)
퇴각탐색
붙이는 스티커의 크기에 따라 다음 탐색 위치를 결정하는 퇴각 검색
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

int arr[12][12];
int myMin = 25;
int used[6];

void update(int i, int j, int size, int v) {
	for (int h = i; h <= i + size - 1; h++) {
		for (int w = j; w <= j + size - 1; w++) {
			arr[h][w] = v;
		}
	}
}

bool canPaste(int i, int j, int size) {
	if (i + size - 1 > 10) return false;
	if (j + size - 1 > 10) return false;

	for (int h = i; h <= i + size - 1; h++) {
		for (int w = j; w <= j + size - 1; w++) {
			if (!arr[h][w]) return false;
		}
	}
	return true;
}

bool isEmpty() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			if (arr[i][j]) return false;
		}
	}
	return true;
}

void dfs(int i, int j) {
	if (i == 11) {
		if (isEmpty()) {
			int cnt = 0;
			for (int k = 1; k <= 5; k++) {
				cnt += used[k];
			}
			myMin = min(myMin, cnt);
		}
		return;
	}

	if (arr[i][j] == 0) {
		if (j == 10) dfs(i + 1, 1);
		else dfs(i, j + 1);
		return;
	}

	for (int k = 1; k <= 5; k++) {
		if (used[k] < 5 && canPaste(i, j, k)) {
			update(i, j, k, 0);
			used[k] += 1;
			if (j + k - 1 == 10) dfs(i + 1, 1);
			else dfs(i, j + 1);
			update(i, j, k, 1);
			used[k] -= 1;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cin >> arr[i][j];
		}
	}

	dfs(1, 1);

	if (myMin == 25) {
		cout << "-1\n";
	}
	else {
		cout << myMin << "\n";
	}

	return 0;
}

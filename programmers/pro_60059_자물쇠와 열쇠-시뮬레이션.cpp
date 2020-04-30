/*
pro_60059_자물쇠와 열쇠(난이도 : level 3)
시뮬레이션 문제
자물쇠룰 가쥰욿
Key의 왼쪽 위 꼭짓점을 [-M+1, N] 영역내에서
모두 시뮬레이션 해보면 됨
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

int N, M;
int K[21][21];
int arr[21][21];
int checkMap[61][61];

void rotate() {
	int temp[21][21];
	for (int m = 1; m <= M; m++) {
		for (int i = 1; i <= M; i++) {
			temp[m][i] = K[m][i];
		}
	}

	for (int m = 1; m <= M; m++) {
		for (int i = 1; i <= M; i++) {
			K[i][M + 1 - m] = temp[m][i];
		}
	}
}

bool myCheck(int h, int w) {
	memset(checkMap, 0, sizeof(checkMap));

	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= N; i++) {
			checkMap[20 + n][20 + i] = arr[n][i];
		}
	}

	for (int m = 1; m <= M; m++) {
		for (int i = 1; i <= M; i++) {
			int& ref = checkMap[20 + h + m][20 + w + i];
			if (ref == 0) ref = K[m][i];
			else if (ref == 1 && K[m][i] == 1) return false;
		}
	}

	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= N; i++) {
			if (checkMap[20 + n][20 + i] == 0) return false;
		}
	}

	return true;
}

bool solve() {
	for (int i = -M + 1; i < N; i++) {
		for (int j = -M + 1; j < N; j++) {
			if (myCheck(i, j)) return true;
		}
	}
	return false;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	M = key.size();
	for (int m = 1; m <= M; m++) {
		for (int i = 1; i <= M; i++) {
			K[m][i] = key[m - 1][i - 1];
		}
	}

	N = lock.size();
	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= N; i++) {
			arr[n][i] = lock[n - 1][i - 1];
		}
	}

	if (solve()) return true;
	rotate();
	if (solve()) return true;
	rotate();
	if (solve()) return true;
	rotate();
	if (solve()) return true;
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution({ {0,0,0}, {1,0,0}, {0,1,1} }, { {1,1,1}, {1,1,0}, {1,0,1} });

	return 0;
}
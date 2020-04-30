/*
pro_64064_불량 사용자(난이도 : level3)
dfs, 순열
dfs를 통해 후보를 추리고
후보의 순열을 구해 적합 여부 판단
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
string arr[9];
string ban[9];

int selected[9];
int myCnt;
bool isSame(int idx, int target) {
	if (arr[idx].size() != ban[target].size()) return false;
	for (int i = 0; i < arr[idx].size(); i++) {
		if (arr[idx][i] == ban[target][i] || ban[target][i] == '*') continue;
		else return false;
	}
	return true;
}

bool myCheck() {
	int order[] = { 0,1,2,3,4,5,6,7,8 };

	do {
		bool flag = true;
		for (int m = 1; m <= M; m++) {
			if (!isSame(selected[m], order[m])) {
				flag = false;
				break;
			}
		}
		if (flag) return true;
	} while (next_permutation(order + 1, order + M + 1));
	return false;
}

void dfs(int now, int cnt) {
	if (cnt == M) {
		if (myCheck())
			myCnt++;
		return;
	}

	if (now <= N) {
		for (int n = now; n <= N; n++) {
			selected[cnt + 1] = n;
			dfs(n + 1, cnt + 1);
			selected[cnt + 1] = 0;
		}
	}
}

int solution(vector<string> user_id, vector<string> banned_id) {
	N = user_id.size();
	for (int i = 0; i < N; i++) {
		arr[i + 1] = user_id[i];
	}

	M = banned_id.size();
	for (int i = 0; i < M; i++) {
		ban[i + 1] = banned_id[i];
	}

	dfs(1, 0);
	return myCnt;
}

/*
pro_17679_프렌즈4블록(난이도 : level 2)
완전탐색
공간의 크기가 작아 완전탐색
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

int H, W;
int arr[32][32];

int ni[] = { 0,1,1 };
int nj[] = { 1,0,1 };

vii find() {
	vii rst;
	for (int h = 1; h <= H - 1; h++) {
		for (int w = 1; w <= W - 1; w++) {
			int base = arr[h][w];
			if (base == 0) continue;
			bool flag = true;
			for (int k = 0; k < 3; k++) {
				int i = h + ni[k];
				int j = w + nj[k];
				if (base == arr[i][j]) continue;
				else {
					flag = false; break;
				}
			}
			if (flag) rst.push_back({ h,w });
		}
	}
	return rst;
}

void remove(vii& e) {
	for (auto node : e) {
		arr[node.first][node.second] = 0;
		for (int k = 0; k < 3; k++) {
			int i = node.first + ni[k];
			int j = node.second + nj[k];
			arr[i][j] = 0;
		}
	}

	for (int w = 1; w <= W; w++) {
		queue<int> qi;
		for (int h = H; h >= 1; h--) {
			if (arr[h][w] != 0) qi.push(arr[h][w]);
		}

		for (int h = H; h >= 1; h--) {
			if (qi.empty()) arr[h][w] = 0;
			else {
				arr[h][w] = qi.front();
				qi.pop();
			}
		}
	}
}

int myCnt() {
	int cnt = 0;
	for (int h = 1; h <= H; h++) {
		for (int w = 1; w <= W; w++) {
			if (arr[h][w] == 0) cnt++;
		}
	}
	return cnt;
}

int solution(int m, int n, vector<string> board) {
	H = m;
	W = n;
	for (int h = 1; h <= H; h++) {
		for (int w = 1; w <= W; w++) {
			arr[h][w] = board[h - 1][w - 1];
		}
	}

	vii now = find();
	while (now.size() != 0) {
		remove(now);
		now = find();
	}

	int answer = myCnt();
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution(6, 6, { "TTTANT", "RRFACC", "RRRFCC", "TRRRAA", "TTMMMF", "TMMTTJ" });

	return 0;
}

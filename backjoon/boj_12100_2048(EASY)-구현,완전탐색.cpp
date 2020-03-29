/*
boj_12100_2048 (EASY)(난이도 : 골드2)
구현, 완전탐색
참고) 블록을 합치는 과정에서 한 번만 합쳐지도록 주의
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

int N, myMax;

vi move(vii line) {
	vi rst;
	for (ii now : line) {
		if (now.second >= 2) {
			for (int i = 0; i < now.second / 2; i++) {
				rst.push_back(now.first << 1);
			}
		}
		if (now.second % 2 == 1) {
			rst.push_back(now.first);
		}
	}
	return rst;
}

void move_top(vvi& bd) {
	for (int w = 0; w < N; w++) {
		vi temp;
		for (int h = 0; h < N; h++) {
			if (bd[h][w] != 0) temp.push_back(bd[h][w]);
		}
		if (temp.size() == 0) continue;

		vii v;
		ii pre = { temp[0], 1 };
		for (int i = 1; i < temp.size(); i++) {
			if (pre.first == temp[i]) {
				pre.second++;
			}
			else {
				v.push_back(pre);
				pre = { temp[i],1 };
			}
		}
		v.push_back(pre);
		vi rst = move(v);

		for (int h = 0; h < N; h++) {
			if (h < rst.size()) {
				bd[h][w] = rst[h];
			}
			else bd[h][w] = 0;
		}
	}
}

void move_bottom(vvi& bd) {
	vvi rst = bd;
	for (int w = 0; w < N; w++) {
		for (int h = 0; h < N; h++) {
			rst[N - h - 1][w] = bd[h][w];
		}
	}
	move_top(rst);
	for (int w = 0; w < N; w++) {
		for (int h = 0; h < N; h++) {
			bd[N - h - 1][w] = rst[h][w];
		}
	}
}

vvi rotate_right(vvi& src) {
	int h = src.size();
	int w = src[0].size();

	vvi rst(w, vi(h));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			rst[j][h - i - 1] = src[i][j];
		}
	}
	return rst;
}

vvi rotate_left(vvi& src) {
	int h = src.size();
	int w = src[0].size();

	vvi rst(w, vi(h));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			rst[w - j - 1][i] = src[i][j];
		}
	}
	return rst;
}

void move_left(vvi& bd) {
	bd = rotate_right(bd);
	move_top(bd);
	bd = rotate_left(bd);
}

void move_right(vvi& bd) {
	bd = rotate_left(bd);
	move_top(bd);
	bd = rotate_right(bd);
}

int getMax(vvi& bd) {
	int m = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			m = max(m, bd[i][j]);
		}
	}
	return m;
}

void backtrack(int now, vvi& bd) {
	if (now == 5) {
		myMax = max(myMax, getMax(bd));
		return;
	}

	vvi temp1 = bd;
	move_top(temp1);
	backtrack(now + 1, temp1);

	vvi temp2 = bd;
	move_bottom(temp2);
	backtrack(now + 1, temp2);

	vvi temp3 = bd;
	move_left(temp3);
	backtrack(now + 1, temp3);

	vvi temp4 = bd;
	move_right(temp4);
	backtrack(now + 1, temp4);
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	vvi bd(N, vi(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> bd[i][j];
		}
	}
	backtrack(0, bd);

	cout << myMax << "\n";

	return 0;
}

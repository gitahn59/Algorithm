/*
pro_64061_크레인 인형뽑기 게임(난이도 : level1)
시뮬레이션
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

int bd[31][31];
int H, W;

int solution(vector<vector<int>> board, vector<int> moves) {

	H = board.size();
	W = board[0].size();

	for (int h = 1; h <= H; h++) {
		for (int w = 1; w <= W; w++) {
			bd[h][w] = board[h - 1][w - 1];
		}
	}

	stack<int> si;
	int cnt = 0;
	for (int i : moves) {
		for (int h = 1; h <= H; h++) {
			if (bd[h][i] != 0) {
				if (si.empty()) {
					si.push(bd[h][i]);
				}
				else {
					if (si.top() == bd[h][i]) {
						si.pop();
						cnt += 2;
					}
					else {
						si.push(bd[h][i]);
					}
				}
				bd[h][i] = 0;
				break;
			}
		}
	}

	return cnt;
}
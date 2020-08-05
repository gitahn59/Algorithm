/*
boj_1007_벡터 매칭(난이도 : 골드2)
backtracking
벡터의 성질을 이용하여 backtracking으로 해결 가능한 문제
선정된 절반은 더하고, 선정된 절반은 빼므로
20개중 10개만 선정하면 됨
20C10 은 3,628,800이므로 해결 가능함
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
typedef deque<int> di;
typedef pair<int, ii> iii;
typedef set<int> si;

int T, N, M;
int X[20], Y[20];
int turn;
double myMin;
int visited[20];
int selected[20];

void backtrack(int now, int cnt) {
	if (cnt == M) {
		turn++;
		for (int m = 0; m < M; m++) {
			visited[selected[m]] = turn;
		}
		ll lx = 0, ly = 0, rx = 0, ry = 0;
		for (int n = 0; n < N; n++) {
			if (visited[n] == turn) {
				lx += X[n];
				ly += Y[n];
			}
			else {
				rx += X[n];
				ry += Y[n];
			}
		}
		double rst = sqrt((lx - rx) * (lx - rx) + (ly - ry) * (ly - ry));
		myMin = min(myMin, rst);
		return;
	}

	if (now < N) {
		selected[cnt] = now;
		backtrack(now + 1, cnt + 1);
		backtrack(now + 1, cnt);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		M = N / 2;
		for (int n = 0; n < N; n++) {
			cin >> X[n] >> Y[n];
		}
		myMin = 1000000000;
		backtrack(0, 0);
		printf("%.8lf\n", myMin);
	}

	return 0;
}


/*
boj_14891_톱니바퀴(난이도 : 실버1)
시뮬레이션 문제
톱니바퀴의 회전을 bit연산을 통해 구현하여 구현
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

int gear[5];
int K;

int ccw(int src) {
	int temp = (1 << 7) & src;
	src = src << 1;
	src -= (temp << 1);
	src += (temp >> 7);

	return src;
}

int cw(int src) {
	int temp = (1 << 0) & src;
	src = src >> 1;
	src += (temp << 7);

	return src;
}

int getValue(int place, int src) {
	if (src & (1 << place)) return 1;
	else return 0;
}

bool isDone(int a, int b) {
	int a_3 = getValue(5, gear[a]);
	int b_9 = getValue(1, gear[b]);
	if (a_3 != b_9) {
		return true;
	}
	return false;
}

void task(int start, int d) {
	int v[5] = { 0,0,0,0,0 };
	v[start] = d;

	for (int i = start; i >= 1; i--) {
		if (isDone(i - 1, i)) {
			v[i - 1] = v[i] * -1;
		}
		else continue;
	}

	for (int i = start; i <= 3; i++) {
		if (isDone(i, i + 1)) {
			v[i + 1] = v[i] * -1;
		}
		else continue;
	}

	for (int i = 1; i <= 4; i++) {
		if (v[i] == 0) continue;
		if (v[i] == 1) gear[i] = cw(gear[i]);
		else gear[i] = ccw(gear[i]);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	char str[10];
	for (int n = 1; n <= 4; n++) {
		cin >> str;
		for (int i = 0; i < 8; i++) {
			if (str[i] == '1')
				gear[n] += (1 << (7 - i));
		}
	}

	cin >> K;
	int now, d;
	for (int k = 1; k <= K; k++) {
		cin >> now >> d;
		task(now, d);
	}

	int result = getValue(7, gear[1]) + 2 * getValue(7, gear[2]) + 4 * getValue(7, gear[3]) + 8 * getValue(7, gear[4]);
	cout << result << "\n";

	return 0;
}


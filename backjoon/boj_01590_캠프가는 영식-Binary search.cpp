/*
boj_1590_캠프가는 영식(난이도 : 골드5)
Binary search
최초 버스의 출발 시간과, 버스의 배차 간격이 주어지면
이진탐색으로 가장 가까운 버스 시간을 구할 수 있음
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

typedef struct bus {
	int start, gap, num;
}Bus;
int N, T;
Bus arr[100000];

ll INF = LLONG_MAX;
ll myMin = 0;
void binSearch(ll base, ll gap, int i, int j) {
	if (i > j) return;

	int mid = (i + j) >> 1;
	ll temp = base + gap * mid;
	if (temp == T) {
		myMin = 0;
	}
	else {
		if (temp > T) {
			myMin = min(myMin, abs(temp - T));
			binSearch(base, gap, i, mid - 1);
		}
		else {
			binSearch(base, gap, mid + 1, j);
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> T;
	int a, b, c;
	for (int i = 0; i < N; i++) {
		cin >> a >> b >> c;
		arr[i] = { a,b,c - 1 };
	}

	ll rst = INF;
	for (int i = 0; i < N; i++) {
		myMin = INF;
		binSearch(arr[i].start, arr[i].gap, 0, arr[i].num);
		rst = min(myMin, rst);
	}

	if (rst == INF) {
		cout << "-1\n";
	}
	else {
		cout << rst << "\n";
	}

	return 0;
}



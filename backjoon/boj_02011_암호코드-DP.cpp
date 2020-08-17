/*
boj_2011_암호코드(난이도 : 실버1)
Topdown DP
문자열을 1개 또는 2개씩 잘라가며
Topdown을 통해
경우의 수 탐색
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

ll dist[5000];
int mod = 1000000;
int N;
int NONE = -1000;
string pwd;

ll topdown(int pos) {
	ll& ref = dist[pos];
	if (ref != -1) return dist[pos];

	ll rst = -1;
	ll left = NONE;
	if (pos < N - 1 && pwd[pos] != '0') {
		left = topdown(pos + 1);
	}
	else if (pos == N - 1) {
		if (pwd[pos] != '0') left = 1;
	}
	ll right = NONE;
	if (pos < N - 1) {
		string temp = "";
		temp += pwd[pos];
		temp += pwd[pos + 1];
		int num = stoi(temp);
		if (num >= 10 && num <= 26) {
			if (pos + 2 == N) {
				right = 1;
			}
			else {
				right = topdown(pos + 2);
			}
		}
	}
	if (left == NONE && right == NONE)
		return NONE;
	else if (left == NONE) {
		return ref = right;
	}
	else if (right == NONE) {
		return ref = left;
	}
	else {
		return ref = (left + right) % mod;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> pwd;
	N = pwd.size();
	for (int n = 0; n < N; n++) {
		dist[n] = -1;
	}

	ll rst = topdown(0);
	if (rst == NONE) {
		cout << 0 << "\n";
	}
	else {
		cout << rst << "\n";
	}

	return 0;
}



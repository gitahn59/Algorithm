/*
boj_2239_스도쿠(난이도 : 골드4)
백트랙킹
스도쿠 조건 검사만 잘 짜면 됨
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

int arr[10][10];
ii candidate[81];
int cnt = 0;

bool checkRow(int h, int num) {
	for (int k = 1; k <= 9; k++) {
		if (arr[h][k] == num) return false;
	}
	return true;
}

bool checkCal(int w, int num) {
	for (int k = 1; k <= 9; k++) {
		if (arr[k][w] == num) return false;
	}
	return true;
}

bool checkBox(int h, int w, int num) {
	ii row = { (h + 2) / 3 * 3 - 2, (h + 2) / 3 * 3 };
	ii cal = { (w + 2) / 3 * 3 - 2, (w + 2) / 3 * 3 };

	for (int i = row.first; i <= row.second; i++) {
		for (int j = cal.first; j <= cal.second; j++) {
			if (arr[i][j] == num) return false;
		}
	}
	return true;
}

void myPrint() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			cout << arr[i][j];
		}
		cout << "\n";
	}
}

bool backtrack(int now) {
	if (now == cnt + 1) {
		myPrint();
		return true;
	}

	for (int i = 1; i <= 9; i++) {
		if (checkRow(candidate[now].first, i) &&
			checkCal(candidate[now].second, i) &&
			checkBox(candidate[now].first, candidate[now].second, i))
		{
			arr[candidate[now].first][candidate[now].second] = i;
			if (backtrack(now + 1)) return true;
			arr[candidate[now].first][candidate[now].second] = 0;
		}
	}

	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	char str[15];

	for (int i = 1; i <= 9; i++) {
		cin >> str + 1;
		for (int j = 1; j <= 9; j++) {
			arr[i][j] = str[j] - '0';
			if (arr[i][j] == 0) {
				candidate[++cnt] = { i,j };
			}
		}
	}

	backtrack(1);

	return 0;
}



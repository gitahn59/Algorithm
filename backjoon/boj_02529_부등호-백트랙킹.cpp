/*
boj_2529_부등호(난이도 : 실버2)
기본적인 백트랙킹
used 배열을 통해 최소로 탐색
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

int K;

char arr[10];
int selected[11];
bool used[10];

string myMax = "";
string myMin = "";

void backtrack(int now) {
	if (now == K + 1) {
		string result = "";
		for (int i = 1; i <= K + 1; i++) {
			result += ('0' + selected[i]);
		}
		myMax = max(myMax, result);
		myMin = min(myMin, result);
		return;
	}

	if (arr[now] == '>') {
		for (int i = 0; i < selected[now]; i++) {
			if (used[i]) continue;
			selected[now + 1] = i;
			used[i] = 1;
			backtrack(now + 1);
			used[i] = 0;
		}
	}
	else if (arr[now] == '<') {
		for (int i = selected[now] + 1; i <= 9; i++) {
			if (used[i]) continue;
			selected[now + 1] = i;
			used[i] = 1;
			backtrack(now + 1);
			used[i] = 0;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> K;

	char str[5];
	for (int k = 1; k <= K; k++) {
		cin >> str;
		arr[k] = str[0];
		myMax += "0";
		myMin += "9";
	}

	for (int i = 0; i <= 9; i++) {
		selected[1] = i;
		used[i] = 1;
		backtrack(1);
		used[i] = 0;
	}

	cout << myMax << "\n";
	cout << myMin << "\n";
	return 0;
}

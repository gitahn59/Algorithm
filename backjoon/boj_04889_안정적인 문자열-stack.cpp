/*
boj_4889_안정적인 문자열(난이도 : 실버1)
괄호 짝 맞추기
1. 짝이 맞는 괄호짝 제거
2. 두 개씩 비교해서 같은 괄호면 +1, 다른 괄호면 +2
다른 괄호일때 +2인 이유는 항상 )( 이기 때문임
단계 1에서 () 는 전부 제거되었기 때문
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

int solve(string str) {
	if (str == "") return 0;
	string rst = "";

	stack<char> sc;
	for (char c : str) {
		if (c == '{') sc.push(c);
		else {
			if (sc.empty()) sc.push(c);
			else if (sc.top() == '{') sc.pop();
			else sc.push(c);
		}
	}

	if (sc.empty()) return 0;


	int num = 0;
	while (!sc.empty()) {
		char b = sc.top(); sc.pop();
		char a = sc.top(); sc.pop();
		if (a == b) num += 1;
		else num += 2;
	}

	return num;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int t = 1; true; t++) {
		string str;
		cin >> str;
		if (str[0] == '-') break;
		cout << t << ". " << solve(str) << "\n";
	}

	return 0;
}

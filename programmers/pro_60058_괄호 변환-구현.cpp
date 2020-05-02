/*
pro_60058_괄호 변환(난이도 : level 2)
구현
주어진 알고리즘을 따라 구현
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

bool isRight(string s) {
	stack<char> sc;
	for (char c : s) {
		if (c == '(') sc.push(c);
		else {
			if (sc.empty()) return false;
			if (sc.top() == '(') sc.pop();
			else return false;
		}
	}
	return true;
}

string solve(string str) {
	if (str == "") return "";

	int l = 0, r = 0;
	int cnt = 0;
	for (char c : str) {
		if (c == '(') l++;
		else r++;
		if (l == r) {
			break;
		}
		cnt++;
	}

	string u = str.substr(0, cnt + 1);
	string v = str.substr(cnt + 1, str.size());
	if (isRight(u)) {
		return u + solve(v);
	}
	else {
		string rst = "(";
		rst += solve(v);
		rst += ")";

		string rv;
		for (int i = 1; i < u.size() - 1; i++) {
			if (u[i] == '(') rv += ')';
			else rv += '(';
		}
		return rst + rv;
	}
}

string solution(string p) {
	string answer = solve(p);
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution(")(");

	return 0;
}

/*
boj_17255_N으로 만들기(난이도 : 골드5)
DP
Topdown DP와 Tree Map를 이용해
중복검사
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

string N;
map<string, ll> m;

ll topdown(string num) {
	if (m[num] != 0) return m[num];
	if (num.size() == 1) {
		return m[num] = 1;
	}

	string a = num.substr(1, num.size() - 1);
	string b = num.substr(0, num.size() - 1);

	if (a == b) {
		return m[num] = topdown(a);
	}
	else {
		return m[num] = topdown(a) + topdown(b);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	cout << topdown(N) << "\n";

	return 0;
}



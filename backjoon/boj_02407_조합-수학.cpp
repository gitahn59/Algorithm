/*
boj_2407_조합(난이도 : 실버1)
조합, 큰수
string을 이용한 큰수 연산
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

string mem[101][51];

string add(string a, string b) {
	if (a.length() > b.length()) swap(a, b);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());

	int c = 0, s = 0;
	string rst = "";
	for (int i = 0; i < a.size(); i++) {
		int l = a[i] - '0';
		int r = b[i] - '0';
		s = l + r + c;
		c = s / 10;
		rst += '0' + (s % 10);
	}

	for (int i = a.size(); i < b.size(); i++) {
		int l = b[i] - '0';
		s = l + c;
		c = s / 10;
		rst += '0' + (s % 10);
	}

	if (c != 0) rst += '0' + c;
	reverse(rst.begin(), rst.end());
	return rst;
}

string topdown(int n, int m) {
	if (n - m < m) m = n - m;
	string& ref = mem[n][m];
	if (ref != "") return ref;

	if (m == 1) return ref = to_string(n);

	string left = topdown(n - 1, m - 1);
	string right = topdown(n - 1, m);
	return ref = add(left, right);
}

int N, M;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M;
	cout << topdown(N, M) << "\n";

	return 0;
}


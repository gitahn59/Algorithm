/*
pro_17684_압축(난이도 : level 2)
구현
수도코드에 맞추어 그대로 구현
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

typedef map<string, int> msi;

string MSG;

vi solve() {
	vi rst;

	int N = MSG.size() - 1;
	msi m;
	m[""] = -1;
	for (int i = 0; i < 26; i++) {
		string s;
		s += ('A' + i);
		m[s] = i + 1;
	}

	int idx = 26;

	for (int n = 1; n <= N;) {
		int i = m[MSG.substr(n, N)];
		if (i != 0) {
			rst.push_back(i);
			break;
		}
		string pre, next;
		int len = 1;
		for (; len + n - 1 <= N; len++) {
			next = MSG.substr(n, len);
			if (m[next] != 0) {
				pre = next;
			}
			else {
				m[next] = ++idx;
				break;
			}
		}
		n += pre.size();
		rst.push_back(m[pre]);
	}

	return rst;
}

vector<int> solution(string msg) {
	MSG = ' ' + msg;
	vector<int> answer = solve();
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution("KAKAO");

	return 0;
}

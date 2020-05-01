/*
boj_2800_괄호 제거(난이도 : 골드5)
문자열, 스택, 비트마스킹
스택을 이용해 각 괄호의 짝과 위치를 판별하고
비트마스킹을 통해 괄호 쌍의 조합으로
적합한 문자열을 구하는 문제
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

char str[210];
int N;
ii pos[11];
int cnt;
vector<string> vs;
string src;

void solve(int num) {
	char temp[210];
	memset(temp, 0, sizeof(temp));

	for (int c = 1; c <= cnt; c++) {
		if (num & (1 << c)) {
			temp[pos[c].first] = '(';
			temp[pos[c].second] = ')';
		}
	}

	string rst;
	for (int n = 1; n <= N; n++) {
		if (str[n] != 0) rst += str[n];
		if (temp[n] != 0) rst += temp[n];
	}

	if (rst == src) return;
	vs.push_back(rst);
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> str + 1;
	N = strlen(str + 1);

	stack<int> s;
	for (int n = 1; n <= N; n++) {
		src += str[n];
		if (str[n] == '(') {
			s.push({ n });
			str[n] = 0;
		}
		else if (str[n] == ')') {
			int idx = s.top();
			s.pop();
			pos[++cnt] = { idx,n };
			str[n] = 0;
		}
	}

	int end = (1 << (cnt + 1)) - 1;
	for (int num = 0; num <= end; num++) {
		solve(num);
	}

	sort(vs.begin(), vs.end());
	auto it = unique(vs.begin(), vs.end());
	for (auto i = vs.begin(); i != it; i++) {
		cout << *i << "\n";
	}


	return 0;
}

/*
boj_2800_��ȣ ����(���̵� : ���5)
���ڿ�, ����, ��Ʈ����ŷ
������ �̿��� �� ��ȣ�� ¦�� ��ġ�� �Ǻ��ϰ�
��Ʈ����ŷ�� ���� ��ȣ ���� ��������
������ ���ڿ��� ���ϴ� ����
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

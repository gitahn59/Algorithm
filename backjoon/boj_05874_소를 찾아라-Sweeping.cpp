/*
boj_5874_�Ҹ� ã�ƶ�(���̵� : �ǹ�5)
Sweeping
head�� tail�� �ĺ��� ���� Ž���Ͽ�
tail�� �������� lower_bound�� head�� Ž���Ͽ�
������ �ĺ��� ���� Ž��
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
typedef deque<int> di;
typedef pair<int, ii> iii;
typedef set<int> si;

int N;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string str;
	cin >> str;
	N = str.length();

	vi head, tail;

	for (int n = 0; n < N - 1; n++) {
		if (str[n] == str[n + 1] && str[n + 1] == ')') {
			head.push_back(n);
		}
	}

	for (int n = 0; n < N - 1; n++) {
		if (str[n] == str[n + 1] && str[n + 1] == '(') {
			tail.push_back(n + 1);
		}
	}

	ll rst = 0;
	for (int now : tail) {
		auto it = lower_bound(head.begin(), head.end(), now + 1);
		int len = head.end() - it;
		rst += len;
	}

	cout << rst << "\n";

	return 0;
}



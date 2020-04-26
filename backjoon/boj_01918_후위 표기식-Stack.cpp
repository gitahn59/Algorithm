/*
boj_1918_���� ǥ���(���̵� : ���4)
stack
stack�� �̿��� ���� ǥ����� ����ǥ������� ��ȯ�ϴ� ����

�����ڰ� �켱������ ����Ͽ�
�켱������ �������� ���� ���ÿ��� �������� �����ؾ� ��
���� �켱������ ���� �� �ִ� �����ڰ� ����
���� top�� ������ �켱������ �� ���ų� ������ �̸� ���ְ�
������ ���� ���� �÷� �� ���� pop �ǵ��� �ؾ���

(, )�� (�� ���� ���� �켱������ �ο��ϰ�
(�� �켱���� �� ���� ������ ���ÿ� �ֵ��� �ϰ�
)�� ���ö����� ���������� �ʵ��� �ؾ� ��
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

string str;

int priority(char c) {
	if (c == '(') return 0;
	else if (c == '+' || c == '-') return 1;
	else if (c == '*' || c == '/') return 2;
}

string solve() {
	string rst = "";
	stack<char> sc;
	for (char c : str) {
		if ('A' <= c && c <= 'Z') {
			rst += c;
			continue;
		}

		switch (c) {
		case '(':
			sc.push(c);
			break;
		case ')':
			while (sc.top() != '(') {
				rst += sc.top();
				sc.pop();
			}
			sc.pop();
			break;
		default:
			while (!sc.empty()) {
				int p = priority(sc.top());
				if (p < priority(c)) {
					break;
				}
				else {
					rst += sc.top();
					sc.pop();
				}
			}
			sc.push(c);
			break;
		}
	}

	while (!sc.empty()) {
		rst += sc.top();
		sc.pop();
	}

	return rst;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> str;
	cout << solve() << "\n";

	return 0;
}



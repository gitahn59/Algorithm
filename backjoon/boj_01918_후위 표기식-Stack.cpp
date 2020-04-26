/*
boj_1918_후위 표기식(난이도 : 골드4)
stack
stack을 이용해 중위 표기식을 후위표기식으로 변환하는 문제

연산자간 우선순위를 고려하여
우선순위가 높을수록 먼저 스택에서 나오도록 설계해야 함
동일 우선순위는 먼저 들어가 있는 연산자가 높음
따라서 top의 연산자 우선순위가 더 높거나 같으면 미리 빼주고
낮으면 스택 위에 올려 더 먼저 pop 되도록 해야함

(, )는 (가 가장 낮은 우선순위를 부여하고
(는 우선순위 비교 없이 무조건 스택에 넣도록 하고
)가 나올때까지 빠져나오지 않도록 해야 함
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



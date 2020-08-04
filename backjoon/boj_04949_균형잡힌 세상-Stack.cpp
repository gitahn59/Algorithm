/*
boj_4949_균형잡힌 세상(난이도 : 실버4)
Stack
괄호 검사
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

bool task(char* str) {
	int len = strlen(str);
	stack<char> s;
	for (int i = 0; i < len; i++) {
		if (str[i] == '(' || str[i] == '[') {
			s.push(str[i]);
		}
		else if (str[i] == ')') {
			if (s.size() != 0 && s.top() == '(') {
				s.pop();
			}
			else {
				s.push('Z');
				break;
			}
		}
		else if (str[i] == ']') {
			if (s.size() != 0 && s.top() == '[') {
				s.pop();
			}
			else {
				s.push('Z');
				break;
			}
		}
	}

	if (s.size() != 0) return 0;
	else return 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	char str[120];
	while (cin.getline(str, 120)) {
		if (str[0] == '.') break;
		if (task(str)) cout << "yes\n";
		else cout << "no\n";

	}

	return 0;
}


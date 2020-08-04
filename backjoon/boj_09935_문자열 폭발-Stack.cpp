/*
boj_9935_문자열 폭발(난이도 : 골드4)
Stack
스택을 이용하여 O(N*M) 시간에 탐색하는 문제
폭발 문자열에는 같은 문자가 반복되지 않으므로
폭발 문자열의 중첩에 의한 동시 폭발이 일어나지 않으므로 순차적인
확인이 가능하다
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


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string l, r;
	cin >> l >> r;
	reverse(r.begin(), r.end());
	int N = l.size();
	int M = r.size();

	stack<char> s;
	for (char c : l) {
		s.push(c);
		if (c == r[0] && s.size() >= M) {
			stack<char> temp;
			int i = 0;
			for (; i < M; i++) {
				if (s.top() == r[i]) {
					temp.push(r[i]);
					s.pop();
				}
				else {
					break;
				}
			}
			if (i == M) continue;
			while (!temp.empty()) {
				s.push(temp.top());
				temp.pop();
			}
		}
	}

	vector<char> vc;
	while (!s.empty()) {
		vc.push_back(s.top());
		s.pop();
	}
	reverse(vc.begin(), vc.end());
	if (vc.size() == 0) {
		cout << "FRULA\n";
	}
	else {
		for (char c : vc) {
			cout << c;
		}
		cout << "\n";
	}

	return 0;
}


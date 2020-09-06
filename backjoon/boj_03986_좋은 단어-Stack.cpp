/*
boj_3986_좋은 단어(난이도 : 실버4)
Stack
스택을 사용하여 단어 짝 확인
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

int N;
string str;
int judge() {
	stack<char> s;
	for (char c : str) {
		if (s.empty()) s.push(c);
		else {
			if (s.top() == c) s.pop();
			else s.push(c);
		}
	}

	if (s.size() == 0) return 1;
	else return 0;
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int cnt = 0;
	for (int n = 0; n < N; n++) {
		cin >> str;
		if (str.size() % 2 == 0)
			cnt += judge();
	}

	cout << cnt << "\n";

	return 0;
}



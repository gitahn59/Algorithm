/*
pro_17682_다트 게임(난이도 : level 2) 
문자열 파싱
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

int score[4];
string opt[4];

int trans(char c) {
	if (c == 'S') {
		return 1;
	}
	else if (c == 'D') {
		return 2;
	}
	else {
		return 3;
	}
}

int bonus(char c) {
	if (c == '#') {
		return -1;
	}
	else {
		return 2;
	}
}

ll getSum() {
	ll a = pow((double)score[1], (double)trans(opt[1][0]));
	if (opt[1].length() == 2) {
		a *= bonus(opt[1][1]);
	}

	ll b = pow((double)score[2], (double)trans(opt[2][0]));
	if (opt[2].length() == 2) {
		int bns = bonus(opt[2][1]);
		b *= bns;
		if (bns == 2) {
			a *= 2;
		}
	}

	ll c = pow((double)score[3], (double)trans(opt[3][0]));
	if (opt[3].length() == 2) {
		int bns = bonus(opt[3][1]);
		c *= bns;
		if (bns == 2) {
			b *= 2;
		}
	}
	return a + b + c;
}

int solution(string dartResult) {
	char str[100];
	strcpy(str, dartResult.c_str());

	int i = 1;
	char* p = strtok(str, "0123456789");
	while (p != NULL) {
		string s(p);
		opt[i++] = s;
		p = strtok(NULL, "0123456789");
	}

	strcpy(str, dartResult.c_str());
	i = 1;
	p = strtok(str, "SDT#*");
	while (p != NULL) {
		score[i++] = stoi(p);
		p = strtok(NULL, "SDT#*");
	}

	int answer = getSum();
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution("1S2D*3T");

	return 0;
}

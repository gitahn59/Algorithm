/*
boj_6581_HTML(난이도 : 실버1)
문자열
기본적인 문자열 처리 문제
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

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> LL;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;

typedef vector<string> vs;

int idx;
int LIMIT = 80;

void print(string word) {
	if (word == "<br>") {
		idx = 0;
		cout << "\n";
	}
	else if (word == "<hr>") {
		if (idx != 0) {
			cout << "\n";
			idx = 0;
		}
		for (int i = 0; i < LIMIT; i++) {
			cout << "-";
		}
		cout << "\n";
	}
	else {
		if (idx == 0) {
			cout << word;
			idx = word.size();
		}
		else {
			if (idx + 1 + word.size() <= LIMIT) {
				idx = idx + 1 + word.size();
				cout << " " << word;
				if (idx == LIMIT) {
					cout << "\n";
					idx = 0;
				}
			}
			else {
				cout << "\n" << word;
				idx = word.size();
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	string word;
	while (cin >> word) {
		print(word);
	}
	cout << "\n";

	return 0;
}
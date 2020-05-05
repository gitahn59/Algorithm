/*
pro_17683_방금그곡(난이도 : level2)
문자열
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

int N;

string trans(string music) {
	string rst;
	for (char c : music) {
		if (c == '#') {
			rst.back() = rst.back() - 'A' + 'a';
		}
		else rst += c;
	}
	return rst;
}

int timetrans(char* ts) {
	int sum = 0;
	char* p = strtok(ts, ":");
	sum += stoi(p) * 60;
	p = strtok(NULL, ":");
	sum += stoi(p);
	return sum;
}

typedef struct node {
	int t;
	string name, code;

	node(string music) {
		char cstr[3000];
		strcpy(cstr + 1, music.c_str());
		char* ts = strtok(cstr + 1, ",");
		char* te = strtok(NULL, ",");
		name = strtok(NULL, ",");
		code = strtok(NULL, ",");
		code = trans(code);
		t = timetrans(te) - timetrans(ts);

		if (t > code.size()) {
			int cdsize = code.size();
			int l = t / cdsize;
			int r = t % cdsize;

			string rst;
			for (int i = 1; i <= l; i++) {
				rst += code;
			}
			if (r != 0) {
				rst += code.substr(0, r);
			}
			code = rst;
		}
		else if (t < code.size()) {
			code = code.substr(0, t);
		}
	}
}Node;

string solution(string m, vector<string> musicinfos) {
	N = musicinfos.size();
	m = trans(m);
	vector<Node> vn;
	for (int n = 0; n < N; n++) {
		vn.push_back(Node(musicinfos[n]));
	}

	int t = 0;
	string rst = "(None)";
	for (int n = 0; n < N; n++) {
		if (m.size() > vn[n].code.size()) continue;
		int idx = vn[n].code.find(m);
		if (idx >= 0) {
			if (t < vn[n].t) {
				rst = vn[n].name;
				t = vn[n].t;
			}
		}
	}

	return rst;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution("CC#BCC#BCC#BCC#B", { "00:00,00:59,FOO,CC#B", "04:00,04:08,BAR,CC#BCC#BCC#B" });

	return 0;
}

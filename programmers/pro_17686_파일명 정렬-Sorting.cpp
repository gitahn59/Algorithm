/*
pro_17686_파일명 정렬(난이도 : level 2)
정렬
제공된 수도코드에 따라 정렬 알고리즘 구현
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

typedef struct node {
	string head, tail;
	int num;
}Node;

Node make(string str) {
	Node node;
	char cstr[110];
	char num[110];
	strcpy(cstr + 1, str.c_str());
	for (int n = 1; n <= str.size(); n++) {
		if ('A' <= cstr[n] && cstr[n] <= 'Z') {
			cstr[n] = cstr[n] - 'A' + 'a';
		}
	}
	strcpy(num + 1, cstr + 1);
	char* h = strtok(cstr + 1, "012345678910");
	string head(h);
	node.head = head;

	char* nbr = strtok(num + 1, "abcdefghijklmnopqrstuvwxyz- .");
	node.num = stoi(nbr);
	node.tail = str.substr(head.size() + strlen(nbr), str.size());
	return node;
}

bool myCmp(string a, string b) {
	Node l = make(a);
	Node r = make(b);

	if (l.head == r.head) {
		return l.num < r.num;
	}
	else return l.head < r.head;
	return true;
}

vector<string> solution(vector<string> files) {
	vector<string> answer;
	stable_sort(files.begin(), files.end(), myCmp);
	return files;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution({ "img12bar20.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" });

	return 0;
}

/*
pro_17677_뉴스 클러스터링(난이도 : level2)
map
필요없는 문자는 버리고 
교집합, 합집합의 크기를 구하여
조건에 맞는 답을 구함
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

typedef map<string, int> msi;

void parse(string src, msi& m) {
	for (int i = 0; i < src.size() - 1; i++) {
		string s;
		char c = src[i];
		if ('A' <= c && c <= 'Z') s += (c - 'A' + 'a');
		else if ('a' <= c && c <= 'z') s += c;
		else continue;

		c = src[i + 1];
		if ('A' <= c && c <= 'Z') s += (c - 'A' + 'a');
		else if ('a' <= c && c <= 'z') s += c;
		else continue;

		m[s]++;
	}
}

int intersection(msi& a, msi& b) {
	int sum = 0;
	for (auto i : a) {
		int l = i.second;
		int r = b[i.first];
		sum += min(l, r);
	}
	return sum;
}

int unionset(msi& a, msi& b) {
	msi temp;
	int sum = 0;
	for (auto i : a) {
		temp[i.first] = i.second;
	}
	for (auto i : b) {
		temp[i.first] = max(i.second, temp[i.first]);
	}

	for (auto i : temp) {
		sum += i.second;
	}

	return sum;
}

int solution(string str1, string str2) {
	msi left;
	parse(str1, left);
	msi right;
	parse(str2, right);

	if (left.size() == 0 && right.size() == 0) return 65536;
	double i = intersection(left, right);
	double u = unionset(left, right);

	int answer = (i / u * 65536);
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution("FRANCE", "french");

	return 0;
}

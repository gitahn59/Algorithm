/*
pro_60057_���ڿ� ����(���̵� : level 2)
���� Ž��
������ ũ�Ⱑ �۾� ���� Ž�� ����

���̰� n �ΰ�쿡
���ڿ��� ���� n���� �ڸ��� ���� ���� Ȯ��
�̸� �� 1~N �� �ݺ��Ͽ� �ּڰ� Ž��
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
string str;

int compress(int size) {
	vector<string> vs;
	for (int i = 0; i < str.size(); i += size) {
		string s;
		for (int j = i; j <= i + size - 1 && j < str.size(); j++) {
			s += str[j];
		}
		vs.push_back(s);
	}

	string rst;
	int cnt = 1;
	string pre = vs[0];
	for (int i = 1; i < vs.size(); i++) {
		if (pre == vs[i]) cnt++;
		else {
			if (cnt == 1) rst += pre;
			else rst += to_string(cnt) + pre;
			cnt = 1;
			pre = vs[i];
		}
	}
	if (cnt == 1) rst += pre;
	else rst += to_string(cnt) + pre;

	return rst.size();
}

int solution(string s) {
	N = s.size();
	str = s;

	int myMin = N;
	for (int n = 1; n <= N; n++) {
		myMin = min(myMin, compress(n));
	}
	return myMin;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution("aabbaccc");

	return 0;
}

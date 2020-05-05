/*
pro_17687_n진수 게임(난이도 : level2)
수학
n진법을 변환해서 배열에 기록하고
순서대로 꺼내옴
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

int N, T, M, P;

vi trans(int num) {
	vi rst;
	while (num >= N) {
		rst.push_back(num % N);
		num /= N;
	}
	rst.push_back(num);

	reverse(rst.begin(), rst.end());
	return rst;
}

string solve() {
	vi rst;
	for (int num = 0;; num++) {
		vi temp = trans(num);
		rst.insert(rst.end(), temp.begin(), temp.end());
		if (rst.size() >= (M * T)) break;
	}

	string str;
	for (int i = P;; i += M) {
		int ref = rst[i - 1];
		if (0 <= ref && ref < 10) {
			str += (ref + '0');
		}
		else {
			str += (ref - 10 + 'A');
		}
		if (str.length() == T) break;
	}

	return str;
}


string solution(int n, int t, int m, int p) {
	N = n, T = t, M = m, P = p;

	string answer = solve();
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution(16, 16, 2, 1);

	return 0;
}

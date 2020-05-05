/*
pro_17681_비밀지도(난이도 : level2)
bitmask
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
int myMap[17][17];

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	N = n;
	for (int n = 0; n < N; n++) {
		for (int i = 0; i < N; i++) {
			if (arr1[n] & (1 << i)) {
				myMap[n][i] = 1;
			}
		}
	}

	for (int n = 0; n < N; n++) {
		for (int i = 0; i < N; i++) {
			if (arr2[n] & (1 << i)) {
				myMap[n][i] = 1;
			}
		}
	}

	vector<string> answer;
	for (int n = 0; n < N; n++) {
		string rst;
		for (int i = 0; i < N; i++) {
			if (myMap[n][i] == 1) rst = '#' + rst;
			else rst = ' ' + rst;
		}
		answer.push_back(rst);
	}

	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	solution(5, { 9,20,28,18,11 }, { 30, 1, 21, 17, 28 });

	return 0;
}

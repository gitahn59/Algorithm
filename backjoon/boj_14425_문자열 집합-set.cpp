/*
boj_14425_문자열 집합(난이도 : 실버3)
set 자료구조
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

set<string> ss;
int N, M;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	string str;
	for (int n = 1; n <= N; n++) {
		cin >> str;
		ss.insert(str);
	}

	int cnt = 0;
	for (int m = 1; m <= M; m++) {
		cin >> str;
		auto it = ss.find(str);
		if (it != ss.end()) cnt++;
	}

	cout << cnt << "\n";

	return 0;
}

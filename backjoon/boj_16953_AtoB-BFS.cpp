/*
boj_16953_ A to B(난이도 : 실버1)
BFS
BFS와 비슷하게 loop를 구성하여
조건에 맞는 값만 검사
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
#include <climits>

#define PRIME 1000000007
#define mp make_pair

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

ll A, B;
vll	now[33];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B;
	now[1].push_back(A);

	int rst = -1;
	for (int t = 1; t <= 29; t++) {
		for (ll num : now[t]) {
			ll l = num << 1;
			if (l < B) {
				now[t + 1].push_back(l);
			}
			else if (l == B) {
				rst = t + 1;
				t = 100;
				break;
			}
			ll r = num * 10 + 1;
			if (r < B) {
				now[t + 1].push_back(r);
			}
			else if (r == B) {
				rst = t + 1;
				t = 100;
				break;
			}
		}
	}

	cout << rst << "\n";

	return 0;
}


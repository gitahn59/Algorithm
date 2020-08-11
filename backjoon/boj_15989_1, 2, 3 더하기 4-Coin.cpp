/*
boj_15989_1, 2, 3 더하기 4(난이도 : 실버 1)
Coin
기본적인 DP Coin 교환 문제
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

int N;
int dist[10001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	dist[0] = 1;

	for (int n = 1; n <= 3; n++) {
		for (int i = n; i <= 10000; i++) {
			int pre = i - n;
			if (dist[pre]) {
				dist[i] += dist[pre];
			}
		}
	}

	int tag;
	for (int n = 1; n <= N; n++) {
		cin >> tag;
		cout << dist[tag] << "\n";
	}

	return 0;
}



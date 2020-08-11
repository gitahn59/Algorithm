/*
boj_15486_퇴사 2(난이도 : 실버 1)
Bottom UP Dp
기본적인 Bottom UP DP 문제
현재 시간에 가능한 최대값을 계속
갱신하면 됨
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
int dist[1500001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int t, p;
	int rst = 0;
	for (int n = 1; n <= N; n++) {
		cin >> t >> p;
		int last = n + t - 1;
		if (last > N) {
			rst = max(rst, dist[n]);
			continue;
		}
		dist[last] = max(rst + p, dist[last]);
		rst = max(rst, dist[n]);
	}

	cout << rst << "\n";

	return 0;
}


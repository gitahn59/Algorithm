/*
boj_11058_크리보드(난이도 : 실버1)
Bottom Up Dp
1. Ctrl-V를 하기위해서는 n-3번째에서부터
선택 및 복사를 하고, n번째에 사용할 수 있다.
=> 복사는 dist[n-3]개를 복사

2. 복사를 하고 나면 n+1 부터는 바로 사용할 수 있다
=> i=n부터 i<=N 까지 미리 값 계산

따라서 이 2가지 성질을 이용하여 Bottom UP DP를 구성하면
O(n^2) 시간의 시간복잡도를 가지며
최대 N = 100이므로 제한시간을 만족한다.
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
ll dist[101];
int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 0; n <= N; n++) dist[n] = -1;

	dist[1] = 1;
	dist[2] = 2;
	dist[3] = 3;
	for (int n = 4; n <= N; n++) {
		dist[n] = max(dist[n], dist[n - 1] + 1);
		ll temp = dist[n - 3];
		int j = 1;
		for (int i = n; i <= N; i++, j++) {
			dist[i] = max(dist[i], dist[n - 3] + temp * j);
		}
	}

	cout << dist[N] << "\n";

	return 0;
}



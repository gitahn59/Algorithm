/*
boj_12849_본대 산책(난이도 : 실버1)
dp
특이한 형태의 dp
고정된 그래프에서
topdown이나 bottom 형태가 아닌
노드마다 경로 개수를 기억해두고
이전 노드의 경로의 방법이 아닌, 개수에만 초점을 두고
dp를 계산
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

int prime = 1000000007;
ll dp[8];
ll temp[8];
int D;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> D;

	//base
	dp[1] = 1;
	dp[3] = 1;
	for (int d = 2; d <= D; d++) {
		temp[0] = (dp[1] + dp[3]) % prime;
		temp[1] = (dp[0] + dp[2] + dp[3]) % prime;
		temp[2] = (dp[1] + dp[3] + dp[4] + dp[5]) % prime;
		temp[3] = (dp[0] + dp[1] + dp[2] + dp[5]) % prime;
		temp[4] = (dp[2] + dp[5] + dp[6]) % prime;
		temp[5] = (dp[2] + dp[3] + dp[4] + dp[7]) % prime;
		temp[6] = (dp[4] + dp[7]) % prime;
		temp[7] = (dp[5] + dp[6]) % prime;
		for (int n = 0; n < 8; n++) {
			dp[n] = temp[n];
		}
	}
	cout << dp[0] << "\n";

	return 0;
}


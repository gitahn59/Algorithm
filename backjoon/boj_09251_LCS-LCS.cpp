/*
boj_9251_LCS(난이도 : 골드5)
LCS 
두 문자열에 대해 테이블을 구성하여 최장공통 수열을 찾는 알고리즘

n,m 에 대하여 

h[n] == l[m]이면
table(n,m) = table(n-1,m-1) +1
다르면
table(n,m) = max(table(n-1,m), table(n,m-1))
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

int N, M;
char h[1010], w[1010];
int arr[1010][1010];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> h + 1 >> w + 1;
	N = strlen(h + 1);
	M = strlen(w + 1);

	int myMax = 0;
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			if (h[n] == w[m]) {
				arr[n][m] = arr[n - 1][m - 1] + 1;
			}
			else {
				arr[n][m] = max(arr[n - 1][m], arr[n][m - 1]);
			}
			myMax = max(myMax, arr[n][m]);
		}
	}

	cout << myMax << "\n";

	return 0;
}



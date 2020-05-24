/*
boj_9252_LCS 2(난이도 : 골드5)
LCS + LCS 출력
boj_9251 참고
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
	ii pos;

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			if (h[n] == w[m]) {
				arr[n][m] = arr[n - 1][m - 1] + 1;
				if (myMax < arr[n][m]) {
					myMax = arr[n][m];
					pos = mp(n, m);
				}
			}
			else {
				arr[n][m] = max(arr[n - 1][m], arr[n][m - 1]);
			}
		}
	}

	cout << myMax << "\n";
	if (myMax == 0) return 0;

	string rst;
	while (true) {
		int& i = pos.first;
		int& j = pos.second;
		if (h[i] == w[j]) {
			rst += h[i];
			i--; j--;
			myMax--;
		}
		else {
			if (arr[i - 1][j] >= arr[i][j - 1]) i--;
			else j--;
		}
		if (myMax == 0) break;
	}
	reverse(rst.begin(), rst.end());
	cout << rst << "\n";
	return 0;
}


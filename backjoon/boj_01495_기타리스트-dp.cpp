/*
boj_1495_기타리스트(난이도 : 실버1)
기본적인 bottom up dp
주의) n번 째 시행에서 적어도 1번만 통과하면 다음 시행을 시도할 수 있음
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

int N, S, M;

int arr[101];
int mem[101][1001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> S >> M;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}

	mem[0][S] = 1;
	for (int n = 1; n <= N; n++) {
		bool flag = false;
		for (int m = 0; m <= M; m++) {
			if (mem[n - 1][m] == 0) continue;
			if (m + arr[n] <= M) {
				mem[n][m + arr[n]] = 1;
				flag = true;
			}
			if (m - arr[n] >= 0) {
				mem[n][m - arr[n]] = 1;
				flag = true;
			}
		}
		if (!flag) {
			cout << "-1\n";
			return 0;
		}
	}

	int myMax = 0;
	for (int m = M; m >= 0; m--) {
		if (mem[N][m] != 0) {
			myMax = m;
			break;
		}
	}

	cout << myMax << "\n";
	return 0;
}

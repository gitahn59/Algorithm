/*
boj_11658_구간 합 구하기3(난이도 : 플레5)
크기가 작아 O(NM)으로 풀리는 누적합 문제
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

int N, M;

int arr[1025][1025];
int brr[1025][1025];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int n = 1; n <= N; n++) {
		brr[n][0] = 0;
	}

	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= N; i++) {
			cin >> arr[n][i];
			brr[n][i] = brr[n][i - 1] + arr[n][i];
		}
	}

	int w, x, y, c, x2, y2;
	for (int m = 1; m <= M; m++) {
		cin >> w;
		if (w == 0) {
			cin >> x >> y >> c;
			int num = c - arr[x][y];
			for (int i = y; i <= N; i++) {
				brr[x][i] += num;
			}
			arr[x][y] = c;
		}
		else {
			cin >> x >> y >> x2 >> y2;
			ll sum = 0;
			if (x > x2) swap(x, x2);
			if (y > y2) swap(y, y2);
			for (int i = x; i <= x2; i++) {
				sum += (brr[i][y2] - brr[i][y - 1]);
			}
			cout << sum << "\n";
		}
	}

	return 0;
}

/*
boj_18111_마인크래프트(난이도 : 실버3)
특정 작업을 통해 모든 구역의 높이를 동일하게 맞추어야 할 때
가장 적은 시간이 걸리는 경우를 찾는 문제

블록의 높이는 최대 257개가 가능하므로
전부 검사하면
257 * 500 * 500 의 시간복잡도를 가짐
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

int N, M, B;
int K;
int arr[500 * 500];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> B;
	K = N * M;
	for (int k = 0; k < K; k++) {
		cin >> arr[k];
	}
	sort(arr, arr + K);

	ll best_time = 300 * 500 * 500 * 2;
	int myMax = 0;

	for (int i = 0; i <= 256; i++) {
		int b = B;
		ll spend = 0;
		for (int k = 0; k < K; k++) {
			int gap = arr[k] - i;
			if (gap == 0) continue;
			else if (gap < 0) { // need to put
				spend += abs(gap);
				b -= abs(gap);
			}
			else { // need to remove
				spend += (gap << 1);
				b += gap;
			}
		}

		if (b >= 0 && best_time >= spend) {
			best_time = spend;
			myMax = i;
		}
	}

	cout << best_time << " " << myMax << "\n";

	return 0;
}



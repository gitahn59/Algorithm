/*
boj_2512_예산 (난이도 : 실버3)
이분탐색
주의) 요청 예산의 합이 국가 예산 보다 작으면
요청 예산중에서 최댓값을 출력해야 함
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

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> LL;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef deque<int> di;
typedef set<int> si;
typedef vector<string> vs;

int N;
int arr[10010];
int M;

bool myCheck(int upper) {
	int sum = 0;
	for (int n = 1; n <= N; n++) {
		sum += min(arr[n], upper);
	}
	if (sum <= M) return true;
	else return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int sum = 0;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
		sum += arr[n];
	}
	sort(arr + 1, arr + 1 + N);
	cin >> M;
	if (M >= sum) {
		cout << arr[N] << "\n";
		return 0;
	}

	int l = 1;
	int r = M;
	int pre;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (myCheck(mid)) {
			pre = mid;
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << pre << "\n";

	return 0;
}
/*
boj_02343_기타레슨(난이도 : 실버 1)
Binary search
임의의 값으로 조건을 통과하는지 검사 O(N)
임의의 값 찾기 O(logN)
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

int N, M;
int arr[100001];

bool isable(int num) {
	int sum = 0;
	int need = 1;
	for (int n = 1; n <= N; n++) {
		if (sum + arr[n] > num) {
			sum = 0;
			need++;
		}
		sum += arr[n];
	}

	if (need <= M) return true;
	return false;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	int sum = 0;
	int myMax = 0;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
		sum += arr[n];
		myMax = max(myMax, arr[n]);
	}

	int l = myMax;
	int r = sum;
	int pre = -1;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (isable(mid)) {
			pre = mid;
			r = mid - 1;
		}
		else {
			l = mid + 1;
		}
	}
	cout << pre << "\n";
	return 0;
}
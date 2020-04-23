/*
boj_02166_다각형의 면적(난이도 : 골드5)
ccw
ccw의 값이 평행사변형의 값임을 이용한
n다각형의 넓이
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
typedef pair<int, ii> iii;
typedef set<int> si;

ll ccw(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3) {
	ll left = x1 * y2 + x2 * y3 + x3 * y1;
	ll right = y1 * x2 + y2 * x3 + y3 * x1;
	return left - right;
}

ii arr[10001];
int N;

int main() {
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		scanf("%d %d", &arr[n].first, &arr[n].second);
	}

	ll sum = 0;
	for (int n = 1; n <= N - 1; n++) {
		sum += ccw(arr[1].first, arr[1].second, arr[n].first, arr[n].second, arr[n + 1].first, arr[n + 1].second);
	}

	sum = abs(sum);
	printf("%.1lf", sum / 2.0);

	return 0;
}


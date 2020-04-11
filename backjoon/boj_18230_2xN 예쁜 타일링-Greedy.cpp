/*
boj_18230_2xN 예쁜 타일링(난이도 : 실버1)
greedy
N이 홀수인 경우, 반드시 A에서 최댓값인 타일은 1개 선정하고
나머지는 greedy하게 탐색
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

int N, A, B;
int arr[2001];
int brr[2001];

ll solve() {
	int a = 1;
	int b = 1;
	ll sum = 0;
	if (N % 2 == 1) {
		sum += arr[a++];
		N--;
	}

	int left, right;
	while (N > 0) {
		if (a + 1 <= A) left = arr[a] + arr[a + 1];
		else left = 0;
		if (b <= B) right = brr[b];
		else right = 0;
		if (left < right) {
			sum += right;
			b++;
		}
		else {
			sum += left;
			a += 2;
		}
		N -= 2;
	}
	return sum;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> A >> B;

	for (int a = 1; a <= A; a++) {
		cin >> arr[a];
	}
	sort(arr + 1, arr + 1 + A, greater<int>());
	for (int b = 1; b <= B; b++) {
		cin >> brr[b];
	}
	sort(brr + 1, brr + 1 + B, greater<int>());

	cout << solve() << "\n";
	return 0;
}


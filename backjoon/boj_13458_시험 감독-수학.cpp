/*
boj_13458_시험 감독(난이도 : 브론즈2)
수학
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

int N;
int arr[1000001];
int B, C;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}

	cin >> B >> C;
	ll sum = 0;
	for (int n = 1; n <= N; n++) {
		arr[n] -= B;
		if (arr[n] <= 0) continue;
		else {
			sum += (arr[n] / C);
			if (arr[n] % C != 0) {
				sum += 1;
			}
		}
	}
	sum += N;
	cout << sum << "\n";

	return 0;
}

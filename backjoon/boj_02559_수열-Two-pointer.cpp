/*
boj_2559_수열(난이도 : 실버3)
Two-pointer
연속적인 합들 중에서 최댓값 선정
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

int N, K;
int arr[100001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}

	int myMax = 0;
	for (int k = 1; k <= K; k++) {
		myMax += arr[k];
	}

	int now = myMax;
	for (int n = K + 1; n <= N; n++) {
		now += arr[n];
		now -= arr[n - K];
		myMax = max(myMax, now);
	}

	cout << myMax << "\n";

	return 0;

}

/*
boj_2531_회전 초밥(난이도 : 실버1)
Two-pointer
초밥의 종류에 따른 cnt를 두면 풀이가 간단해짐
회전을 고려하기 위해 arr에 여유공간을 두고
회전 이후의 상황을 미리 복사해두면 
선형적으로 풀 수 있음
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

int N, D, K, C, M;
int arr[33001];
int cnt[3001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> D >> K >> C;
	M = N + K;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}

	for (int k = 1; k <= K; k++) {
		arr[N + k] = arr[k];
	}

	int kind = 0;
	int myMax = 0;
	for (int k = 1; k <= K; k++) {
		int num = arr[k];
		cnt[num]++;
		if (cnt[num] == 1) kind++;
	}

	if (cnt[C] >= 1) myMax = kind;
	else myMax = kind + 1;

	for (int m = K + 1; m <= M; m++) {
		int num = arr[m];
		cnt[num]++;
		if (cnt[num] == 1) kind++;
		int pre = arr[m - K];
		cnt[pre]--;
		if (cnt[pre] == 0) kind--;

		if (cnt[C] >= 1) myMax = max(myMax, kind);
		else myMax = max(myMax, kind + 1);
	}

	cout << myMax << "\n";
	return 0;

}


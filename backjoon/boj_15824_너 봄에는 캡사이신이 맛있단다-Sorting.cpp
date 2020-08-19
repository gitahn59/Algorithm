/*
boj_15824_너 봄에는 캡사이신이 맛있단다(난이도 : 골드1)
Sorting
1 4 5 5 6 10

3 4 4 5 9 = 3 + 4*2 + 4*4 + 5*8 + 9*16 : a
- 1 1 2 6 = - + 1*1 + 1*2 + 2*4 + 6*8  : b
- - 0 1 4 = - + --- + 0*1 + 1*2 + 4*4  : c
- - - 1 5 = - + --- + --- + 1*1 + 5*2  : d
- - - - 4 = - + --- + --- + --- + 4*1  : e

a~e 사이의 관계를 이용해 O(N)에 답을 구할 수 있음
F(N-1) = (F(N) * len * weight) * 2 + len 의 관계를 가짐
len은 변화량, weight는 2의 제곱값들의 합
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

int N;
ll arr[300001];
int mod = 1000000007;
ll weight[300001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> arr[n];
	}
	if (N == 1) {
		cout << "0\n";
		return 0;
	}

	sort(arr, arr + N);
	reverse(arr, arr + N);

	int w = 1;
	weight[0] = 1;
	for (int n = 1; n < N; n++) {
		w *= 2;
		w = w % mod;
		weight[n] = (weight[n - 1] + w) % mod;
	}

	ll sum = (arr[0] - arr[1]) % mod;
	ll now = (arr[0] - arr[1]) % mod;
	for (int n = 1; n < N - 1; n++) {
		ll len = (arr[n] - arr[n + 1]) % mod;
		ll temp = (len * weight[n - 1]) % mod;
		temp = (temp + now) % mod;
		temp = (temp << 1) % mod;
		temp = (temp + len) % mod;
		now = temp;
		sum = (sum + now) % mod;
	}

	cout << sum << "\n";

	return 0;
}



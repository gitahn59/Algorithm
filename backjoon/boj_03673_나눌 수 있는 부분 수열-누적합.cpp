/*
boj_3673_나눌 수 있는 부분 수열(난이도 : 골드3)
누적합
수열의 부분 수열 중에서 그 합이 D로 나누어지는 부분 수열의 개수를 탐색

누적합이 구해질 때 마다 D로 나눈 나머지를
기록해두면 0 ~ N-1 까지 모든 경우의 누적합의 나머지가 차례대로 구해짐

i번째 누적합을 구했을 때 i-1까지의 가능한 모든 부분수열 쌍들 중에서
나머지 연산이 취한 결과들이 모두 저장되어있기 때문임

ex)
0-4 누적합 계산하고 나머지를 구하면 a라고 하자
0-0
0-1
0-2
0-3
들의 나머지가 이미 계산되어있음
이는 cnt 배열에 저장해두면 
나머지가 a인 수열의 개수를 알 수 있고
0-4 수열에서 나머지가 a인 수열을 빼면 나머지가 0이 되므로
나머지가 a인 수열의 개수가 합이 D의 배수인 수열의 개수를 의미함을 알 수 있음
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

int T, D, N;
ll cnt[1000000];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> D >> N;
		for (int i = 0; i < D; i++) {
			cnt[i] = 0;
		}
		ll rst = 0;
		ll num = 0;
		ll now = 0;
		for (int n = 0; n < N; n++) {
			cin >> num;
			now += num;
			rst += cnt[now % D];
			if (now % D == 0) rst++;
			cnt[now % D] += 1;
		}
		cout << rst << "\n";
	}

	return 0;
}



/*
boj_2830_행성 X3(난이도 : 골드4)
Mathmatics

XOR 연산은 비트단위로 이루어 지므로
수를 쪼개서 XOR 연산을 하거나,
수 그대로 연산을 하거나 그 합은 같음

따라서 N개의 수를 비트단위로 분해하고
각 비트자리에 1이 몇개 나왔는지만 계산하면
O(N)에 모든 수쌍의 XOR 연산의 합을 구할 수 있음
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
int arr[20];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int num;
	for (int n = 0; n < N; n++) {
		cin >> num;
		for (int i = 0; i < 20; i++) {
			if (num & (1 << i))
				arr[i]++;
		}
	}

	int weight = 1;
	ll rst = 0;
	for (int i = 0; i < 20; i++) {
		ll cnt0 = N - arr[i];
		ll cnt1 = arr[i];
		rst += cnt0 * cnt1 * weight;
		weight = weight << 1;
	}
	cout << rst << "\n";

	return 0;
}



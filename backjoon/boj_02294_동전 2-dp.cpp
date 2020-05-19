/*
boj_2294_동전 2(난이도 : 실버 1)
bottomup dp
이전에 사용된 동전의 종류는 상관없이
개수만 고려해야 함
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

int N, K;
int arr[101];
int mem[10001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int n = 1; n <= N; n++)
		cin >> arr[n];

	mem[0] = 1;
	for (int n = 1; n <= N; n++) {
		for (int j = arr[n]; j <= K; j++) {
			int pre = j - arr[n];
			if (mem[pre] == 0) continue;
			if (mem[j] == 0) mem[j] = mem[pre] + 1;
			else mem[j] = min(mem[j], mem[pre] + 1);
		}
	}

	if (mem[K] == 0) cout << "-1\n";
	else cout << mem[K] - 1 << "\n";

	return 0;
}

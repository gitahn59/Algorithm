/*
boj_12865_Æò¹üÇÑ ¹è³¶(³­ÀÌµµ : °ñµå5)
bottomup dp(knapsack)
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
int W[101], V[101];
int mem[100001];
int nxt[100001];
int FIRST = -1;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int n = 1; n <= N; n++) {
		cin >> W[n] >> V[n];
	}

	fill(mem, mem + K + 1, FIRST);

	mem[0] = 0;
	for (int n = 1; n <= N; n++) {
		for (int w = 0; w <= K; w++) {
			if (mem[w] == FIRST) continue;
			int weight = w + W[n];
			if (weight <= K) nxt[weight] = max(nxt[weight], V[n] + mem[w]);
		}
		for (int w = 0; w <= K; w++) {
			mem[w] = max(nxt[w], mem[w]);
		}
	}

	int rst = 0;
	for (int w = 0; w <= K; w++) {
		rst = max(rst, mem[w]);
	}
	cout << rst << "\n";

	return 0;
}


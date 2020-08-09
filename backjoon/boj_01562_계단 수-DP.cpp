/*
boj_1562_계단 수(난이도 : 골드1)
Bottom UP DP
boj_10844의 확장 문제
기본 계단 수 알고리즘에 비트마스킹을 추가하여 
현재 상태를 모두 저장하여 더해가는 DP 문제
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
typedef deque<int> di;
typedef pair<int, ii> iii;
typedef set<int> si;

vi candidate[10];
int N;
int dist[10][101][1 << 10];
int mod = 1000000000;

void preprocessing() {
	candidate[0] = { 1 };
	for (int i = 1; i <= 8; i++) {
		candidate[i].push_back(i - 1);
		candidate[i].push_back(i + 1);
	}
	candidate[9] = { 8 };
	for (int i = 0; i <= 9; i++) {
		dist[i][1][1 << i] = 1;
	}

	int end = (1 << 10) - 1;
	for (int n = 2; n <= N; n++) { // 100
		for (int i = 0; i <= 9; i++) { // 10
			for (int j : candidate[i]) {
				for (int start = 1; start <= end; start++) { // 1024
					int nxt = start | (1 << i);
					dist[i][n][nxt] = (dist[i][n][nxt] + dist[j][n - 1][start]) % mod;
				}
			}
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	preprocessing();

	int rst = 0;
	for (int i = 1; i <= 9; i++) {
		rst = (rst + dist[i][N][(1 << 10) - 1]) % mod;
	}

	cout << rst << "\n";

	return 0;
}


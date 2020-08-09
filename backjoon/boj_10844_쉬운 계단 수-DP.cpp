/*
boj_10844_쉬운 계단 수(난이도 : 실버1)
Bottom UP DP
i로 시작하는 계단 수의 개수를 저장하는 dist mem 구성
dist[시작하는수][길이] = 개수
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
int dist[10][101];
int mod = 1000000000;

void preprocessing() {
	candidate[0] = { 1 };
	for (int i = 1; i <= 8; i++) {
		candidate[i].push_back(i - 1);
		candidate[i].push_back(i + 1);
	}
	candidate[9] = { 8 };
	for (int i = 0; i <= 9; i++) {
		dist[i][1] = 1;
	}

	for (int n = 2; n <= N; n++) {
		for (int i = 0; i <= 9; i++) {
			for (int j : candidate[i]) {
				dist[i][n] += dist[j][n - 1];
			}
			dist[i][n] = dist[i][n] % mod;
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
		rst = (rst + dist[i][N]) % mod;
	}

	cout << rst << "\n";

	return 0;
}


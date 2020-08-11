/*
boj_11057_������ ��(���̵� : �ǹ� 1)
Bottom UP DP
���̿� ���� �ĺ��� �� �� �ִ� ������
�ٴں��� �����ϴ� DP ����
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
int dist[10][1001];
int mod = 10007;
int N;

void preprocessing() {
	for (int i = 0; i <= 9; i++) {
		dist[i][1] = 1;
		for (int j = i; j <= 9; j++) {
			candidate[i].push_back(j);
		}
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
	for (int i = 0; i <= 9; i++) {
		rst += dist[i][N];
	}

	cout << rst % mod << "\n";

	return 0;
}


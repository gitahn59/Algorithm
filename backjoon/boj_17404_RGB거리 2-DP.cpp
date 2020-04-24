/*
boj_17404_RGB�Ÿ� 2(���̵� : ���3)
bottomup dp
ù ��° ���� ������ ���� ����Ǿ��ִ� ȯ�� dp
���� ù ��° ���� ���� ������Ű��
dp�� ���� �����־�� ��

����) ���� ������ ���� �ٸ� ���� ����� INF�� ó���ϸ� 
�ٸ� ���� ��꿡�� �ɷ��� �� ����
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

int R[1001], G[1001], B[1001];
int N;
int cost[3][1001];
int INF = 1000 * 2000;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> cost[0][n] >> cost[1][n] >> cost[2][n];
	}

	int myMin;
	R[1] = cost[0][1]; G[1] = INF; B[1] = INF;
	for (int n = 2; n < N; n++) {
		R[n] = min(G[n - 1] + cost[0][n], B[n - 1] + cost[0][n]);
		G[n] = min(R[n - 1] + cost[1][n], B[n - 1] + cost[1][n]);
		B[n] = min(R[n - 1] + cost[2][n], G[n - 1] + cost[2][n]);
	}
	int left = min(cost[1][N] + B[N - 1], cost[1][N] + R[N - 1]); // G
	int right = min(cost[2][N] + R[N - 1], cost[2][N] + G[N - 1]); // B
	myMin = min(left, right);

	R[1] = INF; G[1] = cost[1][1]; B[1] = INF;
	for (int n = 2; n < N; n++) {
		R[n] = min(G[n - 1] + cost[0][n], B[n - 1] + cost[0][n]);
		G[n] = min(R[n - 1] + cost[1][n], B[n - 1] + cost[1][n]);
		B[n] = min(R[n - 1] + cost[2][n], G[n - 1] + cost[2][n]);
	}
	left = min(cost[0][N] + G[N - 1], cost[0][N] + B[N - 1]); // R
	right = min(cost[2][N] + R[N - 1], cost[2][N] + G[N - 1]); // B
	myMin = min(myMin, min(left, right));

	R[1] = INF; G[1] = INF; B[1] = cost[2][1];
	for (int n = 2; n < N; n++) {
		R[n] = min(G[n - 1] + cost[0][n], B[n - 1] + cost[0][n]);
		G[n] = min(R[n - 1] + cost[1][n], B[n - 1] + cost[1][n]);
		B[n] = min(R[n - 1] + cost[2][n], G[n - 1] + cost[2][n]);
	}
	left = min(cost[0][N] + G[N - 1], cost[0][N] + B[N - 1]); // R
	right = min(cost[1][N] + R[N - 1], cost[1][N] + B[N - 1]); // G
	myMin = min(myMin, min(left, right));

	cout << myMin << "\n";
	return 0;
}


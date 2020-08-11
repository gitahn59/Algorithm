/*
boj_2156_������ �ý�(���̵� : �ǹ�1)
Bottom UP DP
�����ָ� ������ �ʰ� �ǳʶ�� ��찡
���߿� ���� ���� ����� �� �����Ƿ�
�̵� ��꿡 �����Ͽ��� ��
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

int N;
int arr[10001];
int dist[3][10001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}

	dist[1][1] = dist[2][1] = arr[1];
	for (int n = 2; n <= N; n++) {
		dist[1][n] = max(dist[1][n - 2], dist[2][n - 2]) + arr[n];
		dist[2][n] = max(dist[1][n - 1], max(dist[1][n - 2], dist[2][n - 2])) + arr[n];

		int deny = max(dist[1][n - 1], dist[2][n - 1]);
		dist[1][n] = max(deny, dist[1][n]);
		dist[2][n] = max(deny, dist[2][n]);
	}

	int rst = 0;
	for (int n = 1; n <= N; n++) {
		rst = max(rst, dist[1][n]);
		rst = max(rst, dist[2][n]);
	}

	cout << rst << "\n";
	return 0;
}



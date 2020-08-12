/*
boj_11058_ũ������(���̵� : �ǹ�1)
Bottom Up Dp
1. Ctrl-V�� �ϱ����ؼ��� n-3��°��������
���� �� ���縦 �ϰ�, n��°�� ����� �� �ִ�.
=> ����� dist[n-3]���� ����

2. ���縦 �ϰ� ���� n+1 ���ʹ� �ٷ� ����� �� �ִ�
=> i=n���� i<=N ���� �̸� �� ���

���� �� 2���� ������ �̿��Ͽ� Bottom UP DP�� �����ϸ�
O(n^2) �ð��� �ð����⵵�� ������
�ִ� N = 100�̹Ƿ� ���ѽð��� �����Ѵ�.
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
ll dist[101];
int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 0; n <= N; n++) dist[n] = -1;

	dist[1] = 1;
	dist[2] = 2;
	dist[3] = 3;
	for (int n = 4; n <= N; n++) {
		dist[n] = max(dist[n], dist[n - 1] + 1);
		ll temp = dist[n - 3];
		int j = 1;
		for (int i = n; i <= N; i++, j++) {
			dist[i] = max(dist[i], dist[n - 3] + temp * j);
		}
	}

	cout << dist[N] << "\n";

	return 0;
}



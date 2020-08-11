/*
boj_15486_��� 2(���̵� : �ǹ� 1)
Bottom UP Dp
�⺻���� Bottom UP DP ����
���� �ð��� ������ �ִ밪�� ���
�����ϸ� ��
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
int dist[1500001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int t, p;
	int rst = 0;
	for (int n = 1; n <= N; n++) {
		cin >> t >> p;
		int last = n + t - 1;
		if (last > N) {
			rst = max(rst, dist[n]);
			continue;
		}
		dist[last] = max(rst + p, dist[last]);
		rst = max(rst, dist[n]);
	}

	cout << rst << "\n";

	return 0;
}


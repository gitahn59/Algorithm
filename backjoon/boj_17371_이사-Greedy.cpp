/*
boj_17371_�̻�(���̵� : ���2)
Greedy
1. O(N^2)
������ ���տ��� �� 2���� ����
�׸��� �� ���� ���������ϴ� ���� ��� ������ ���ԵǴ��� Ȯ���Ѵ�.

2. O(1)
�ٸ� ������ ��� �����ϴ� ���� ������ �����ϴ� �����߿���
�� ������ ���� ª�� ���̰� �Ǵ� �ĺ� ���� ã�´�.

�� ��ġ�� ���� ������ �ִܰŸ��� ����Ÿ��� ���� ����� �ּҰ� �ȴ�.
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
ii arr[1000];

double getlen(ii a, ii b) {
	return (a.first - b.first) * (a.first - b.first)
		+ (a.second - b.second) * (a.second - b.second);
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 0; n < N; n++) {
		cin >> arr[n].first >> arr[n].second;
	}

	if (N == 1) {
		cout << arr[0].first << " " << arr[0].second << "\n";
		return 0;
	}

	int best;
	double rst = 6400000000;
	for (int i = 0; i < N; i++) {
		int idx = -1;
		double now = 0;
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			double len = getlen(arr[i], arr[j]);
			if (len > now) {
				idx = j;
				now = len;
			}
		}
		if (now < rst) {
			best = i;
			rst = now;
		}
	}

	cout << arr[best].first << " " << arr[best].second << "\n";

	return 0;
}



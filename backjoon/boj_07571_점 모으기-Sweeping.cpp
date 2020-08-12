/*
boj_7571_�� ������(���̵� : �ǹ�2)
Sweeping
���� ����Ʈ���� �� ���ҿ��� ���̸� ���Ѵ�.
�̶� ������ ���� �ּҰ� �Ǵ� ���� ���ؾ� �ϴ� ����,

�߾Ӱ��� �����ϸ� �ּҰ� ��
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

int N, M;
ll X[10001];
vi xnum, ynum;
ll Y[10001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int x, y;
	int xmin, xmax, ymin, ymax;
	xmin = ymin = 10000;
	xmax = ymax = 0;
	for (int m = 0; m < M; m++) {
		cin >> x >> y;
		X[x]++;
		xmin = min(xmin, x);
		xmax = max(xmax, x);
		xnum.push_back(x);
		Y[y]++;
		ymin = min(ymin, y);
		ymax = max(ymax, y);
		ynum.push_back(y);
	}
	sort(xnum.begin(), xnum.end());
	int xmedian = xnum[xnum.size() / 2];
	auto xend = unique(xnum.begin(), xnum.end());
	sort(ynum.begin(), ynum.end());
	int ymedian = ynum[ynum.size() / 2];
	auto yend = unique(ynum.begin(), ynum.end());

	ll xdist = 0;
	for (auto it = xnum.begin(); it != xend; it++) {
		xdist += X[*it] * abs(*it - xmedian);
	}

	ll ydist = 0;
	for (auto it = ynum.begin(); it != yend; it++) {
		ydist += Y[*it] * abs(*it - ymedian);
	}

	cout << ydist + xdist << "\n";
	return 0;
}



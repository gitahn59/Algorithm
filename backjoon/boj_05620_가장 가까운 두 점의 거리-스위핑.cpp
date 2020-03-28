/*
boj_05620_���� ����� �� ���� �Ÿ�(���̵� : �÷�5)
�������� �̿��� Ǯ��
1. ��ǥ���� x��ǥ �������� ����
2. y ��ǥ�� �������� �����ϴ� �ĺ����� set ���� 
3. ��ǥ n�� ���� 
	3-1 x��ǥ�� ���� �Ÿ��� �� ���� �ĺ����� ����
	3-2 lower_bound, upper_bound�� y ��ǥ�� ���� �� ���� ����
	3-3 �ĺ� ������ ���� ��ǥ n�� �ĺ��� ������ �ִ� �Ÿ� ���
4. ��ǥ n�� �ĺ��� �߰�
5. n<N �� ���� 3~4 �ݺ�
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

typedef struct point {
	int x, y;
	bool operator < (const point& p) const {
		if (p.y == y) {
			return x < p.x;
		}
		else {
			return y < p.y;
		}
	}
}Point;

bool myCmp(const Point& a, const Point& b) {
	return a.x < b.x;
}

int dist(const Point& a, const Point& b) {
	return ((a.x - b.x) * (a.x - b.x)) + ((a.y - b.y) * (a.y - b.y));
}

Point arr[500001];
int N;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n].x >> arr[n].y;
	}

	sort(arr + 1, arr + 1 + N, myCmp);

	int ans = dist(arr[1], arr[N]);
	set<Point> candidate = { arr[1],arr[N] };
	int start = 1;

	for (int n = 2; n < N; n++) {
		Point now = arr[n];
		while (start < n) {
			Point p = arr[start];
			int x = p.x - now.x;
			if (x * x > ans) {
				candidate.erase(p);
				start++;
			}
			else {
				break;
			}
		}

		int d = (int)sqrt((double)ans) + 1;
		Point lp = { -100000,now.y - d };
		Point up = { 100000,now.y + d };
		auto lower = candidate.lower_bound(lp);
		auto upper = candidate.upper_bound(up);

		for (auto it = lower; it != upper; it++) {
			int d = dist(now, *it);
			if (d < ans) {
				ans = d;
			}
		}
		candidate.insert(now);
	}

	cout << ans << "\n";

	return 0;
}

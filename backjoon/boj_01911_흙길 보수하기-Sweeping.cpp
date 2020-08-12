/*
boj_1911_흙길 보수하기(난이도 : 실버2)
Sweeping
boj_02594_놀이공원 확장문제

판자로 채워지는 영역을 업데이트 하면서
선분을 채워나가면 됨
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

int N, L;
ii arr[10000];

bool myCmp(ii a, ii b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int cover(int start, int end) {
	int len = end - start + 1;
	if (len % L == 0) return len / L;
	else return (len / L) + 1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> L;
	for (int n = 0; n < N; n++) {
		cin >> arr[n].first >> arr[n].second;
		arr[n].second--;
	}
	sort(arr, arr + N, myCmp);

	ii now = arr[0];
	int cnt = cover(now.first, now.second);
	now.second = now.first + (L * cnt) - 1;
	for (int n = 1; n < N; n++) {
		if (now.second < arr[n].first) {
			int c = cover(arr[n].first, arr[n].second);
			now.second = arr[n].first + (c * L) - 1;
			cnt += c;
		}
		else {
			if (now.second < arr[n].second) {
				int c = cover(now.second + 1, arr[n].second);
				now.second = now.second + 1 + (c * L) - 1;
				cnt += c;
			}
		}
	}

	cout << cnt << "\n";

	return 0;
}



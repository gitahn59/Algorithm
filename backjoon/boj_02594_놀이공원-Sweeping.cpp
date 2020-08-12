/*
boj_2594_놀이공원(난이도 : 실버3)
Sweeping
선 그리기 문제
현제 선을 기준으로 다음에 그릴 선이
1. 현재 선 안에 포함됨
=> 공백도 없고, 현재선 그대로
2. 현재 선을 연장함
=> 공백없이 현재 선을 갱신
3. 현재 선에서 떨어져 있음
=> 공백이 있으므로 갱신
을 분류하여 조건에 맞게 처리하면 됨
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
ii arr[50];

bool myCmp(ii a, ii b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int a, b;
	for (int n = 0; n < N; n++) {
		cin >> a >> b;
		arr[n].first = ((a / 100) * 60) + (a % 100) - 10;
		arr[n].second = ((b / 100) * 60) + (b % 100) + 10;
	}
	sort(arr, arr + N, myCmp);

	int start = 10 * 60;
	int end = 22 * 60;
	ii now = { start, arr[0].second };
	int rst = arr[0].first - start;
	for (int n = 1; n < N; n++) {
		if (arr[n].first >= now.second) {
			rst = max(rst, arr[n].first - now.second);
			now.second = arr[n].second;
		}
		else {
			if (arr[n].second > now.second) {
				now.second = arr[n].second;
			}
		}
	}
	rst = max(rst, end - now.second);
	cout << rst << "\n";
	return 0;
}



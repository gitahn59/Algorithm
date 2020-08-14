/*
boj_15922_아우으 우아으이야!!(난이도 : 골드5)
Sweeping
기본적인 선분 그리기 문제
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
ii arr[100000];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int x, y;
	int sum = 0;
	for (int n = 0; n < N; n++) {
		cin >> arr[n].first >> arr[n].second;
	}

	ii now = arr[0];
	int len = arr[0].second - arr[0].first;
	for (int n = 1; n < N; n++) {
		if (now.second <= arr[n].first) {
			len += (arr[n].second - arr[n].first);
			now.second = arr[n].second;
		}
		else {
			if (arr[n].second > now.second) {
				len += (arr[n].second - now.second);
				now.second = arr[n].second;
			}
		}
	}

	cout << len << "\n";

	return 0;
}



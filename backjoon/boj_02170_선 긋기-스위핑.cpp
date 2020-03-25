/*
boj_02170_선 긋기(난이도 : 골드5)
스위핑 알고리즘 활용 문제
정렬을 통해 O(n)번만 비교하도록 함
주의) first에 대해 정렬된 것이므로 second는 별도로 조건을 검사해야 함
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

int N;
ii arr[1000001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	int N;
	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n].first >> arr[n].second;
		if (arr[n].first > arr[n].second)
			swap(arr[n].first, arr[n].second);
	}

	sort(arr + 1, arr + 1 + N);

	int sum = 0;
	ii now = arr[1];
	for (int n = 2; n <= N; n++) {
		if (now.second >= arr[n].first) {
			if (arr[n].second > now.second) {
				now.second = arr[n].second;
			}
		}
		else {
			sum += now.second - now.first;
			now = arr[n];
		}
	}
	sum += now.second - now.first;
	cout << sum << "\n";

	return 0;
}
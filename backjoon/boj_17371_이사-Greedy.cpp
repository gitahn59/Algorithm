/*
boj_17371_이사(난이도 : 골드2)
Greedy
1. O(N^2)
점들의 집합에서 점 2개를 고른다
그리고 두 점을 지름으로하는 원에 모든 점들이 포함되는지 확인한다.

2. O(1)
다른 점들을 모두 포함하는 원의 지름을 구성하는 집합중에서
그 지름이 가장 짧은 길이가 되는 후보 점을 찾는다.

그 위치에 집을 지으면 최단거리와 최장거리의 합의 평균이 최소가 된다.
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



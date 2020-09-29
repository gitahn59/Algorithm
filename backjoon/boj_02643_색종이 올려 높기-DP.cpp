/*
boj_2643_색종이 올려 놓기(난이도 : 골드4)
DP
넓이 순서로 정렬하면
간단한 topdown dp로 해결 가능
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

bool myCmp(ii a, ii b) {
	int aa = a.first * a.second;
	int bb = b.first * b.second;

	if (aa == bb) {
		return a.first > b.first;
	}
	else {
		return aa < bb;
	}
}

int N;
ii arr[100];
int dist[100];
int topdown(int id) {
	if (dist[id] != 0) return dist[id];

	int myMax = 1;
	int x = arr[id].first;
	int y = arr[id].second;

	for (int i = 0; i < id; i++) {
		int a = arr[i].first;
		int b = arr[i].second;
		if ((a <= x && b <= y) || (b <= x && a <= y)) {
			myMax = max(myMax, topdown(i) + 1);
		}
	}
	return dist[id] = myMax;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + N, myCmp);

	int myMax = 1;
	for (int i = 0; i < N; i++) {
		myMax = max(myMax, topdown(i));
	}

	cout << myMax << "\n";

	return 0;
}



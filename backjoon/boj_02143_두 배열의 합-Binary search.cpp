/*
boj_2143_두 배열의 합(난이도 : 골드3)
Binary search
후보 배열을 두개 생성 및 정렬하고,
A 후보배열을 선형 탐색하면서,
B 후보배열에서 이진탐색으로 값이 존재하는지 탐색
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

ll T;
int N, M;
vi arr, brr;
int acc[1001];

void prerocessing(vi& dest) {
	int num = 0;
	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> num;
		acc[n] = acc[n - 1] + num;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			int temp = 0;
			temp += acc[j];
			temp -= acc[i - 1];
			dest.push_back(temp);
		}
	}

	sort(dest.begin(), dest.end());
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	int num;

	cin >> T;
	prerocessing(arr);
	prerocessing(brr);

	ll cnt = 0;
	for (int i : arr) {
		int target = (T - i);
		auto left = lower_bound(brr.begin(), brr.end(), target);
		auto right = upper_bound(brr.begin(), brr.end(), target);
		int len = right - left;
		cnt += len;
	}

	cout << cnt << "\n";

	return 0;
}



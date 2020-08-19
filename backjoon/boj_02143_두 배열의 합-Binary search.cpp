/*
boj_2143_�� �迭�� ��(���̵� : ���3)
Binary search
�ĺ� �迭�� �ΰ� ���� �� �����ϰ�,
A �ĺ��迭�� ���� Ž���ϸ鼭,
B �ĺ��迭���� ����Ž������ ���� �����ϴ��� Ž��
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



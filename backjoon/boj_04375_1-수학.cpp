/*
boj_4375_1(���̵� : �ǹ�3)
����
���� �յ��� ������ �̿�
���� Ű�����°� �ƴ϶� ��������
��� update�Ͽ� ���� Ž��
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
#include <tuple>

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
int solve(int num) {
	int r, cnt;
	cnt = 1;
	r = 1 % num;
	while (r != 0) {
		r = ((10 * r) + 1) % num;
		cnt++;
	}
	return cnt;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (scanf("%d", &N) != EOF) {
		cout << solve(N) << "\n";
	}

	return 0;
}


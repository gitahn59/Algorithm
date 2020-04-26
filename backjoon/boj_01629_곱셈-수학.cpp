/*
boj_01629_����(���̵� : �ǹ�1)
����
������ ������ �̸� ����ϰ�
�� ������� ������ �����ϸ� ��
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

ll A, B, C;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> A >> B >> C;
	vi route;
	ll temp = B;
	while (temp != 1) {
		if (temp % 2 == 1) {
			route.push_back(1);
		}
		else {
			route.push_back(0);
		}
		temp = temp >> 1;
	}

	reverse(route.begin(), route.end());

	ll rst = A % C;
	for (int i : route) {
		if (i == 1) {
			rst = (rst * rst) % C;
			rst = (rst * A) % C;
		}
		else {
			rst = (rst * rst) % C;
		}
	}

	cout << rst % C << "\n";

	return 0;
}



/*
boj_10942_�Ӹ����?(���̵� : ���2)
topdown dp
O(2000*2000) �ȿ� �ذᰡ���� topdown dp ����
������ �ҹ����� �ɰ��鼭 �Ӹ������ ������ �� ����
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

int N, M;
int mem[2001][2001];
int arr[2001];

int topdown(int a, int b) {
	int& ref = mem[a][b];
	if (ref != 0) return mem[a][b];
	if (a >= b) return ref = 1;
	if (arr[a] == arr[b] && topdown(a + 1, b - 1) == 1) {
		ref = 1;
	}
	else {
		ref = -1;
	}
	return mem[a][b] = ref;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}

	cin >> M;
	int a, b;
	for (int m = 1; m <= M; m++) {
		cin >> a >> b;
		int rst = topdown(a, b);
		if (rst == 1) cout << "1\n";
		else cout << "0\n";
	}

	return 0;
}


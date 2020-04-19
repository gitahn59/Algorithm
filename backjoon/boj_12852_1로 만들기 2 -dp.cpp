/*
boj_12852_1�� ����� 2(���̵� : �ǹ�1)
bottom dp
�⺻���� dp ���� ��� ����� �ʿ��� ����
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
int mem[1000001];
int path[1000001];
int INF = 1000000000;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int n = 1; n <= N; n++) {
		mem[n] = INF;
	}

	mem[1] = 0;
	for (int n = 1; n < N; n++) {
		if (mem[n] == INF) continue;

		if (mem[n + 1] > mem[n] + 1) {
			mem[n + 1] = mem[n] + 1;
			path[n + 1] = n;
		}

		if ((n << 1) <= N && mem[n << 1] > mem[n] + 1) {
			mem[n << 1] = mem[n] + 1;
			path[n << 1] = n;
		}

		if ((n * 3) <= N && mem[n * 3] > mem[n] + 1) {
			mem[n * 3] = mem[n] + 1;
			path[n * 3] = n;
		}
	}

	int start = N;
	cout << mem[N] << "\n";
	while (start != 1) {
		cout << start << " ";
		start = path[start];
	}
	cout << "1\n";

	return 0;
}




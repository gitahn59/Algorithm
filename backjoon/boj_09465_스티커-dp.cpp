/*
boj_09465_��ƼĿ(���̵� : �ǹ�2)
bottom dp
������ �پ��ִ� ��ƼĿ�� ���´� ��������Ƿ�
����ȭ ����
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

int T, N;
//mem[i][j]
// j : 0�� 1��
// i : i�� ��ƼĿ�� ���������
// [j][i] : j�� i�� ��ƼĿ�� ���� �� �ִ�
int mem[2][100001];
int arr[2][100001];

int myMax(int a, int b, int c) {
	return max(max(a, b), c);
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int t = 1; t <= T; t++) {
		cin >> N;
		for (int n = 1; n <= N; n++) {
			cin >> arr[0][n];
		}
		for (int n = 1; n <= N; n++) {
			cin >> arr[1][n];
		}

		mem[0][1] = arr[0][1];
		mem[1][1] = arr[1][1];
		for (int n = 2; n <= N; n++) {
			mem[0][n] = myMax(mem[1][n - 1], mem[0][n - 2], mem[1][n - 2]) + arr[0][n];
			mem[1][n] = myMax(mem[0][n - 1], mem[0][n - 2], mem[1][n - 2]) + arr[1][n];
		}

		int left = max(mem[0][N], mem[1][N]);
		int right = max(mem[0][N - 1], mem[1][N - 1]);
		cout << max(left, right) << "\n";

		for (int n = 1; n <= N; n++) {
			mem[0][n] = mem[1][n] = 0;
		}
	}

	return 0;
}


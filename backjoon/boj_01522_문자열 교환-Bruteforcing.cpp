/*
boj_1522_���ڿ� ��ȯ(���̵� : ���5)
����Ž��
������ �ĺ��� ��� ���غ���
�� �ĺ��� �Ǵµ� �ʿ��� ��ȯȽ���� ����
�ּڰ� ã��
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

char src[1010];
int N, A;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> src + 1;
	N = strlen(src + 1);
	for (int n = 1; n <= N; n++) {
		if (src[n] == 'a') A++;
	}

	int myMin = N;
	for (int n = 1; n <= N; n++) {
		int cnt = 0;
		for (int i = n; i <= n + A - 1; i++) { // A��
			int idx = i;
			if (idx > N) idx -= N;
			if (src[idx] == 'a') continue;
			else if (src[idx] == 'b') cnt++;
		}
		myMin = min(myMin, cnt);
	}

	cout << myMin << "\n";

	return 0;
}

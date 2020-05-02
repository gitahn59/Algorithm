/*
boj_1541_�Ҿ���� ��ȣ(���̵� : �ǹ�2)
���ڿ�, �׸���
�ּڰ��� ���ϴ� �����̹Ƿ�
�ѹ� - ������ �����ϸ� �� ���� ������ ���� -�� ġȯ ����
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
char src[55];
char cpy[55];

int op[55];
int op_cnt = 0;

int num[55];
int num_cnt = 0;

int solve() {
	int idx = 1;
	for (idx = 1; idx <= op_cnt; idx++) {
		if (op[idx] == -1) {
			for (int i = idx + 1; i <= op_cnt; i++) {
				op[i] = -1;
			}
			break;
		}
	}

	int now = num[1];
	for (int idx = 2; idx <= num_cnt; idx++) {
		now += (num[idx] * op[idx - 1]);
	}
	return now;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> src + 1;
	strcpy(cpy + 1, src + 1);
	N = strlen(src + 1);

	for (int n = 1; n <= N; n++) {
		if (src[n] == '+') {
			op[++op_cnt] = 1;
		}
		else if (src[n] == '-') {
			op[++op_cnt] = -1;
		}
	}

	char* p = strtok(cpy + 1, "+-");
	while (p != NULL) {
		num[++num_cnt] = stoi(p);
		p = strtok(NULL, "+-");
	}

	cout << solve() << "\n";
	return 0;
}

/*
pro_60062_�ܺ�����(���̵� : level 3)
����Ž��
�ܺ��� ������鿡 ���ؼ� 
������ ��� ������, ������ ��� ģ���� ������
����Ž��
weak�� ���̰� ���� ������� ������ �����ǰ� ���̰� 15�����̹Ƿ�
15���� ������ ����
ģ���� ���� 8�����̹Ƿ� 8! = 40320
���� 15 * 40320 �� �ð����⵵�� ����

����)
�ĺ��� ���� ���ǰ˻縦 �ϴ� �κ��� ��ٷο�
1. ���̰� ģ���� ������ �Ÿ����� ª���� ť���� ���⸸�ϰ�
2. ���̰� �� ��� ģ���� ���Լ��� �÷��־�� ��
3. ť�� ���� ������� 1���̸�, �� ũ�⿡ ������� ������ �����ϹǷ�
�׳� break ���ָ� ��
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
int len[16];
int candidate[9];

int myCheck() {
	queue<int> qi;
	for (int n = 1; n <= N; n++) {
		qi.push(len[n]);
	}

	int myMin = M + 1;
	for (int n = 1; n <= N; n++) {
		int temp = qi.front();
		{
			queue<int> q = qi;
			int m = 1;
			int now = 0;
			while (!q.empty() && m <= M) {
				if (q.size() == 1) {
					break;
				}
				if (now + q.front() <= candidate[m]) {
					now += q.front();
					q.pop();
				}
				else {
					q.pop();
					now = 0;
					m++;
				}
			}
			myMin = min(myMin, m);
		}
		qi.pop();
		qi.push(temp);
	}

	return myMin;
}

int solution(int n, vector<int> weak, vector<int> dist) {
	N = weak.size();
	if (n == 1) return 1;

	for (int n = 1; n < N; n++) {
		len[n] = weak[n] - weak[n - 1];
	}
	len[N] = n + weak[0] - weak[N - 1];
	M = dist.size();

	int per[] = { 0,1,2,3,4,5,6,7 };
	int myMin = M + 1;
	// O(8!) = 40320
	do {
		for (int m = 1; m <= M; m++) {
			candidate[m] = dist[per[m - 1]];
		}
		myMin = min(myMin, myCheck());
	} while (next_permutation(per, per + M));

	if (myMin > M) return -1;
	else return myMin;
}


int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution(12, { 1, 5, 6, 10 }, { 1, 2, 3, 4 });


	return 0;
}

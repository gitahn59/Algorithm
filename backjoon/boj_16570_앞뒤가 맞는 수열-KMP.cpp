/*
boj_16570_�յڰ� �´� ����(���̵� : ���1)
KMP 
�տ������� ������ ������ ���ڸ� ������ ��
���̻� �迭�� ���λ� �迭�� ���� ������ �ִ� ���̸� �ľ��ϴ� ����

�տ��������ڸ��� ������ ����� �ڸ��� ������ �ٲٸ�
�̴� KMP ������ ġȯ�� �� ����
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

int M;
int target[10000001];
int p[10000001];
void makep() {
	for (int m = 1, j = 0; m < M; m++) {
		while (j > 0 && target[m] != target[j]) {
			j = p[j - 1];
		}
		if (target[m] == target[j]) {
			j++;
			p[m] = j;
		}
	}
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> M;
	for (int m = M - 1; m >= 0; m--) {
		cin >> target[m];
	}
	makep();
	sort(p, p + M);
	int myMax = p[M - 1];
	int cnt = 1;
	if (myMax == 0) {
		cout << -1 << "\n";
		return 0;
	}

	for (int m = M - 2; m >= 0; m--) {
		if (myMax == p[m]) {
			cnt++;
		}
		else break;
	}

	cout << myMax << " " << cnt << "\n";

	return 0;
}



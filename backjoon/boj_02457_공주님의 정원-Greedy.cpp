/*
boj_2457_���ִ��� ����(���̵� : ���4)
��� ����
��,�� �������� �־����� �����͸�
1~365�� �Ϸ� ġȯ�ϸ� �ִ� 10������ �ĺ��� 
�ִ� 365���� �ĺ��� ������ �� ����

���� �ĺ��� �����Ҷ�����, �̸� ������ �ĺ��� ��� �˻��ϸ�
���� �ĺ��� ����ų� ���ܵξ� ������ �ĺ��� ������ �� ����
�� O(N^2)�� Ǯ�̷� �ذ� ������
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

int N;
int convert[13][32];
int date[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
int flower[366];
int NONE = -1000;
ii rst[366];

void preprocessing() {
	int tag = 1;
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= date[i]; j++) {
			convert[i][j] = tag++;
		}
	}
}

bool myCmp(ii a, ii b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second < b.second;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	preprocessing();
	int start = convert[3][1];
	int end = convert[11][30];

	cin >> N;
	int a, b, x, y;
	for (int n = 0; n < N; n++) {
		cin >> a >> b >> x >> y;
		int s = convert[a][b];
		int e = convert[x][y] - 1;
		flower[s] = max(flower[s], e);
	}

	vii candidate;
	for (int i = 1; i <= 365; i++) {
		if (flower[i] == 0) continue;
		bool flag = 1;
		for (int j = 1; j <= i - 1; j++) {
			if (flower[j] != 0) continue;
			if (flower[j] >= flower[i]) {
				flag = 0;
				break;
			}
		}
		if (flag) candidate.push_back({ i,flower[i] });
	}

	sort(candidate.begin(), candidate.end(), myCmp);

	int M = candidate.size();
	int idx = NONE;
	ii now = { NONE, NONE };
	for (int m = 0; m < M; m++) {
		if (candidate[m].first <= start && candidate[m].second >= start) {
			if (now.first == NONE) {
				now = candidate[m];
				idx = m;
			}
			else {
				if (now.second < candidate[m].second) {
					now = candidate[m];
					idx = m;
				}
			}
		}
	}

	if (idx == NONE) {
		cout << "0\n";
	}
	else {
		int len = 1;
		rst[0] = candidate[idx];
		for (int i = idx + 1; i < M; i++) {
			for (int j = 0; j < len; j++) {
				if (rst[j].second + 1 >= candidate[i].first) {
					rst[j + 1] = candidate[i];
					len = j + 2;
					break;
				}
			}
		}

		for (int i = 0; i < len; i++) {
			if (rst[i].second >= end) {
				cout << i + 1 << "\n";
				return 0;
			}
		}
		cout << "0\n";
	}

	return 0;
}



/*
boj_5525_IOIOI(���̵� : �ǹ�1)
KMP
�ս��Լ� �κ��� ������ 
KMP �˰��� ����

KMP �˰���
���ڿ� Ž���� O(N+M)�ð��� ���� Ž���ϴ� �˰���
���ϴ� ���ڿ� ���� �ߺ��Ǵ� �κ��� ������
�� �κ��� �ǳʶ�� ���� �񱳸� ������

�̿� ���� �ս� ���� ���� �̸� ����ص�
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
typedef deque<int> di;
typedef pair<int, ii> iii;
typedef set<int> si;

int N, M;
string str;
string P = "I";
int arr[1000001];
void make_sp() {
	for (int i = 3; i <= P.size(); i++) {
		arr[i] = i - 2;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	cin >> str;

	for (int n = 0; n < N; n++) {
		P += "OI";
	}
	make_sp();

	int i = 0, j = 0;
	int cnt = 0;
	for (; i < str.size();) {
		int base = i;
		for (; j < P.size(); j++, i++) {
			if (str[i] == P[j]) continue;
			else break;
		}
		if (j == P.size()) {
			cnt++;
		}
		i = i - j + 1 + arr[j];
		j = arr[j];
	}

	cout << cnt << "\n";

	return 0;
}

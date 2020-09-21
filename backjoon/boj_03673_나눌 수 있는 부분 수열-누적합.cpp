/*
boj_3673_���� �� �ִ� �κ� ����(���̵� : ���3)
������
������ �κ� ���� �߿��� �� ���� D�� ���������� �κ� ������ ������ Ž��

�������� ������ �� ���� D�� ���� ��������
����صθ� 0 ~ N-1 ���� ��� ����� �������� �������� ���ʴ�� ������

i��° �������� ������ �� i-1������ ������ ��� �κм��� �ֵ� �߿���
������ ������ ���� ������� ��� ����Ǿ��ֱ� ������

ex)
0-4 ������ ����ϰ� �������� ���ϸ� a��� ����
0-0
0-1
0-2
0-3
���� �������� �̹� ���Ǿ�����
�̴� cnt �迭�� �����صθ� 
�������� a�� ������ ������ �� �� �ְ�
0-4 �������� �������� a�� ������ ���� �������� 0�� �ǹǷ�
�������� a�� ������ ������ ���� D�� ����� ������ ������ �ǹ����� �� �� ����
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

int T, D, N;
ll cnt[1000000];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> D >> N;
		for (int i = 0; i < D; i++) {
			cnt[i] = 0;
		}
		ll rst = 0;
		ll num = 0;
		ll now = 0;
		for (int n = 0; n < N; n++) {
			cin >> num;
			now += num;
			rst += cnt[now % D];
			if (now % D == 0) rst++;
			cnt[now % D] += 1;
		}
		cout << rst << "\n";
	}

	return 0;
}



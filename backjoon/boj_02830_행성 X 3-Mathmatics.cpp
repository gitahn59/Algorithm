/*
boj_2830_�༺ X3(���̵� : ���4)
Mathmatics

XOR ������ ��Ʈ������ �̷�� ���Ƿ�
���� �ɰ��� XOR ������ �ϰų�,
�� �״�� ������ �ϰų� �� ���� ����

���� N���� ���� ��Ʈ������ �����ϰ�
�� ��Ʈ�ڸ��� 1�� � ���Դ����� ����ϸ�
O(N)�� ��� ������ XOR ������ ���� ���� �� ����
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
int arr[20];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int num;
	for (int n = 0; n < N; n++) {
		cin >> num;
		for (int i = 0; i < 20; i++) {
			if (num & (1 << i))
				arr[i]++;
		}
	}

	int weight = 1;
	ll rst = 0;
	for (int i = 0; i < 20; i++) {
		ll cnt0 = N - arr[i];
		ll cnt1 = arr[i];
		rst += cnt0 * cnt1 * weight;
		weight = weight << 1;
	}
	cout << rst << "\n";

	return 0;
}



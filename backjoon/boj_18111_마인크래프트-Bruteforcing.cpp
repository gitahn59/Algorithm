/*
boj_18111_����ũ����Ʈ(���̵� : �ǹ�3)
Ư�� �۾��� ���� ��� ������ ���̸� �����ϰ� ���߾�� �� ��
���� ���� �ð��� �ɸ��� ��츦 ã�� ����

����� ���̴� �ִ� 257���� �����ϹǷ�
���� �˻��ϸ�
257 * 500 * 500 �� �ð����⵵�� ����
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

int N, M, B;
int K;
int arr[500 * 500];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> B;
	K = N * M;
	for (int k = 0; k < K; k++) {
		cin >> arr[k];
	}
	sort(arr, arr + K);

	ll best_time = 300 * 500 * 500 * 2;
	int myMax = 0;

	for (int i = 0; i <= 256; i++) {
		int b = B;
		ll spend = 0;
		for (int k = 0; k < K; k++) {
			int gap = arr[k] - i;
			if (gap == 0) continue;
			else if (gap < 0) { // need to put
				spend += abs(gap);
				b -= abs(gap);
			}
			else { // need to remove
				spend += (gap << 1);
				b += gap;
			}
		}

		if (b >= 0 && best_time >= spend) {
			best_time = spend;
			myMax = i;
		}
	}

	cout << best_time << " " << myMax << "\n";

	return 0;
}



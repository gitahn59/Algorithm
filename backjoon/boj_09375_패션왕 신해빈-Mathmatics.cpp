/*
boj_9375_�мǿ� ���غ�(���̵� : �ǹ�3)
����
������ ������ ���ϴ� ����� �ƴ϶�
�� �ǻ��� ������ ������ 1�� ���� �ʴ°�츦 ���Խ�Ű��
�����ָ� �������� ��츦 �����Ͽ� ������ ����� �� ����
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

typedef map<string, int> msi;
int T, N;
int arr[30];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> N;
		msi cnt;
		string name, type;
		for (int n = 0; n < N; n++) {
			cin >> name >> type;
			cnt[type]++;
		}
		int M = cnt.size();
		memset(arr, 0, M * 4);
		int m = 0;
		for (auto it = cnt.begin(); it != cnt.end(); it++, m++) {
			arr[m] = it->second;
		}

		ll rst = 1;
		for (int m = 0; m < M; m++) {
			rst *= (arr[m] + 1);
		}
		cout << --rst << "\n";
	}

	return 0;
}

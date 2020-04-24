/*
boj_10775_����(���̵� : ���2)
Disjoint setGreedy / Segment tree / Set
���μ����� : ��带 ����ϰ� ���� n�� n-1�� mearge�Ͽ�
���̻� �� ��带 ������� ���ϵ��� �ϴ� ���� �ٽ�

segment tree : lowerbound�� ���� �� �� �ִ� �ڸ� Ž��, ���� ����

set : lowerbound�� ���� �� �� �ִ� �ڸ� Ž��, ���� ���� ������
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

int G, P;
int arr[100001];
si s;

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> G >> P;
	for (int p = 1; p <= P; p++) {
		cin >> arr[p];
	}

	for (int g = 1; g <= G; g++) {
		s.insert(-g);
	}

	int rst = 0;
	for (int p = 1; p <= min(P, G); p++) {
		auto it = s.lower_bound(-arr[p]);
		if (it == s.end()) break;
		rst++;
		s.erase(it);
	}

	cout << rst << "\n";

	return 0;
}




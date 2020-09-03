/*
boj_2295_�� ���� ��(���̵� : �ǹ�1)
BinSearch
�� ���� ���� Bruteforcing ���� ���ϸ� 1000 * 1000 * 1000 ���� 10���� ��
���� 1000*1000(�� ������), 1000*1000(�� ���� ��) ���� ���� �� ���� �ĺ����� ���ϰ�
������ ���� �Ǵ� �ĺ��� ���� Ž������ �߸��� ��
���� �ð� ���⵵�� O(N^2lg(N^2)) �� ��
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

vi candidate;
vii target;
int N;
int arr[1000];
int binMax;

bool cmp(ii a, ii b) {
	if (a.first == b.first) {
		return a.second > b.second;
	}
	else {
		return a.first < b.first;
	}
}

void binSearch(int i, int j, int num) {
	if (i > j) return;
	int mid = (i + j) >> 1;
	if (target[mid].first == num) {
		binMax = max(binMax, target[mid].second);
		binSearch(i, mid - 1, num);
	}
	else if (target[mid].first > num) {
		binSearch(i, mid - 1, num);
	}
	else {
		binSearch(mid + 1, j, num);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			candidate.push_back(arr[i] + arr[j]);
			target.push_back({ arr[j] - arr[i], arr[j] });
		}
	}
	sort(target.begin(), target.end(), cmp);

	int rst = 0;
	for (int i : candidate) {
		binMax = -1;
		binSearch(0, candidate.size() - 1, i);
		rst = max(rst, binMax);
	}

	cout << rst << "\n";

	return 0;
}



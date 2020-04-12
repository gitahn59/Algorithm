/*
boj_11758_CCW(���̵� : ���5)
���� : CCW
���� ���� k�� ���ϴ� ���⿡ ���� ������ ��Ģ�� ���� AB, AC�� ��ġ�� ������
k�� ����̸� AB�� AC���� �����ʿ� �����Ƿ� �ݽð� ����
K�� 0�̸� AB, AC�� ����
k�� �����̸� AB�� AC���� ���ʿ� �����Ƿ� �ð����

���� U x V = m1n2 - m2n1 ( U = (m1,m2) V = (n1, n2) )
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

ii A, B, C;
ii AB, AC;

int ccw(ii left, ii right) {
	int rst = left.first * right.second - left.second * right.first;
	if (rst == 0) return 0;
	else if (rst > 0) return 1;
	else return -1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> A.first >> A.second;
	cin >> B.first >> B.second;
	cin >> C.first >> C.second;

	AB = { B.first - A.first, B.second - A.second };
	AC = { C.first - A.first, C.second - A.second };

	cout << ccw(AB, AC) << "\n";

	return 0;
}


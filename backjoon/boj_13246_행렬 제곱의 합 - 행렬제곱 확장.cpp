/*
boj_13246_��� ������ ��(���̵� : ���2)
boj_10830�� Ȯ�� ����
����� ���չ�Ģ�� �����ϹǷ� ���������� ���� �ذ��� �� ����
ex)
S2 = A1 + A2
A3 + A4 = A2 * S2

���� ������ �̿��Ͽ� SB�� �ִ� ��θ� �̸� ����ϰ�
��ο� ���� ���� ������
S10 = S5 + S5
S5 = S2 + A2*S2 + A5
S2 = A1 + A2
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

ll N, B;
vvi matrix;

void myPlus(vvi& a, vvi b) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			a[i][j] = (a[i][j] + b[i][j]) % 1000;
		}
	}
}

vvi multiple(vvi a, vvi b) {
	vvi result(N + 1, vi(N + 1, 0));

	for (int i = 1; i <= N; i++) { // i��
		for (int j = 1; j <= N; j++) { // j��
			for (int k = 1; k <= N; k++) { // k��
				result[i][j] = (result[i][j] + (a[i][k] * b[k][j])) % 1000;
			}
		}
	}
	return result;
}

void solve() {
	ll num = B;
	vi path;
	while (num > 1) {
		if (num % 2 == 0) {
			path.push_back(0);
		}
		else {
			path.push_back(1);
		}
		num /= 2;
	}
	reverse(path.begin(), path.end());

	vvi A_B(N + 1, vi(N + 1, 0));
	A_B = matrix;

	vvi left = matrix;
	for (int task : path) {
		if (task == 0) {
			left;
			vvi right = multiple(left, A_B);
			myPlus(left, right);
			A_B = multiple(A_B, A_B);
		}
		else if (task == 1) {
			left;
			vvi right = multiple(left, A_B);
			myPlus(left, right);
			A_B = multiple(A_B, A_B);
			A_B = multiple(A_B, matrix);
			myPlus(left, A_B);
		}
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << left[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> B;
	for (int n = 1; n <= N + 1; n++) {
		matrix.push_back(vi(N + 1, 0));
	}

	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= N; i++) {
			cin >> matrix[n][i];
			matrix[n][i] = matrix[n][i] % 1000;
		}
	}

	solve();

}
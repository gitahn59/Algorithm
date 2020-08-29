/*
pro_67258_��������(���̵� : level3)
Sweeping
1���� �����ι���
1. ��� ������ �����ϴ� ù��° ���� Ž��
2. �� �������� �����ؼ� ��� ��ĭ�� ������ Ȯ���ϰ�,
	�¿��� �ʿ���� �������� �Ź� ������ 
	=> �׻� ��� ������ �����ϴ� ���·� ���� �̵�
3. Ž�� �߿� �ĺ��Ǵ� ������ �� ���� ª�� ���� ���
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

int M;
int cnt[100000];
vi candidate;

void preprocessing(vector<string>& gems) {
	int idx = 1;
	map<string, int> id;

	for (string s : gems) {
		if (id[s] == 0) {
			id[s] = idx++;
		}
		candidate.push_back(id[s] - 1);
	}
	M = idx - 1;
}

vi sweeping() {
	set<int> first;
	int N = candidate.size();
	int i = 0;
	// first
	for (; i < N; i++) {
		first.insert(candidate[i]);
		cnt[candidate[i]]++;
		if (first.size() == M) {
			break;
		}
	}

	ii rst = { 0,i };
	while (rst.first < rst.second && cnt[candidate[rst.first]] > 1) {
		cnt[candidate[rst.first]]--;
		rst.first++;
	}
	ii range = rst;
	i++;
	for (i; i < N; i++) {
		cnt[candidate[i]]++;
		range.second++;
		while (range.first < range.second && cnt[candidate[range.first]]>1) {
			cnt[candidate[range.first]]--;
			range.first++;
		}
		if (rst.second - rst.first > range.second - range.first) {
			rst = range;
		}
	}

	return { rst.first + 1, rst.second + 1 };
}

vector<int> solution(vector<string> gems) {
	vector<int> answer;
	preprocessing(gems);
	return sweeping();
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	vi rst = solution({ "b","a","b","b", "c","c","b","a" });

	return 0;
}



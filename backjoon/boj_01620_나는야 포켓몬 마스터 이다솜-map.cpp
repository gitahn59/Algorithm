/*
boj_01620_나는야 포켓몬 마스터 이다솜(난이도 : 실버4)
map으로 string 에 대한 번호를 기록
map을 사용한 query이므로 logN 시간에 탐색 가능
O(NlogN)
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
typedef vector<vi> adj;
typedef deque<int> di;
typedef pair<int, ii> iii;
typedef set<int> si;

int N, M;

string arr[100001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	map<string, int> msi;

	for (int n = 1; n <= N; n++) {
		string s;
		cin >> s;
		msi.insert({ s,n });
		arr[n] = s;
	}

	for (int m = 1; m <= M; m++) {
		string query;
		cin >> query;
		if ('0' <= query[0] && query[0] <= '9') {
			cout << arr[stoi(query)] << "\n";
		}
		else {
			cout << msi[query] << "\n";
		}
	}
}
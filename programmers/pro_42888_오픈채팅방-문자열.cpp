/*
pro_42888_오픈채팅방(난이도 : level 2)
문자열 파싱
간단한 문자열 파싱, mapping 문제
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

typedef struct info {
	int type; string id;
}Info;
int N;
int cnt;

Info arr[100001];
map<string, string>  mss;

vector<string> solution(vector<string> record) {
	N = record.size();
	char temp[30];
	for (int n = 1; n <= N; n++) {
		strcpy(temp + 1, record[n - 1].c_str());
		if (temp[1] == 'E') {
			char* p = strtok(temp + 1, " ");
			p = strtok(NULL, " ");
			cnt++;
			string id(p);
			arr[cnt] = { 1, id };
			p = strtok(NULL, " ");
			string name(p);
			mss[id] = name;
		}
		else if (temp[1] == 'L') {
			char* p = strtok(temp + 1, " "); p = strtok(NULL, " ");
			cnt++;
			string id(p);
			arr[cnt] = { 2, id };
		}
		else {
			char* p = strtok(temp + 1, " ");
			p = strtok(NULL, " "); string id(p);
			p = strtok(NULL, " "); string name(p);
			mss[id] = name;
		}
	}

	vector<string> answer;
	for (int i = 1; i <= cnt; i++) {
		string rst;
		if (arr[i].type == 1) {
			rst = mss[arr[i].id] + "님이 들어왔습니다.";
		}
		else {
			rst = mss[arr[i].id] + "님이 나갔습니다.";
		}
		answer.push_back(rst);
	}
	return answer;
}

int main() {
	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan" });


	return 0;
}

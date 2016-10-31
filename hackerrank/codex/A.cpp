/*
Author : lifecodemohit
*/

#ifdef __APPLE__

    #include <cassert>
    #include <iostream>
    #include <iomanip>
    #include <ctime>
    #include <cstdio>
    #include <vector>
    #include <algorithm>
    #include <utility>
    #include <queue>
    #include <stack>
    #include <string>
    #include <cstring>
    #include <sstream>
    #include <map>
    #include <set>
    #include <unordered_map>
    #include <unordered_set>

#else

    #include <bits/stdc++.h>

#endif  

using namespace std;

vector < int > v1;

void prime() {
	v1.push_back(1);
	for (int i = 2; i <= 1000001; i++) {
		bool flag = true;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i%j == 0) {
				flag = false;
				break;
			}
		}
		if (flag)
			v1.push_back(i);
	}
}

int main()
{
	prime();
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (i&1) {
			int x = i-1;
			x = x/2;
			if (!(x&1))
				cnt++;
		}
		else {
			int x = i;
			x = x/2;
			if ((x&1))
				cnt++;
		}
	}
	bool flag = true;
	for (int j = 2; j <= sqrt(cnt); j++) {
		if (cnt%j == 0) {
			flag = false;
			break;
		}
	}
	cout << cnt << endl;
	if (flag) {
		cout << cnt << endl;
		return 0;
	}

	int ans = 1;
	int sz = v1.size();
	cout << cnt << endl;
	for (int i = 0; i < sz; i++) {
		if (cnt%v1[i] == 0)
			ans = v1[i];
		else if (cnt < v1[i])
			break;
	}
	cout << ans << endl;
	return 0;
}
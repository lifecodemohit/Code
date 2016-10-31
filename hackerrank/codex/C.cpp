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
map < int, long long > m1;

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		v1.clear();
		m1.clear();
		int n, m, s;
		cin >> n >> m >> s;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int x;
				cin >> x;
				m1[x]++;
				if (m1[x] == 1)
					v1.push_back(x);
			}
		}
		int sz = v1.size();
		long long ans = -1;
		for (int i = 0; i < sz; i++) {
			int elem = v1[i];
			bool flag = true;
			long long opr = 0;
			for (int j = 0; j < sz; j++) {
				if (abs(v1[i]-v1[j])%s == 0) {
					opr = opr + (m1[v1[j]])*(abs(v1[i]-v1[j])/s);
				}
				else {
					flag = false;
				}
			}
			if (flag) {
				if (ans == -1)
					ans = opr;
				else
					ans =  min(ans, opr);
			}
 		}
		cout << ans << endl;
	}
	return 0;
}
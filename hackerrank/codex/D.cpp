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

int main()
{
	int t;
	cin >> t;
	while (t--) {
		string word = "vedaytas";
		string rword = "satyadev";
		string str;
		cin >> str;
		const int sz = str.length();
		if (sz < 16) {
			cout << "No Treat" << endl;
		}
		else {
			int pre[sz];
			for (int i = 0; i < sz/2 + sz%2; i++) {
				if (i == 0) {
					pre[i] = (str[i] != str[sz-1-i]);
				}
				else {
					pre[i] = pre[i-1] + (str[i] != str[sz-1-i]); 
				}
			}
			int ans = -1;
			string res = "";
			for (int i = 7; i < sz/2 + sz%2; i++) {
				int opr = 0;
				for (int j = 0; j < 8; j++) {
					if (str[i-j] != word[7-j])
						opr++;
					if (str[sz-1-i+j] != rword[j])
						opr++;
				}
				if (i-8 >= 0)
					opr = opr + pre[sz/2+sz%2-1] - (pre[i]-pre[i-8]);
				else
					opr = opr + pre[sz/2+sz%2-1] - (pre[i]);
				if (ans == -1 || ans >= opr) {
					string this_ = str;
					for (int j = 0; j < sz; j++) {
						this_[j] = min(str[j], str[sz-1-j]);
					}
					for (int j = 0; j < 8; j++) {
						this_[i-j] = word[7-j];
						this_[sz-1-i+j] = rword[j];
					}
					if (ans == -1) {
						ans = opr;
						res = this_;
					}
					else {
						ans = opr;
						res = min(res, this_);
					}
				}
			}
			cout << res << " " << ans << endl;
		}
	}
	return 0;
}
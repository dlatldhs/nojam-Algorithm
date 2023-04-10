# DPS와 BPS

## 활동 1
```cpp
#include <bits/stdc++.h>
using namespace std;
int n;
vector<string> v;
string s;

vector<string> split(string input , string delimiter) {
	vector<string> ret;
	long long pos;
	string token="";
	while( (pos = input.find(delimiter)) != string::npos ) {
		token = input.substr(0,pos);
		ret.push_back(token);
		input.erase(0,pos+delimiter.length());
	}
	ret.push_back(input);
	return ret;
}

int main() {
	cin >> n;
	cin.ignore();
	for ( int i = 0 ; i < n ; i++ ) {
		getline(cin,s);
		v.push_back(s);
	}
	string d = " ";
	
	for ( auto it : v ) split(it,d);
	return 0;
}
```

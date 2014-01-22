#include <iostream>
#include <string>

using namespace std;

// // 简单STL应用， 涉及str.length() str.size() str.substr(pos, length)
int main(void) {
	int n;
	cin >> n;
	
	while(n--) {
		int count = 0;
		string sub, str;
		cin >> sub >> str;
		int len = sub.length();

		int begin = 0;
		while(begin < str.length()) {
			if(sub == str.substr(begin, len))
				count ++;
			begin ++;
		}
		cout << count << endl;
	}

	return 0;
}

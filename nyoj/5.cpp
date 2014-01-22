#include <iostream>
#include <string>

using namespace std;

// 简单STL应用， 涉及str.length() str.size() str.find(sub, pos)
int main(void) {
	int n, times;
	string sub, str;
	cin >> n;

	while(n--) {
		times = 0;
		cin >> sub >> str;
		int begin = str.find(sub);
		int len = sub.length();
		while(begin != -1) {
			times ++;
			//str.erase(begin, len);
			begin = str.find(sub, begin+1);
		}
		cout << times << endl;
	}

	return 0;
}

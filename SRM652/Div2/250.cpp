#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <stack>
#include <iterator>
using namespace std;

class ValueOfString {
public:
	int findValue(string s) {
		int val = 0;
		int l = s.length();
		for (int i = 0; i < s.length(); i++) {
			char c = s[i];
			int sum = 0;
			for (int j = 0; j < s.length(); j++) {
				if (c >= s[j]) sum++;
			}
			val += (c - 'a' + 1) * sum;
		}
		return val;
	}
};
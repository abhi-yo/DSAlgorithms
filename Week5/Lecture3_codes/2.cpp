#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string removeOccurrences(string s, string part) {
        int pos = s.find(part);
        while (pos != string::npos) {
            s.erase(pos, part.length());
            pos = s.find(part);
        }
        return s;
    }
};

int main() {
    Solution solution;
    string s = "leetcode";
    string part = "leet";
    string result = solution.removeOccurrences(s, part);
    cout << "Original string: " << s << endl;
    cout << "Part to remove: " << part << endl;
    cout << "Resulting string: " << result << endl;
    return 0;
}

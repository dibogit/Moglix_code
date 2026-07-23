#include <iostream>
#include <stack>
#include <string>
using namespace std;

int longestValid(string s) {
    stack<int> st1;
    st1.push(-1);
    int maxlen = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st1.push(i);
        } else {
            st1.pop();

            if (st1.empty()) {
                st1.push(i);
            } else {
                maxlen = max(maxlen, i - st1.top());
            }
        }
    }

    return maxlen;
}

int main() {
    string s;
    cin >> s;

    cout << longestValid(s) << endl;

    return 0;
}
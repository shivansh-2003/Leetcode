class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int c1 = 0;

        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else if (!st.empty() && st.top() == '(') {
                st.pop();
            } else {
                c1++;
            }
        }

        return c1 + st.size();
    }
};
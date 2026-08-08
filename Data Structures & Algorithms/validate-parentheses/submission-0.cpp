class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char c : s) {

            // If it is an opening bracket, push it
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            }
            else {
                // If there is no opening bracket
                if (st.empty())
                    return false;

                char top = st.top();
                st.pop();

                // Check if the brackets match
                if (c == ')' && top != '(')
                    return false;

                if (c == '}' && top != '{')
                    return false;

                if (c == ']' && top != '[')
                    return false;
            }
        }

        // Stack should be empty if all brackets are matched
        return st.empty();
    }
};


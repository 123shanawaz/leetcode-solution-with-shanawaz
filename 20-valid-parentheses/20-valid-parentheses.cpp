class Solution {
public:
    bool isValid(string s) {stack<char> stack;

	for (auto ch : s) {
		if (ch == '{' || ch == '(' || ch == '[')
			stack.push(ch);
		else {
			if (stack.empty() == true) {
				return false;
			}
			else if (ch == '}' && stack.top() == '{')
				stack.pop();
			else if (ch == ']' && stack.top() == '[')
				stack.pop();
			else if (ch == ')' && stack.top() == '(')
				stack.pop();
			else
				return false;
		}
	}

	return stack.empty() == true;
}
        
    
    
};
class Solution {
public:
    bool isValid(string s) {
        stack<char> MyStack;

        for(int i = 0; i < s.size(); i++){
            switch(s[i]){
                case '(':
                    MyStack.push(')');
                    break;
                case '[':
                    MyStack.push(']');
                    break;
                case '{':
                    MyStack.push('}');
                    break;
                default:
                    if(MyStack.size() == 0 || s[i] != MyStack.top())
                        return false;
                    MyStack.pop();
            }
        }

        if(MyStack.size() == 0)
            return true;
        else
            return false;
    }
};

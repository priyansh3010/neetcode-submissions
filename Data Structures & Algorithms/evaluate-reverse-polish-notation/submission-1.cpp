class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        int sum = stoi(tokens[0]);
        for (string token : tokens) {
            if (token == "+") {
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();

                int currResult = num1 + num2;
                s.push(currResult);
                sum = currResult;
            }
            else if (token == "-") {
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();

                int currResult = num1 - num2;
                s.push(currResult);
                sum = currResult;

            }
            else if (token == "*") {
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();

                int currResult = num1 * num2;
                s.push(currResult);
                sum = currResult;

            }
            else if (token == "/") {
                int num2 = s.top();
                s.pop();
                int num1 = s.top();
                s.pop();

                int currResult = num1 / num2;
                s.push(currResult);
                sum = currResult;

            }
            else {
                s.push(stoi(token));
            }
        }


        return sum;
    }
};

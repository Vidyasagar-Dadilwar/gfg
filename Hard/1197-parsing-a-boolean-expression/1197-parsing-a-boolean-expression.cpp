class Solution {
public:
    // 1. create stack and push everything except ',' ')'
    // 2. iterate over each element of expression
    // 2.1 if element is ')', pop everything and push in vector until '(' is found
    // 2.2 extract the operator
    // 3. pass boolean expression and operator to helper function
    // 3.1 if operator is '&' return f if any 'f' encountered, do same for '|' and '!'
    // 4. In main return the top of the stack i.e the answer 

    char solve(char op, vector<char>&boolExp){
        if(op == '&'){
            for(auto i: boolExp){
                if(i == 'f')
                    return 'f';
            }
            return 't';
        }
        else if(op == '|'){
            for(auto i: boolExp){
                if(i == 't')
                    return 't';
            }
            return 'f';
        }
        else if(op == '!'){
            return (boolExp[0] == 't')?'f':'t';
        }
        return 'f';
    }
    bool parseBoolExpr(string expression) {
        stack<char>stk;
        for(auto i: expression){
            if(i != ',' && i != ')'){
                stk.push(i);
            }
            else if(i == ')'){
                vector<char>boolExp;
                while(stk.top()!='('){
                    boolExp.push_back(stk.top());
                    stk.pop();
                }
                stk.pop();   // removes '('
                char op = stk.top();
                stk.pop();
                stk.push(solve(op, boolExp));
            }
        }
        return stk.top() == 't';
    }
};
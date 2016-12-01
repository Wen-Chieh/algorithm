class calculator{

    int calc(string& str, int& curIdx){
        stack<int> stk;
        int num = 0;
        char sign = '+';
        int size = str.size();
        bool fromInnerBracket;
        
        while(curIdx < size){
            fromInnerBracket = false;
            
            if(isdigit(str[curIdx])){
                num = num * 10 + (str[curIdx] - '0');
            }
            else if(str[curIdx] == '('){
                curIdx++;//discard '('
                num = calc(str, curIdx);
                fromInnerBracket = true;//indicating that ")" is from inner bracket
            }
            
            if(str[curIdx] == '+' || str[curIdx] == '-' || str[curIdx] == '*' || str[curIdx] == '/' ||
               (!fromInnerBracket && str[curIdx] == ')')|| curIdx == size-1){
                
                if(sign == '+') stk.push(num);
                else if(sign == '-') stk.push(-num);
                else if(sign == '*'){
                    int prevNum = stk.top();
                    stk.pop();
                    stk.push(prevNum * num);
                }
                else{
                    int prevNum = stk.top();
                    stk.pop();
                    stk.push(prevNum / num);
                }
                num = 0;
                if(str[curIdx] == ')') break;
                sign = str[curIdx];
            }
            curIdx++;
        }
        
        num = 0;
        while(!stk.empty()){
            num += stk.top();
            stk.pop();
        }
        return num;
    }
    
public:
    int calc(string& str){
        int curIdx = 0;
        return calc(str, curIdx);
    }
};
class calculator{

    int calc1(string& str, int& curIdx){
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
                num = calc1(str, curIdx);
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
    
    /*Calculator not using stack*/
    int calc2(string& str, int& curIdx){
        int result = 0, curNum = 0, prevNum = 0;
        int prevOprtr = '+';
        int size = str.size();
        while(curIdx < size){
            if(isdigit(str[curIdx])){
                /*Calculate current number. If previous operator is a '*' or '/', combine current number with previous number.*/
                
                curNum = 0;
                while(curIdx < size && isdigit(str[curIdx]))
                    curNum += curNum * 10 + (str[curIdx++] - '0');
                
                if(prevOprtr == '-') curNum = -curNum;
                else if(prevOprtr == '*') curNum = prevNum * curNum;
                else if(prevOprtr == '/') curNum = prevNum / curNum;
                
                curIdx--;//make curIdx point at the last digit of current number
            }
            else if(str[curIdx] == '('){
                curIdx++;//discard the index of '('
                curNum = calc2(str, curIdx);
                if(prevOprtr == '-') curNum = -curNum;
                else if(prevOprtr == '*') curNum = prevNum * curNum;
                else if(prevOprtr == '/') curNum = prevNum / curNum;
            }
            else if(str[curIdx] == ')'){
                break;
            }
            else if(!isspace(str[curIdx])){
                if(str[curIdx] == '+' || str[curIdx] == '-')    result += curNum;
                else                                            prevNum = curNum;
                curNum = 0;
                prevOprtr = str[curIdx];
            }
            
            curIdx++;
        }
        return result + curNum;
    }
public:
    int calc(string& str){
        int curIdx = 0;
        /*optional:
        calc2(str, curIdx);*/
        return calc1(str, curIdx);
    }
};
// Naive: Complexity - Time O(1) Space O(N)

The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
/*returns min element from stack*/
int _stack :: getMin() {
    if(s.empty())
        return -1;
    else
        return s.top();
   
}
/*returns poped element from stack*/
int _stack ::pop(){
    if(!s.empty()) {
        int x;
        s.pop();
        x = s.top();
        s.pop();
        return x;
    }
    else
        return -1;
}
/*push element x into the stack*/
void _stack::push(int x) {
    int m;
    if(!s.empty())
        m = min(s.top(), x);
    else
        m = x;
    
    s.push(x);
    s.push(m);
}

// Mathematical Manipulation - Time O(1) Space O(1)
/*returns min element from stack*/
int _stack :: getMin() {
    if(!s.empty())
        return minEle;
    else
        return -1;
}
/*returns poped element from stack*/
int _stack ::pop(){
    int x;
    if(!s.empty()) {
        if(s.top() >= minEle) {
            x = s.top();
            s.pop();
        }
        else {
            x = minEle;
            minEle = 2*minEle - s.top();
            s.pop();
        }
        return x;
    }
    else
        return -1;
}
/*push element x into the stack*/
void _stack::push(int x) {
    if(!s.empty()) {
        if(minEle <= x)
            s.push(x);
        else {
            s.push(2*x - minEle);
            minEle = x;
        }
    }
    else {
        s.push(x);
        minEle = x;
    }
}

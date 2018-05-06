#include<bits/stdc++.h>
using namespace std;
/*
Imagine you have a special keyboard with the following keys: 
Key 1:  Prints 'A' on screen
Key 2: (Ctrl-A): Select screen
Key 3: (Ctrl-C): Copy selection to buffer
Key 4: (Ctrl-V): Print buffer on screen appending it
                 after what has already been printed. 

If you can only press the keyboard for N times (with the above four keys), 
write a program to produce maximum numbers of A's. That is to say, the input parameter is N 
(No. of keys that you can press), the output is M (No. of As that you can produce).
*/

/*
Catch to the solution is that for keystroke upto 6 maximum no. of a's that can be printed is 6.
There aren't any advantages of pressing the CTRL+A CTRL+C CTRL+V key.
Now if their is more than 6 keystrokes you will have to decide which point is best for carrying out CTRL+A CTRL+C 
followed by series of CTRL+v.
For this after every keypress from the 6th keypress we try to find out the breakpoint after which performing 
copy paste produces maximum no. of a's.
*/


//Solution 1 : Recursive
int copypaste(int n) {
    if(n < 7)
        return n;
    
    int ans = n;
    for(int b=n-3; b>=1; b--) {
        int curr = (n-b-1)*copypaste(b);
        ans = max(ans, curr);
    }
    return ans;
}

//Solution 2 : Dynamic Programming
int copypasteDP(int n) {
    if(n < 7)
        return n;
    
    int screen[n] = {};
    for(int i=1; i<=6; i++) {
        screen[i-1] = i;
    }

    for(int i=7; i<=n; i++) {
        screen[i-1] = 0;
        for(int b=i-3; b>=1; b--) {
            int curr = (i-b-1)*screen[b-1];
            screen[i-1] = max(screen[i-1], curr);
        }
    }

    return screen[n-1];
}


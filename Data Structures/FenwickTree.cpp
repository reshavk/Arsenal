/*
Fenwick tree also known as Binary Indexed Tree, serves the purpose of solving range based query efficiently.
It is analagous with segment tree but is still used due to less line of codes (although more complexity of understanding).
Given below is the use of fenwick tree for one of the most trivial range queries
Prefix Sum

When to use Binary Indexed Tree?

Before going for Binary Indexed tree to perform operations over range, one must confirm that the operation or the function is:

Associative. i.e 
f(f(a,b),c)=f(a,f(b,c))
f(f(a,b),c)=f(a,f(b,c)) 
this is true even for seg-tree

Has an inverse. eg:

Addition has inverse subtraction (this example we have discussed)
Multiplication has inverse division
gcd() :gcd() has no inverse, so we can’t use BIT to calculate range gcd’s
Sum of matrices has inverse
Product of matrices would have inverse if it is given that matrices are degenerate i.e. determinant of any matrix is not equal to 0

*/
const int MAX = 1e5+7;
long long BIT[MAX] = {};

void update(int x, int val) {
	for( ; x<=n; x += x&-x ) {
		BIT[x] += val;
	}
}

void query(int x) {
	long long sum = 0;
	for( ; x>0; x -= x&-x) {
		sum += BIT[x];
	}
	return sum;
}
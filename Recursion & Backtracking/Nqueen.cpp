//Solution to popular N-Queen Problem

/*
N-Queen problem states that for a chess boar of dimension N X N what is the arrangement of N no. of queens in such a
way that these queens don't attack each other.
*/
#include<bits/stdc++.h>
using namespace std;

//Backtracking Recursive solution : 
bool board[8][8] = {};
vector<int> ans;
bool sol;

bool issafe(int n, int row, int col) {
    for(int i=col; i>=1; i--) {
        if(board[row][i])
            return false;
    }

    for(int i=row, j=col; i>=1 && j>=1; i--, j--) {
        if(board[i][j])
            return false;
    }

    for(int i=row,j=col; i <= n && j>=1; i++, j--) {
        if(board[i][j])
            return false;
    }
    return true;
}

void nqueenUtil(int n, int col, int row) {
    if(ans.size() == n) {
        sol = true;
        cout << "[";
        for(int i=0; i<n; i++)
            cout << ans[i] << " ";
        cout << "] ";
        return;
    }
    
    if(col > n)
        return;
    
    for(int i=1; i<=n; i++) {
        if(issafe(n, i, col+1)) {
            board[i][col+1] = true;
            ans.push_back(i);
            nqueenUtil(n, col+1, i);
            ans.pop_back();
            board[i][col+1] = false;
        }
    }
    return;
}


void nqueen(int n) {
    int row = 1;
    sol = false;
    for(int i=1; i<=n; i++) {
        nqueenUtil(n, i, row);
        ans.clear();
        memset(board, false, sizeof(board));
    }
    if(!sol) {
        cout << -1;
    }
    else {
        for(int i=0; i<ans.size(); i++) {
            cout << ans[i] << " ";
        }
    }
    cout << "\n";
}


// prob link: https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#


int celebrity(vector<vector<int> >& M, int n) {
    stack<int> s;
    for(int i=0; i<n; ++i){
        s.push(i);
    }
    while(s.size() >= 2){
        int fr = s.top();
        s.pop();
        int sc = s.top();
        s.pop();
        if(M[fr][sc]) s.push(sc);
        else s.push(fr);
    }
    int e = s.top();
    for(int i=0; i<n && i!=e; ++i){
        if(M[i][e] == 0) return -1;
    }
    for(int j=0; j<n; ++j){
        if(M[e][j] == 1) return -1;
    }
    return e;
}
// Time complx: O(n+n+n+n) = O(n)
// Space complx: O(n)
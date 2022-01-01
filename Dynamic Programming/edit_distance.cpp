

// prob link: https://leetcode.com/problems/edit-distance/


// Method-1 (recursion or brute force)

int editDist(string r, string s, int idxR, int idxS){
    if(idxR == 0) return idxS;
    if(idxS == 0) return idxR;
    

    int minVal = min(min(editDist(r,s,idxR-1,idxS-1),   // Replace
     editDist(r,s,idxR-1,idxS)),                        // Remove
      editDist(r,s,idxR,idxS-1));                       // Insert
    if(r[idxR-1] == s[idxS-1])
        return editDist(r,s,idxR-1,idxS-1);
    else
        return (minVal+1);
    
}


// Time Complx: O(3^n)
// Space Complx: O(n)



//Method-2

int editDist(string r, string s, int idxR, int idxS){
    for(int i=0; i<=idxR; i++){
        for(int j=0; j<=idxS; j++){
            if(i == 0){
                dp[i][j] = j;
            }
            else if(j == 0){
                dp[i][j] = i;
            }
            else{
                int minVal = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
                if(r[i-1] == s[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = minVal+1;
                }
            }
        }
    }
    return dp[idxR][idxS];
    
}
// time: O(n^2)
// space: O(n^2)   2d array is used



//Method-3 (optimised storage space)

const int MAX_SIZE = 500;

int dp[2][MAX_SIZE];
int editDist(string r, string s, int idxR, int idxS){
    
    for(int i=0; i<=idxR; i++){
        for(int j=0; j<=idxS; j++){
            if(i == 0){
                dp[i][j] = j;
            }
            else if(j == 0){
                dp[i%2][j] = i;
            }
            else{
                int minVal = min(min(dp[(i-1)%2][j], dp[i%2][j-1]), dp[(i-1)%2][j-1]);
                if(r[i-1] == s[j-1]){
                    dp[i%2][j] = dp[(i-1)%2][j-1];
                }
                else{
                    dp[i%2][j] = minVal+1;
                }
            }
        }
    }
    return dp[idxR%2][idxS];
    
}

// Time Complx: O(n^2)
// Space Complx: O(n)   


//  [1,2,2,3,4]<-
//  [2,3,4,6,7]<-   <-
//  [1,2,3,4,5]     <-  <-
//  [4,5,6,7,8]         <-
// we only need 2 arrays at a time as we are checcking for [i-1][j-1], [i-1][j], [i][j-1] indexes
// hence take 2*len(str) array and update it while iterations






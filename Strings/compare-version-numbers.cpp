// prob link: https://leetcode.com/problems/compare-version-numbers/


class Solution {
public:
    int compareVersion(string v1, string v2) {
        int i=0, j=0;
        int n1,n2;
        while(i<v1.size() || j<v2.size()){
            n1=0, n2=0;
            while(i<v1.size() && v1[i] != '.'){
                n1 *= 10;
                n1 += (v1[i++]-'0');
            }
            while(j<v2.size() && v2[j] != '.'){
                n2 *= 10;
                n2 += (v2[j++]-'0');
            }
            if(n1 > n2) return 1;
            else if(n1 < n2) return -1;
            i++;
            j++;
        }
        return 0;
    }
};
// Time complx: O(n+m)
// Space complx: O(1)
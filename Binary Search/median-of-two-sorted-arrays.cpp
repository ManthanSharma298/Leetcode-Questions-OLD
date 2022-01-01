// prob link: https://leetcode.com/problems/median-of-two-sorted-arrays/



class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        int m = a.size(), n = b.size();
        double res;
        int k = m+n;
        if(n > m) return findMedianSortedArrays(b, a);
        int l=0, r=n-1;
        while(true){
            int md = l+(r-l)/2;
            int id = (k+1)/2-md;
            
            int bL = (md-1 < 0 ? -1e9 : b[md-1]);
            int bR = (md >= n ? 1e9 : b[md]);
            int aL = (id-1 < 0 ? -1e9 : a[id-1]);
            int aR = (id >= m ? 1e9 : a[id]);
            // cout<<aL<<" "<<aR<<" "<<bL<<" "<<bR<<"\n";
    
            if(aL <= bR && bL <= aR){
                if(k%2 == 1){
                    double v = max(aL, bL);
                    res = v;
                }
                else{
                    double v = max(aL, bL) + min(aR, bR);
                    res = v/2;
                }
                return res;
            }
            else if(bL > aR){
                r = md-1;
            }
            else{
                l = md+1;
            }
        }
        return 0;
    }
};

// Time complx: O(log(min(m,n)))
// Space complx: O(1)
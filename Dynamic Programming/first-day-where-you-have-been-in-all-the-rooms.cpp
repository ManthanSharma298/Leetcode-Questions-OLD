// prob link: https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/


class Solution {
public:
    int m = 1e9+7;
    int firstDayBeenInAllRooms(vector<int>& nv) {
        int n = nv.size();
        vector<long long> f(n,0), s(n,0);
        f[0] = 1;
        s[0] = 2;
        for(int i=1; i<n; ++i){
            f[i] = (s[i-1] + 1)%m;  // first time you visit a room in f[i] days
            s[i] = (f[i] + 1 + f[i] - f[nv[i]] + m)%m;
            // second time you visit a room in f[i] days
            // first reach i in f[i] days
            // then by moving to nv[i] which require 1 day
            // then d days from nv[i] to again i
            // hence f[i] + 1 + d 
            // where d = f[i] - f[nv[i]]
        }
        return (f[n-1]+m-1)%m;
    }
};
// Time complx: O(n)
// Space complx: O(n + n) = O(n)

// prob link: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/

// Method - 1 (Brute Force)

class Solution {
public:
    set<int>st;
    int log(int a){
        int b = 1;
        for (int i = 0; i <= 16; ++i){
            if(a == b)
                return i;
            if (a < b)
                return i - 1;
            b *= 3;
        }
        return 0;
    }
    
    bool checkPowersOfThree(int n) {
        if(n == 0) return true;
        
        int lg = log(n);    
        if(st.count(lg)) return false;
        st.insert(lg);
        return checkPowersOfThree(n - pow(3, lg));
    
    }
};


// Time complx: O(logn)
// Space complx: O(logn)





// Method - 2 (Ternary approach like binary)

class Solution {
public:
    
    bool checkPowersOfThree(int n) {
    	while(n){
			if(n%3 == 2) return false;	// base case

			n /= 3;
		}
        return true;
   	}
};

// Time complx: O(logn) {base 3}
// Space complx: O(1) 

// it is like a binary number eg 1010 -> 2^3*1 + 2^1*1
// it means 1, 3 powers of two can sum up to get the given number
//
// if n is divided by three there are 3 possibilities
// n%3 = 0,1,2
// but n%3 != 2 as if it is 2 then
// consider eg  201 -> 3^2*2 + 3^0*1 = 3^2 + 3^2 + 3^0*1
// power 2 is used twice but all powers are unique according to question
// then if n%3 == 2 we return false

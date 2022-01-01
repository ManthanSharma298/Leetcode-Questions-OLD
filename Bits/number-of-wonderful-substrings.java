
// prob link: https://leetcode.com/problems/number-of-wonderful-substrings/

class Solution {
    public long wonderfulSubstrings(String word) {
        int mask = 0;
        long res = 0;
        
        char[] w = word.toCharArray();
        long[] fq = new long[1025]; 
        fq[0] = 1;
        for(char ch: w){
            int flip = (1 << (ch - 'a'));
            mask = (mask ^ flip);
            res += fq[mask];
            for(int i=0; i<10; ++i){
                res += fq[mask ^ (1 << i)];
            }
            fq[mask]++;
        }
        return res;
    }
}

// APPROACH
// abcda -> 1110
// bit represents that the ith character is occuring odd number of times or even number of times
// 0 -> even and 1 -> odd 
// for each representation 110000...11 it denotes a state giving us the pairity of each character

// When we encounter a character we flip that bit of the mask
// as if before it was present odd number of times then now it is even and vice versa
// and increment the count of that state by one
// 
// but the additional condition is that we can have atmost 1 character present odd number of times
// for this we need to traverse for all numbers and flip their bit and add the count to result
// then increment the frequency of the mask



// n = word.length
// Time complx: O(10*n) = O(n)
// Space complx: (1025) = O(1)


// prob link: https://www.lintcode.com/problem/659/

class Solution {
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs) {
        // write your code here
        string res;
        for(string str: strs){
            res += to_string(str.size()) + "#" + str;
        }
        // cout<<res<<"\n";
        return res;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str) {
        // write your code here
        vector<string> res;
        int n = str.size(), i=0, len;
        while(i < n){
            int j = i;
            while(str[j] != '#'){
                j++;
            }
            len = stoi(str.substr(i, j-i));
            i = j+1;
            res.push_back(str.substr(i, len));
            i += len;
        }
        return res;
    }
};

// # is requires eg ["2res","time"]
// then string becomes "42res4time"
// so it means 42 
// hence "4#2res4#time"

// Time complx: O(N)
// Space complx: O(1)
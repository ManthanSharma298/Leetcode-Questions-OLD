// prob link: https://leetcode.com/problems/find-median-from-data-stream/


class MedianFinder {
    priority_queue<int> p1;
    priority_queue<int,vector<int>,greater<int>> p2;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(p1.size() == 0) p1.push(num);
        else if(num < p1.top()) p1.push(num);
        else p2.push(num);
        
        int s1 = p1.size(), s2 = p2.size();
        if(abs(s1-s2) > 1){
            if(s1 > s2){
                p2.push(p1.top());
                p1.pop();
            }
            else{
                p1.push(p2.top());
                p2.pop();
            }
        }
    }
    
    double findMedian() {
        double md;
        int s1 = p1.size(), s2 = p2.size();
        if(s1 == s2 && s1 > 0){
            double num = p1.top() + p2.top();
            md = num/2;
        }
        else if(s1 > s2){
            md = p1.top();
        }
        else{
            md = p2.top();
        }
        return md;
    }
};
// addNum -> O(log(s1) + log(s2))
// findMed -> O(1)
// Space complx: O(s1 + s2)
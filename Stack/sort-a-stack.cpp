// prob link: https://www.codingninjas.com/codestudio/problems/sort-a-stack_985275?leftPanelTab=0


// Using recursion
void insert(stack<int>& s, int e){
    if(s.empty() || e > s.top()){
        s.push(e);
        return;
    }
    int tp = s.top();
    s.pop();
    insert(s,e);	// insert in remaining stack as it is less than top
    s.push(tp);		// push the top again
}
void sortStack(stack<int> &stack){
    if(stack.empty()) return;
        
    int tp = stack.top();
    stack.pop();
    sortStack(stack);	// to sort the remaining stack
    insert(stack,tp);   // to insert the element at its correct position
}
// Time complx: O(n*n)
// Space complx: o(n + n) = O(n)    for stack calls


// Using two stacks
void sortStack(stack<int> &sk){
	stack<int> s,t;
    int cnt=0;
    while(!sk.empty()){
        int curr = sk.top();
        sk.pop();
        while(!s.empty()){
            cnt++;
            if(curr < s.top()){
                t.push(s.top());
            	s.pop();
            }
            else{
                break;
            }
        }
        s.push(curr);
        // put back the elements
        while(!t.empty()){
            s.push(t.top());
            t.pop();
        }
    }
    cout<<cnt<<"\n";
    sk = s;
}
// Time complx: O(n + n) = O(n)
// Space complx: O(2*n) = O(n)
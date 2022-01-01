// prob link: https://www.geeksforgeeks.org/count-frequencies-elements-array-o1-extra-space-time/


// Negative index
void frequencyCount(vector<int>& arr,int N, int P){
    int i=0;
    while(i < N){
        if(arr[i] <= 0){
            i++;
            continue;
        }
        int idx = arr[i]-1;
        if(arr[idx] <= 0){
            arr[idx]--;
            arr[i] = 0;
            i++;
        }
        else{
            arr[i] = arr[idx];  // preserve arr[idx] value
            arr[idx] = -1;
        }
    }
    for(int i=0; i<N; ++i){
        arr[i] *= -1;
    }
}

// Time complx: O(n)
// Space complx: O(1)

// mod method
void frequencyCount(vector<int>& arr,int N, int P){
    for(int i=0; i<N; ++i){
        arr[i] -= 1;
    }
    for(int i=0; i<N; ++i){
        arr[arr[i]%N] += N;
    }
    for(int i=0; i<N; ++i){
        arr[i] /= N;
    }
}

// Time complx: O(n)
// Space complx: O(1)
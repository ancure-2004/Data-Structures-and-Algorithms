#include<bits/stdc++.h>
using namespace std;

void printarr(vector<int> &arr){
    for(int i = 0; i < arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return;
}

// Prints all the subsequence with sum == k
void k_sum_subsequence(int arr[], int n, vector<int> &subsequence, int index, int sum, int k){
    
    if(index >= n){
        if(sum == k){
            printarr(subsequence);
        }
        return;
    }

    subsequence.push_back(arr[index]);
    sum += arr[index];
    k_sum_subsequence(arr, n, subsequence, index + 1, sum, k);
    subsequence.pop_back();
    sum -= arr[index];
    k_sum_subsequence(arr, n, subsequence, index + 1, sum, k);
}

// IF want to print only the one subsequence with sum == k then
/* technique of printing only the one answer */ 

bool only_One_kSumSub(int arr[], int n, vector<int> &subsequence, int index, int sum, int k){
    if(index >= n){
        if(sum == k){
            printarr(subsequence);
            return true;
        }
        else return false;
    }

    subsequence.push_back(arr[index]);
    sum += arr[index];
    if(only_One_kSumSub(arr, n, subsequence, index + 1, sum , k) == true) return true;

    subsequence.pop_back();
    sum -= arr[index];
    if(only_One_kSumSub(arr, n , subsequence, index + 1, sum, k) == true) return true;

    return false;
}

//Count the no. of subsequence that has sum = k;
int count_kSumSub(int arr[], int n, int index, int sum, int k){
    if(index >= n){
        if(sum == k) return 1;
        
        else return 0;
    }

    sum += arr[index];

    int left_count = count_kSumSub(arr, n, index + 1, sum, k);

    sum -= arr[index];
    int right_count = count_kSumSub(arr, n,  index + 1, sum, k);

    return left_count + right_count;
    
}

int main(){

    int arr[] = {1, 1, 1, 2, 2};
    int n = 5;
    int k = 4;

    vector<int> subsequence;
    int sum = 0;
    
    k_sum_subsequence(arr, n, subsequence, 0, sum, k);
    cout << endl;
    only_One_kSumSub(arr, n, subsequence, 0, sum , k);
    cout << endl;
    int count = count_kSumSub(arr, n, 0, sum, k);
    cout << count <<endl;

    return 0;
}
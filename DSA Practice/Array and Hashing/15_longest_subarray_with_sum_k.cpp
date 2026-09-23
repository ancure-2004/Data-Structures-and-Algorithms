#include<bits/stdc++.h>
using namespace std;

//Extreme Brute Force (O(n^3))
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size();

    int length_longest = 0;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            long long sum = 0;
            for(int p = i; p <= j; p++){
                sum = sum + a[p];
                if(sum > k){
                    break;
                }
            }
            if(sum == k){
                int current_length = j - i + 1;
                length_longest = max(current_length, length_longest);
            }
        }
    }

    return length_longest;
}


//Optimizd Brute Force (O(n^3))
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size();

    int length_longest = 0;
    for(int i = 0; i < n; i++){
        long long sum = 0;
        for(int j = i; j < n; j++){
            sum = sum + a[j];
            if(sum > k){
                break;
            }
            if(sum == k){
                int current_length = j - i + 1;
                length_longest = max(current_length, length_longest);
            }
        }
    }

    return length_longest;
}


//Sliding windows
int longestSubarrayWithSumK(vector<int> a, long long k) {
    int n = a.size();

    int l = 0;
    int r = 0;
    long long sum = 0;
    int longest_subarr = 0;

    while(r < n){
        sum = sum + a[r];

        while(sum > k){
            sum = sum - a[l];
            l++;
        }

        if(sum == k){
            int current_length = r - l + 1;
            longest_subarr = max(current_length, longest_subarr);
        }

        r++;
    }

    return longest_subarr;
}
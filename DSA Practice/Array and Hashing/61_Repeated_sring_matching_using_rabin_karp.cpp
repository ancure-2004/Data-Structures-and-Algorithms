#include<bits/stdc++.h>
using namespace std;


#include <bits/stdc++.h>
using namespace std;

//Rabin Karp Algorithm
class Solution {
public:
    int MOD = 1000000;

    int hashVal(string s, int factor, int length){
        int ans = 0;

        for(int i = 0; i < length; i++){
            ans = (ans * factor + (s[i] - 'a')) % MOD;
        }

        return ans;
    }

    bool RabinKarpAlgo(string hayStack, string needle){
        /*  
            step 1 -> find hashvalue of needle.
            step 2 -> loop through the string a
            step 3 -> if(start of the loop then) find the hashvalue of first m elements, m is size of needle
            step 4 -> if not start of the loop, then increase the power of all the elements then remove the first
                        element with maximum power and then add the next element 

            step 5 -> if hashneedle == hashhay then iterate one more time to check if the elements are really same,
                        if yes then return i,
        */

        int n = hayStack.size();
        int m = needle.size();

        if(m > n) return false;

        //Value based on which we will be finding hashvalue can be anything 10, 26 etc.
        int factor = 26;

        int maxFactor = 1;
        for(int i = 0; i < m; i++){
            maxFactor = (maxFactor * factor) % MOD;
        }

        //Finding hashvalue of needle
        int hashNeedle = hashVal(needle, factor, m);
        
        //Hash rolling step, rolling the hash function and finding the match
        int hashHay = hashVal(hayStack, factor, m);
        
        for(int i = 0; i <= n - m; i++){

            //If hashHay == hashNeedle matched then iterate and check if actually matches or not
            if(hashHay == hashNeedle){

                for(int j = 0; j < m; j++){
                    if(needle[j] != hayStack[i + j]) break;
                    
                    if(j == m - 1) return true;
                }

            }

            //For every other time, rolling the hash subtracting last one adding next one
            if(i < n - m){
                int leading = hayStack[i] - 'a';
                int trailing = hayStack[i + m] - 'a';

                hashHay = (hashHay * factor) % MOD;
                hashHay = (hashHay - (leading * maxFactor) % MOD + MOD) % MOD;
                hashHay = (hashHay + trailing) % MOD;
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {

        int n = a.size();
        int m = b.size();

        if(a == b) return 1;

        if(RabinKarpAlgo(a, b)){
            return 1;
        }

        string hayStack = "";

        int cnt = 0;
        while(hayStack.size() < b.size()){
            hayStack += a;
            cnt++;
        }

        if(RabinKarpAlgo(hayStack, b)){
            return cnt;
        }

        hayStack += a;
        
        if(RabinKarpAlgo(hayStack, b)){
            cnt++;
            return cnt;
        }

        return -1;
    }
};

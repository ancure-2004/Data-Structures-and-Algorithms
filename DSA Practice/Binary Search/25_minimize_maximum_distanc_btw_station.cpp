#include<bits/stdc++.h>
using namespace std;

//Brute Force
class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        
        int howmany[n - 1] = {0};
        
        for(int station = 1; station <= k; station++){
            long double maxDistance = -1;
            int maxInd = -1;
             
            for(int i = 0; i < n - 1; i++){
                long double distance = stations[i + 1] - stations[i];
                long double sectionLength = distance/(long double)(howmany[i] + 1);
                 
                if(sectionLength > maxDistance){
                    maxDistance = sectionLength;
                    maxInd = i;
                }
            }
             
            howmany[maxInd]++;
        }
         
        long double maxAns = -1;
        
        for(int i = 0; i < n - 1; i++){
            long double distance = stations[i + 1] - stations[i];
            long double sectionLength = distance/(long double)(howmany[i] + 1);
            
            maxAns = max(maxAns, sectionLength);
        }
        
        return maxAns;
    }
};


//Better Approach
class Solution {
  public:
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        
        priority_queue<pair<long double, int>> pq;
        
        int howmany[n - 1] = {0};
        
        for(int i = 0; i < n - 1; i++){
            long double diff = stations[i + 1] - stations[i];
            
            pq.push({diff, i});
        }
        
        for(int station = 1; station <= k; station++){
            auto element = pq.top();
            pq.pop();
            
            long double maxDistance = element.first;
            int maxInd = element.second;
            
            howmany[maxInd]++;
            
            long double diff = stations[maxInd + 1] - stations[maxInd];
            long double newSectionLength = diff/(long double)(howmany[maxInd] + 1);
            
            pq.push({newSectionLength, maxInd});
        }
         
        return pq.top().first;
    }
};


//Most Optimized approach
class Solution {
  public:
    int findGasStation(long double mid, vector<int> stations){
        int no_of_gasStations = 0;
        
        for(int i = 0; i < stations.size() - 1; i++){
            int diff = stations[i + 1] - stations[i];
            
            int no_in_btw = (diff/mid);
            
            if(diff/mid == no_in_btw * mid){
                no_in_btw--;
            }
            
            no_of_gasStations += no_in_btw;
        }
        
        return no_of_gasStations;
    }
    
  
    double minMaxDist(vector<int> &stations, int k) {
        // Code here
        int n = stations.size();
        
        long double maxDiff = -1;
        for(int i = 0; i < n-1; i++){
            maxDiff = max(maxDiff, (long double) (stations[i + 1] - stations[i]));
        }
        
        long double low = 0;
        long double high = maxDiff;
        
        while(high - low > 1e-6){
            long double mid = low + (high - low)/2.0;
            
            int no_of_gasStation = findGasStation(mid, stations);
            
            if(no_of_gasStation > k){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        
        return high;
    }
};
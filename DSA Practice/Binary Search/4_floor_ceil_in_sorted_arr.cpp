#include<bits/stdc++.h>
using namespace std;

pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	int ceil = -1;
	int s = 0, e = n - 1;

	while(s <= e){
		int mid = s + (e - s)/2;

		if(a[mid] >= x){
			ceil = a[mid];
			e = mid - 1;
		}
		else{
			s = mid + 1;
		}
	}

	int floor = -1;
	s = 0, e = n - 1;
	while(s <= e){
		int mid = s + (e - s)/2;

		if(a[mid] <= x){
			floor = a[mid];
			s = mid + 1;
		}
		else{
			e = mid - 1;
		}
	}

	return {floor, ceil};
}
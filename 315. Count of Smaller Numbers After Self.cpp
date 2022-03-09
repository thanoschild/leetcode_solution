class Solution {
public:
    void merge(vector<pair<int, int>> &v, vector<int> &count, int left, int mid, int right){
        vector<pair<int, int>> temp(right - left +1);
        int i = left;
        int j = mid+1;
        int k = 0;
        while(i <= mid && j <= right){
            if(v[i].first <= v[j].first){
                temp[k++] = v[j++];
            }
            else{
                count[v[i].second] += right - j + 1;
                temp[k++] = v[i++];
            }
        }
        while( i<= mid){
            temp[k++] = v[i++];
        }
        while(j <= right){
            temp[k++] = v[j++];
        }
        for(int i = left; i<= right; i++){
            v[i] = temp[i - left];
        }
    }
    void mergesort(vector<pair<int, int>> &v, vector<int> &count, int left, int right){
        if(left < right){
            int mid = left + (right - left)/2;
            mergesort(v, count, left, mid);
            mergesort(v, count, mid+1, right);
            merge(v, count, left, mid, right);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
       int n = nums.size();
       vector<pair<int, int>> v;
       for(int i = 0; i<n; i++){
           v.push_back({nums[i], i});
       }
       vector<int> count(n, 0);
       mergesort(v, count, 0, n-1);
       return count;
    }
};

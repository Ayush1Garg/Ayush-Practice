class Solution {
public:
    int partition(int low, int high, vector<string>&names, vector<int>& height){
        int ind = low, pivot = height[ind];
        for(int i=low+1; i<=high; i++){
            if(height[i]>pivot){
                swap(height[i],height[ind+1]);
                swap(names[i],names[ind+1]);
                ind++;
            }
        }
        swap(height[low],height[ind]);
        swap(names[low],names[ind]);
        return ind;
    }
    void quicksort(int low, int high, vector<string>&names, vector<int>& heights){
        if(high>low){
            int p = partition(low,high,names,heights);
            quicksort(low,p,names,heights);
            quicksort(p+1,high,names,heights);
        }
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = heights.size();
        if(n==1) return names;
        quicksort(0,n-1,names,heights);
        return names;
    }
};
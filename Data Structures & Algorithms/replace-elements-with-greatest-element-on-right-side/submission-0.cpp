class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vactor<int> ans(n);
        int rightmax=-1;
        for(int i = n-1; i > 0; i--)
        {
            ans[i] = rightmax;
            rightmax= max(rightmax, arr[i]);
        }
         return ans;
    }
};
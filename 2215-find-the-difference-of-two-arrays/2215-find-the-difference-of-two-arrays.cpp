class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1,s2;
        for(int i=0;i<nums1.size();i++){
            s1.insert(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++){
            s2.insert(nums2[i]);
        }
        vector<vector<int>> ans(2);
        for(auto x: s1){
            if(s2.find(x)==s2.end()){
                ans[0].push_back(x);
            }
        }
        for(auto x: s2){
            if(s1.find(x)==s1.end()){
                ans[1].push_back(x);
            }
        }
        return ans;
    }
};
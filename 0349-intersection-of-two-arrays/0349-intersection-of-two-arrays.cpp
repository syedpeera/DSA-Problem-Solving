class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> hashSet;
        for(int i=0;i<nums1.size();i++){
            hashSet.insert(nums1[i]);
        }
        
        vector<int> result;
        for(int i=0;i<nums2.size();i++){
            if(hashSet.find(nums2[i])!=hashSet.end()){
                result.push_back(nums2[i]);
                hashSet.erase(nums2[i]);
            }
        }
        
        return result;
    }
};
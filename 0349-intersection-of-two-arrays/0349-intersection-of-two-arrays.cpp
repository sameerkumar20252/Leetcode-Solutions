class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_set<int> ans;
        unordered_set<int> s;
        if(n1>n2){
            for(int i=0;i<n1;i++){
                s.insert(nums1[i]);
            }
            for(int j=0;j<n2;j++){
                if(s.find(nums2[j])!=s.end()){
                    ans.insert(nums2[j]);
                }
            }

        }else{
             for(int i=0;i<n2;i++){
                s.insert(nums2[i]);
            }
            for(int j=0;j<n1;j++){
                if(s.find(nums1[j])!=s.end()){
                    ans.insert(nums1[j]);
                }
            }
        }
        vector<int> ans2;
        for(auto dig:ans){
           ans2.push_back(dig);
        }
    return ans2;
    }
};
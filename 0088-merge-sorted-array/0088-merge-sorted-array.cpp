class Solution {
public:
    void merge(vector<int>& A, int m, vector<int>& B, int n) {
        int i=0,j=0;
        vector<int> temp;
        while(i<m && j<n){
            if(A[i]<=B[j]){
                temp.push_back(A[i]);
                i++;
            }else{
                temp.push_back(B[j]);
                j++;
            }
        }
        while(i<m){
            temp.push_back(A[i]);
            i++;
        }
        while(j<n){
            temp.push_back(B[j]);
            j++;
        }
        for(int j=0;j<temp.size();j++){
            A[j]=temp[j];
        }
    }
};
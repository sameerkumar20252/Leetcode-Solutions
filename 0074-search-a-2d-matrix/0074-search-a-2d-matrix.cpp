class Solution {
public:
    bool binarysearch(vector<int>& row,int st,int end,int tar){
        while(st<=end){
            int mid=st+(end-st)/2;
            if(row[mid]==tar){
                return true;
            }else if(tar<row[mid]){
                end=mid-1;
            }else{
                st=mid+1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = (rows > 0) ? matrix[0].size() : 0;
        bool x=false;
        int st=0,end=rows-1;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][cols-1]){
                if(target==matrix[mid][0] || target==matrix[mid][cols-1]){
                    return true;
                }
                x = binarysearch(matrix[mid],0,cols-1,target);
                break;
            }else if(target>=matrix[mid][cols-1]){
                st=mid+1;
            }else{
                end=mid-1;
            }
        }
    return x;
    }
};
class Solution {
public:
    int findRow(vector<vector<int>>& matrix,int target){
        int left=0;
        int right=matrix.size()-1;
        int column= matrix[0].size()-1;  
        int mid;
        while(left<=right){
            mid=(left+right)/2;
            if (target < matrix[mid][0]) right=mid-1;
            else if(target > matrix[mid][column]) left= mid+1;
            else return mid;
        }
        return -1;
    }

    bool binarySearch(vector<int> matrix,int target){
        int left=0;
        int right=matrix.size()-1;
        int mid;
        while(left<=right){
            mid=(left+right)/2;
            if (target<matrix[mid]) right = mid-1;
            else if(target >matrix[mid]) left= mid+1;
            else return true;
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = findRow(matrix,target);
        if(row==-1) return false;

        return binarySearch(matrix[row],target);
    }
};
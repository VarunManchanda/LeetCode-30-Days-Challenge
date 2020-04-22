/*
(This problem is an interactive problem.)
A binary matrix means that all elements are 0 or 1. For each individual row of the matrix, this row is sorted in 
non-decreasing order.
Given a row-sorted binary matrix binaryMatrix, return leftmost column index(0-indexed) with at least a 1 in it. 
If such index doesn't exist, return -1.
You can't access the Binary Matrix directly.  You may only access the matrix using a BinaryMatrix interface:
BinaryMatrix.get(x, y) returns the element of the matrix at index (x, y) (0-indexed).
BinaryMatrix.dimensions() returns a list of 2 elements [m, n], which means the matrix is m * n.
Submissions making more than 1000 calls to BinaryMatrix.get will be judged Wrong Answer.  Also, any solutions 
that attempt to circumvent the judge will result in disqualification.
For custom testing purposes you're given the binary matrix mat as input in the following four examples. You will not 
have access the binary matrix directly.
*/
/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        return bruteForce(binaryMatrix);
    }
    int bruteForce(BinaryMatrix &binaryMatrix)
    {
        vector<int> v = binaryMatrix.dimensions();
        int n = v[0], m = v[1];
        int ans = m;
        for(int i=0; i<n; i++)
        {
            int lo = 0, hi = m-1;
            while(lo<=hi)
            {
                int mid = lo + (hi-lo)/2;
                if(binaryMatrix.get(i,mid)==1)
                {
                    ans = min(ans,mid);
                    hi = mid-1;
                }
                else lo = mid+1;
            }
        }
        return (ans==m) ? -1 : ans;
        
    }
    int fastMethod(BinaryMatrix &binaryMatrix)
    {
        vector<int> v = binaryMatrix.dimensions();
        int n = v[0], m = v[1];
        int i = 0, j = m-1;
        int result = -1;
        while(i<n and j>=0)
        {
            if(binaryMatrix.get(i,j)==1) 
                result = j, j-=1;
            else i+=1;
            
        }
        return result;
    }
};

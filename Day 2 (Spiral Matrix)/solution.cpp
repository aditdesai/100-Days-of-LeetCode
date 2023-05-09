class Solution {
public:
    void spiralOrderHelper(vector<vector<int>>& matrix, vector<int> &result, int tlx, int tly, int brx, int bry)
    {
        int i;

        //base cases
        if (tlx > brx || tly > bry)
            return;
        if (tlx == brx && tly == bry)
        {
            result.push_back(matrix[tlx][tly]);
            return;
        }
        else if (tlx == brx)
        {
            for(i = tly; i <= bry; ++i)
                result.push_back(matrix[tlx][i]);
            return;
        }
        else if (tly == bry)
        {
            for(i = tlx; i <= brx; ++i)
                result.push_back(matrix[i][tly]);
            return;
        }


        // border elements
        
        for(i = tly; i <= bry; ++i)
            result.push_back(matrix[tlx][i]);
        
        for(i = tlx+1; i <= brx; ++i)
            result.push_back(matrix[i][bry]);

        for(i = bry-1; i >= tly; --i)
            result.push_back(matrix[brx][i]);

        for(i = brx-1; i > tlx; --i)
            result.push_back(matrix[i][tly]);
        
        // shrink matrix
        spiralOrderHelper(matrix, result, tlx+1, tly+1, brx-1, bry-1);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        // something recursive (divide and conquer)
        // border elements and then divide problem into matrix in middle

        int m = matrix.size(), n = matrix[0].size();
        vector<int> result;
        spiralOrderHelper(matrix, result, 0, 0, m-1, n-1);

        return result;

    }
};
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for(int i = 0; i < numRows; ++i)
        {
            result[i] = vector<int> (i+1, 0); // set default value 1 instead (as done in python solution)
        }
        result[0][0] = 1;

        if (numRows == 1)
            return result;

        for(int i = 1; i < numRows; ++i)
        {
            for(int j = 0; j <= i; ++j)
            {
                int n1 = j != 0 ? result[i-1][j-1] : 0; //no need for this since 1st and last number of every row are gonna be 1
                int n2 = j != i ? result[i-1][j] : 0;

                result[i][j] = n1 + n2;
            }
        }

        return result;
    }
};

int main()
{
    Solution s;

    vector<vector<int>> res = s.generate(5);

    for(int i = 0; i < 5; ++i)
    {
        for(int j = 0; j <= i; ++j)
        {
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
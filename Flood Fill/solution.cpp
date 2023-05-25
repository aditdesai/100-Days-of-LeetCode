#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void flood(vector<vector<int>>& image, int i, int j, int origColor, int newColor) //DFS
    {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size())
            return;
        if (image[i][j] == newColor) 
            return;
        if (image[i][j] == origColor)
        {
            image[i][j] = newColor;

            flood(image, i+1, j, origColor, newColor);
            flood(image, i, j+1, origColor, newColor);
            flood(image, i-1, j, origColor, newColor);
            flood(image, i, j-1, origColor, newColor);
        }
    }
public:

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int origColor = image[sr][sc];
        flood(image, sr, sc, origColor, color);

        return image;
    }
};

int main()
{
    vector<vector<int>> v = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    Solution s;
    v = s.floodFill(v, 1, 1, 2);

    for(int i = 0; i < v.size(); ++i)
    {
        for(int j = 0; j < v[0].size(); ++j)
        {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}
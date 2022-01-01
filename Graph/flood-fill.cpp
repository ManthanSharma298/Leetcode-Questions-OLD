
// prob link: https://leetcode.com/problems/flood-fill/


// DFS solution
class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& image, int color, int newColor, set<pair<int,int>>& st){
        int r = image.size(), c = image[0].size();
        if(image[i][j] == color){
            image[i][j] = newColor;
            st.insert({i, j});
            if(j+1 < c && !st.count({i, j+1})){
                dfs(i, j+1, image, color, newColor, st);
            }
            if(j-1 >= 0 && !st.count({i, j-1})){
                dfs(i, j-1, image, color, newColor, st);
            }
            if(i+1 < r && !st.count({i+1, j})){
                dfs(i+1, j, image, color, newColor, st);
            }
            if(i-1 >= 0 && !st.count({i-1, j})){
                dfs(i-1, j, image, color, newColor, st);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int color = image[sr][sc];
        set<pair<int,int>>vis;
        dfs(sr, sc, image, color, newColor, vis);
        return image;
    }
};

// Time complx: O(r*c)
// Space complx: O(r*c)    {used a set and stack formed by dfs recursion}
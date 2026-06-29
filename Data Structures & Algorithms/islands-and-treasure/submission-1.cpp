#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    // Directions vectors
    vector<int> row = {-1, 1, 0, 0};
    vector<int> col = {0, 0, -1, 1};

    void islandsAndTreasure(vector<vector<int>>& grid) {
        if (grid.empty()) return;
        
        int n = grid.size(), m = grid[0].size();
        // Changed from priority_queue to a standard queue for O(1) push/pop
        queue<pair<int, int>> q; 

        // Multi-source initialization: Push all treasures to the queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        // Standard BFS
        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {
                int r = i + row[k];
                int c = j + col[k];

                // Boundary check and obstacle check
                if(r >= n || r < 0 || c >= m || c < 0 || grid[r][c] == -1) {
                    continue;
                }
                
                // If we found a shorter path to grid[r][c]
                if(grid[r][c] > grid[i][j] + 1) {
                    grid[r][c] = grid[i][j] + 1;
                    q.push({r, c});
                }
            }
        }
    }
};
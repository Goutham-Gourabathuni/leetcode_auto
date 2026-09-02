#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int rows = classroom.size(), cols = classroom[0].size();
        vector<pair<int, int>> litters;
        int startR = 0, startC = 0;
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (classroom[r][c] == 'S') { startR = r; startC = c; } 
                else if (classroom[r][c] == 'L') { litters.push_back({r, c}); }
            }
        }
        
        int targetMask = (1 << litters.size()) - 1;
        if (targetMask == 0) return 0;
        
        queue<tuple<int, int, int, int, int>> q;
        q.push({0, startR, startC, 0, energy});
        
        vector<vector<vector<int>>> visited(rows, vector<vector<int>>(cols, vector<int>(1 << litters.size(), -1)));
        visited[startR][startC][0] = energy;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        while (!q.empty()) {
            auto [moves, r, c, mask, currE] = q.front();
            q.pop();
            if (currE == 0) continue;
            
            for (auto& d : dirs) {
                int nr = r + d.first, nc = c + d.second;
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && classroom[nr][nc] != 'X') {
                    int nextE = currE - 1, nextMask = mask;
                    if (classroom[nr][nc] == 'R') nextE = energy;
                    if (classroom[nr][nc] == 'L') {
                        for (int i = 0; i < litters.size(); ++i) {
                            if (litters[i].first == nr && litters[i].second == nc) { nextMask |= (1 << i); break; }
                        }
                    }
                    if (nextMask == targetMask) return moves + 1;
                    if (visited[nr][nc][nextMask] < nextE) {
                        visited[nr][nc][nextMask] = nextE;
                        q.push({moves + 1, nr, nc, nextMask, nextE});
                    }
                }
            }
        }
        return -1;
    }
};
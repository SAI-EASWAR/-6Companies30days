class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;

        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                }
            }
        }

        int answer = 0;

        while(!q.empty()){
            answer = max(answer, q.front()[2]);
            int r = q.front()[0];
            int c = q.front()[1];
            int time = q.front()[2];
            q.pop();


            int x[] = {-1,0,1,0};
            int y[] = {0,1,0,-1};

            for(int i=0;i<4;i++){
                int nx = r + x[i];
                int ny = c + y[i];

                if(nx >= 0 and ny >= 0 and nx < m and ny < n and grid[nx][ny] == 1){
                    grid[nx][ny] = 2;
                    q.push({nx,ny,time+1});
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return answer;
    }
};
class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m = img.size();
        int n = img[0].size();

        vector<int> temp(n);
        int prevCor = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                int sum = 0;
                int count = 0;

                // bottom neighbors
                if(i + 1 < m){
                    if(j-1 >= 0){
                        sum += img[i+1][j-1];
                        count += 1;
                    }

                    sum += img[i+1][j];
                    count += 1;

                    if(j + 1 < n){
                        sum += img[i+1][j+1];
                        count += 1;
                    }
                }

                if(j + 1 <n){
                    sum += img[i][j+1];
                    count += 1;
                }

                sum += img[i][j];
                count += 1;

                //previous neighbor
                if(j-1 >= 0){
                    sum += temp[j-1];
                    count += 1;
                }

                if(i - 1 >= 0){
                    // left-top corner sharing neighbor
                    if(j-1 >= 0){
                        sum += prevCor;
                        count += 1;
                    }
                    sum += temp[j];
                    count += 1;

                    if(j+1 <n){
                        sum += temp[j+1];
                        count += 1;
                    }}

                    if(i-1 >=0){
                        prevCor = temp[j];
                    }

                    temp[j] = img[i][j];

                    img[i][j] = sum/count;
                }
            }
        return img;
    }
}; // time complexity : O(n*m) and space complexity O(n)


class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size(), m = img[0].size();

        vector<vector<int>> result(n,vector<int>(m));

        vector<int> xIndex = {-1,0,1,1,1,0,-1,-1,0};
        vector<int> yIndex = {1,1,1,0,-1,-1,-1,0,0};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int cnt = 0;
                int sum = 0;

                for(int k=0;k<9;k++){
                    int x = i + xIndex[k];
                    int y = j + yIndex[k];

                    if(x >= 0 and x < n and y >= 0 and y < m ){
                        cnt++;
                        sum+=img[x][y];
                    }
                }
                result[i][j] = sum/cnt;
            }
        }
        return result;
    }
}; // time complexity : O(n*m) and space complexity O(n*m)


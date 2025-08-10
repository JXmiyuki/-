#include<iostream>
#include<vector>
using namespace std;
class Matrix{
    private:
    int rows;
    int cols;
    vector<vector<int>> data;
    public:
    //初始化矩阵
    Matrix(int r, int c, const vector<vector<int>>& initData) {
        rows=r;
        cols=c;
        data=initData;}
    //获取行和列
    int getRows() const {
        return rows;
    }
    int getCols() const {
        return cols;
    }
    void print() const {
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cout<<data[i][j]<<" ";
            }
        cout<<endl;
        }
    }
    // 3x3均值滤波
    Matrix meanFilter3x3() const{
    vector<vector<int>> resultData(rows,vector<int>(cols,0));
     for (int i = 1; i < rows - 1; i++) {  // i从1开始，到rows-2结束（避开第0行和最后一行）
            for (int j = 1; j < cols - 1; j++) {  
                // 计算当前像素（i,j）周围3x3区域的总和
                int sum = 0;
                // 遍历3x3邻域（i-1到i+1行，j-1到j+1列）
                for (int di = -1; di <= 1; di++) {  
                    for (int dj = -1; dj <= 1; dj++) {
                        sum += data[i + di][j + dj];  // 累加邻域内的像素值
                    }
                }
                resultData[i][j] = sum / 9;
            }
        }
    return Matrix(rows, cols, resultData);
    }
};//test

#include <opencv2/opencv.hpp> 
using namespace cv;           
int main() {
    VideoCapture cap("videoname");  // 输入视频地址
    while (cap.isOpened()) {  // 先检查视频是否成功打开
        Mat frame;  // 用来存当前帧
        bool ret = cap.read(frame);  // 读一帧（翻一页）
        if (!ret) break;  // 如果没读到帧（比如翻到最后一页了），就退出循环
        //显示当前帧（把这一页的画面展示出来）
        imshow("视频播放", frame);
        //控制播放速度（多久翻一页），按q键退出
        if (waitKey(25) == 'q') break;  // 25毫秒翻一页
    }
    cap.release();       // 关闭视频文件
    destroyAllWindows(); // 关掉显示窗口
    return 0;
}
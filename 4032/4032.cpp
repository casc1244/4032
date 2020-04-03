
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
using namespace cv;
using namespace std;



int main()
{

	cv::Mat dstMat;
	cv::Mat srcMat = cv::imread("D:\\360downloads\\7.png", 1);

	const cv::Point2f src_pt[] = {
		cv::Point2f(200,200),
		cv::Point2f(250,200),
		cv::Point2f(200,100),
	};
	const cv::Point2f dst_pt[] = {
		cv::Point2f(300,100),
		cv::Point2f(300,50),
		cv::Point2f(200,100),
	};
	const cv::Mat affine_matrix = getAffineTransform(src_pt, dst_pt);
	cv::warpAffine(srcMat, dstMat, affine_matrix,srcMat.size());
	imshow("原", srcMat);
	imshow("换", dstMat);


	// 等待用户按任意按键退出程序
	waitKey(0);

	return 0;
}

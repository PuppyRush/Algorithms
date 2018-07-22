//#define _CRT_SECURE_NO_WARNINGS
//
//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <math.h>
//
//using point = int;
//using p_info = signed char;
//
//typedef struct POINT
//{
//	point x1, x2, y1, y2;
//	POINT()
//		:x1(0), x2(0), y1(0), y2(0)
//	{}
//};
//
//class RECT
//{
//private:
//	p_info **rect;
//	POINT point_info;
//	point width;
//	point height;
//
//public:
//
//	explicit RECT(const POINT p)
//		:rect(nullptr), point_info(p)
//	{
//		height = p.y2 - p.y1;
//		width = p.x2 - p.x1;
//		rect = new p_info*[height];
//
//		for (point y = 0 ; y < height; y++)
//		{
//			rect[y] = new p_info[width];
//			memset(rect[y], 1, sizeof(p_info)*width);
//		}
//		
//	}
//
//	void operator-=(const RECT &src)
//	{
//		
//		const size_t len_x = std::max(this->point_info.x2, src.point_info.x2);
//		const size_t len_y = std::max(this->point_info.y2, src.point_info.y2);
//
//		auto** tmp = new p_info*[len_y];
//		for (size_t y = 0; y < len_y; y++)
//		{
//			tmp[y] = new p_info[len_x];
//			memset(tmp[y], 0, sizeof(p_info)*len_x);
//		}
//
//		for (size_t y = 0; y < height ; y++)
//		{
//			for (auto x = 0; x < width; x++)
//				tmp[this->point_info.y1+y][this->point_info.x1+x] = this->rect[y][x];
//		}
//
//		for (auto y = src.point_info.y1; y < src.point_info.y2; y++)
//		{
//			for (auto x = src.point_info.x1; x < src.point_info.x2; x++)
//			{
//				tmp[y][x] -= 1;
//			}
//		}
//
//		for (auto y = 0; y < height; y++)
//		{
//			for (auto x = 0; x < width; x++)
//			{
//				this->rect[y][x] = tmp[this->point_info.y1 + y][this->point_info.x1 + x];
//			}
//			delete tmp[y];
//		}
//		
//		delete tmp;
//	}
//	
//	const long long getFee() const
//	{
//		long long fee = 0;
//		for (size_t y = 0; y < height; y++)
//		{
//			for (auto x = 0; x < width; x++)
//				if (rect[y][x] == 1)
//					fee++;
//		}
//		return fee;
//	}
//};
//
//int main()
//{
//	POINT p1, p2, p3;
//	scanf("%d %d %d %d ", &p1.x1, &p1.y1, &p1.x2, &p1.y2);
//	scanf("%d %d %d %d ", &p2.x1, &p2.y1, &p2.x2, &p2.y2);
//	scanf("%d %d %d %d ", &p3.x1, &p3.y1, &p3.x2, &p3.y2);
//
//	RECT r1(p1);
//	RECT r2(p2);
//	RECT r3(p3);
//	
//	r1 -= r2;
//	r1 -= r3;
//	printf("%d", r1.getFee());
//}
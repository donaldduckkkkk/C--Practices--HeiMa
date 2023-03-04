#include<iostream>
using namespace std;
#include"circle.h"
#include"point.h"
#include<cmath>

void isincircle(Circle &c, Point &p)
{
	//计算两点之间的距离
	double distance = sqrt((c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY()));
	//计算半径
	double radius = c.getR();

	if (distance == radius)
	{
		cout << "点在圆上" << endl;
	}
	else if (distance > radius)
	{
		cout << "点在圆外" << endl;
	}
	else
	{
		cout << "点在圆内" << endl;
	}
}

int main()
{
	//创建圆
	Circle c;//实例化
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);

	//创建点
	Point p;//实例化
	p.setX(10);
	p.setY(20);

	//比较圆和点的位置
	isincircle(c, p);

	system("pause");
	return 0;
}
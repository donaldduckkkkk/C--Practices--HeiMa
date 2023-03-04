#pragma once
#include <iostream>
#include "point.h"
using namespace std;


class Circle//创建圆类
{
public:
	void setR(int R);

	int getR();

	void setCenter(Point Center);

	Point getCenter();

private:
	int m_R;//设置半径
	Point m_Center;//设置圆心
};
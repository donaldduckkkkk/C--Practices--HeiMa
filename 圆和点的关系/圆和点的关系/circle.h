#pragma once
#include <iostream>
#include "point.h"
using namespace std;


class Circle//����Բ��
{
public:
	void setR(int R);

	int getR();

	void setCenter(Point Center);

	Point getCenter();

private:
	int m_R;//���ð뾶
	Point m_Center;//����Բ��
};
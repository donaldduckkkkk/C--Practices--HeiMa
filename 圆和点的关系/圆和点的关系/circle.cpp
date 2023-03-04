#include"circle.h"
#include"point.h"


void Circle::setR(int R)
{
	m_R = R;
}

int Circle::getR()
{
	return m_R;
}

void Circle::setCenter(Point Center)
{
	m_Center = Center;
}
Point Circle::getCenter()
{
	return m_Center;
}
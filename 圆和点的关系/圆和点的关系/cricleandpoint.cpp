#include<iostream>
using namespace std;
#include"circle.h"
#include"point.h"
#include<cmath>

void isincircle(Circle &c, Point &p)
{
	//��������֮��ľ���
	double distance = sqrt((c.getCenter().getX() - p.getX()) * (c.getCenter().getX() - p.getX()) + (c.getCenter().getY() - p.getY()) * (c.getCenter().getY() - p.getY()));
	//����뾶
	double radius = c.getR();

	if (distance == radius)
	{
		cout << "����Բ��" << endl;
	}
	else if (distance > radius)
	{
		cout << "����Բ��" << endl;
	}
	else
	{
		cout << "����Բ��" << endl;
	}
}

int main()
{
	//����Բ
	Circle c;//ʵ����
	c.setR(10);
	Point center;
	center.setX(10);
	center.setY(0);
	c.setCenter(center);

	//������
	Point p;//ʵ����
	p.setX(10);
	p.setY(20);

	//�Ƚ�Բ�͵��λ��
	isincircle(c, p);

	system("pause");
	return 0;
}
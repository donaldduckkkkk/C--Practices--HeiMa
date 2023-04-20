#pragma once
#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include "speak.h"
#include <algorithm>
#include <deque>
#include <functional>
#include <numeric>
#include <string>
#include <fstream>


//����ݽ������Ĺ�����
class SpeechManager
{
public:

	//���캯��
	SpeechManager();

	//�˵�����
	void show_Menu();

	//�˳�ϵͳ
	void exitSystem();
  
	//��������
	~SpeechManager();

	//��ʼ������
	void initSpeech();

	//����ѡ�� 
	void createSpeaker();

	//��ʼ���� ������������
	void startSpeech();

	//��ǩ
	void speechDraw();

	//����
	void speechContest();

	//չʾ����
	void showScore();

	//�����¼
	void saveRecord();

	//��ȡ��¼
	void loadRecord();

	//�ж��ļ��Ƿ�Ϊ��
	bool fileIsEmpty;

	//��������¼������
	map<int, vector<string>>m_Record;//key�ǽ�����value�Ǵ�ŵĹھ�����

	//�鿴�����¼
	void showRecord();

	//��ռ�¼
	void clearRecord();


	//��Ա����
//�����һ�ֱ���ѡ�ֱ������
	vector<int>v1;
	//����ڶ��ֱ���ѡ�ֱ������
	vector<int>v2;
	//ǰ����ѡ�ֱ������
	vector<int>vVictory;
	//��ű���Լ���Ӧ��ѡ������
	map<int, Speaker>m_Speaker;
	//��ű�������
	int m_Index;

};
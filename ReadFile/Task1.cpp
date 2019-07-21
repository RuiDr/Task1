// ReadFile.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
#include "pch.h"
#include"Facet.h"
#include <iostream>
#include <sstream>
#include<fstream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<ctime>
#include<algorithm>
using namespace std;
bool ReadASCII();
int main()
{
	clock_t startTime, endTime;
	startTime = clock();//计时开始
	ReadASCII();
	endTime = clock();//计时结束
	cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
	system("pause");
	return 0;
}
// map存储
bool ReadASCII()
{
	map<int, Facet> mapList;
	vector<Point>pointlist;
	set<string>strlist;
	string s;
	ifstream fin("D:\\work\\Course1\\test.stl");
	int count = 0;
	//点数
	int i = 0;
	//面片数
	int trangle = 0;
	Facet facet;
	while (getline(fin, s)) {

		if (strstr(s.c_str(), "vertex") != NULL) {
			strlist.insert(s);
			i++;
			istringstream iss(s);
			string first;
			float x1, y1, z1;
			iss >> first >> x1 >> y1 >> z1;
			Point point(x1,y1,z1);
			pointlist.push_back(point);
			if (i%3==1)
			{
				facet.setX(point);
			}
			else if(i%3==2)
			{
				facet.setY(point);
			}
			else {
				facet.setZ(point);
				mapList.insert(pair<int, Facet>(trangle, facet));
				Facet mypoint;
				trangle++;
			}			
		}
	}
	sort(pointlist.begin(), pointlist.end());
	cout << "面片数" << mapList.size() << endl;
	cout << "节点数" << strlist.size() << endl;
	return true;
}


	
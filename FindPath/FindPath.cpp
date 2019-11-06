// FindPath.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

struct MapNode
{
	int pos_x;
	int pos_y;
	MapNode* per_node;

	MapNode()
		: pos_x(0)
		, pos_y(0)
		, per_node(NULL)
	{

	}

	bool isEqual(const MapNode* other_node)
	{
		return pos_x == other_node->pos_x && pos_y == other_node->pos_y;
	}
};

int main()
{
	MapNode start_node;
	cout << "Please input a start position X : " << endl;
	cin >> start_node.pos_x;
	cout << "Please input a start position Y : " << endl;
	cin >> start_node.pos_y;

	MapNode end_node;
	cout << "Please input a end position X : " << endl;
	cin >> end_node.pos_x;
	cout << "Please input a end position Y : " << endl;
	cin >> end_node.pos_y;

	
	
	system("PAUSE");
    return 0;
}


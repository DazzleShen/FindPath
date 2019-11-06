// FindPath.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <list>
using namespace std;

const int max_width = 50;
const int max_height = 50;

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

	bool operator==(const MapNode* other_node)
	{
		return this->isEqual(other_node);
	}
};

bool is_map_node_legitimate(MapNode* check_node)
{
	return check_node->pos_x >= 0 && check_node->pos_y >= 0 && check_node->pos_x <= max_width && check_node->pos_y <= max_height;
}

void print_path(MapNode* end_node)
{
	list<MapNode*> path_list;
	do 
	{
		path_list.push_front(end_node);
		end_node = end_node->per_node;
	} while (end_node != NULL);

	for (int h_index = 0 ; h_index <= max_width ; ++h_index)
	{
		for (int v_index = 0 ; v_index <= max_height ; ++v_index)
		{
			bool is_find = false;
			for (const auto& list_element : have_check_list)
			{
				if (*list_element == next_priority_node)
				{
					is_find = true;
					break;
				}
			}
		}
	}
}

int main()
{
	MapNode* start_node = new MapNode();
	cout << "Please input a start position X : " << endl;
	cin >> start_node->pos_x;
	cout << "Please input a start position Y : " << endl;
	cin >> start_node->pos_y;

	MapNode* end_node = new MapNode();
	cout << "Please input a end position X : " << endl;
	cin >> end_node->pos_x;
	cout << "Please input a end position Y : " << endl;
	cin >> end_node->pos_y;

	list<MapNode*> will_check_list;
	list<MapNode*> have_check_list;
	will_check_list.push_back(start_node);

	int check_count = 0;
	while (!will_check_list.empty())
	{
		MapNode* front_node = will_check_list.front();
		//cout << "Check index:" << ++check_count << " position X:" << front_node->pos_x << " Y:" << front_node->pos_y << endl;
		if (*front_node == end_node)
		{
			cout << "Find success! The path is:" << endl;
			do 
			{
				cout << front_node->pos_x << "," << front_node->pos_y << endl;
				front_node = front_node->per_node;
			} while (front_node != NULL);
			break;
		}
		will_check_list.pop_front();
		have_check_list.push_back(front_node);
		for (int h_index = -1; h_index <= 1; ++h_index)
		{
			for (int v_index = -1; v_index <=1; ++v_index)
			{
				if (abs(h_index) == abs(v_index))
				{
					continue;
				}
				MapNode* next_priority_node = new MapNode();
				next_priority_node->pos_x = front_node->pos_x + h_index;
				next_priority_node->pos_y = front_node->pos_y + v_index;
				if (!is_map_node_legitimate(next_priority_node))
				{
					delete next_priority_node;
					continue;
				}
				bool is_find = false;
				for (const auto& list_element : have_check_list)
				{
					if (*list_element == next_priority_node)
					{
						is_find = true;
						break;
					}
				}
				if (is_find)
				{
					delete next_priority_node;
					continue;
				}
				for (const auto& list_element : will_check_list)
				{
					if (*list_element == next_priority_node)
					{
						is_find = true;
						break;
					}
				}
				if (is_find)
				{
					delete next_priority_node;
					continue;
				}
				next_priority_node->per_node = front_node;
				will_check_list.push_back(next_priority_node);
			}
		}
	}
	
	do 
	{
		MapNode* node = will_check_list.front();
		will_check_list.pop_front();
		delete node;
	} while (!will_check_list.empty());

	do
	{
		MapNode* node = have_check_list.front();
		have_check_list.pop_front();
		delete node;
	} while (!have_check_list.empty());

	system("PAUSE");
    return 0;
}


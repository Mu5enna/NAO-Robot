/**
* @author Mustafa Eren NAKAS
* @date 09.01.2024
* @brief creates next pointer and pose object
*
* Node class supposed to create next pointer and pose object
*/

#pragma once
#include "Pose.h"

class Node {
public:
	Node* next;
	Node* prev;
	Pose pose;

	Node(Pose pose, Node* prev, Node* next) : pose(pose), prev(prev), next(next) {}
};

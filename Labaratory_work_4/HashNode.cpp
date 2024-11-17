#include "HashNode.h"
#include <iostream>

HashNode* CreateHashNode()
{
	HashNode* hashNode = new HashNode;
	hashNode->Value = "0";
	hashNode->Key = "0";

	return hashNode;
}

void DeletetHashNode(HashNode* hashNode)
{
	delete hashNode;
}
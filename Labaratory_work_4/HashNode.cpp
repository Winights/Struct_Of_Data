#include "HashNode.h"
#include <iostream>

HashNode* CreateHashNode()
{
	HashNode* hashNode = new HashNode;
	hashNode->Value = "";
	hashNode->Key = "";

	return hashNode;
}

void DeletetHashNode(HashNode* hashNode)
{
	delete hashNode;
}
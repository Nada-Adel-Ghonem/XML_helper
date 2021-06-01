#include "XML_Data.h"
#include "XML_Node.h"
#include <iostream>
#include <stack>

using namespace std;

XML_Node *XML_Data::getRoot() const
{
    return root;
}

const map<string, vector<XML_Node *>> &XML_Data::getGetName() const
{
    return get_Name;
}

XML_Data::XML_Data()
{
    root = new XML_Node("root");
}

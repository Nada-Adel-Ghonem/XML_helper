#include "XML_Data.h"

using namespace std;

XML_Data::XML_Data()
{
    root = new XML_Node("root");
}

XML_Node *XML_Data::getRoot() const
{
    return root;
}

void XML_Data::addNode(const string &name, XML_Node *node)
{
    getNode[name].emplace_back(node);
}

const vector<XML_Node *> &XML_Data::getNodeByName(const string &name)
{
    return getNode[name];
}

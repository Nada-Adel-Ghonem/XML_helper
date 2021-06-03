#ifndef XML_HELPER_XML_DATA_H
#define XML_HELPER_XML_DATA_H

#include "XML_Node.h"
#include <iostream>
#include <stack>

using namespace std;

class XML_Data
{

private:
    XML_Node *root;
    map<string, vector<XML_Node *>> getNode;

public:
    XML_Data();

    XML_Node *getRoot() const;

    const vector<XML_Node *> &getNodeByName(const string &);

    void addNode(const string &, XML_Node *);

};

#endif //XML_HELPER_XML_DATA_H

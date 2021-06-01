#ifndef XML_HELPER_XML_DATA_H
#define XML_HELPER_XML_DATA_H

#include "XML_Node.h"
#include <map>

using namespace std;

class XML_Data
{
    XML_Node *root;
    map<string, vector<XML_Node*>> get_Name;
};


#endif //XML_HELPER_XML_DATA_H

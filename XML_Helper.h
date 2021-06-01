#ifndef XML_HELPER_XML_HELPER_H
#define XML_HELPER_XML_HELPER_H

#include <fstream>
#include "XML_Data.h"
#include <iostream>
#include <stack>

class XML_Helper
{

public:
    static void get_Input(XML_Data *data);
    static void saveDate(string filePath, XML_Data xmlData);

private:
    static void printNode(const XML_Node* xmlNode, int indentation, ofstream& fileName);

};


#endif //XML_HELPER_XML_HELPER_H

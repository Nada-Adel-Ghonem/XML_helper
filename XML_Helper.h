#ifndef XML_HELPER_XML_HELPER_H
#define XML_HELPER_XML_HELPER_H

#include <fstream>
#include "XML_Data.h"

class XML_Helper
{

public:
    static XML_Data getInput();

    static void saveDate(string filePath, XML_Data xmlData);

    static XML_Data loadData(string filepath);

private:
    static void printNode(const XML_Node *xmlNode, int indentation, ofstream &fileName);

};


#endif //XML_HELPER_XML_HELPER_H

#include <iostream>
#include "XML_Helper.h"

using namespace std;

int main()
{

    XML_Data xmlData;
    XML_Helper::getInput(&xmlData);
    XML_Helper::saveDate("output_sample", xmlData);
//    dfs(data->getRoot(), 0);
    return 0;
}

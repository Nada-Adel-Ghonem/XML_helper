#include <iostream>
#include "XML_Helper.h"

using namespace std;

// void dfs(XML_Node *node, int lvl)
// {
//     int cnt = lvl;
//     while (cnt--) cout << '\t';
//     cout << "<" << node->getTagName() << ">\n";
//     if (node->isLeaf())
//     {
//         cnt = lvl + 1;
//         while (cnt--) cout << '\t';
//         cout << node->getText() << '\n';
//     }
//     for (auto i : node->getChildren())
//     {
//         dfs(i, lvl + 1);
//     }
//     while (lvl--) cout << '\t';
//     cout << "</" << node->getTagName() << ">\n";
// }

int main()
{
    XML_Data xmlData;
    XML_Helper::get_Input(&xmlData);
    XML_Helper::saveDate("output_sample", xmlData);
//    dfs(data->getRoot(), 0);
    return 0;
}

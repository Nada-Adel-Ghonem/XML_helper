#include <iostream>
#include "XML_Node.h"
#include "XML_Data.h"
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
    XML_Data *data = new XML_Data();
    XML_Helper::get_Input(data);
    // dfs(data->getRoot(), 0);
    return 0;
}

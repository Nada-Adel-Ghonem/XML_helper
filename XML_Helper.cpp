#include "XML_Helper.h"
#include "XML_Data.h"
#include "XML_Node.h"
#include <stack>
#include <iostream>

using namespace std;

void XML_Helper::get_Input(XML_Data *data)
{
    stack<XML_Node*> parents;
    parents.push(data->getRoot());
    while (parents.size())
    {
        cout << "Is it a leaf?" << endl;
        bool is_leaf;
        cin >> is_leaf;
        if (is_leaf)
        {
            cout << "Enter text: " << endl;
            string text;
            cin >> text;
        }
        else
        {
            cout << "Enter number of children: " << endl;
            int children;
            cin >> children;
        }
    }
}

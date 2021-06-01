#include "XML_Helper.h"

using namespace std;

void XML_Helper::get_Input(XML_Data *data)
{
    stack<XML_Node *> parents;
    parents.push(data->getRoot());
    while (parents.size())
    {
        cout << "Do you want to add child for node " << parents.top()->getTagName() << endl;
        bool new_child;
        cin >> new_child;
        if (new_child)
        {
            cout << "Enter tag name: " << endl;
            string tag_name;
            cin >> tag_name;
            parents.top()->setChildren(new XML_Node(tag_name));
            parents.push(parents.top()->getChildren().back());
            cout << "Is it a leaf?" << endl;
            bool is_leaf;
            cin >> is_leaf;
            if (is_leaf)
            {
                cout << "Enter text: " << endl;
                string text;
                cin >> text;
                parents.top()->setLeaf(is_leaf);
                parents.top()->setText(text);
                parents.pop();
            }
        }
        else
        {
            parents.pop();
        }
    }
}

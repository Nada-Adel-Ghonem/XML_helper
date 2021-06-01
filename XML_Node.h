#ifndef XML_HELPER_XML_NODE_H
#define XML_HELPER_XML_NODE_H

#include <string>
#include <vector>

using namespace std;

class XML_Node
{

private:
    string tagName, text;
    bool leaf;
    vector<XML_Node *> children;

public:
    XML_Node(const string &tagName);

    const string &getTagName() const;

    const string &getText() const;

    bool isLeaf() const;

    const vector<XML_Node *> &getChildren() const;

};


#endif //XML_HELPER_XML_NODE_H

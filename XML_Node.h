#ifndef XML_HELPER_XML_NODE_H
#define XML_HELPER_XML_NODE_H

#include <string>
#include <vector>
#include <map>

using namespace std;

class XML_Node
{

private:
    string tagName, text;
    bool leaf;
    vector<XML_Node *> children;
    map<string, string> attributes;

public:
    XML_Node(const string &tagName);

    const string &getTagName() const;

    const string &getText() const;

    bool isLeaf() const;

    const vector<XML_Node *> &getChildren() const;

    void setLeaf(bool leaf);

    void setText(const string &text);

    void addChild(XML_Node *child);

    const map<string, string> &getAttributes() const;

    void addAttribute(string key, string value);

};


#endif //XML_HELPER_XML_NODE_H

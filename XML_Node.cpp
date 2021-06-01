#include "XML_Node.h"

XML_Node::XML_Node(const string &tagName) : tagName(tagName)
{
}

const string &XML_Node::getTagName() const
{
    return tagName;
}

const string &XML_Node::getText() const
{
    return text;
}

bool XML_Node::isLeaf() const
{
    return leaf;
}

const vector<XML_Node *> &XML_Node::getChildren() const
{
    return children;
}

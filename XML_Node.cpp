#include "XML_Node.h"

using namespace std;

XML_Node::XML_Node(const string &tagName) : tagName(tagName)
{
    leaf = false;
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

void XML_Node::setLeaf(bool leaf)
{
    XML_Node::leaf = leaf;
}

void XML_Node::setText(const string &text)
{
    XML_Node::text = text;
}

void XML_Node::setChildren(XML_Node *child)
{
    XML_Node::children.emplace_back(child);
}

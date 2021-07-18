#include "XML_Helper.h"

using namespace std;

int XML_Helper::getPositiveInteger()
{
    int number;
    cin >> number;
    while(number <= 0)
    {
        cout << "Please enter a positive integer" << endl;
        cin >> number;
    }
    return number;
}

bool XML_Helper::getYesOrNoResponse()
{
    string userResponse;
    while (userResponse != "Yes" && userResponse != "No")
    {
        cout << "Please Enter \'Yes\' or \'No\' without quotations\n";
        cin >> userResponse;
    }
    return userResponse == "Yes";
}

XML_Data XML_Helper::getInput()
{
    XML_Data data;
    stack<XML_Node *> nodes;
    nodes.push(data.getRoot());
    while (!nodes.empty())
    {
        auto currentNode = nodes.top();
        nodes.pop();
        data.addNode(currentNode->getTagName(), currentNode);
        cout << "Please enter the data of the " << currentNode->getTagName() << " node" << endl;

        cout << "Does the node " << currentNode->getTagName() << " has attributes?" << endl;
        bool hasAttributes = getYesOrNoResponse();

        if (hasAttributes)
        {
            cout << "How many attributes does the " << currentNode->getTagName() << " node has?" << endl;
            int attrsCount = getPositiveInteger();
            for (int i = 1; i <= attrsCount; ++i)
            {
                string attrName;
                cout << "Enter the name of attribute #" << i << endl;
                cin >> attrName;
                string attrText;
                cout << "Enter the value of attribute #" << i << " then press Enter" << endl;
                cin.ignore();
                getline(cin, attrText);
                currentNode->addAttribute(attrName, attrText);
            }
        }

        cout << "Is the " << currentNode->getTagName() << " a leaf node?" << endl;
        bool isLeaf = getYesOrNoResponse();

        if (isLeaf)
        {
            cout << "Enter its text then press Enter" << endl;
            string nodeText;
            cin.ignore();
            getline(cin, nodeText);
            currentNode->setLeaf(true);
            currentNode->setText(nodeText);
        } else
        {
            cout << "How many children does the " << currentNode->getTagName() << " node has?" << endl;
            int childrenCount = getPositiveInteger();
            for (int i = 1; i <= childrenCount; ++i)
            {
                cout << "Enter the tag name for the child number " << i << endl;
                string tagName;
                cin >> tagName;
                currentNode->addChild(new XML_Node(tagName));
            }
            for (int i = childrenCount - 1; i >= 0; --i)
            {
                nodes.push(currentNode->getChildren()[i]);
            }
        }
    }
    return data;
}

void XML_Helper::saveDate(string filePath, XML_Data xmlData)
{
    ofstream outputFile;
    outputFile.open(filePath + ".xml");
    printNode(xmlData.getRoot(), 0, outputFile);
    outputFile.close();
}

void XML_Helper::printNode(const XML_Node *xmlNode, int indentation, ofstream &fileName)
{
    fileName << string(indentation, '\t') << "<" << xmlNode->getTagName();
    for (auto &attr : xmlNode->getAttributes())
    {
        fileName << ' ' << attr.first << "=\"" << attr.second << "\"";
    }
    fileName << ">\n";
    if (xmlNode->isLeaf())
    {
        fileName << string(indentation + 1, '\t') << xmlNode->getText() << "\n";
    }
    else
    {
        for (auto child : xmlNode->getChildren())
        {
            printNode(child, indentation + 1, fileName);
        }
    }
    fileName << string(indentation, '\t') << "</" << xmlNode->getTagName() << ">\n";
}

XML_Data XML_Helper::loadData(string filePath)
{
    string inputText;
    ifstream inputFile(filePath + ".xml");
    XML_Data data;
    stack<XML_Node *> parents;
    while (getline(inputFile, inputText))
    {
        string lastInput;
        for (char i : inputText)
        {
            if (i == '<' && !lastInput.empty())
            {
                parents.top()->setText(lastInput);
                lastInput.clear();
                parents.top()->setLeaf(true);
            }
            if ((i == ' ' || i == '\t') && (lastInput.empty() || lastInput.back() == ' '))
            {
                continue;
            }
            lastInput.push_back(i);
            if (i == '>' && !lastInput.empty() && lastInput[0] == '<')
            {
                if (lastInput[1] != '/')
                {
                    if (lastInput == "<root>")
                    {
                        parents.push(data.getRoot());
                    }
                    else
                    {
                        lastInput.erase(lastInput.begin());
                        lastInput.erase(lastInput.end() - 1);
                        parents.top()->addChild(new XML_Node(lastInput));
                        parents.push(parents.top()->getChildren().back());
                    }
                    data.addNode(parents.top()->getTagName(), parents.top());
                }
                else
                {
                    lastInput.erase(lastInput.begin(), lastInput.begin() + 2);
                    lastInput.erase(lastInput.end() - 1);
                    if (parents.empty() || (lastInput != parents.top()->getTagName()))
                    {
                        cout << "There is no open tag with " << lastInput << endl;
                        exit(0);
                    }
                    else
                    {
                        parents.pop();
                    }
                }
                lastInput.clear();
            }
        }
        if (!lastInput.empty())
        {
            parents.top()->setText(lastInput);
            parents.top()->setLeaf(true);
            lastInput.clear();
        }
    }
    if (!parents.empty())
    {
        cout << "This xml file is not complete" << endl;
        exit(0);
    }
    return data;
}
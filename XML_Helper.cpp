#include "XML_Helper.h"

using namespace std;

XML_Data XML_Helper::getInput()
{
    XML_Data data;
    stack<XML_Node *> parents;
    parents.push(data.getRoot());
    while (!parents.empty())
    {
        cout << "Do you want to add child for node " << parents.top()->getTagName() << endl;
        bool new_child;
        cin >> new_child;
        if (new_child)
        {
            cout << "Enter tag name: " << endl;
            string tag_name;
            cin >> tag_name;
            parents.top()->addChild(new XML_Node(tag_name));
            parents.push(parents.top()->getChildren().back());
            data.addNode(tag_name, parents.top());
            cout << "How many attributes it has?" << endl;
            int attrs;
            cin >> attrs;
            for (int i = 0; i < attrs; ++i)
            {
                string name;
                cout << "Enter " << i + 1 << "th attribute name" << endl;
                cin >> name;
                string text;
                cout << "Enter " << i + 1 << "th attribute value" << endl;
                cin.ignore();
                getline(cin, text);
                parents.top()->addAttribute(name, text);
            }
            cout << "Is it a leaf?" << endl;
            bool is_leaf;
            cin >> is_leaf;
            if (is_leaf)
            {
                cout << "Enter text: " << endl;
                string text;
                cin.ignore();
                getline(cin, text);
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
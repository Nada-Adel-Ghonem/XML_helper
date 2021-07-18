# XML_helper

 XML Helper is a C++ class that works as a helper for any developer who needs to use XML files in his project. The data inside an XML file is stored inside an instance of the XML_Data class.
 
 
 ### The main functions:
 * ```saveData(string filePath, XML_Data xmlData): void``` method that converts the data inside an XML_Data object into an XML file.
 * ```loadData(string filePath): XML_Data``` method that loads an existing XML file into an XML_Data object.
 
 ### Additional Features:
 * The XML_Helper class contains ```getInput(): XML_Data ``` method that creates a new XML_Data object and interacts with the user to fill its data.
 * The XML_Data class contains ```getNodeByName(string): vector<XML_Node*>``` method that returns a vector of pointers to all the XML nodes that have a tag name of the string passed to the function.

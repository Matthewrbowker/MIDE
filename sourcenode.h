#include <string>

using namespace std;

#ifndef SOURCENODE_H
#define SOURCENODE_H


class sourceNode
{
private:
    string name;
    string url;
    string notes;
    sourceNode * next;

public:
    sourceNode();
    void setName(string tmpName);
    string getName();
    void setUrl(string tmpUrl);
    string getUrl();
    void setNotes(string tmpNotes);
    string getNotes();
    void setNext(sourceNode *);
    sourceNode * getNext();
};

#endif // SOURCENODE_H

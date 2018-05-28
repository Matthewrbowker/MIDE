#include "sourcenode.h"

sourceNode::sourceNode()
{
    name = "";
    url = "";
    notes = "";
}

void sourceNode::setName(string tmpName) {
    name = tmpName;
}

string sourceNode::getName() {
    return name;
}

void sourceNode::setUrl(string tmpUrl) {
    url = tmpUrl;
}

string sourceNode::getUrl() {
    return url;
}

void sourceNode::setNotes(string tmpNotes) {
    notes = tmpNotes;
}

string sourceNode::getNotes() {
    return notes;
}

void sourceNode::setNext(sourceNode * tmpNode) {
    next = tmpNode;
}

sourceNode * sourceNode::getNext() {
    return next;
}

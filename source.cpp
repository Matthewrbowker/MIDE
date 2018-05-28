#include "source.h"

Source::Source()
{
    first = nullptr;
}

void Source::add(string name, string url, string notes) {
    sourceNode tmp;
    tmp.setName(name);
    tmp.setUrl(url);
    tmp.setNotes(notes);
    tmp.setNext(nullptr);
    if (first != nullptr) {

    }
    else {
        first = &tmp;
    }
}

sourceNode * Source::find(string name) {
    return first;
}

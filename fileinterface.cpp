#include "fileinterface.h"
#include <string>
#include <iostream>
#include "buckaroo/official/leethomason/tinyxml2/tinyxml2.h"
#include "mideexception.h"

using namespace std;

FileInterface::FileInterface()
{
    newFile();
}

FileInterface::FileInterface(string fileName) {
    newFile();
    loadFile(fileName);
}

void FileInterface::newFile() {
    remoteApi = "";
    lastUpdate = "";
    title = "";
    text = "";
    file = "";

}

void FileInterface::saveFile(string fileName) {
    throw new exception();
}

bool FileInterface::isNewFile() {
    return (file.compare(""));
}

void FileInterface::loadFile(string fileName) {
    tinyxml2::XMLDocument doc;
    doc.LoadFile(fileName.c_str());
    tinyxml2::XMLNode * root = doc.FirstChildElement("mide");
    if (root == nullptr) {
        throw new MIDEException("Unknown root node, bad file format.");
        return;
    }
    tinyxml2::XMLNode * article = root->FirstChildElement("article");
    tinyxml2::XMLNode * sources = root->FirstChildElement("sources");
    if (article == nullptr || sources == nullptr) {
        cout << "FAIL" << endl;
        return;
    }

    tinyxml2::XMLElement * remote = article->FirstChildElement("remote");
    if (remote == nullptr) {
        cout << "FAIL" << endl;
        return;
    }

    // Actually load the data
    remoteApi = remote->Attribute("api");
    lastUpdate = remote->Attribute("last-update");
    title = remote->Attribute("title");

    /*for(TiXmlElement* e = root->FirstChildElement("sources"); e != NULL; e = e->NextSiblingElement("sources"))
    {
        string wmName = e->Attribute("name");

    }*/

    file = fileName;
}

void FileInterface::setRemoteApi(string remoteApiTmp) {
    remoteApi = remoteApiTmp;
}

string FileInterface::getRemoteApi() {
    return remoteApi;
}

void FileInterface::setLastUpdate(string lastUpdateTmp) {
    lastUpdate = lastUpdateTmp;
}

string FileInterface::getLastUpdate() {
    return lastUpdate;
}

void FileInterface::setTitle(string titleTmp) {
    title = titleTmp;
}

string FileInterface::getTitle() {
    return title;
}

void FileInterface::setText(string textTmp) {
    text = textTmp;
}

string FileInterface::getText() {
    return text;
}

void FileInterface::dump() {
    cout << "Contents currently loaded: " << endl;
    cout << remoteApi << endl;
    cout << lastUpdate << endl;
    cout << title << endl;
    cout << text << endl;
    cout << file << endl;

}

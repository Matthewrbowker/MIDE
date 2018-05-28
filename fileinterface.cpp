#include "fileinterface.h"
#include <string>
#include <iostream>
#include "buckaroo/official/leethomason/tinyxml2/tinyxml2.h"

using namespace std;

FileInterface::FileInterface()
{

}

FileInterface::FileInterface(string fileName) {
    loadFile(fileName);
}

void FileInterface::newFile() {

}

void FileInterface::saveFile(string fileName) {

}

void FileInterface::loadFile(string fileName) {
    tinyxml2::XMLDocument doc;
    doc.LoadFile(fileName.c_str());
    cout << "Testing" << endl;
    cout << doc.ErrorName() << endl;
    tinyxml2::XMLNode * root = doc.FirstChildElement("mide");
    // cout << doc.FirstChildElement("mide")->FirstChildElement("sources")->FirstChildElement("example")->GetText() << endl;
    if (root == nullptr) {
        cout << "FAIL" << endl;
        return;
    }
    else {
        cout << "SUCCESS" << endl;
    }
    tinyxml2::XMLNode * article = root->FirstChildElement("article");
    tinyxml2::XMLNode * sources = root->FirstChildElement("sources");
    if (article == nullptr || sources == nullptr) {
        cout << "FAIL" << endl;
        return;
    }
    else {
        cout << "SUCCESS" << endl;
    }

    tinyxml2::XMLElement * remote = article->FirstChildElement("remote");
    if (remote == nullptr) {
        cout << "FAIL" << endl;
        return;
    }
    else {
        cout << "SUCCESS" << endl;
    }
    // Actually load the data
    remoteApi = remote->Attribute("api");
    cout << "SUCCESS" << endl;
    lastUpdate = remote->Attribute("last-update");
    cout << "SUCCESS" << endl;
    title = remote->Attribute("title");
    cout << "SUCCESS" << endl;

    /*for(TiXmlElement* e = root->FirstChildElement("wave_manager"); e != NULL; e = e->NextSiblingElement("wave_manager"))
    {
        string wmName = e->Attribute("name");

    }*/
    cout << remoteApi << endl;
    cout << lastUpdate << endl;
    cout << title << endl;
    cout << "TESTING" << endl;
    //
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

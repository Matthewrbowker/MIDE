#include "fileinterface.h"
#include <string>
#include <iostream>
#include "buckaroo/official/leethomason/tinyxml2/tinyxml2.h"
#include "mideexception.h"

using namespace std;

void FileInterface::FileOperation(bool save) {

}

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
    tinyxml2::XMLDocument doc;

    tinyxml2::XMLElement root;

    root.SetName("mide");

    doc.LinkEndChild(root);

    tinyxml2::XMLElement article;

    article.SetName("article");
    tinyxml2::XMLElement sources;
    sources.SetName("sources");

    root.LinkEndChild(article);
    root.LinkEndChild(sources);


    tinyxml2::XMLElement api =new tinyxml2::XMLElement("api");
    tinyxml2::XMLElement lastUpdateNode =new tinyxml2::XMLElement("last-update");
    tinyxml2::XMLElement titleNode =new tinyxml2::XMLElement("title");
    tinyxml2::XMLElement textNode =new tinyxml2::XMLElement("text");

    api.SetText(remoteApi);
    lastUpdateNode.setText(lastUpdate);
    titleNode.SetText(title);
    textNode.SetText(text);

    article.LinkEndChild(api);
    article.LinkEndChild(lastUpdateNode);
    article.LinkEndChild(titleNode);
    article.LinkEndChild(textNode);

    doc.SaveFile(fileName.c_str() + "_2.mide");
    modified = false;
}

bool FileInterface::isNewFile() {
    return (file.compare(""));
}

void FileInterface::loadFile(string fileName) {
    modified = false;
    tinyxml2::XMLDocument doc;
    doc.LoadFile(fileName.c_str());
    tinyxml2::XMLNode * root = doc.FirstChildElement("mide");
    if (root == nullptr) {
        throw new MIDEException("Unknown root node, bad file format.");
        return;
    }

    tinyxml2::XMLNode * article = root->FirstChildElement("article");
    if (article == nullptr) {
        cout << "FAIL" << endl;
        return;
    }

    tinyxml2::XMLElement * api = article->FirstChildElement("api");
    tinyxml2::XMLNode * sources = root->FirstChildElement("sources");
    tinyxml2::XMLElement * lastUpdateNode = article->FirstChildElement("last-update");
    tinyxml2::XMLElement * titleNode = article->FirstChildElement("title");
    tinyxml2::XMLElement * textNode = article->FirstChildElement("text");
    if (api == nullptr || sources == nullptr || lastUpdateNode == nullptr || titleNode == nullptr || textNode == nullptr) {
        cout << "FAIL" << endl;
        return;
    }

    // Actually load the data
    text = textNode->GetText();
    remoteApi = api->GetText();
    lastUpdate = lastUpdateNode->GetText();
    title = titleNode->GetText();

    /*for(TiXmlElement* e = root->FirstChildElement("sources"); e != NULL; e = e->NextSiblingElement("sources"))
    {
        string wmName = e->Attribute("name");

    }*/

    file = fileName;
}

void FileInterface::setRemoteApi(string remoteApiTmp) {
    modified = true;
    remoteApi = remoteApiTmp;
}

string FileInterface::getRemoteApi() {
    return remoteApi;
}

void FileInterface::setLastUpdate(string lastUpdateTmp) {
    modified = true;
    lastUpdate = lastUpdateTmp;
}

string FileInterface::getLastUpdate() {
    return lastUpdate;
}

void FileInterface::setTitle(string titleTmp) {
    modified = true;
    title = titleTmp;
}

string FileInterface::getTitle() {
    return title;
}

void FileInterface::setText(string textTmp) {
    modified = true;
    text = textTmp;
}

string FileInterface::getText() {
    return text;
}

string FileInterface::getFile() {
    return file;
}

void FileInterface::dump() {
    cout << "Contents currently loaded: " << endl;
    cout << remoteApi << endl;
    cout << lastUpdate << endl;
    cout << title << endl;
    cout << text << endl;
    cout << file << endl;

}

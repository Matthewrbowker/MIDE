#include "fileinterface.h"

FileInterface::FileInterface()
{

}

FileInterface::FileInterface(string fileName) {
    loadFile(fileName);
}

FileInterface::loadFile(string fileName) {

}

void FileInterface::setRemoteApi(string remoteApiTmp) {
    rempoteApi = remoteApiTmp;
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

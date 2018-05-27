#ifndef FILEINTERFACE_H
#define FILEINTERFACE_H


class FileInterface
{
private:
    string remoteApi;
    string lastUpdate;
    string title;
    string text;
public:
    FileInterface();
    FileInterface(string fileName);
    loadFile(string fileName);
    void setRemoteApi(string remoteApiTmp);
    string getRemoteApi();
    void setLastUpdate(string lastUpdateTmp);
    string getLastUpdate();
    void setTitle(string titleTmp);
    string getTitle();
    void setText(string textTmp);
    string getText();
};

#endif // FILEINTERFACE_H

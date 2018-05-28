#include <string>

using namespace std;

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
    FileInterface(string);
    void loadFile(string);
    void setRemoteApi(string);
    string getRemoteApi();
    void setLastUpdate(string);
    string getLastUpdate();
    void setTitle(string);
    string getTitle();
    void setText(string);
    string getText();
};

#endif // FILEINTERFACE_H

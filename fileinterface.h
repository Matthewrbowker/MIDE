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
    string file;
public:
    FileInterface();
    FileInterface(string);
    void newFile();
    void loadFile(string);
    void saveFile(string = NULL);
    bool isNewFile();
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

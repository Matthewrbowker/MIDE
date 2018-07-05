#include "mainwindow.h"
#include "fileinterface.h"
#include <string>
#include <QApplication>
#include <iostream>
#include "mideexception.h"

using namespace std;

int main(int argc, char *argv[])
{
    //if (argc > 1 && argv[1] == '--command') {
    if (true) {
        int choice;
        FileInterface fi;
        while(1) {
            cout << "1: New File" << endl
                 << "2: Load File" << endl
                 << "3: Save File" << endl
                 << "4: Dump current file contents" << endl
                 << "5: Modify API" << endl
                 << "6: Modify Title" << endl
                 << "7: Modify Text" << endl
                 //<< "8: Add Source" << endl
                 //<< "9: Show Sources" << endl
                 //<< "10: Delete Source" << endl
                 << "0: Quit!" << endl;
            try {
                cin >> choice;
                if (choice == 1) {
                    fi.newFile();
                    cout << "New file created!" << endl;
                }
                else if (choice == 2) {
                    string file;
                    cout << "File location: ";
                    cin >> file;
                    fi.loadFile(file);
                }
                else if (choice == 3) {
                    cout << "Save location: ";
                    string file;
                    cin >> file;
                    fi.saveFile(file);
                }
                else if(choice == 4) {
                    fi.dump();
                }
                else if(choice == 5) {
                    string newAPI;
                    cout << "Current API Value: " << fi.getRemoteApi() << endl;
                    cout << "New API Value: ";
                    cin >> newAPI;
                    fi.setRemoteApi(newAPI);
                    cout << "Value set: " << fi.getRemoteApi() << endl;
                }
                else if(choice == 6) {
                    string newTitle;
                    cout << "Current Title: " << fi.getTitle() << endl;
                    cout << "New Title: ";
                    cin >> newTitle;
                    fi.setTitle(newTitle);
                    cout << "Value set: " << fi.getTitle() << endl;
                }
                else if(choice == 7) {
                    string newText;
                    cout << "Current Text: " << fi.getText() << endl;
                    cout << "New Text: ";
                    cin >> newText;
                    fi.setText(newText);
                    cout << "Value set: " << fi.getText() << endl;
                }
                else if (choice == 0) {
                    return 0;
                }
                else {
                    cout << "Unknown command" << endl;
                }
            }
            catch(MIDEException e) {
                cout << e.what() << endl;
                return 0;
            }

        }
    }
    else {
        QApplication a(argc, argv);
        MainWindow w;
        w.show();

        return a.exec();

    }
}

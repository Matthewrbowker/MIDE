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

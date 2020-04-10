/*
Write a program using vectors and iterators that allows a user to maintain
a list of his or her favorite games. The program should allow the
user to list all game titles, add a game title, and remove a game title.

04062020 added save and load functions 

*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void addAlbum(vector<string>& list);
void delAlbum(vector<string>& list);
void printAlbum(const vector<string>& list);
void saveList(const vector<string>& list);
void loadList(vector <string>& list);
int menu();

int main()
{

    vector<std::string> albumList;
    int menuChoice = 1;
    cout << "\tWelcome to the Album Program\n\n";
    
    do
    {
        menuChoice = menu();
        switch (menuChoice)
        {
        case 1:
            addAlbum(albumList);
            break;
        case 2:
            delAlbum(albumList);
            break;
        case 3:
            printAlbum(albumList);
            break;
        case 4:
            saveList(albumList);
            break;
        case 5:
            loadList(albumList);
            break;
        case 0:
            menuChoice = 0;
            break;
        default:
            cout << "That is not a valid choice\n\n";
            break;
        }
    } while (menuChoice != 0);

    return 0;
}

void addAlbum(vector<string>& list)
{
    cin.ignore();
    string newAlbum;
    do {
        cout << "Enter your new album Q to quit: ";
        getline(cin, newAlbum);
        if (newAlbum != "Q")
            list.push_back(newAlbum);
    } while (newAlbum != "Q");
}//End addAlbum

void delAlbum(vector<string>& list)
{
    int albumNumber;
    cout << "\n\nWhich album would you like to delete: ";
    cin >> albumNumber;
    list.erase(list.begin() + albumNumber - 1);
    printAlbum(list);
}//End delAlbum

void printAlbum(const vector<string>& list)
{
    vector<string>::const_iterator iter;
    int i = 1;

    cout << "\nDisplay list\n\n";
    for (iter = list.begin(); iter != list.end(); iter++)
    {
        cout << i << ": " << *iter << endl;
        i++;
    }
    cout << endl;
}//End printAlbum

void saveList(const vector<string>& list) {
    ofstream outFile;
    vector<string>::const_iterator iter;
    outFile.open("cdlist.dat");
    if (outFile.is_open())
    {
        for (iter = list.begin(); iter != list.end(); iter++) {
            outFile << *iter << endl;
            }
        cout << "Your file is done saving." << endl << endl;
        outFile.close();
    }
    else
        cout << "File failed to open :(" << endl << endl;
 }//End saveList

void loadList(vector<string>& list) {
    ifstream infile;
    string album;
    vector<string>::iterator iter;
    infile.open("cdlist.dat");
    if (infile.is_open()){
        while (getline(infile, album)) {
             list.push_back(album);           
        }
        infile.close();
    }
    cout << "You're file is done loading" << endl;
}//End loadList

int menu()
{
    int choice;
    cout << "\tPlease select an option:\n\n";
    cout << "1. Add album\n";
    cout << "2. Delete album\n";
    cout << "3. List albums\n";
    cout << "4. Save\n";
    cout << "5. Load list\n";
    cout << "0 to quit\n\n";
    cout << "Please enter your number: ";
    cin >> choice;
    return choice;
}//End menu

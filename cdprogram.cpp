/*
Write a program using vectors and iterators that allows a user to maintain
a list of his or her favorite games. The program should allow the
user to list all game titles, add a game title, and remove a game title.

04062020 added save and load functions 
04122020 created Album class along with operator overloads

*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "album.h"

using namespace std;

void addAlbum(vector<Album>& list);
void delAlbum(vector<Album>& list);
void printAlbum(const vector<Album>& list);
void saveList(const vector<Album>& list);
void loadList(vector <Album>& list);
char menu();

int main()
{

    vector<Album> albumList;
    char menuChoice = 1;

    if (albumList.empty())
    {
        loadList(albumList);
        cout << "*********************\n";
    }
    
    cout << "\tWelcome to the Album Program\n\n";
    
    do
    {
        menuChoice = menu();
        switch (menuChoice)
        {
        case '1':
            addAlbum(albumList);
            break;
        case '2':
            delAlbum(albumList);
            break;
        case '3':
            printAlbum(albumList);
            break;
        case '4':
            saveList(albumList);
            break;
        case '5':
            loadList(albumList);
            break;
        case '0':
            menuChoice = 0;
            break;
        default:
            cout << "That is not a valid choice\n\n";
            break;
        }
    } while (menuChoice != '0');

    return 0;
}

void addAlbum(vector<Album>& list)
{
    cin.ignore();
    Album newAlbum;
    char choice = ' ';
    do {
        cout << "Enter the name of the album: ";
        getline(cin, newAlbum.m_Name);
        cout << "Enter the album Artist: ";
        getline(cin,newAlbum.m_Artist);
        cout << "Enter the year it was made: ";
        getline(cin, newAlbum.m_Year);
        list.push_back(newAlbum);
        cout << "\n\nPush any key to enter a new album \"Q\" to quit: ";
        cin.get(choice);
    } while (choice != 'Q');
    cin.ignore();
}//End addAlbum

void delAlbum(vector<Album>& list)
{
    int albumNumber;
    cout << "\n\nWhich album would you like to delete: ";
    cin >> albumNumber;
    list.erase(list.begin() + albumNumber - 1);
    printAlbum(list);
}//End delAlbum

void printAlbum(const vector<Album>& list){
    vector<Album>::const_iterator iter;
    cout << "\nDisplay list\n\n";
    int i = 1;
    for(iter=list.begin(); iter != list.end(); iter++){
        cout << i << ". " << *iter << endl;
        i++;
    }
    cin.ignore();
}//End printAlbum

void saveList(const vector<Album>& list) {
    ofstream outFile;
    vector<Album>::const_iterator iter;
    outFile.open("cdlist.dat");
    if (outFile.is_open()){
        for (iter = list.begin(); iter != list.end(); iter++){
            outFile << *iter;        
        }
        cout << "Your file is done saving." << endl << endl;
    }
    else
        cout << "File failed to open :(" << endl << endl;
    cin.ignore();
 }//End saveList

void loadList(vector<Album>& list) {
    ifstream infile;
    Album information;
    infile.open("cdlist.dat");
    while(infile >> information){
        list.push_back(information);
    } 
    cout << "You're file is done loading, push ENTER to continue." << endl;
    if(cin.eof())
        cin.ignore();   //Clear the stream
}//End loadList

char menu(){
    char choice;
    cout << "\tPlease select an option:\n\n";
    cout << "1. Add album\n";
    cout << "2. Delete album\n";
    cout << "3. List albums\n";
    cout << "4. Save\n";
    cout << "5. Load list\n";
    cout << "0 to quit\n\n";
    cout << "Please enter your number: ";
    cin.get(choice);
    return choice;
}//End menu


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Books {
private:
    string BookName;
    string AuthorName;
    int BookYear;

public:
    string setBookName(string n) {
        BookName = n;
        return BookName;
    }
    string setAuthorName(string m) {
        AuthorName = m;
        return AuthorName;
    }
    int setBookYear(int a) {
        BookYear = a;
        return BookYear;
    }

    string getBookName() {
        return BookName;
    }

    string getAuthorName() {
        return AuthorName;
    }

    int getBookYear() {
        return BookYear;
    }
};

int main() {
    int choice, i = 0;
    Books Add[100];
    string temp;
    int year;

    while (true) {
        cout << "\nMenu"
             << "\n1 - Add Book"
             << "\n2 - Display Books"
             << "\n3 - Search Book"
             << "\n4 - Exit"
             << "\nEnter your choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1:
                cout << "Enter Book Name: ";
                getline(cin, temp);
                Add[i].setBookName(temp);

                cout << "Enter Author Name: ";
                getline(cin, temp);
                Add[i].setAuthorName(temp);

                cout << "Enter Publication Year: ";
                cin >> year;
                Add[i].setBookYear(year);
                i++;
                break;

            case 2:
                cout << left << setw(30) << "Title"<< setw(30) << "Author"<< setw(10) << "Year" << endl;
                
                for (int j = 0; j < i; j++) {
                    cout << left << setw(30) << Add[j].getBookName()
                         << setw(30) << Add[j].getAuthorName()
                         << setw(10) << Add[j].getBookYear() << endl;
                }
                break;

            case 3:
                cout << "Enter the name of the book to search: ";
                getline(cin, temp);
                {
                    bool found = false;
                    for (int j = 0; j < i; j++) {
                        if (Add[j].getBookName() == temp) {
                            found = true;
                            cout << "Book found!" << endl;
                            cout << left << setw(30) << Add[j].getBookName()
                                 << setw(30) << Add[j].getAuthorName()
                                 << setw(10) << Add[j].getBookYear() << endl;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Book not found!" << endl;
                    }
                }
                break;

            case 4:
                cout << "Exiting program." << endl;
                return 0;  

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}

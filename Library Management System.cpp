#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Library {
protected:
    string title;
    int id;
    int year;

public:
    Library(string t, int i, int y) : title(t), id(i), year(y) {}
    
    virtual ~Library() {} 
    
    virtual void display() = 0;
    virtual double calculateFine(int days) { 
        return 0.0; 
        
    }
    
    int getId() { 
        return id;
        }
    string getTitle() { 
        return title; 
        
    }
};

class Book : public Library {
private:
    string author;
    int pages;

public:
    Book(string t, int i, int y, string a, int p) 
        : Library(t, i, y), author(a), pages(p) {}
        
    void display() override {
        cout << "ID: " << id << " | Title: " << title  << " | Author: " << author << " | Pages: " << pages  << " | Year: " << year << endl;
    }
    
    double calculateFine(int days) override { return days * 0.5; }
    friend void compareBooks(Book& b1, Book& b2);
};

void compareBooks(Book& b1, Book& b2) {
    if (b1.pages > b2.pages) {
        cout << "\n-> \"" << b1.title << "\" is larger than \"" << b2.title << "\"" << endl;
    } else if (b2.pages > b1.pages) {
        cout << "\n-> \"" << b2.title << "\" is larger than \"" << b1.title << "\"" << endl;
    } else {
        cout << "\n-> Both books are equal at " << b1.pages << " pages." << endl;
    }
}

class Magazine : public Library {
private:
    int issueNumber;

public:
    Magazine(string t, int i, int y, int issue) 
        : Library(t, i, y), issueNumber(issue) {}

    void display() override {
        cout << "ID: " << id << " | Title: " << title  << " | Issue No: " << issueNumber << " | Year: " << year << endl;
    }
    
    double calculateFine(int days) override { return days * 0.2; }
};

class DVD : public Library {
private:
    int duration;

public:
    DVD(string t, int i, int y, int d) 
        : Library(t, i, y), duration(d) {}

    void display() override {
        cout << "ID: " << id << " | Title: " << title  << " | Duration: " << duration << " mins | Year: " << year << endl;
    }
    
    double calculateFine(int days) override { return days * 1.0; }
};

class library {
private:
    vector<Library*> collection;
    
    bool idExists(int id) {
        for (auto item : collection) {
            if (item->getId() == id) 
            return true;
        }
        return false;
    }
    
public: 
    ~library() {
        for (auto item : collection) {
            delete item;
        }
    }

    void addBook() {
        string title, author;
        int id, year, pages;
        cout << endl << "Enter ID: "; cin >> id;
        if (idExists(id)) { 
            cout << "ID already exists  in the database"; 
        }
        cout << "Enter Title: "; getline(cin, title);
        cout << "Enter Author: "; getline(cin, author);
        cout << "Enter Year: "; cin >> year;
        cout << "Enter Pages: "; cin >> pages;

        collection.push_back(new Book(title, id, year, author, pages));
        cout << "Book added" << endl;
    }
    
    void addMagazine() {
        string title;
        int id, year, issue;
        cout << endl << "Enter ID: "; cin >> id;
        if (idExists(id)) { 
            cout << "ID already exists in the database" << endl; 
        }
        cout << "Enter Title: "; getline(cin, title);
        cout << "Enter Year: "; cin >> year;
        cout << "Enter Issue Number: "; cin >> issue;

        collection.push_back(new Magazine(title, id, year, issue));
        cout << "Magazine added " << endl;
    }

    void addDVD() {
        string title;
        int id, year, duration;
        cout << endl << "Enter ID: "; cin >> id;
        if (idExists(id)) { 
            cout << "ID already exists  in the database" << endl;
        }
        cout << "Enter Title: "; getline(cin, title);
        cout << "Enter Year: "; cin >> year;
        cout << "Enter Duration (mins): "; cin >> duration;

        collection.push_back(new DVD(title, id, year, duration));
        cout << "DVD added to collection" << endl;
    }
    
    void displayAll() {
        if (collection.empty()) {
            cout << endl << "The library collection is currently empty." << endl;
        }
        else {
        for (auto item : collection) {
            item->display();
      }
     }
    }
    
    void searchItem() {
        int id;
        cout << "Enter ID to search: "; cin >> id;
        for (auto item : collection) {
            if (item->getId() == id) {
                cout << "Item Found: ";
                item->display();
                cout << endl;
            }
        }
        cout << "Item with ID " << id << " were not found." << endl;
    }

    void removeItem() {
        int id;
        cout << "Enter ID to remove: "; cin >> id;
        for (int i = 0; i < collection.size(); i++) {
            if (collection[i]->getId() == id) {
                delete collection[i];
                
                for (int j = i; j < collection.size() - 1; j++) {
                    collection[j] = collection[j + 1];
                }
                collection.pop_back();
                
                cout << "Item removed" << endl;
            }
        }
        cout << "Error: Item with ID " << id << " does not exist" << endl;
    }

    void calculateFineMenu() {
        int id, days;
        cout << "Enter Item ID: "; cin >> id;
        for (auto item : collection) {
            if (item->getId() == id) {
                cout << "Enter overdue days: "; cin >> days;
                cout << "Total Fine for " << item->getTitle() << ": " 
                     << item->calculateFine(days) << " USD" << endl;
            }
        }
        cout << "Item not found." << endl;
    }

    void compareBooksMenu() {
        vector<Book*> books;
        
        for (int i = 0; i < collection.size(); i++) {
            Book* b = dynamic_cast<Book*>(collection[i]);
            if (b != nullptr) {
                books.push_back(b);
            }
        }

        if (books.size() < 2) {
            cout << "Need at least 2 books to compare.";
            return;
        }

        cout << "Available Books:";
        for (int i = 0; i < books.size(); i++) {
            cout << "ID: " << books[i]->getId() << " - " << books[i]->getTitle() << endl;
        }

        int id1, id2;
        cout << "Enter ID of first book: "; cin >> id1;
        cout << "Enter ID of second book: "; cin >> id2;

        Book* b1 = nullptr;
        Book* b2 = nullptr;

        for (int i = 0; i < books.size(); i++) {
            if (books[i]->getId() == id1)
            b1 = books[i];
            if (books[i]->getId() == id2)
            b2 = books[i];
        }

        if (b1 == nullptr || b2 == nullptr) {
            cout << "One or both books not found among selection.\n";
        }

        compareBooks(*b1, *b2);
    }
}; 

int main() {
    library lib; 
    int choice;

    while (true) {
        cout << "\n===== MAIN MENU =====" << endl;
        cout << "1. Add a Book" << endl;
        cout << "2. Add a Magazine" << endl;
        cout << "3. Add a DVD" << endl;
        cout << "4. Display All Library Items" << endl;
        cout << "5. Search for an Item by ID" << endl;
        cout << "6. Remove an Item by ID" << endl;
        cout << "7. Calculate Overdue Fines" << endl;
        cout << "8. Compare Two Books by number of Pages" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter your choice (1-9): ";
        cin >> choice;
        
        if (choice == 9) {
            cout << "Exiting Application" << endl;
            break;
        }
        
        switch (choice) {
            case 1:
             lib.addBook(); 
             break;
             
            case 2:
             lib.addMagazine();
             break;
             
            case 3:
             lib.addDVD();
             break;
             
            case 4:
             lib.displayAll();
             break;
            
            case 5:
             lib.searchItem();
             break;
            
            case 6: 
             lib.removeItem();
             break;
            
            case 7:
             lib.calculateFineMenu();
             break;
            
            case 8: 
             lib.compareBooksMenu();
             break; 
            
            default:
             cout << "Invalid choice, please choose between 1 to 9 " << endl;
             break;
        }
    }
    return 0;
}
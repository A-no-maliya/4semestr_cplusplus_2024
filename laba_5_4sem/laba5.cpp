#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

struct Book {
    std::string id, author, title;
    int pages;
};

class Library {
public:
    void writeBooksToFile(const std::string& filename, const std::vector<Book>& books);
    void readBooksFromFile(const std::string& filename, std::vector<Book>& books);
    void addBook(std::vector<Book>& books);
    void viewBooks(const std::vector<Book>& books);
    void deleteBook(std::vector<Book>& books, const std::string& id);
    void searchBook(const std::vector<Book>& books, const std::string& title);
    void searchBookByPrefix(const std::vector<Book>& books, const std::string& prefix);
    void editBook(std::vector<Book>& books, const std::string& id);
};

void Library::writeBooksToFile(const std::string& filename, const std::vector<Book>& books) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Failed to open file " << filename << " for writing" << std::endl;
        return;
    }
    for (const auto& book : books) {
        outFile << book.id << " " << book.author << " " << book.title << " " << book.pages << std::endl;
    }
    outFile.close();
}

void Library::readBooksFromFile(const std::string& filename, std::vector<Book>& books) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) {
        std::cerr << "Failed to open file " << filename << " for reading" << std::endl;
        return;
    }
    Book book;
    while (inFile >> book.id >> book.author >> book.title >> book.pages) {
        books.push_back(book);
    }
    inFile.close();
}

void Library::addBook(std::vector<Book>& books) {
    Book newBook;
    std::cout << "Enter ID, author, title, and number of pages: ";
    std::cin >> newBook.id >> newBook.author >> newBook.title >> newBook.pages;
    books.push_back(newBook);
    writeBooksToFile("library.txt", books);
}

void Library::viewBooks(const std::vector<Book>& books) {
    for (const auto& book : books) {
        std::cout << book.id << " " << book.author << " " << book.title << " " << book.pages << std::endl;
    }
}

void Library::deleteBook(std::vector<Book>& books, const std::string& id) {
    books.erase(std::remove_if(books.begin(), books.end(), [&id](const Book& book) { return book.id == id; }), books.end());
    writeBooksToFile("library.txt", books);
}

void Library::searchBook(const std::vector<Book>& books, const std::string& title) {
    auto it = std::find_if(books.begin(), books.end(), [&title](const Book& book) { return book.title == title; });
    if (it != books.end()) {
        std::cout << it->id << " " << it->author << " " << it->title << " " << it->pages << std::endl;
    }
    else {
        std::cout << "Book not found." << std::endl;
    }
}

void Library::searchBookByPrefix(const std::vector<Book>& books, const std::string& prefix) {
    std::cout << "Books with titles starting with '" << prefix << "':" << std::endl;
    for (const auto& book : books) {
        if (book.title.compare(0, prefix.length(), prefix) == 0) {
            std::cout << book.id << " " << book.author << " " << book.title << " " << book.pages << std::endl;
        }
    }
}

void Library::editBook(std::vector<Book>& books, const std::string& id) {
    auto it = std::find_if(books.begin(), books.end(), [&id](const Book& book) { return book.id == id; });
    if (it != books.end()) {
        Book updatedBook;
        std::cout << "Enter new data: ";
        std::cin >> updatedBook.id >> updatedBook.author >> updatedBook.title >> updatedBook.pages;
        *it = updatedBook;
        writeBooksToFile("library.txt", books);
    }
    else {
        std::cout << "Book with ID " << id << " not found." << std::endl;
    }
}

int main() {
    Library library;
    std::vector<Book> books;
    library.readBooksFromFile("library.txt", books);

    int choice;
    std::string input;
    do {
        std::cout << "Select action:\n"
            << "1. Add a book\n"
            << "2. View all books\n"
            << "3. Delete a book\n"
            << "4. Search for a book\n"
            << "5. Search for books by prefix\n"
            << "6. Edit a book\n"
            << "7. Exit\n"
            << "Select: ";
        std::cin >> input;
        std::istringstream iss(input);
        if (!(iss >> choice)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            return 1;
        }

        switch (choice) {
        case 1:
            library.addBook(books);
            break;
        case 2:
            library.viewBooks(books);
            break;
        case 3: {
            std::string id;
            std::cout << "Enter the book ID to delete: ";
            std::cin >> id;
            library.deleteBook(books, id);
            break;
        }
        case 4: {
            std::string title;
            std::cout << "Enter the title of the book to search: ";
            std::cin >> title;
            library.searchBook(books, title);
            break;
        }
        case 5: {
            std::string prefix;
            std::cout << "Enter the prefix to search: ";
            std::cin >> prefix;
            library.searchBookByPrefix(books, prefix);
            break;
        }
        case 6: {
            std::string id;
            std::cout << "Enter the book ID to edit: ";
            std::cin >> id;
            library.editBook(books, id);
            break;
        }
        case 7:
            std::cout << "Exiting the program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            break;
        }
    } while (choice != 7);

    return 0;
}

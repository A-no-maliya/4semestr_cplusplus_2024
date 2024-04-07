#include <iostream>
#include <sstream>
#include "book_catalog.h"
#include "matrix_operations.h"

int main() {
    std::vector<Book> books;
    std::string booksFilename = "books.txt";
    readBooksFromFile(booksFilename, books);

    std::vector<Matrix> matrices = {
        {{{1, 2, 3}, {4, 5, 6}}},
        {{{7, 8}, {9, 10}, {11, 12}}}
    };
    std::string matricesFilename = "matrices.txt";

    writeMatrixToFile(matricesFilename, matrices);
    std::vector<Matrix> readMatrices = readMatricesFromFile(matricesFilename);
    for (const auto& matrix : readMatrices) {
        std::cout << "\nMatrix:" << std::endl;
        for (const auto& row : matrix.data) {
            for (int value : row) {
                std::cout << value << ' ';
            }
            std::cout << std::endl;
        }
    }

    int choice;
    std::string input;
    do {
        std::cout << "\nMenu:\n"
            << "1. Add a book\n"
            << "2. View all books\n"
            << "3. Delete a book\n"
            << "4. Search for a book\n"
            << "5. Edit a book\n"
            << "6. Exit\n"
            << "Select: ";
        std::cin >> input;
        std::istringstream iss(input);
        if (!(iss >> choice)) {
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }

        switch (choice) {
        case 1:
            addBook(books);
            writeBooksToFile(booksFilename, books);
            break;
        case 2:
            viewBooks(books);
            break;
        case 3: {
            std::string id;
            std::cout << "Enter the book ID to delete: ";
            std::cin >> id;
            deleteBook(books, id);
            writeBooksToFile(booksFilename, books);
            break;
        }
        case 4: {
            std::string title;
            std::cout << "Enter the title of the book to search: ";
            std::cin >> title;
            searchBook(books, title);
            break;
        }
        case 5: {
            std::string id;
            std::cout << "Enter the book ID to edit: ";
            std::cin >> id;
            editBook(books, id);
            writeBooksToFile(booksFilename, books);
            break;
        }
        case 6:
            std::cout << "Exiting the program." << std::endl;
            break;
        default:
            std::cout << "Invalid choice. Try again." << std::endl;
            break;
        }
    } while (choice != 6);

    return 0;
}

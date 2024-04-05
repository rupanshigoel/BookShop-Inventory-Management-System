#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;

/*
 * ABOUT THIS PROGRAM
 * This program manages an inventory system for a bookstore to manage books.
 * The user can add a book via multiple options, store multiple authors for each book, update a book's price or quantity,
 * get information on a specific book, and check the inventory of the entire stock.
 */

/*
 * The Book Class models a book that is held in inventory.
 */
class Book {
public:
    string ID;
    string title;
    string authors [5] = {};
    int numAuthors = 0;
    string genre;
    double price;
    int year;
    int numberAvailable;

    //constructors
    //default constructor
    Book(){
    }

    /* This function is a constructor for Option A of Case 1 of main()
    * Precondition:
    *   A user would like to add a book using its title and author(s) only. These parameters, along with the number of authors are sent to this constructor.
    * Postcondition:
    *   This constructor/function initializes a book with the values given, then assigns an ID for the book, and default values for the rest of the inventory options,
     *   allowing a new book object to be created with said information by the calling function, addBookObjectTitleAuthors().
    */
    Book(string titleInput, string authorsInput[], int numAuthorsInput) {

        title = titleInput;
        numAuthors = numAuthorsInput;
        for (int i = 0; i < numAuthors; i++) {
            authors[i] = authorsInput[i];
        }
        //create Book ID
        ID = title;
        ID.erase((remove(ID.begin(), ID.end(), ' ')), ID.end());
        transform(ID.begin(), ID.end(), ID.begin(), ::tolower);

        //default values for other information held in each book object
        year = -1;
        genre = "not available";
        price = 0.00;
        numberAvailable = 1;
    }

    /* This function is a constructor for Option B of Case 1 of main()
    * Precondition:
    *   A user would like to add a book using its title, author(s), and year only. These title and author(s) are sent as parameters, along with the number of authors are sent to this constructor.
    * Postcondition:
    *   This constructor/function initializes a book with the values given, then assigns an ID for the book, and default values for the rest of the inventory options,
     *   allowing a new book object to be created with said information by the calling function, addBookObjectTitleAuthorsYear().
    */
    Book(string titleInput, string authorsInput[], int numAuthorsInput, int yearInput) {
        title = titleInput;
        numAuthors = numAuthorsInput;
        for (int i = 0; i < numAuthors; i++) {
            authors[i] = authorsInput[i];
        }
        year = yearInput;

        //create Book ID
        ID = title;
        ID.erase((remove(ID.begin(), ID.end(), ' ')), ID.end());
        transform(ID.begin(), ID.end(), ID.begin(), ::tolower);

        //default values for other information held in each book object
        genre = "not available";
        price = 0.00;
        numberAvailable = 1;
    }

    /* This function is a constructor for Option C of Case 1 of main()
    * Precondition:
    *   A user would like to add a book using its title, author(s), year, and genre. These title and author(s) are sent as parameters, along with the number of authors are sent to this constructor.
    * Postcondition:
    *   This constructor/function initializes a book with the values given, then assigns an ID for the book, and default values for the rest of the inventory options,
     *   allowing a new book object to be created with said information by the calling function, addBookObjectTitleAuthorsYearGenre().
    */
    Book(string titleInput, string authorsInput[], int numAuthorsInput, int yearInput, string genreInput) {
        title = titleInput;
        numAuthors = numAuthorsInput;
        for (int i = 0; i < numAuthors; i++) {
            authors[i] = authorsInput[i];
        }
        year = yearInput;
        genre = genreInput;

        //create Book ID
        ID = title;
        ID.erase((remove(ID.begin(), ID.end(), ' ')), ID.end());
        transform(ID.begin(), ID.end(), ID.begin(), ::tolower);

        //default values for other information held in each book object
        price = 0;
        numberAvailable = 1;
    }
    //getters
    string getID() {
        return ID;
    }
    string getTitle() {
        return title;
    }
    string* getAuthors() {
        return authors;
    }
    string getGenre(){
        return genre;
    }
    double getPrice() {
        return price;
    }
    int getYear() {
        return year;
    }
    int getNumberAvailable() {
        return numberAvailable;
    }

    //setters
    void setID(string IDA){
        ID = IDA;
    }
    void setTitle(string titleA) {
        title = titleA;
    }
    void setGenre(string genreA) {
        genre = genreA;
    }
    void setYear(int yearA) {
        year = yearA;
    }
    void setPrice(double priceA) {
        price = priceA;
    }
    void setNumberAvailable(int numberAvailableA) {
        numberAvailable = numberAvailableA;
    }

    /* This function prints member data for one or all books in the inventory, Cases 4 and 5 in main()
    * Precondition:
    *   One or multiple books needs to be printed.
    * Postcondition:
    *   Each book called by printAllInventoryBooks() in the Inventory Class is printed (Case 4) or data for one particular book is printed as called by Case 5 in main()
    */
    void printBook() {
        cout << "ID: " << ID << "\nTitle: " << title << "\nAuthor(s): ";
        for (int i = 0; i < numAuthors; i++){
            cout << "#" << i+1 << ": " << authors[i] << " ";
        }
        cout << "\nYear: " << year << "\nGenre: " << genre << "\nPrice: " << price << "\nNumber Available: " << numberAvailable << endl;
    }
};

/*
 * This Inventory class will manage multiple Book objects to simulate an inventory management system for a bookstore.
 */
class Inventory {

public:
    Book books[100];
    int bookCounter = 0;

    string bookYearString;
    int bookYear;
    string bookGenre;

    //constructors
    //creates the array and sets bookCounter = 0
    Inventory() {
    }

    //create the array and assign first index to this book object
    Inventory(Book bookObject) {
        books[bookCounter] = bookObject;
        bookCounter++;
    }

    /* This function adds new book objects to the array.
    * Precondition:
    *   A user would like to add a book to the Inventory array of objects.
    * Postcondition:
    *   The new book is added and the bookCounter variable is incremented to set the next available index to the next free spot in the books array.
    */
    void addBook(Book newBook) {
        books[bookCounter] = newBook;
        bookCounter++;
    }

    /*This function updates the price of a book that exists in the books array.
    * Precondition:
    *   The index element and new price are sent to the function.
    * Postcondition:
    *   The book at the given index in the books array is updated to the given price via the setPrice() function in the Book Class.
    */
    void updatePrice(int index, double price){
        books[index].setPrice(price);
    }

    /*This function updates the availability/stock count of a book that exists in the books array.
    * Precondition:
    *   The index element and new quantity are sent to the function.
    * Postcondition:
    *   The book at the given index in the books array is updated to the given quantity via the setNumberAvailable() function in the Book Class.
    */
    void updateNumAvailable(int index, int updatedAmount){
        books[index].setNumberAvailable(updatedAmount);
    }

    /* This function creates a book object with the appropriate Book constructor (Case 1, Option A)
    * Precondition:
    *   A user would like to add a book to the inventory with title and author(s) information. These parameters are passed, along with the number of authors.
    * Postcondition:
     * The addBook() function of this class is called and creates a new book object by calling the appropriate constructor to initialize values,
     * adds it to the books array, and updates the books array index. The calling function in Case 1, Option A adds the book object that is created here to the inventory.
    */
    void addBookObjectTitleAuthors(string titleInput, string authorsInput[], int numAuthorsInput){

        //lazy aesthetic fix
        cout << "\n";

        addBook(Book(titleInput,authorsInput,numAuthorsInput));
    }

    /* This function creates a book object with the appropriate Book constructor (Case 1, Option B)
    * Precondition:
    *   A user would like to add a book to the inventory with title, author(s), and year information. The title and author(s) are passed as parameters, along with the number of authors.
    * Postcondition:
    *   The function asks the user for the year of the book and then the addBook() function of this class is called and creates a new book object by calling
     *   the appropriate constructor to initialize values, adds it to the books array, and updates the books array index.
     *   The calling function in Case 1, Option B adds the book object that is created here to the inventory.
    */
    void addBookObjectTitleAuthorsYear(string titleInput, string authorsInput[], int numAuthorsInput){
        //ask user for year book was published and store
        cout << "\nEnter the year the book was published:";
        getline(cin, bookYearString);
        stringstream(bookYearString) >> bookYear;

        addBook(Book(titleInput,authorsInput,numAuthorsInput,bookYear));
    }

    /* This function creates a book object with the appropriate Book constructor (Case 1, Option C)
    * Precondition:
    *   A user would like to add a book to the inventory with title, author(s), year, and genre information. The title and author(s) are passed as parameters, along with the number of authors.
    * Postcondition:
    *   The function asks the user for the year and genre of the book and then the addBook() function of this class is called and creates a new book object by calling the
     *   appropriate constructor to initialize values, adds it to the books array, and updates the books array index.
     *   The calling function in Case 1, Option C adds the book object that is created here to the inventory.
    */
    void addBookObjectTitleAuthorsYearGenre(string titleInput, string authorsInput[], int numAuthorsInput){
        //ask user for year book was published and genre of and store
        cout << "\nEnter the year the book was published:";
        getline(cin, bookYearString);
        stringstream(bookYearString) >> bookYear;
        cout << "Enter the genre of the book:";
        getline(cin, bookGenre);

        //lazy aesthetic fix
        cout << "\n";

        addBook(Book(titleInput,authorsInput,numAuthorsInput,bookYear, bookGenre));
    }

    /* This function searches the inventory for a book by its title and year.
    * Precondition:
    *   A user would like to search for a book and provides its title and year. The title and year of the book are passed as parameters.
    * Postcondition:
    *   The index of the book in the books[] array is returned, or a number outside of the known range is returned to give an error message in the switch statement in main().
    */
    int searchBooks(string title, int year) {
        int index;
        for (int i = 0; i <= bookCounter; i++) {
            if ((books[i].title.compare(title) == 0) && (books[i].year == year)){
                index = i;
                break;
            } else
                index = 199;
            }
        return index;
    }

    /* This function is used in Case 4 of main() to print all of the books contained in the inventory.
    * Precondition:
    *   A user would like view the entire inventory of books.
    * Postcondition:
    *   The function iterates through each index of the books[] array and calls printBook() in the Book Class on each element to perform the actual printing.
    */
    void printAllInventoryBooks(){
        //remind user of option selected
        cout << "\nAll books in inventory:" << endl;

        //send each element of books array to be printed from printBook() in Book Class
        for (int i = 0; i < bookCounter; i++){
            cout << "Book " << i+1 << endl;
            books[i].printBook();
            cout << "\n";
        }
    }
};

/*
 * The main() function will present the user with a menu that loops until the user exits.
 */
int main() {

    //instantiate Inventory object
    Inventory storeInventory;

    //instantiate Book object
    Book newBook;

    string stringChoice;
    int choice;
    do {
        //present the user with the menu of options
        cout << "___________________________________________________________\n";
        printf("%-40s%-40s\n", "Action", "Option No.");
        cout << "-----------------------------------------------------------\n";
        printf("%-40s%-40s\n", "Add a Book to the Inventory", "1");
        printf("%-40s%-40s\n", "Update the price of a Book", "2");
        printf("%-40s%-40s\n", "Update the inventory count of a Book", "3");
        printf("%-40s%-40s\n", "Print all Books currently in Inventory", "4");
        printf("%-40s%-40s\n", "Print the data for a Book", "5");
        printf("%-40s%-40s\n", "Exit Program", "6");
        cout << "----------------------------------------------------------\nEnter your selection here:";

        //read selection from the user and use that selection to call the applicable function
        getline(cin, stringChoice);
        stringstream(stringChoice) >> choice;

        //instantiate variables to use below
        string bookTitle;
        string bookAuthor;
        string bookAuthors[5];
        string numOfAuthorsString;
        int numOfAuthors;
        string bookYearString;
        int bookYear;
        string bookGenre;
        string updatedPriceString;
        double updatedPrice;
        string updatedInventoryAmountString;
        int updatedInventoryAmount;

        //perform option based upon user choice
        switch(choice){
            //Add a book to the inventory
            case 1: {
                //remind user of option selected and present submenu
                cout << "\nAdd a Book to the Inventory. What information do you have about the book?" << endl;
                cout << "----------------------------------------------------------" << endl;
                string Option1;
                cout << "Option 'A' --> Title and author(s).\n" <<
                "Option 'B' --> Title, author(s), and year.\n" <<
                "Option 'C' --> Title, author(s), year, and genre." << endl;
                cout << "----------------------------------------------------------\nEnter your selection here:";
                getline(cin, Option1);

                //allow user to input value without case sensitivity issue
                transform(Option1.begin(), Option1.end(), Option1.begin(), ::toupper);

                //since this is not inside the if statement, user will not know they did not input an incorrect response until after the author(s) are inputted, therefore:
                if ((Option1 == "A") || (Option1 == "B") || (Option1 == "C")) {
                    //get preliminary information for all cases
                    cout << "\nEnter the Title of the Book:";
                    getline(cin, bookTitle);
                    cout << "How many authors does the book have?";
                    getline(cin, numOfAuthorsString);
                    stringstream(numOfAuthorsString) >> numOfAuthors;

                    //create string array with author(s) provided
                    for (int i = 0; i < numOfAuthors; i++) {
                        cout << "Enter author name:";
                        getline(cin, bookAuthor);
                        bookAuthors[i] = bookAuthor;
                    }

                }
                //user has not selected a valid choice
                else if ((Option1 != "A") || (Option1 != "B") || (Option1 != "C")) {
                        //print if user has not selected a valid choice and remind them of options available
                        cout << "Invalid selection. Please input either A, B, or C.\n" << endl;
                        break;
                }

                /* This option allows a user to add a book with title and author(s) only.
                * Precondition:
                *   We have the title, author(s), and number of authors of a book to be added. A user would like to add
                 *  a book to the inventory with title and author(s) information.
                * Postcondition:
                 * Sends user input to function addBookObjectTitleAuthors() in the Inventory Class with the information provided, which calls addBook() in the Inventory Class which then creates a new
                 * book object by calling the appropriate constructor to initialize values, adds it to the books array, and finally updates the books array index.
                 * We then (here) add the book object to the storeInventory array of objects.
                */
                if (Option1 == "A") {

                    //sends user input to addBookObjectTitleAuthors() function in the Inventory Class and stores book object created in storeInventory
                    storeInventory.addBookObjectTitleAuthors(bookTitle, bookAuthors, numOfAuthors);
                }

                    /* This option allows a user to add a book with title, author(s), and year only.
                    * Precondition:
                    *   We have the title, author(s), and number of authors of a book to be added. A user would like to add
                     *  a book to the inventory with title, author(s), and year information.
                    * Postcondition:
                     * Sends user input to function addBookObjectTitleAuthorsYear() in the Inventory Class with the information provided, which calls addBook() in the Inventory Class which then creates a new
                     * book object by calling the appropriate constructor to initialize values, adds it to the books array, and finally updates the books array index.
                     * We then (here) add the book object to the storeInventory array of objects.
                    */
                 else if (Option1 == "B"){
                    //sends user input to addBookObjectTitleAuthorsYear() function in the Inventory Class and stores book object created in storeInventory
                    storeInventory.addBookObjectTitleAuthorsYear(bookTitle, bookAuthors, numOfAuthors);
                }

                    /* This option allows a user to add a book with title, author(s), year, and genre.
                   * Precondition:
                   *   We have the title, author(s), and number of authors of a book to be added. A user would like to add
                    *  a book to the inventory with title, author(s), year, and genre information.
                   * Postcondition:
                    * Sends user input to function addBookObjectTitleAuthorsYearGenre() in the Inventory Class with the information provided, which calls addBook() in the Inventory Class which then creates a new
                    * book object by calling the appropriate constructor to initialize values, adds it to the books array, and finally updates the books array index.
                    * We then (here) add the book object to the storeInventory array of objects.
                   */
                else if (Option1 == "C") {

                    //sends user input to addBookObjectTitleAuthorsYearGenre() function in the Inventory Class and stores book object created in storeInventory
                    storeInventory.addBookObjectTitleAuthorsYearGenre(bookTitle, bookAuthors, numOfAuthors);
                }
                //user has not selected a valid choice
                else {
                    //print if user has not selected a valid choice and remind them of options available
                    cout << "Invalid selection. Please input either A, B, or C.\n" << endl;
                    break;
                }
                break;
            }

/*
 * This option allows a user to update the price of a Book specified by a title and year.
 * Precondition:
 *      We assume we have an array of book objects to update the price of.
 * Postcondition:
 *      The user is asked for the title and year of the book they wish to update the price of. The searchBooks() function of the Inventory Class
 *      is then used to grab the index at which the book exists. We ask the user for the price they would like to update the book to if the index
 *      is found, and if the index is not found we alert them. A book object is created at the appropriate index returned, and then we update the price
 *      of the book via the updatePrice() function in the Inventory Class, which updates the price at the particular index via the setPrice() function in the Book Class.
*/
            case 2: {
                //remind user of option selected
                cout << "\nUpdate the price of a Book specified by a title and year." << endl;

                //get user information to search for index of book to update
                cout << "\nWhat is the title of the book you would like to update?";
                getline(cin, bookTitle);
                cout << "What is the year of the book you would like to update?";
                getline(cin, bookYearString);
                stringstream(bookYearString) >> bookYear;

                //search for index of book to update in Inventory
                int indexToUpdatePrice = storeInventory.searchBooks(bookTitle, bookYear);

                //check if book does not exist and let the user know
                if (indexToUpdatePrice == 199){
                    cout << "\nThat book was not found or the year is not found in the inventory." << endl;
                    break;
                }
                //get new price and update book price at found index
                else {
                    cout << "\nWhat would you like to update the price to?";
                    getline(cin, updatedPriceString);
                    stringstream(updatedPriceString) >> updatedPrice;

                    //update price of selected book
                    Book updateBook = storeInventory.books[indexToUpdatePrice];
                    storeInventory.updatePrice(indexToUpdatePrice, updatedPrice);
                }
                break;
            }

/*
 * This option allows a user to update the number available/stock of a Book specified by a title and year.
 * Precondition:
 *      We assume we have an array of book objects to update the price of.
 * Postcondition:
 *      The user is asked for the title and year of the book they wish to update the quantity of. The searchBooks() function of the Inventory Class
 *      is then used to grab the index at which the book exists. We ask the user for the quantityt they would like to update the book to if the index
 *      is found, and if the index is not found we alert them. A book object is created at the appropriate index returned, and then we update the quantity
 *      of the book via the updateNumAvailable() function in the Inventory Class, which updates the quantity at the particular index via the setNumberAvailable() function in the Book Class.
*/
            case 3: {
                //remind user of option selected
                cout << "\nUpdate the inventory count for a Book specified by title and year." << endl;

                //get user information to search for index of book to update
                cout << "\nWhat is the title of the book you would like to update?";
                getline(cin, bookTitle);
                cout << "What is the year of the book you would like to update?";
                getline(cin, bookYearString);
                stringstream(bookYearString) >> bookYear;

                //search for index of book to update in Inventory
                int indexToUpdateInventory = storeInventory.searchBooks(bookTitle, bookYear);

                //check if book does not exist and let the user know
                if (indexToUpdateInventory == 199){
                    cout << "\nThat book was not found or the year is not found in the inventory." << endl;
                    break;
                }
                //get new quantity and update book quantity at found index
                else {
                    cout << "\nWhat would you like to update the amount available to?";
                    getline(cin, updatedInventoryAmountString);
                    stringstream(updatedInventoryAmountString) >> updatedInventoryAmount;

                    //update quantity of selected book
                    Book updateBook = storeInventory.books[indexToUpdateInventory];
                    storeInventory.updateNumAvailable(indexToUpdateInventory, updatedInventoryAmount);
                }
                break;
            }
/*
 * This option allows a user to print all information about all of the books currently in inventory.
 * Precondition:
 *      We assume we have an array of book objects currently in inventory.
 * Postcondition:
 *      The printAllInventoryBooks() of the Inventory class is called on our inventory object, storeInventory.
 *      This function then calls the printBook() function in the Book Class for each index of the books array and prints the information on each book.
*/
            case 4: {
                //call function in Inventory Class to initiate printing via printBook() in Book Class
                storeInventory.printAllInventoryBooks();
                break;
            }
/*
 * This option allows a user to print all information of a book by searching by title and year of a book.
 * Precondition:
 *      We assume we have an array of book objects to search for the requested book of.
 * Postcondition:
 *      The user is asked for the title and year of the book they wish to view. The searchBooks() function of the Inventory Class
 *      is then used to grab the index at which the book exists. If the index is not found we alert the user.
 *      the printBook() function of the Book Class is called to print the information of the requested book at the returned index of the books array.
*/
            case 5: {
                //remind user of option selected
                cout << "\nData for a particular book." << endl;

                //get input from user to search book inventory
                cout << "\nWhat is the title of the book you would like to view?";
                getline(cin, bookTitle);
                cout << "What is the year of the book you would like to view?";
                getline(cin, bookYearString);
                stringstream(bookYearString) >> bookYear;

                //get index of book to print
                int bookDataIndex = storeInventory.searchBooks(bookTitle, bookYear);

                //check if book does not exist and let user know
                if (bookDataIndex == 199){
                    cout << "\nThat book was not found or the year is not found in the inventory." << endl;
                    break;
                }
                //print selected book using printBook() function in Book Class
                else {
                    cout << "\n";
                    storeInventory.books[bookDataIndex].printBook();
                }
                break;
            }
            //Exit program
            case 6: {
                //let user know they have exited the program
                cout << "Program exited successfully." << endl;
                break;
            }
            default: {
                //print if user has not selected a valid choice and remind them of options available
                cout << "Invalid selection. Please input either 1, 2, 3, 4, 5, or 6.\n" << endl;
            }
        }
    } while (choice != 6);

    return 0;
}



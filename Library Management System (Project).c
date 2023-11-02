#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Structure of the library
struct Book
{
    char title[100];
    char author[100];
    int year;
    float price;
    struct Book* next;
};

// Function to add a new book to the library
struct Book* addBook(struct Book* library, char title[], char author[], int year, float price)
{
    struct Book* newBook = (struct Book*)malloc(sizeof(struct Book));
    if (newBook == NULL)
    {
        printf("Memory allocation failed. Unable to add book.\n");
        return library;
    }

    strcpy(newBook->title, title);
    strcpy(newBook->author, author);
    newBook->year = year;
    newBook->price = price;
    newBook->next = library;

    return newBook;
}

// Function to update the information of an existing book
void updateBook(struct Book* library, char title[], char author[], int year, float price)
{
    while (library != NULL)
    {
        if (strcmp(library->title, title) == 0)
        {
            strcpy(library->author, author);
            library->year = year;
            library->price = price;
            printf("\nBook updated successfully.\n");
            return;
        }
        library = library->next;
    }

    printf("\nBook not found. Update failed.\n");
}

// Function to search for a book by title and display its information
void searchBook(struct Book* library, char title[])
{
    while (library != NULL)
    {
        if (strcmp(library->title, title) == 0)
        {
            printf("------------------\n");
            printf("Title: %s\nAuthor: %s\nYear: %d\nPrice: %.2f\n", library->title, library->author, library->year, library->price);
            printf("------------------\n");
            return;
        }
        library = library->next;
    }

    printf("\nBook not found.\n");
}

// Function to delete a book by title
struct Book* deleteBook(struct Book* library, char title[])
{
    struct Book* current = library;
    struct Book* prev = NULL;

    while (current != NULL)
    {
        if (strcmp(current->title, title) == 0)
        {
            if (prev == NULL)
            {
                library = current->next;
            }
            else
            {
                prev->next = current->next;
            }
            free(current);
            printf("\nBook deleted successfully.\n");
            return library;
        }
        prev = current;
        current = current->next;
    }

    printf("\nBook not found. Delete failed.\n");
    return library;
}

// Function to display the entire library
void displayLibrary(struct Book* library)
{
    int count =1;
    while (library != NULL)
    {
        printf("------------------\n");
        printf("Book: %d\nTitle: %s\nAuthor: %s\nYear: %d\nPrice: %.2f\n",count, library->title, library->author, library->year, library->price);
        printf("------------------\n\n");
        library = library->next;
        count++;
    }
}

// Function to save the library to a file
void saveLibraryToFile(struct Book* library, const char* filename)
{
    FILE* file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("\nUnable to open the file for writing.\n");
        return;
    }

    while (library != NULL)
    {
        fprintf(file, "%s;%s;%d;%.2f\n", library->title, library->author, library->year, library->price);
        library = library->next;
    }

    fclose(file);
}

// Function to load the library from a file
struct Book* loadLibraryFromFile(const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("\nUnable to open the file for reading.\n");
        return NULL;
    }

    struct Book* library = NULL;
    char line[512];

    while (fgets(line, sizeof(line), file) != NULL)
    {
        char title[100], author[100];
        int year;
        float price;

        if (sscanf(line, "%99[^;];%99[^;];%d;%f", title, author, &year, &price) == 4)
        {
            library = addBook(library, title, author, year, price);
        }
    }

    fclose(file);
    return library;
}

// Function to free the memory allocated for the library
void freeLibrary(struct Book* library)
{
    while (library != NULL)
    {
        struct Book* current = library;
        library = library->next;
        free(current);
    }
}

int main()
{
    struct Book* library = NULL;
    char filename[] = "library.txt";
    library = loadLibraryFromFile(filename);

    int choice;
    char title[100], author[100];
    int year;
    float price;

    while (1)
    {
        printf("\n            **************  Library Management System   **************\n");
        printf("\n               **************  Developed By Shakib  **************\n");
        printf("\n\n\n");
        printf("1. Add a new book\n");
        printf("2. Update book information\n");
        printf("3. Search for a book\n");
        printf("4. Delete a book\n");
        printf("5. Display the entire library\n");
        printf("6. Save library to file\n");
        printf("7. Quit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\n");
            printf("Enter book title: ");
            scanf(" %[^\n]s", title);
            printf("Enter author name: ");
            scanf(" %[^\n]s", author);
            printf("Enter release year: ");
            scanf("%d", &year);
            printf("Enter price: ");
            scanf("%f", &price);
            library = addBook(library, title, author, year, price);
            printf("\nBook added successfully.\n");
            break;
        case 2:
            printf("\n");
            printf("Enter the title of the book to update: ");
            scanf(" %[^\n]s", title);
            printf("Enter updated author name: ");
            scanf(" %[^\n]s", author);
            printf("Enter updated release year: ");
            scanf("%d", &year);
            printf("Enter updated price: ");
            scanf("%f", &price);
            updateBook(library, title, author, year, price);
            break;
        case 3:
            printf("\n");
            printf("Enter the title of the book to search: ");
            scanf(" %[^\n]s", title);
            searchBook(library, title);
            break;
        case 4:
            printf("\n");
            printf("Enter the title of the book to delete: ");
            scanf(" %[^\n]s", title);
            library = deleteBook(library, title);
            break;
        case 5:
            displayLibrary(library);
            break;
        case 6:
            saveLibraryToFile(library, filename);
            printf("\nLibrary saved to file.\n");
            break;
        case 7:
            saveLibraryToFile(library, filename);
            freeLibrary(library);
            printf("\nLibrary saved to file and program terminated.\n");
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}


#include<stdio.h>
#include<string.h>

#define LIBRARY_CAPACITY 100

struct Book {
	char title[100];
	char author[100];
	char ISBN[50];
};

struct Book library[LIBRARY_CAPACITY];
int totalBooks = 0;

void loadLibraryData();
void saveLibraryData();
void insertBookRecord();
void removeBookByTitle();
void findBookByTitle();
void listAllBooks();

int main(){
	int choice;
	
	loadLibraryData();
		printf("=============================================\n");
		printf("          MINI LIBRARY MANAGEMENT SYSTEM       \n");
		printf("=============================================\n");
	
	do{
		printf("\n==== Library Menu ====\n");
		printf("1. Insert New Book Record\n");
		printf("2. Remove Book by Title\n");
		printf("3. Find Book by Title\n");
		printf("4. List All Books\n");
		printf("5. Save & Exit Program\n");
		printf("---------------------------\n");
		printf("Enter your choice (1-5): ");
		scanf("%d" , &choice);
		getchar();
		
		switch(choice){
			case 1:
				insertBookRecord();
				break;
			case 2:
				removeBookByTitle();
				break;
			case 3:
				findBookByTitle();
				break;
			case 4:
				listAllBooks();
				break;
			case 5:
				saveLibraryData();
				printf("Exiting... Data Saved\n");
				break;
			default:
				printf("Invalid choice! Try again.\n");
		}
	}while(choice != 5);
	return 0;
}

void insertBookRecord(){
	if(totalBooks < LIBRARY_CAPACITY){
		
	printf("\n--- Add New Book ---\n");
	
	printf("Enter book title: ");
	scanf(" %[^\n]", library[totalBooks].title);
	
	printf("Enter author name: ");
	scanf(" %[^\n]", library[totalBooks].author);
	
	printf("Enter ISBN number: ");
	scanf(" %[^\n]", library[totalBooks].ISBN);
	
	totalBooks++;
	printf("Book added successfully!\n");
	}else{
		printf("\nSorry! The library is full. Cannot add more books.\n");
	}
}

void findBookByTitle(){
	char titleToFind[100];
	int isFound = 0;
	int i;
	
	printf("\nEnter book title to search: ");
	scanf(" %[^\n]", titleToFind);
	
	for(i = 0; i < totalBooks; i++){
		if(strcmp(library[i].title, titleToFind) == 0){
			printf("\nBook Found:\n");
			printf("Title : %s\n", library[i].title);
			printf("Author : %s\n", library[i].author);
			printf("ISBN : %s\n", library[i].ISBN);
			isFound = 1;
			break;
		}
	}
	if(!isFound){
		printf("Book are not found in the library.\n");
	}
}


void removeBookByTitle(){
	char deleteTitle[100];
	int isFound = 0;
	int i, j;
	
	printf("\nEnter book title to delete: ");
	scanf(" %[^\n]", deleteTitle);
	
	for(i = 0; i < totalBooks; i++){
		if(strcmp(library[i].title, deleteTitle) == 0){
			for(j = i; j < totalBooks - 1; j++){
				library[j] = library[j + 1];
			}
			totalBooks--;
			isFound = 1;
			printf("Book deleted successfully!\n");
			break;
		}
	}
	if(!isFound){
		printf("Book not found. Deletion failed.\n");
	}
}

void saveLibraryData() {
    FILE *file = fopen("library_data.txt", "w");
    int i;
    if (file == NULL) {
        printf("? Error saving data!\n");
        return;
    }

    for (i = 0; i < totalBooks; i++) {
        fprintf(file, "%s\n%s\n%s\n", library[i].title, library[i].author, library[i].ISBN);
    }

    fclose(file);
}

void loadLibraryData() {
    FILE *file = fopen("library_data.txt", "r");
    if (file == NULL) {
        return;
    }

    while (fgets(library[totalBooks].title, sizeof(library[totalBooks].title), file)) {
        library[totalBooks].title[strcspn(library[totalBooks].title, "\n")] = '\0';

        fgets(library[totalBooks].author, sizeof(library[totalBooks].author), file);
        library[totalBooks].author[strcspn(library[totalBooks].author, "\n")] = '\0';

        fgets(library[totalBooks].ISBN, sizeof(library[totalBooks].ISBN), file);
        library[totalBooks].ISBN[strcspn(library[totalBooks].ISBN, "\n")] = '\0';

        totalBooks++;
    }

    fclose(file);
}

void listAllBooks(){
	int i;
	if(totalBooks == 0){
		printf("\nThe Library is currently empty. Please add some books first.\n");
	}else{
		printf("\n Listing All Books in the Library:\n");
		printf("=============================================\n");
		
		for(i = 0; i < totalBooks; i++){
			printf("\nBook %d:\n" , i + 1);
			printf("Title: %s\n" , library[i].title);
			printf("Author: %s\n" , library[i].author);
			printf("ISBN: %s\n" , library[i].ISBN);
		}
		printf("=============================================\n");
		printf("Total Books in Library: %d\n" , totalBooks);
	}
}

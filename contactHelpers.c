/* -------------------------------
 Name: Muntaqa Maahi
 Student Number: 164356180
 Email: mmaahi@myseneca.ca
 Section: SJJ
 Date:2/2/19
 ----------------------------------
 Assignment: 2
 Milestone:  4
 ---------------------------------- */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>

// This source file needs to "know about" the SYSTEM string library functions.
// HINT: The library name is string.h.
//       #include the string.h header file on the next line:
#include <string.h>

// -------------------------------
// Include your contactHelpers header file on the next line:

#include "contactHelpers.h"

// -------------------------------
// define MAXCONTACTS for sizing contacts array (5):
#define MAXCONTACTS 5

//--------------------------------
// Function Definitions
//--------------------------------

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        function definitions below...            |
// +-------------------------------------------------+

// clearKeyboard

void clearKeyboard(void)
{
    while (getchar() != '\n')   ; // empty execution code block on purpose
}

// pause:
void Pause(void)
{
    
    printf("(Press Enter to Continue)");
    printf("\n");
    clearKeyboard();
}

// getInt:

int getInt(void)
{
    char nL;
    int value;
    scanf("%d%c", &value, &nL);
    if (nL != '\n')
    {
        clearKeyboard();
    }
    
    while (nL != '\n'){
        printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        scanf("%d%c", &value, &nL);
        
        if (nL != '\n')
        {
            clearKeyboard();
        }
    };
    
    
    return value;
}

// getIntInRange:
int getIntInRange(int min, int max)
{
    int intInRange;
    do {
        intInRange = getInt();
        if (intInRange > max || intInRange < min) {
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ",min,max);
        }
    } while (intInRange > max || intInRange < min);
    return intInRange;
}


// yes:
int yes(void)
{
    char yn;
    char nl;
    scanf("%c%c",&yn,&nl);
    if (nl!='\n')
    {
        clearKeyboard();
    }
    
    while((yn != 'Y' && yn != 'y' && yn != 'N' && yn != 'n') || (nl != '\n')){
        printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
        scanf("%c%c", &yn, &nl);
        if (nl != '\n')
        {
            clearKeyboard();
        }
    }
    if (yn == 'Y' || yn == 'y') return 1;
    else return 0;
}

// menu:
int menu(void)
{
    int menu;
 
    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n");
    printf("\n");
    printf("Select an option:> ");
    do {
        menu = getInt();
        if (menu > 6 || menu < 0) {
            printf("*** OUT OF RANGE *** <Enter a number between 0 and 6>: ");
        }
    } while (menu > 6 || menu < 0);
    return menu;
}

// contactManagerSystem:
void contactManagerSystem(void)
{
    struct Contact contacts[MAXCONTACTS] =
    { { { "Rick",{ '\0' }, "Grimes" },
        { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
        { "4161112222", "4162223333", "4163334444" } },
        {
            { "Maggie", "R.", "Greene" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9051112222", "9052223333", "9053334444" } },
        {
            { "Morgan", "A.", "Jones" },
            { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
            { "7051112222", "7052223333", "7053334444" } },
        {
            { "Sasha",{ '\0' }, "Williams" },
            { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
            { "9052223333", "9052223333", "9054445555" } },
    };
    int selection;
    int yn = 0;
    while (yn == 0) {
        selection = menu();
        switch (selection)
        {
            case 1:
                displayContacts(contacts, MAXCONTACTS);
                Pause();
                break;
            case 2:
                addContact(contacts, MAXCONTACTS);
                Pause();
                break;
            case 3:
                updateContact(contacts, MAXCONTACTS);
                Pause();
                break;
            case 4:
                deleteContact(contacts, MAXCONTACTS);
                Pause();
                break;
            case 5:
                searchContacts(contacts, MAXCONTACTS);
                Pause();
                break;
            case 6:
                sortContacts(contacts, MAXCONTACTS);
                Pause();
                break;
            case 0:
                printf("\nExit the program? (Y)es/(N)o: ");
                yn = yes();
                printf("\n");
                if (yn)printf("Contact Management System: terminated\n");
                break;
            default:
                break;
        }
    }
}



// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        empty function definitions below...      |
// +-------------------------------------------------+

// getTenDigitPhone:


void getTenDigitPhone(char phoneNum[11])
{
    int i;
    int needInput = 1;
    int length=0;
    
    while (needInput == 1) {
        scanf("%10s", phoneNum);
        clearKeyboard();
        
        length = strlen(phoneNum);
        for ( i=0;i<length; i++){
            if (!isdigit(phoneNum[i])){
                
                needInput=1;
                length--;
            }
            
        }
        // (String Length Function: validate entry of 10 characters)
        if (length == 10)
            needInput = 0;
        
        else{
            needInput=1;
            printf("Enter a 10-digit phone number: ");
        }
        
    }
  
    
}


// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]){
    //looping through contacts to find number that matches, then returning index
    int i;
    for (i = 0; i < size; i++)
    {
        if (strcmp(contacts[i].numbers.cell,cellNum)==0) {
            return i;
        }
    }
    return -1;
}

// displayContactHeader
void displayContactHeader(void){
    
    printf("\n");
    printf("+-----------------------------------------------------------------------------+\n");
    printf("|                              Contacts Listing                               |\n");
    printf("+-----------------------------------------------------------------------------+\n");
    
    
}

// displayContactFooter
void displayContactFooter(int count){
    printf("+-----------------------------------------------------------------------------+\n");
    printf("Total contacts: %d\n", count);
    printf("\n");
}

// displayContact:
void displayContact(const struct Contact *contact){
    printf(" %s", contact->name.firstName);
    if(strlen(contact->name.middleInitial)!=0) {
        printf(" %s", contact->name.middleInitial);
    }
    printf(" %s\n", contact->name.lastName);
    printf("    C: %-10s   H: %-10s   B: %-10s\n", contact->numbers.cell, contact->numbers.home, contact->numbers.business);
    printf("       %d %s, ",contact->address.streetNumber, contact->address.street);
    if(contact->address.apartmentNumber>0) printf("Apt# %d, ", contact->address.apartmentNumber);
    printf("%s, %s\n", contact->address.city, contact->address.postalCode);
}


// displayContacts:

void displayContacts(const struct Contact contacts[], int size){
    int i;
    int count=0;
    displayContactHeader();
    for (i = 0; i < size; i++)
    {
        if (strlen(contacts[i].numbers.cell) != 0)
        {
            displayContact(&contacts[i]);
            count++;
        }
    }
    displayContactFooter(count);
}
// searchContacts:
void searchContacts(const struct Contact contacts[], int size){
    char cellnumb[11];
    int foundIndex;
    printf("\nEnter the cell number for the contact: ");
    getTenDigitPhone(cellnumb);
    foundIndex = findContactIndex(contacts, sizeof(contacts), cellnumb);
    if (foundIndex == -1) {
        printf("*** Contact NOT FOUND ***\n");
        printf("\n");
    }
    else {
        printf("\n");
        displayContact(&contacts[foundIndex]);
        printf("\n");
    }
    
}

// addContact:
void addContact(struct Contact contacts[], int size){
    int i;
    for (i = 0; i < size; i++)
    {
        if (strlen(contacts[i].numbers.cell) == 0) {
            break;
        }
    }
    if (i == size) printf("\n*** ERROR: The contact list is full! ***\n\n");
    
     else {
        printf("\n");
        getContact(&contacts[i]);
        printf("--- New contact added! ---\n");
        printf("\n");
    }
}


// updateContact:
void updateContact(struct Contact contacts[], int size){
    char phoneNumb[11];
    int foundIndex;
    int yn;
    printf("\nEnter the cell number for the contact: ");
    getTenDigitPhone(phoneNumb);
    foundIndex = findContactIndex(contacts, sizeof(contacts), phoneNumb);
    if (foundIndex == -1) printf("*** Contact NOT FOUND ***\n\n");
    else {
        printf("\nContact found:\n");
        displayContact(&contacts[foundIndex]);
        printf("\n");
        printf("Do you want to update the name? (y or n): ");
        yn = yes();
        if (yn == 1) getName(&contacts[foundIndex].name);
        printf("Do you want to update the address? (y or n): ");
        yn = yes();
        if (yn == 1) getAddress(&contacts[foundIndex].address);
        printf("Do you want to update the numbers? (y or n): ");
        yn = yes();
        if (yn == 1) getNumbers(&contacts[foundIndex].numbers);
        printf("--- Contact Updated! ---\n");
        printf("\n");
    }
}

// deleteContact:

void deleteContact(struct Contact contacts[], int size){
    char phoneNumb[11];
    int foundIndex;
    int yn;
    printf("\nEnter the cell number for the contact: ");
    getTenDigitPhone(phoneNumb);
    foundIndex = findContactIndex(contacts, sizeof(contacts), phoneNumb);
    if (foundIndex == -1) printf("*** Contact NOT FOUND ***\n\n");
    else {
        printf("\nContact found:\n");
        displayContact(&contacts[foundIndex]);
        printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");
        yn = yes();
        if (yn == 1)
        {
            contacts[foundIndex].numbers.business[0] = '\0';
            contacts[foundIndex].numbers.cell[0] = '\0';
            contacts[foundIndex].numbers.home[0] = '\0';
            printf("--- Contact deleted! ---\n");
           
        }
         printf("\n");
    }
}
// sortContacts:
void sortContacts(struct Contact contacts[], int size){
    int i;
    int j;
    struct Contact temp;
    for (i = 0; i < size-1; i++)
    {
        for (j = i+1; j  < size; j ++)
        {
            if (strlen(contacts[i].numbers.cell) != 0 && strlen(contacts[j].numbers.cell) != 0) {
                if (strcmp(contacts[i].numbers.cell, contacts[j].numbers.cell) > 0) {
                    temp = contacts[i];
                    contacts[i] = contacts[j];
                    contacts[j] = temp;
                }
            }
        }
    }
    printf("\n--- Contacts sorted! ---\n\n");
}

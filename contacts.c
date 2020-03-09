/* -------------------------------------------
 Name: Muntaqa Maahi
 Student number:164356180
 Email:mmaahi@myseneca.ca
 Section:SJJ
 Date:6/21/19
 ----------------------------------------------
 Assignment: 1
 Milestone:  4
 ---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


// This source file needs to "know about" the structures you declared
// in the header file before referring to those new types:
// HINT: put the header file name in double quotes so the compiler knows
//       to look for it in the same directory/folder as this source file
// #include your contacts header file on the next line:

#include "contacts.h"

// Declare variables here:

struct Name name = {{'\0'}};
struct Address Addr= {0,{'\0'}};
struct Numbers num={{'\0'}};
char c = '0';

// Get and store from standard input the values for Name
// Put your code here that defines the Contact getName function:
void getName(struct Name *name) {
    
    printf("Please enter the contact's first name: ");
    scanf(" %[^\n]", name->firstName);
    
    printf("Do you want to enter a middle initial(s)? (y or n): ");
    scanf(" %c", &c);
    
    if (c == 'y') {
        printf("Please enter the contact's middle initial(s): ");
        scanf(" %[^\n]", name->middleInitial);
    }
    
    
    printf("Please enter the contact's last name: ");
    scanf(" %[^\n]", (*name).lastName);
    
}



// Get and store from standard input the values for Address
// Put your code here that defines the Contact getAddress function:
void getAddress(struct Address *addr) {
    printf("Please enter the contact's street number: ");
    scanf(" %u", &addr -> streetNumber);
    
    
    printf("Please enter the contact's street name: ");
    scanf(" %[^\n]", addr->street);
    
    
    printf("Do you want to enter an apartment number? (y or n): ");
    scanf(" %c", &c);
    if (c != 'n') {
        printf("Please enter the contact's apartment number: ");
        scanf(" %u", &addr->apartmentNumber);
        
    }
    
    printf("Please enter the contact's postal code: ");
    scanf(" %[^\n]", addr -> postalCode);
    
    printf("Please enter the contact's city: ");
    scanf(" %[^\n]", addr -> city);
    
}


// Get and store from standard input the values for Numbers
// Put your code here that defines the Contact getNumbers function:

void getNumbers(struct Numbers *num) {
    printf("Do you want to enter a cell phone number? (y or n): ");
    scanf(" %c", &c);
    if (c != 'n') {
        printf("Please enter the contact's cell phone number: ");
        scanf(" %[^\n]", num -> cell);
        
    }
    
    printf("Do you want to enter a home phone number? (y or n): ");
    scanf(" %c", &c);
    if (c != 'n') {
        printf("Please enter the contact's home phone number: ");
        scanf(" %[^\n]", num -> home);
        
    }
    
    printf("Do you want to enter a business phone number? (y or n): ");
    scanf(" %c", &c);
    if (c != 'n') {
        printf("Please enter the contact's business phone number: ");
        scanf(" %[^\n]", num -> business);
        
    }
}




//void getContact(struct Contact* uContact)
//{
//    // Calls the Contact function getName to store the values for Name
//    getName(&uContact->name);
//    // Calls the Contact function getAddress to store the values for the Address
//    getAddress(&uContact->address);
//    // Call the Contact function getNumbers to store the values for the Numbers member
//    getNumbers(&uContact->numbers);
//
//    }

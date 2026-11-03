Contact List (C++ / OOP)
A console-based contact management program written in C++ that demonstrates core Object-Oriented Programming concepts and dynamic memory management.
Features
• Create any number of contacts at runtime.
• Each contact stores a unique ID and a name.
• Each contact can have multiple phone numbers, emails, and addresses.
• Every phone number, email, and address has its own type (e.g. Home, Work) and description.
• Displays all stored contacts in a clean, readable format.
OOP Concepts Used
• Encapsulation: all data members are private and accessed through getters and setters.
• Classes and objects: Phone, Emails, Addresses, User, and Contact.
• Composition: a User owns arrays of Phone, Emails, and Addresses; a Contact owns an array of User pointers.
• Constructors and destructors: default values are set in constructors, and destructors free all dynamically allocated memory.
• Dynamic memory allocation: new / delete[] are used for arrays and pointers, with no memory leaks in normal use.
Class Overview
Class
Responsibility
Phone
Stores a phone number, its type, and description
Emails
Stores an email address, its type, and description
Addresses
Stores an address, its type, and description
User
Holds a person's ID, name, and their phones, emails, and addresses
Contact
Manages the full collection of users and displays them
How to Build and Run
Requirements: any C++ compiler that supports C++11 or later (g++, clang, or Visual Studio).
g++ main.cpp -o contact_list
./contact_list
Example Usage
Enter Number Of Contact You Want To Have : 1
Enter The How Many Phone Number The User 1 Have : 1
Enter The How Many Email The User 1 Have : 1
Enter The How Many Addresses The User 1 Have : 1
Enter The ID -> 1
Enter The Name -> Ahmed
...
Known Limitations and Future Improvements
• Input uses cin >>, so values containing spaces are not supported yet. Switching to getline would fix this.
• No copy constructor or assignment operator for User (Rule of Three).
• Data is not saved to a file between runs; adding file storage is a planned improvement.
• Add search, edit, and delete contact features with a menu.
Author
Karim Attya, Faculty of Computers and Information, Zagazig University (AI Program).

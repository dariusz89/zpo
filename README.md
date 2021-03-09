# Usage of object-oriented programming
Project to pass the course: usage of object oriented programming

## Application subject
**Database**
*(entering, displaying, editing, deleting, searching, sorting data, any database content - e.g. personal data)*
A database application is a data processing program. The program database is in a file with the *.stefan* extension.

## Build and run
In order to compile the program, use any tools that enable the compilation of programs written in C++.
It is required that the compiler supports the *ISO C++17 standard*, and that during the compilation additional libraries for the linker concerning the filesystem support are included, in other words compiling using the argument: *-lstdc++fs*.

__Windows__

In Visual Studio, take the following steps to compile and run the program.
1. Create a project:
    * File -> New Project
    * Empty project -> Empty project -> next -> ...
2. Adding header files:
    * Solution Explorer:
    * right click (rmb) on Source files -> Add - Class
    * Class name: Address
    * Other options: select inline
    * OK, and then copy the contents of the Address.h file to the file with the newly created class
    * Repeat step 2 for all *.h files
3. Adding source files:
    * Solution Explorer:
    * right click (rmb) on Source files -> Add - New item
    * C++ file
    * Name: DB.cpp
    * Add and copy the contents of the DB.cpp file to it from the directory with the program code
4. Project configuration - C++17 support
    * Solution Explorer:
    * right click (rmb) on ProjectName -> Properties
    * Configuration Properties -> General
    * Change the C++ Language Standard to: Standard ISO C++17 (/std:c++17)
    * OK.
    * Now you can build and run the program (choose x86 architecture). 

__Linux__

**~/projects/db$ g++ --version**
>g++ (Debian 8.3.0-6) 8.3.0 
>Copyright (C) 2018 Free Software Foundation, Inc. 
>This is free software; see the source for copying conditions. There is NO warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. 

In order to compile and run the program, upload all files to a directory of your choice.
The directory I have chosen is: __~/projects/db__.

I create 3 subdirectories in the indicated directory:
  * __build__ - it will contain the program's executable file
  * __database__ - where I store the database
  * __src__ - directory with the source code of the program.

I compile and run with the following command:

**g++ src/DB.cpp -std=c++17 -lstdc++fs -o build/DB.o && ./build/DB.o database/db.stefan**

There are two ways to run a program, with or without an additional argument, such as is the path with the location of the database file. 
In the case where the path of the database file data is not specified by the user, the program will accept it as default the database path from which the program was started. 
That is, if there is our first contact with this program, all it takes is to start in it the job is to just run it.
However, if the user enters more than one an additional argument, the program will terminate immediately.

## Database structure
The database consists of three tables: Client, Company, Addresses.
* __Table structure: *Client*:__
  * int idClient
  * string firstName
  * string lastName
  * string email
  * bool gender
  * bool softDel
  * int companyId
  * int addressId
* __Table structure: *Company*:__
  * int idCompany
  * string name
  * string nip
  * string regon
  * string krs
  * bool deletedFromREGON
  * bool softDel
  * int addressId
* __Table structure: *Addresses*:__
  * int idAddress
  * string country
  * string state
  * string county
  * string community
  * string town
  * string street
  * string propertyNo
  * string apartmentNo
  * string postCode
  * string postalTown
  * bool softDel

## Summary
Even though the program works and does exactly what is expected of it, it is clear that it could have been written much better.

This library is for the creation and interaction with a family tree.  All of the interactions are through the
terminal emulator.  You begin by adding in relatives, as many as you like.  At first they are completely disconected,
but you can edit each individual "profile" and add all the connections offered.  Once the relatives start to get connected and more information is filled into each, you can start printing the individual profiles or all of the names.

INSTRUCTIONS:
This program runs out of the box.  When you start it up the main.cpp should explain itself pretty well.  There are a few details that are important:

Profiles are capital sensitive, so be careful when searching/querying.
When entering birthdays, the months need to be in integer form (maybe that is a fork add-on you could do?), so 1-12.

DEPENDENCIES:
This project runs off of all standard libraries, so no need to mess with any package installations or linkers! Woot!

Here are all of the #include statements I used:

#include <vector>
#include <string>
#include <iostream>
#include <stdlib.h> (for atoi())

SYSTEM REQUIREMENTS:
I created the whole thing on the CU VM, so as long as you are running the code from there it will work.  I haven't tested on any other platform.

GROUP MEMBERS:
Just me, Darwin Wood

CONTRIBUTORS:
Just me said the bee.

OPEN ISSUES/BUGS
Well, a few issues might be that I have 0 control (outside of data types) on the user inputs!  So someone could have been born on 10000231/123131/6845243 and the program would take it.  Also, my function showChronologically() does not in fact print chronologically.  I started on that but left it due to a lack of time.  That would be a good add-on, it's very similar to the hash table alphabetization (is that a word?)  in the last homework assignment.







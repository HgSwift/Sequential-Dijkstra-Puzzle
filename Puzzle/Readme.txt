In order to run in the way it was tested:
Run the USF VPN, access one of the machines in the C4 lab, upload EightPuzz.cpp, EightPuzz.hpp, puzz.cpp, and Unsolved.txt to the C4 machine
navigate to the diectory that they were stored in using cd /home/c/(the directory)
compile with 
g++ -std=c++17 -Wall *.cpp 
and run with
.a./out
Alternatively try running it on visual studio it worked on my computer but our configuration settings could be different.

The unsoved puzzle is to be stored in Unsolved.txt and stored in the same directory as the other three files.
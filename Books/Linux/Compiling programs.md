Chapter 23 Compiling Programs

While compiling, need linking. 
Why?
* many programs involves performing the same actions, linking links program to reusable routines in libraries 

* header files (*.h): descriptions of routines included in a source code file or library 

What is configure use for?
* to analyse the build environment, make adjustments to accommodate to different unix systems

# Why need ./ and not just configure?
* the current dir is not automatically searched so need be specific 


3 steps to install:
1. ./configure: generates Makefile
2. make Makefile: convert source code into binaries 
3. sudo install make: copies binaries into local system directories



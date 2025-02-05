Last Updated: 2/5/2025
____====PROGRAM BUILD====______________________________________________________________
Everything was navigated and tested with WSL ubuntu.
Scripts are in bash.
The bash scripts thusfar are used for development.
To make "buttons" that most IDE's have.

Program is in C++.
I used clang as the C++ compiler.
I use git on the console, and push to a remote repository called MathBuffsDB 
on github.

____=====Main Directory Files=====_____________________________________________________
____****GIT****________________________________________________________________________
/desktop.ini
This is a git preferences folder that popped up when I was messing 
with the settings that one time.

/.git 
This is the git folder, it allows me to save and track stages to a repository.
Github included.

____****MathBuffDB-Source****__________________________________________________________
/src
contains all the cpp files and main, aka the source files.

/include
contains all header files for my source files.

/build
Contains the executable a.out for the program once compiled.

/lib
Is currently empty cause I have no precompiled libraries to work with at the moment.

____**** Scripts & Organization ****_____________________________________________________
/README
Oh hi, looks like you made it.
This is where I'll be organizing the Program stuff.

/run [This is a Bash Script]
This is a .sh file that contains a bash script that I use the windows subsystem
for linux with in order to more readily test the program using the command line 
via the clang compiler.

/save [This is a Bash Script]
This is a file that I spent 2 hours figuring out that the line ending encoding for 
windows and unix somehow differ for whatever reason.
It caused problems until I figured I change a few settings in notepads and create a 
new file from within notepads.
I was able to get the unix line ending down, which is compatible with bash.

____==== Main Source & Header Composition ====___________________________________________
#Check .h and .cpp, these /files are an abstraction.

/Test
This is just a experimental setup section That I'm saving for learning purposes. 

/TextPort
This is a text File interface being developed for C++.
Plan is to make using and reading text files a piece of cake and as straight forward
as possible.

____====MISC====_________________________________________________________________________
Refference for me to get a fast WSL start:
cd /mnt
cd c
cd Users/Lucas/documents/AProjects/Prog/MathBuffDB

# CMD_TaskManagerForWindows

A command line-based task manager for Windows users. It can be run from any
terminal application you'd like: the Command Prompt(CMD), Git Bash, Windows Terminal etc.
It is not as powerful as the main Task Manager, but it can be as useful. You can see every
process, get a certain process's ID and terminate it if you'd like. It is much faster to
run this if you just wish to kill a misbehaving program.

The application has been built using the Windows API, therefore it cannot be used on GNU/Linux, MacOS
or any other operating system. I might make a Linux port for it in the future, but for now, it is 
Windows only.

There are precompiled binaries in the "bin" folder, although if you're planning to use them, it is
recommended that you first run them through an antivirus program to make sure that they are not 
harmful to your computer. You should NEVER run executables/dlls that you've downloaded from the internet
before scanning them first.

The task manager itself is "tman.exe", the two dynamic libraries(dlls): iofuncs.dll and proc.dll, can be
used in your own project if you'd like to use the functions I've written. They can pretty much be used
in every C project on Windows(although you should link them to your project using the GNU(MinGW) Linker)
and also on C++ projects(The MinGW Linker should still be used).

If you wish to compile the binaries yourself, you need to have:<br/>
    - The MinGW(GCC) x64 compiler<br/>
    - Make<br/>

Or you could use an IDE(i.e. Code::Blocks) to compile it, although I personally advise you
to use the Makefile I've created.

If you're going for the first approach(MinGW + Make) then you should also:<br/>
    - Add the "bin" MinGW folder to the "PATH" environment variable<br/>
    - If you don't have Make, you can download it from this link(http://gnuwin32.sourceforge.net/packages/make.htm)<br/>
    - Once you've downloaded it, you should move/copy the ZIP archive's contents to MinGW's "bin" folder<br/>
    - Once that's done, you can open Git, CMD or any terminal for that matter, go to the directory where you<br/>
    cloned/downloaded the repository and run "make all" if you want to compile all three binaries or you can<br/>
    run "make <*the name of the binary you want*>.exe/dll" to get a specific executable/dll.<br/>
    - It is recommended that you do this through Git Bash, as the Makefile has been made around it, if you want<br/>
    to use the CMD you have to change the "rm" command to "del" and the forward slashes("//") to backslashes("\\\\").<br/>

You can use the resources in this repository for whatever purpose you want. Any published projects, derived
from this project, should also be licensed under the GNU GPL v3.0. For more information about the license,
see LICENSE. 
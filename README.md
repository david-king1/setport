##This document explains the use of the setport program

\*Ports must be an int between 0 and 65k, non-inclusive

There are two main ways to set a port using this program.  
1)To set a specific port from the command line, type:  
./setport [-p or --port] \[number]  
2)To set a port from an environment variable type:  
./setport [-p or --port] -e [VARIABLE NAME]*

*Note: If no variable name is given, program will look for default  
value found under PORT.  

In addition to the "-p" or "--port" flag, these flags may be useful:  
-h, --help, -?      See the usage screen  
-v, --version       See the version number

##This document explains the use of the setport program

#Note to reviewer:#

  Unfortunately this program is incomplete but I hope that you will take a look at what I have.
  Testing has not been implemented.  Right now the language is hard-coded to English.

There are two main ways to set a port using this program.  
1)To set a specific port from the command line, type:  
`./setport [-p or --port] \[number]`  
2)To set a port from an environment variable type:  
`./setport [-p or --port] -e [VARIABLE NAME]*`

**Ports must be an int between 0 and 65k, non-inclusive**

\*Note: If no variable name is given, program will look for default  
value found under PORT.  

In addition to the "-p" or "--port" flag, these flags may be useful:  
-h, --help, -?      See the usage screen  
-v, --version       See the version number

#include <stdio.h>

int main(int argc, char *argv[]) {

  puts("Hello world.");
  puts("I'm buddhamagnet.");
  puts("This is C.");
  puts("Say hello to each other.");
  puts("This is the start of a beautiful friendship.");
  puts("A romance, even.");
  fputs("Who knows where it will end.\n", stdout);

  return 0;
}

/*

NOTES:

1. During this build the stdio header is ommitted, which generates an implict function
   warning. When C doesn't find a declaration, it assumes this implicit declaration: int f()
   which means the function can receive anything and return an integer. In many cases this will
   be acceptable (as in the case of printf above) but in others (e.g. the function actually 
   returns something other than an integer) it may cause issues. Recompiling this program with
   -Werror causes this to be an actual error rather than a warning.

EXTRA CREDIT:

1. Open the ex1 file in your text editor and change or delete random parts. 
   Try running it and see what happens.

   Working on this part of the file:

   cffa edfe 0700 0001 0300 0080 0200 0000
   1000 0000 6005 0000 8500 2000 0000 0000

   The following problems were created:

   cffa: exec format error
   edfe: exec format error
   0700: bad CPU type in executable
   0001: bad CPU type in executable
   0300: no discernible impact
   0080: no discernible impact
   0200: bad executable or shared library
   0000: bad executable or shared library
   1000: malformed Mach-o file
   0000: malformed Mach-o file
   6005: command line hangs
   0000: malfirmed Mach-o file
   8500: no discernible impact
   2000: no discernible impact
   0000: no discernible impact
   0000: no discernible impact

   Running otool -h on the file gives the following output:

   magic 0xfeedfacf
   cputype 16777223
   cpusubtype 3
   caps 0x80
   filetype 2
   ncmds 16
   sizeofcmds 1376
   flags 0x00200085

2. Print out 5 more lines of text or something more complex than hello world.

Included above.

3. Run man 3 puts and read about this function and many others.

Function signature: puts(const char *s).

This function writes the string s, plus a terminating newline character, to stdout.

A related function is fputs:

Function signature: fputs(const char *restrict s, FILE *restrict stream).

This function writes the string s to the stream pointed to by stream. I have included
an example in this program.

Both of these functions return a positive integer on success and EOF on failure.

They both print (null) if the string argument is NULL.

*/

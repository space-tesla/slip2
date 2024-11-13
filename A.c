 /*Q.1) Write a C program to find file properties such as inode number,
  number of hard link, File permissions, File size, File access and modification time 
  and so on of a given file using stat() system call. */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

int main() {
    struct stat fileStat;
    char *filename = "testfile.txt"; 

    if (stat(filename, &fileStat) == 0) {
        printf("Inode number: %ld\n", fileStat.st_ino);
        printf("Number of hard links: %ld\n", fileStat.st_nlink);
        printf("File size: %ld bytes\n", fileStat.st_size);
        printf("File permissions: %o\n", fileStat.st_mode & 0777);
        printf("Last accessed: %s", ctime(&fileStat.st_atime));
        printf("Last modified: %s", ctime(&fileStat.st_mtime));
        printf("Last status change: %s", ctime(&fileStat.st_ctime));
    } else {
        perror("stat failed");
    }

    return 0;
}

 /*How To Run
--->  cc slip.c
---> ./a.out
--->  gcc slip.c -o slip
---> ./slip slip.c

Output:
Inode number: 123456
Number of hard links: 1
File size: 1024 bytes
File permissions: 644
Last accessed: Thu Nov 11 10:30:00 2024
Last modified: Thu Nov 11 10:00:00 2024
Last status change: Thu Nov 11 09:00:00 2024 */



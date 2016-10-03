#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(int argc, char *argv[])
       {
           struct stat sb;

           if (argc != 2) 
	   {
               cout<<"Incomplete parameters!!!...";
               exit(EXIT_FAILURE);
           }

           if (stat(argv[1], &sb) == -1) 
	   {
               cout<<"Error!...";
               exit(EXIT_FAILURE);
           }

           cout<<"File type:                ";

           switch (sb.st_mode & S_IFMT) 
	   {
           case S_IFBLK:  cout<<"block device\n";            break;
           case S_IFCHR:  cout<<"character device\n";        break;
           case S_IFDIR:  cout<<"directory\n";               break;
           case S_IFIFO:  cout<<"FIFO/pipe\n";               break;
           case S_IFLNK:  cout<<"symlink\n";                 break;
           case S_IFREG:  cout<<"regular file\n";            break;
           case S_IFSOCK: cout<<"socket\n";                  break;
           default:       cout<<"unknown?\n";                break;
           }

	cout<<"File Permissions: \t";
	cout<< ((S_ISDIR(sb.st_mode)) ? "d" : "-");
	cout<< ((sb.st_mode & S_IRUSR) ? "r" : "-");
    	cout<< ((sb.st_mode & S_IWUSR) ? "w" : "-");
    	cout<< ((sb.st_mode & S_IXUSR) ? "x" : "-");
    	cout<< ((sb.st_mode & S_IRGRP) ? "r" : "-");
    	cout<< ((sb.st_mode & S_IWGRP) ? "w" : "-");
    	cout<< ((sb.st_mode & S_IXGRP) ? "x" : "-");
    	cout<< ((sb.st_mode & S_IROTH) ? "r" : "-");
    	cout<< ((sb.st_mode & S_IWOTH) ? "w" : "-");
    	cout<< ((sb.st_mode & S_IXOTH) ? "x" : "-");

           cout<<"\nI-node number:            "<<sb.st_ino;
	   cout<<"\nDevice : 		  "<<(long)sb.st_dev<<;
           cout<<"Link count:               "<<(long) sb.st_nlink<<;
           cout<<"Ownership:                UID=   	"<<(long) sb.st_uid<<"		GID=	"<< (long) sb.st_gid<<"\n";
           cout<<"Preferred I/O block size: "<<(long) sb.st_blksize<<"bytes\n";
           cout<<"File size:                "<<(long long) sb.st_size<<"bytes\n";
           cout<<"Blocks allocated:         "<<(long long) sb.st_blocks<<"\n";
           cout<<"Last status change:       "<< ctime(&sb.st_ctime);
           cout<<"Last file access:         "<< ctime(&sb.st_atime);
           cout<<"Last file modification:   "<< ctime(&sb.st_mtime);

           exit(EXIT_SUCCESS);
	   return 0;
       }


OUTPUT:-
[ananya@localhost ~]$ g++ inode.cpp
[ananya@localhost ~]$ ./a.out /home/ananya
File type:                directory
File Permissions: 	drwx------
I-node number:            430496
Device : 		  64769
Link count:               20
Ownership:                UID=   	1000		GID=	1000
Preferred I/O block size: 4096bytes
File size:                4096bytes
Blocks allocated:         8
Last status change:       Sat Oct  1 21:21:26 2016
Last file access:         Sat Oct  1 21:20:06 2016
Last file modification:   Sat Oct  1 21:21:26 2016
[ananya@localhost ~]$ 





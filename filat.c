#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
  if (argc != 2) return 0;
  struct stat fileStat;
  if(stat(argv[1],&fileStat) < 0) return 1;
  printf("\n");
  printf("--------------------%s--------------------\n",argv[1]);
  printf("\n");
  printf("File Type: \t\t");
  if(S_ISBLK(fileStat.st_mode)) printf("Block device");
  else if (S_ISREG(fileStat.st_mode)) printf("Regular file");
  else if (S_ISDIR(fileStat.st_mode)) printf("Directory");
  else if (S_ISCHR(fileStat.st_mode)) printf("Character device");
  else if (S_ISLNK(fileStat.st_mode)) printf("Symbolic link");
  printf("\n");
  printf("Access privileges:\t");
  if (fileStat.st_mode & S_IRUSR)printf("r");
  else printf("-");
  if (fileStat.st_mode & S_IWUSR)printf("w");
  else printf("-");
  if (fileStat.st_mode & S_IXUSR)printf("x");
  else printf("-");
  if (fileStat.st_mode & S_IRGRP)printf("r");
  else printf("-");
  if (fileStat.st_mode & S_IWGRP)printf("w");
  else printf("-");
  if (fileStat.st_mode & S_IXGRP)printf("x");
  else printf("-");
  if (fileStat.st_mode & S_IROTH)printf("r");
  else printf("-");
  if (fileStat.st_mode & S_IWOTH)printf("w");
  else printf("-");
  if (fileStat.st_mode & S_IXOTH)printf("x");
  else printf("-");
  printf("\n");

  printf("File inode: \t\t%ld\n",fileStat.st_ino);
  printf("Device Numbers: \tdev = %ld; rdev = %ld\n",fileStat.st_dev, fileStat.st_rdev);
  printf("Number of Links: \t%ld\n",fileStat.st_nlink);
  printf("UID: \t\t\t%d\n",fileStat.st_uid);
  printf("GID: \t\t\t%d\n",fileStat.st_gid);
  printf("File size: \t\t%ld\n",fileStat.st_size);
  printf("Last access: \t\t%s",asctime(gmtime(&fileStat.st_atime)));
  printf("Last modification: \t%s",asctime(gmtime(&fileStat.st_mtime)));
  printf("Last inode change: \t%s",asctime(gmtime(&fileStat.st_ctime)));
  return 0;
}

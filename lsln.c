#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <time.h>
#include <fcntl.h>
#include <dirent.h>

int main(int argc, char const *argv[]) {
    struct dirent *de;
    DIR *dr = opendir(".");
    if (dr == NULL)  // opendir returns NULL if couldn't open directory
    {
        printf("Could not open current directory" );
        return 0;
    }
    while ((de = readdir(dr)) != NULL) {
      struct stat fileStat;
        if(stat(de->d_name,&fileStat) < 0) return 1;


      printf("\n");
      if(S_ISBLK(fileStat.st_mode)) printf("b");
      else if (S_ISREG(fileStat.st_mode)) printf("-");
      else if (S_ISDIR(fileStat.st_mode)) printf("d");
      else if (S_ISCHR(fileStat.st_mode)) printf("c");
      else if (S_ISLNK(fileStat.st_mode)) printf("l");
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
      if (fileStat.st_mode & S_IXOTH)printf("x ");
      else printf("- ");
      printf("%d ",fileStat.st_uid);
      printf("%d ",fileStat.st_gid);
      printf("%ld \t",fileStat.st_size);
      char time[18];
      strftime(time, 18, "%Y-%m-%d-%H-%M", localtime(&fileStat.st_mtime));
      printf("%s ",time);
      printf("%s",de->d_name );

  }
        closedir(dr);
  return 0;
}

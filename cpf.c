#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>

int main(int argc, char const *argv[]) {
  if (argc != 3) return 0;
  int check_file = open(argv[1], O_RDONLY);
  if (check_file < 0) {
    printf("Error\n");
    return 0;
  }
  int offset = lseek(check_file, 0, SEEK_END);

  char write_string[offset];

  offset = lseek(check_file, 0, 0);
  read(check_file, &write_string, sizeof(write_string));
  check_file = open(argv[2], O_TRUNC);
  check_file = open(argv[2], O_WRONLY);

  int test_write = write(check_file, write_string, sizeof(write_string));
  if (test_write < 0) {
    printf("Couldn't write to file...\n");
    return 0;
  }
  printf("Success!\n");
  return 0;
}

#include <stdio.h>

#include <unistd.h>
int main()
{
 FILE *df;
 fd = fopen(test.txt , "r");    
}



char* mygets(char str[], size_t len, int fileno) {
    size_t count;
    for (count = 0; count < len; ++count) {
        int result;
        if (result = read(fileno, str + count, 1), result != 1) {
            if (result == 0) {
                if (count > 0) {
                    str[count] = 0;
                    return str;
                } else {
                    if (count == 0) {
                        return NULL;
                    }
                }
            } else {
                perror("read");
                return NULL;
            }
        } else {
            if (str[count] == '\n') {
                if (count < len - 1) {
                    str[count + 1] = 0;
                } else {
                    str[count] = 0;
                }
                return str;
            }
        }
    }
    if (count < len) {
        str[count] = 0;
    }
    return str;
}

int main(int argc, char* argv[]) {
    char line[LINELEN + EXTRACHARS];
    char* filename = argv[1];
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return EXIT_FAILURE;
    }
    while (mygets(line, LINELEN + EXTRACHARS, fd)) {
        printf(line);
    }
    close(fd);
    return EXIT_SUCCESS;
}
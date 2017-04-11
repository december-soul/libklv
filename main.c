#include <stdio.h>
#include <stdlib.h>
#include "libklv.h"

int main(int argc, char *argv[]) {
    FILE *fileptr;
    char *buffer;
    long filelen;

    fileptr = fopen(argv[1], "rb");

    fseek(fileptr, 0, SEEK_END);          // Jump to the end of the file
    filelen = ftell(fileptr);             // Get the current byte offset in the file
    rewind(fileptr);                      // Jump back to the beginning of the file

    buffer = (char *)malloc((filelen+1)*sizeof(char)); // Enough memory for file + \0
    fread(buffer, filelen, 1, fileptr); // Read in the entire file
    
    klv_ctx_t *ctx = libklv_init();
    libklv_update_ctx_buffer(ctx, buffer, filelen);
    libklv_parse_data(buffer, filelen, ctx);
    libklv_cleanup(ctx);
    fclose(fileptr);
    return 0;
}

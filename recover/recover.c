#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check for correct usage
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open input file
    FILE *inptr = fopen(argv[1], "r");
    if (inptr == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    BYTE buffer[512];
    FILE *outptr = NULL;
    int file_count = 0;
    char filename[8]; // "###.jpg" + null terminator

    while (fread(buffer, sizeof(BYTE), 512, inptr) == 512)
    {
        // Check for JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0)
        {
            // Close previous file if it exists
            if (outptr != NULL)
                fclose(outptr);

            // Open new JPEG file
            sprintf(filename, "%03i.jpg", file_count);
            outptr = fopen(filename, "w");
            file_count++;
        }

        // Write to file if a JPEG has been found
        if (outptr != NULL)
            fwrite(buffer, sizeof(BYTE), 512, outptr);
    }

    // Close any remaining file
    if (outptr != NULL)
        fclose(outptr);

    fclose(inptr);
    return 0;
}

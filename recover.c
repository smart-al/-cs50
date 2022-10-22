#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(int argc, char *argv[])
{
    //Check the argument is 2
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw");
        return 1;
    }
    //Open file for reading
    FILE *input_file = fopen(argv[1], "r");

    //Check the file is valid!
    if (input_file == NULL)
    {
        printf("Could not open file.");
        return 2;
    }
    //Store blocks in array
    unsigned char buffer[512];

    //Track images generated
    int count_image = 0;

    //FIle pointer recovered images
    FILE *output_file = NULL;

    //Use malloc
    char *filename = malloc(8 * sizeof(char));

    //Read buffers
    while (fread(buffer, sizeof(char), 512, input_file) != 0)
    {
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (count_image > 0)
            {
                fclose(output_file);
            }

            //Write jpeg filename
            sprintf(filename, "%03i.jpg", count_image); //Makes a new jpg

            output_file = fopen(filename, "w");

            count_image++;
        }
        //Check output for valid input
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }
    //Free up space
    free(filename);
    fclose(input_file);
    fclose(output_file);

    return 0;
}

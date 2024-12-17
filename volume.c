#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open input file in binary read mode
    FILE *input = fopen(argv[1], "rb");
    if (input == NULL)
    {
        printf("Could not open input file.\n");
        return 1;
    }

    // Open output file in binary write mode
    FILE *output = fopen(argv[2], "wb");
    if (output == NULL)
    {
        printf("Could not open output file.\n");
        fclose(input);
        return 1;
    }

    // Get the volume adjustment factor from command-line argument
    float factor = atof(argv[3]);

    // Check if the factor is valid
    if (factor <= 0)
    {
        printf("Factor must be greater than 0.\n");
        fclose(input);
        fclose(output);
        return 1;
    }

    // Copy the header from input file to output file
    uint8_t header[HEADER_SIZE]; // Buffer for header
    fread(header, sizeof(uint8_t), HEADER_SIZE, input);
    fwrite(header, sizeof(uint8_t), HEADER_SIZE, output);

    // Process the audio samples (16-bit PCM data)
    int16_t sample; // Buffer for a single audio sample
    while (fread(&sample, sizeof(int16_t), 1, input)) // Read one sample at a time
    {
        // Adjust the volume with overflow protection
        int32_t adjusted_sample = (int32_t)(sample * factor); // Use 32-bit to prevent overflow
        if (adjusted_sample > 32767)
        {
            adjusted_sample = 32767; // Clamp to int16_t max
        }
        else if (adjusted_sample < -32768)
        {
            adjusted_sample = -32768; // Clamp to int16_t min
        }

        // Write the adjusted sample back to the output file
        sample = (int16_t)adjusted_sample; // Cast back to int16_t
        fwrite(&sample, sizeof(int16_t), 1, output);
    }

    // Close the input and output files
    fclose(input);
    fclose(output);

    printf("Volume adjustment completed successfully.\n");
    return 0;
}

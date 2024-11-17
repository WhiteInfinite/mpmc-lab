#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Stores bitmask value
char bitmask[4];
// Stores the binary equivalent of the complete bitmask
char binary_mask[13];

// Finds corresponding binary equivalent of bitmask
// Converts each hex digit of the bitmask into its binary equivalent (4 bits each)
void convert_binary(char bitmask[4])
{
    binary_mask[0] = '\0';  // Initialize the binary_mask to be empty

    for (int i = 0; i < 4; i++)
    {
        char binary[5];  // Store 4 bits + null terminator for each hex digit
        switch (bitmask[i])
        {
            case '0': strcpy(binary, "0000"); break;
            case '1': strcpy(binary, "0001"); break;
            case '2': strcpy(binary, "0010"); break;
            case '3': strcpy(binary, "0011"); break;
            case '4': strcpy(binary, "0100"); break;
            case '5': strcpy(binary, "0101"); break;
            case '6': strcpy(binary, "0110"); break;
            case '7': strcpy(binary, "0111"); break;
            case '8': strcpy(binary, "1000"); break;
            case '9': strcpy(binary, "1001"); break;
            case 'A': case 'a': strcpy(binary, "1010"); break;
            case 'B': case 'b': strcpy(binary, "1011"); break;
            case 'C': case 'c': strcpy(binary, "1100"); break;
            case 'D': case 'd': strcpy(binary, "1101"); break;
            case 'E': case 'e': strcpy(binary, "1110"); break;
            case 'F': case 'f': strcpy(binary, "1111"); break;
            default: strcpy(binary, "0000"); break;  // Error handling for invalid hex
        }
        strcat(binary_mask, binary);  // Append the converted binary to the binary_mask
    }
}


void main()
{
    // Stores starting address to which program is to be relocated
    unsigned int start;
    // Stores the address of text record
    unsigned int address;
    // Stores opcode read from text record
    unsigned int opcode;
    // Stores the final address after relocation
    unsigned int final_addr;
    // Stores the length of the text record
    unsigned int text_rec_len;
    // Stores starting address of record
    unsigned int rec_addr;
    // Stores length of record
    unsigned int length;
    // Stores the first column of the record (H/T/E)
    char col_one[10];
    // Stores address present in object code
    char obj_addr[10];
    // Stores the program name read from the input file
    char prog_name[10];

    FILE *fp = fopen("relocation.txt", "r");

    printf("Enter starting address : ");
    scanf("%x", &start);
    fscanf(fp, "%s", col_one);

    printf("\nLocation\tObject Code");

    while (strcmp(col_one, "E") != 0)
    {
        if (strcmp(col_one, "H") == 0)
        {
            fscanf(fp, "%s", prog_name);
            fscanf(fp, "%x", &rec_addr);
            fscanf(fp, "%x", &length);
            fscanf(fp, "%s", col_one);
        }

        if (strcmp(col_one, "T") == 0)
        {
            fscanf(fp, "%x", &address);
            fscanf(fp, "%x", &text_rec_len);
            fscanf(fp, "%s", bitmask);

            address += start;

            convert_binary(bitmask);

            for (int i = 0; i < 10; i++)
            {
                fscanf(fp, "%x", &opcode);
                fscanf(fp, "%s", obj_addr);

                if (binary_mask[i] == '0')
                    final_addr = (unsigned int)strtol(obj_addr, NULL, 16);
                else
                    final_addr = (unsigned int)strtol(obj_addr, NULL, 16) + start;

                printf("\n%x\t\t%x%04x", address, opcode, final_addr);
                address += 3;

                if (obj_addr[strlen(obj_addr) - 1] == '$')
                    break;
            }

            fscanf(fp, "%s", col_one);
        }
    }
    
    fclose(fp);
}


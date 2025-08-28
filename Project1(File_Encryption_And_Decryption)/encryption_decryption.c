#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

// Function to encrypt a file using XOR cipher
// key is passed by pointer so we can return it to main()
int encryption(FILE* ptrFile, FILE* ptrEnFile,int *key){
    printf("\n--- Starting Encryption Process ---\n");

    *key = (rand() % 256); // Keep it 0–255 so XOR stays in range

    printf("Generated encryption key: %d\n", *key);
    printf("Encrypting your file, please wait...\n");

    int ch;
    while ((ch = fgetc(ptrFile)) != EOF) {
        fputc(ch ^ *key, ptrEnFile); // XOR each byte with the key
    }

    printf("\nFile encrypted successfully!\n");
    printf("IMPORTANT: The Encryption Code is %d. Keep it safe!\n", *key);
    printf("----------------------------------\n");
    return *key;
}

// Function to decrypt a file using the provided key
int Decryption(FILE* ptrEnFile,char deFileName[], int key){
    int attempts = 10; // Max number of tries for entering correct key
    int inputCode;

    printf("\n--- Starting Decryption Process ---\n");

    do {
       printf("Enter the Encryption Code to decrypt (Attempts left: %d): ", attempts);
       scanf("%d", &inputCode);
       attempts--;

       if(inputCode == key){
           printf("Correct code entered!\n");
           break;
       } else {
           printf("Incorrect code! Try again.\n");
       }
    } while(attempts);

    // If no attempts left, exit
    if(attempts == 0){
        printf("\nSorry, you have no attempts left. Decryption aborted.\n");
        return 1;
    }
    
    printf("Decrypting your file, please wait...\n");

    FILE *ptrDeFile = fopen(deFileName,"w+");
    if(ptrDeFile == NULL){
        perror("Failed to create the decrypted file");
        return 1;
    }

    int ch;
    while ((ch = fgetc(ptrEnFile)) != EOF) {
        fputc(ch ^ key, ptrDeFile); // XOR again to get original content
    }
    fclose(ptrDeFile);

    printf("\nFile decrypted successfully! Saved as: %s\n", deFileName);
    printf("----------------------------------\n");
    return 0;
}

// Utility function to remove a file
void removeFile(char* fileName){
    if (remove(fileName) == 0) {
        printf("File '%s' deleted successfully.\n", fileName);
    } else {
        perror("Error deleting file");
    }
}

int main(){
    char filename[100], enFileName[120] = "Encrypted_", deFileName[120] = "Decrypted_";

    printf("Enter the name of the file you want to encrypt (without extension): ");
    fgets(filename,sizeof(filename),stdin);
    
    // Removes the newline character from the end of filename (if present)
    int i = 0;
    while(filename[i] != '\0'){
        if(filename[i] == '\n'){
            filename[i] = '\0';
            break;
        }
        i++;
    }

    // Append ".txt" to original filename and build names for encrypted & decrypted files
    strcat(filename, ".txt");
    strcat(enFileName, filename);
    strcat(deFileName, filename);

    srand(time(0)); // Seed RNG
    int key;

    printf("\nAttempting to open '%s' for encryption...\n", filename);

    FILE *file = fopen(filename, "r");
    if(file == NULL){
        perror("Failed to load the original file");
        return 1;
    }
    
    FILE *enFile = fopen(enFileName, "w+");
    if(enFile == NULL){
        perror("Failed to create encrypted file");
        fclose(file);
        return 1;
    }
    
    // Encrypt file
    int enCode = encryption(file, enFile, &key);
    fclose(file);
    fclose(enFile);

    // Remove original file
    removeFile(filename);
    
    printf("\nOpening encrypted file for decryption...\n");
    enFile = fopen(enFileName, "r");
    if(enFile == NULL){
        perror("Failed to open encrypted file");
        return 1;
    }
    
    //Clears everthing
    int yes;
    printf("Please enter any Number and press Enter if you have Memorised the Encryption Code and want to proceed: ");
    scanf("%d",&yes);
    system("clear");

    // Decrypt file
    Decryption(enFile, deFileName, key);
    
    fclose(enFile);

    printf("\n--- Program Finished ---\n");
    return 0;
}

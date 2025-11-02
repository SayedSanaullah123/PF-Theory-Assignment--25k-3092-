#include <stdio.h>
#include <string.h>

// Function prototypes
void encodeMessage(char message[]);
void decodeMessage(char message[]);
void reverseString(char message[]);
char toggleBits(char ch);

int main() {
    int choice;
    char message[500];  

    do {
        printf("\n===== TCS Message Encoder/Decoder =====\n");
        printf("1. Encode Message\n");
        printf("2. Decode Message\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch(choice) {
            case 1:
                printf("Enter message to encode: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; 
                encodeMessage(message);
                printf("Encoded Message: %s\n", message);
                break;

            case 2:
                printf("Enter message to decode: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0; 
                decodeMessage(message);
                printf("Decoded Message: %s\n", message);
                break;

            case 3:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice! Try again.\n");
        }

    } while(choice != 3);

    return 0;
}


void reverseString(char message[]) {
    int len = strlen(message);
    for(int i = 0; i < len / 2; i++) {
        char temp = message[i];
        message[i] = message[len - i - 1];
        message[len - i - 1] = temp;
    }
}


char toggleBits(char ch) {
    ch ^= (1 << 1); 
    ch ^= (1 << 4); 


    if(ch < 32) ch += 32;
    if(ch > 126) ch -= 32;

    return ch;
}


void encodeMessage(char message[]) {
    reverseString(message); 
    for(int i = 0; message[i] != '\0'; i++) {
        message[i] = toggleBits(message[i]);
    }
}


void decodeMessage(char message[]) {
    for(int i = 0; message[i] != '\0'; i++) {
        message[i] = toggleBits(message[i]); 
    }
    reverseString(message); 
}


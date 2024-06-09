#include <stdio.h>
#include <string.h>

int main() {
    char sentence[200];
    printf("Enter the sentence: ");
    fgets(sentence, 200, stdin);

    int count = 0, i = 0;
    for (i = 0; sentence[i] != '\0'; i++) {
        if (sentence[i] == ' ' && sentence[i+1] != ' ') {
            count++;
        }
    }

    if (i > 0 && sentence[i-1] != ' ') {
        count++;
    }

    printf("The number of words present in the sentence is %d", count);
    return 0;
}

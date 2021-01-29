#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

string cl26[] = {"a", "b", "c", "d", "e", "f", "g", "h", "i", "j", "k", "l", "m", "n", "o", "p", "q", "r", "s", "t", "u", "v", "w", "x", "y", "z"};
string cu26[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};

int main(int argc, string argv[])
{
    while (argc <= 1)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    int first = (int) argv[1][0];
    
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        int d = (int) argv[1][i];
     
        if (d < 48 || d > 57 || first == 48)
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    
    int k = atoi(argv[1]);
    
    string plaintext = get_string("plaintext:  ");
    printf("ciphertext: ");
    
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            int c = (plaintext[i] - 65 + k) % 26;
            printf("%s", cu26[c]);
        }
        else if (islower(plaintext[i]))
        {
            int c = (plaintext[i] - 97 + k) % 26;
            printf("%s", cl26[c]);
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");  
}

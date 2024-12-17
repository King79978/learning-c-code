#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main(int argc,string argv[])
{
    //
    if(argc!=2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
        if(strlen(argv[1])!=26)
    {
        printf("Key must contain 26 characters\n");
        return 1;
    }
    bool Repeat_check[26]={false};
    for(int i=0;i<26;i++)
    {
        if(!isalpha(argv[1][i]))
        {
            printf("Key must contain 26 letter\n");
            return 1;
        }
        int index=tolower(argv[1][i])-'a';
        if(Repeat_check[index])
        {
            printf("Key must contain 26 unique alphabetic characters\n");
            return 1;
        }
        Repeat_check[index]=true;
    }
        string plaintext = get_string("plaintext: ");
        int all_char=strlen(plaintext);
        printf("ciphertext: ");
        for(int i=0;i<all_char;i++)
        {
            if(isalpha(plaintext[i]))
            {
                if(islower(plaintext[i]))
                {
                    int n =plaintext[i]-'a';
                    printf("%c",tolower(argv[1][n]));
                }
                if(isupper(plaintext[i]))
                {
                    int n =plaintext[i]-'A';
                    printf("%c",toupper(argv[1][n]));
                }
            }
            else
            {
                printf("%c",plaintext[i]);
            }
        }
        printf("\n");
        return 0;
}

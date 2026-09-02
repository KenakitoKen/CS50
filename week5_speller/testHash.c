#include <stdio.h>
#include <ctype.h>
#include <string.h>

unsigned int hash(const char *word)
{
    unsigned int hash_value = 0;
    int string_length = strlen(word);
    for (int i = 0; i < string_length && i < 5; i++)
    {
        if (isalpha(word[i])) {
            hash_value += toupper(word[i]) - 'A';
        }
    }
    hash_value = hash_value % 125;
    return hash_value;
}

int main(void)
{
    char *words[] = {"Xylophone", "zzzana", "cat", "zebra", "Hello"};
    int count = sizeof(words) / sizeof(words[0]);

    for (int i = 0; i < count; i++)
    {
        printf("%s -> %u\n", words[i], hash(words[i]));
    }
}

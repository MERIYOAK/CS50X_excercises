#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters (string text);
int count_words (string text);
int count_sentences (string text);

int main(void)
{
    string text = get_string("text: ");
    float letters = count_letters(text);
    float words = count_words(text);
    float sentences = count_sentences(text);
    float average_no_of_letters = letters * 100 / words;
    float average_no_of_sentences = sentences * 100 / words;
    int index = round(0.0588 * average_no_of_letters - 0.296 * average_no_of_sentences - 15.8);

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 15)
    {
        printf("Grade 16+\n");
    }
    else{
        printf("Grade %i\n",index);
    }
}
int count_letters (string text)
{
    int number_of_letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
         if (isalpha(text[i]))
         {
            number_of_letters++;
         }
    }
    return number_of_letters;
}
int count_words (string text)
{
    int number_of_words = 0;
    for (int i = 0; i < strlen(text); i++)
    {
         if (text[i] == ' ')
         {
            number_of_words++;
         }
    }
    return number_of_words + 1;
}
int count_sentences (string text)
{
    int number_of_sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
         if (text[i] == '.' || text[i] == '?' || text[i] == '!')
         {
            number_of_sentences++;
         }
    }
    return number_of_sentences;
}
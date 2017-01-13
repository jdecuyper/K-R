#include<stdio.h>
#include <stdbool.h>
#define NELEMS(x)  (sizeof(x) / sizeof((x)[0]))

void replace(char s[], char t[]) {
    int i = 0;
    int it = 0;
    while (s[i] != '\0') {

        switch (s[i]) {
            case '\n':
                t[it] = '\\';
                t[++it]= 'n';
                break;
            case '\t':
                t[it] = '\\';
                t[++it]= 't';
                break;
            default:
                t[++it] = s[i];
                break;
        }
        i++;
    }
    t[it] = '\0';
}

void undoreplace(char s[], char t[]) {
    int i = 0;
    int it = 0;
    bool foundbackslash = false;

    while (s[i] != '\0') {

        switch (s[i]) {
            case '\\':
                foundbackslash = true;
                break;
            case 'n':
                if (foundbackslash) {
                    t[it] = '\n';
                    foundbackslash = false;
                    it++;
                    break;
                }
            case 't':
                if (foundbackslash) {
                    t[it] = '\t';
                    foundbackslash = false;
                    it++;
                    break;
                }
            default:
                t[it] = s[i];
                it++;
                break;
        }

        i++;
    }

    t[it] = '\0';
}

void printstr(char s[]) {
    int i = 0;
    while (s[i] != '\0') {
        printf("%c", s[i]);
        i++;
    }
    printf("\n");
}

int countchar(char s[], char c) {
    int count = 0;
    int i = 0;

    while (s[i] != '\0') {
        if (s[i] == c)
            count++;
        i++;
    }

    return count;
}

int main()
{
    printf("Exercice 3.2\n");

    // Original input
    char s[] = "Roses are red, violets are\tblue,\nUse one of these poems\nAs a love message from you.";
    //char s[] = "Roses are \n red.";
    printf("\nOriginal array: \n");
    printstr(s);
    printf("\n");
    // Make unvisible chars visible
    // \n and \t will be replaced with 2 chars, \\n and \\t respectively

    // Since each invisible char will be replaced with 2 chars
    // the size of the destination array is greater than the original array
    // To find the destination array size we sum the size of the original array,
    // newline and tab chars
    char t[NELEMS(s) + countchar(s, '\n') + countchar(s, '\t')];

    // Replace all \n and \t with visible \n and \t
    replace(s, t);
    printf("\nReplace newlines and tabs with visible chars: \n");
    printstr(t);
    printf("\n");

    // Undo replacement
    char u[NELEMS(s)];
    undoreplace(t, u);
    printf("\nUndo replacement: \n");
    printstr(u);
    printf("\n");

    return 0;
}

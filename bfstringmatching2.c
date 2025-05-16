#include <stdio.h>
#include <string.h>
void bruteForceMatch(char text[], char pattern[]) {
    int n = strlen(text);
    int m = strlen(pattern);
    
    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++)
            if (text[i + j] != pattern[j])
                break;
        if (j == m)
            printf("Pattern found at index %d\n", i);
    }
}
int main() {
    char text[100], pattern[50];

    printf("Enter the text: ");
    scanf(" %[^\n]", text);  
    printf("Enter the pattern to search: ");
    scanf(" %[^\n]", pattern);

    bruteForceMatch(text, pattern);

    return 0;
}

/*Output:
Enter the text: Hello, Anuj
Enter the pattern to search: Anu
Pattern found at index 7 */

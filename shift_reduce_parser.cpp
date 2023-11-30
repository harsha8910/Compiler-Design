#include <iostream>
#include <cstring>
using namespace std;

struct prodn
{
    char p1[10];
    char p2[10];
};

int main()
{
    char input[50], stack[50], ch[2], *t;
    int i, j, s1, s2, s, count = 0;
    struct prodn p[10];

    // Define the grammar directly in the code
    const char grammar[][10] = {"S->0S0", "S->1S1", "S->2"};

    stack[0] = '\0';

    cout << "Enter the Input String:\n";
    cin >> input;

    cout << "Stack\t\tInput\t\tAction\n\n\n";

    for (count = 0; count < 3; count++)
    {
        strcpy(p[count].p1, strtok((char *)grammar[count], "->"));
        strcpy(p[count].p2, strtok(NULL, "->"));
    }

    i = 0;
    while (1)
    {
        if (i < strlen(input))
        {
            ch[0] = input[i];
            ch[1] = '\0';
            i++;
            strcat(stack, ch);
            cout << stack << "\t\t" << input + i << "\t\tRead " << ch[0] << endl;
        }

        for (j = 0; j < 3; j++)
        {
            t = strstr(stack, p[j].p2);
            if (t != NULL)
            {
                s1 = strlen(stack);
                s2 = strlen(t);
                s = s1 - s2;
                stack[s] = '\0';
                strcat(stack, p[j].p1);
                cout << stack << "\t\t" << input + i << "\t\tReduced by " << p[j].p2 << " to " << p[j].p1 << endl;
                j = -1;
            }
        }

        if (strcmp(stack, "S") == 0 && i == strlen(input))
        {
            cout << "\nAccepted.............." << input << "\n";
            break;
        }

        if (i == strlen(input))
        {
            cout << "\nNot Accepted............" << input << "\n";
            break;
        }
    }

    return 0;
}

#include"header.h"
char op;
int symbol_sel()
{
    int op;
    printf("what type of data to be generated randomly\n");
    printf("1) Numbers [0-9]\n2) Lowercase Chars[a-z]\n3) Uppercase Chars[A-Z]\n4) Symbols[#@#&^]\n");
    printf("select prefered option\n");
    scanf("%d", &op);
    return op;
}
char *random_gen(int size, int sym)
{
    char *ar = malloc(size + 1);
    switch (sym)
    {
    case 1:
        for (int i = 0; i < size; i++)
        {
            char c = rand() % 10 - '0';
            ar[i] = c;
        }
        ar[size] = '\0';
        return ar;
    case 2:
        for (int i = 0; i < size; i++)
        {
            char c = 'a' + rand() % 26;
            ar[i] = c;
        }
        ar[size] = '\0';
        return ar;
    case 3:
        for (int i = 0; i < size; i++)
        {
            char c = rand() % 26 + 'A';
            ar[i] = c;
        }
        ar[size] = '\0';
        return ar;
    case 4:
        const char specialSymbols[] = "!@#$%^&*()_+{}[]<>?";
        int symbolCount = sizeof(specialSymbols) - 1; // Exclude the null terminator
        for (int i = 0; i < symbolCount; i++)
            ar[i] = specialSymbols[rand() % symbolCount];
        ar[size] = '\0';
        return ar;
        break;
    default:
        printf("Invalid option\n");
    }
}
int main()
{
    srand(time(NULL));
    do{
        int size;
        printf("enter the size\n");
        scanf("%d", &size);
        int sy=symbol_sel();
        char *p=random_gen(size,sy);
        while(*p)
        {
            printf("%c ",*p);
            p++;
        }
        printf("Do you want to continue? (y/n): ");
        scanf("%c", &op);
    }
    while(op=='y'||op=='Y');
    return 0;
}
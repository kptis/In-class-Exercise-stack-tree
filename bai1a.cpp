#include <iostream>

using namespace std;

int main()
{
    printf("Doc file input1.txt:\n");
    FILE *fp;
    fp = fopen("input1.txt", "r");
    if ((fp) == NULL)
    {
        fprintf(stderr, "impossible to open: input1.txt\n");
        perror("Because:");
        fclose(fp);
        fflush(stdin);
        getchar();
        return 0;
    }

    char x;

    string s = "";
    while (fscanf(fp, "%c", &x) != EOF)
    {
        s = s + x;
    }
    fclose(fp);
    cout << s << endl;
    cout << "Tan suat xuat hien la: " << endl;
    // tinh tan suat xuat hien
    int i;
    int len;
    int a[256] = {0};
    len = s.length();
    for (i = 0; i < len; i++)
    {

        a[s[i]]++;
    }
    for (i = 0; i < 256; i++)
        a[i] ? printf("%c = %d\n", i, a[i]) : printf("");

    cout << "In ra file output1.txt:" << endl;
    fp = fopen("output1.txt", "w+");
    if ((fp) == NULL)
    {
        fprintf(stderr, "impossible to open: output2.txt\n");
        perror("Because:");
        fclose(fp);
        fflush(stdin);
        getchar();
        return 0;
    }
    for (i = 0; i < 256; i++)
        if (a[i] != 0)
            fprintf(fp, "%c = %d\n", i, a[i]);

    return 0;
}

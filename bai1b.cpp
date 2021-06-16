#include <iostream>
#include <stack>
using namespace std;

int main()
{
    printf("Doc file input1.txt\n");
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
    printf("Cho du lieu vao stack\n");
    char x;
    stack<char> st;
    while (fscanf(fp, "%c", &x) != EOF)
    {
        st.push(x);
    }
    fclose(fp);
    printf("Ghi du lieu theo thu tu nguoc lai ra file output2.txt\n");

    fp = fopen("output2.txt", "w+");
    if ((fp) == NULL)
    {
        fprintf(stderr, "impossible to open: output2.txt\n");
        perror("Because:");
        fclose(fp);
        fflush(stdin);
        getchar();
        return 0;
    }

    while (!st.empty())
    {
        fprintf(fp, "%c", st.top());
        st.pop();
    }
    return 0;
}
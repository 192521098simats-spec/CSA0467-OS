#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int n, m, i, sum = 0;
    long long fact = 1;
    pid_t pid;

    printf("Enter a number for sum: ");
    scanf("%d", &n);

    printf("Enter a number for factorial: ");
    scanf("%d", &m);

    pid = fork();

    if (pid == 0)
    {
        for (i = 1; i <= m; i++)
        {
            fact = fact * i;
        }

        printf("Factorial of %d = %lld\n", m, fact);
    }
    else if (pid > 0)
    {
        for (i = 1; i <= n; i++)
        {
            sum = sum + i;
        }

        printf("Sum of first %d natural numbers = %d\n", n, sum);

        wait(NULL);
    }
    else
    {
        printf("Fork failed\n");
    }

    return 0;
}
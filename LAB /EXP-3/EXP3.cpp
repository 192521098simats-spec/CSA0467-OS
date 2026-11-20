#include <stdio.h>
#include <pthread.h>

int n;

void *check_odd_even(void *arg)
{
    if (n % 2 == 0)
    {
        printf("The number %d is Even\n", n);
    }
    else
    {
        printf("The number %d is Odd\n", n);
    }

    return NULL;
}

void *fibonacci(void *arg)
{
    int a = 0, b = 1, c, i;

    printf("Fibonacci Series: ");

    for (i = 1; i <= n; i++)
    {
        printf("%d ", a);

        c = a + b;
        a = b;
        b = c;
    }

    printf("\n");

    return NULL;
}

int main()
{
    pthread_t thread1, thread2;

    printf("Enter a number: ");
    scanf("%d", &n);

    pthread_create(&thread1, NULL, check_odd_even, NULL);
    pthread_create(&thread2, NULL, fibonacci, NULL);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
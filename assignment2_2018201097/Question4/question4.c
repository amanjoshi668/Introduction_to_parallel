#include <stdio.h>
#include <omp.h>
int main()
{
    const int REPS = 1000000;
    int i;
    double balance = 0.0;
    printf("\nYour starting bank account balance is %0.2f\n", balance);
    // simulate many deposits
     #pragma omp parallel for reduction(+:balance) // A1
    // #pragma omp parallel for private(balance)    // B1
    for (i = 0; i < REPS; i++)
    {
    //     #pragma omp atomic // C1
        balance += 10.0;
    }
    
    printf("\nAfter %d $10 deposits, your balance is %0.2f\n",
           REPS, balance);
    // simulate the same number of withdrawals
     #pragma omp parallel for reduction(-:balance)    // A2
    //#pragma omp parallel for private(balance)    // B2
    for (i = 0; i < REPS; i++)
    {
         //#pragma omp atomic    // C2
        balance -= 10.0;
    }
    // balance should be zero
    printf("\nAfter %d $10 withdrawals, your balance is %0.2f\n\n",
           REPS, balance);
    return 0;
}

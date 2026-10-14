#include <stdio.h>

int sPrime(int n);
int nSplit(int* nDividend, int* nDivisor);

int main() {
    int n, d;
    int nF, dF, gcd;
    double resul;
    
    printf("Dividend: ");
    scanf("%d", &n);

    printf("\nDivisor: ");
    scanf("%d", &d);

    resul = (double)n / d;

    nF = n;
    dF = d;

    int pn = sPrime(n), pd = sPrime(d);

    if(pn && pd) {        
        printf("\n\n%d and %d are PRIME\n", n, d);
    } else if(pn && !pd) {
        printf("\n\n%d is PRIME and %d isn't PRIME\n", n, d);
    } else if(!pn && pd) {
        printf("\n\n%d isn't PRIME and %d is PRIME\n", n, d);
    } else {
        printf("\n\n%d and %d aren't PRIME\n", n, d);
    }
        
    gcd = nSplit(&nF, &dF);

    printf("\n\nFraction: %d / %d = %.8f", n, d, resul);
    printf("\nSimplified fraction: %d / %d", nF, dF);
    printf("\nPercent: %.3f%%", resul * 100);
    printf("\nGreatest common divisor = %d\n\n", gcd);
        
}

int sPrime(int n) {
    for(int i = 2; i < n; i++) {
        if(n% i == 0) {
            return 0;
        }
    }
    
    return 1;
}

int nSplit(int* nDividend, int* nDivisor) {
    for(int i = 2; i <= *nDividend && i <= *nDivisor; i++){
        if(*nDividend % i == 0 && *nDivisor % i == 0){
            *nDividend /= i;
            *nDivisor /= i;
            return i * nSplit(nDividend, nDivisor);
        }
    }

    return 1;
}
//1.odd or even
/* #include <stdio.h>

int main() {
    int n;
    printf("enter  number :");
    scanf("%d",&n);
    if(n%2==0){
        printf(" it is even");

    }else{
        printf("it is odd");
    }
    return 0;
}


//2.  positve ,negative or zero
#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    
    if (n > 0)
        printf("Positive");
    else if (n < 0)
        printf("Negative");
    else
        printf("Zero");

    return 0;
}

//3. Maximum of Two Numbers
#include <stdio.h>
int main() {
    int a, b;
    printf("Enter two number a,b: ");
    scanf("%d %d", &a, &b);

    if (a > b)
        printf("%d", a);
    else
        printf("%d", b);

    return 0;
}
//4. divisible by 5 andd 11
#include <stdio.h>

int main() {
    int n;
    printf("Enter the number");
    scanf("%d", &n);

    if (n % 5 == 0 && n % 11 == 0)
        printf("YES");
    else
        printf("NO");

    return 0;
}
//5. simple calculator
#include <stdio.h>

int main() {
    float a, b;
    char choice;
    scanf("%f %c %f", &a, &choice, &b);

    switch (choice) {
        case '+':
            printf("%.2f", a + b);
            break;
        case '-':
            printf("%.2f", a - b);
            break;
        case '*':
            printf("%.2f", a * b);
            break;
        case '/':
            if (b != 0)
                printf("%.2f", a / b);
            else
                printf("Division by zero is not possible");
            break;
        default:
            printf("Invalid Operator");
    }

    return 0;
}
//6.voter eligibility

#include <stdio.h>

int main() {
    int age;
    printf("enter your age: ")
    scanf("%d", &age);

    if (age >= 18)
        printf("Eligible");
    else
        printf("Not Eligible");

    return 0;
}

//7. Largest of three number
#include <stdio.h>

int main() {
    int a, b, c;
    printf("Enter the number of a,b,c");
    scanf("%d %d %d", &a, &b, &c);

    if (a >= b && a >= c)
        printf("%d", a);
    else if (b >= a && b >= c)
        printf("%d", b);
    else
        printf("%d", c);

    return 0;
}

//8. Electricity Bill calculate
#include <stdio.h>

int main() {
    int units;
    float bill;
    scanf("%d", &units);

    if (units <= 100)
        bill = units * 5;
    else if (units <= 200)
        bill = (100 * 5) + (units - 100) * 7;
    else
        bill = (100 * 5) + (100 * 7) + (units - 200) * 10;

    printf("Total Bill = %.2f", bill);

    return 0;
}*/


//9. Special Number
//#include <stdio.h>

//int main() {
//    int num, d1, d2, sum, product;
//
//    printf("Enter a two-digit number: ");
//    scanf("%d", &num);
//
//    d1 = num / 10;
//    d2 = num % 10;
//
//    sum = d1 + d2;
//    product = d1 * d2;
//
//    if (sum == product)
//        printf("Special\n");
//    else
//        printf("Not Special\n");
//
//    return 0;
//}

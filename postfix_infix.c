//  #include<stdio.h>
// int main(){
//     char fruits[][10]={"aple", "bichi"};
//     int size= sizeof(fruits)/sizeof(fruits[0]);
//     for (int i=0; i<size;i++){
//         printf("%s ",fruits[i]);
//     }
// }
// // enum day{
// //     monday=1 ,tuesday,bichi,fod
// // };
// // int main (){
// //     enum day today=monday;
// //     printf("%d",today);

// // }
#include <stdio.h>
#include <ctype.h>

int main() {
    char postfix[50];
    int stack[50];
    int top = -1, i;
    char c;
    int a, b, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++) {
        c = postfix[i];

        if (isdigit(c)) {
            stack[++top] = c - '0';
        }
        else {
            b = stack[top--];
            a = stack[top--];

            if (c == '+')
                result = a + b;
            else if (c == '-')
                result = a - b;
            else if (c == '*')
                result = a * b;
            else if (c == '/')
                result = a / b;

            stack[++top] = result;
        }
    }

    printf("Result = %d\n", stack[top]);
    return 0;
}
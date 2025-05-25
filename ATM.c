#include <stdio.h>
#include <string.h>

void transaction(int PIN);

int main()
{
    int attempt = 0;
    const int PIN = 1234; 
    const long cardNum=1234567890;  
    long enteredCardNum;
    int enteredPIN;

    printf("welcome to BANK ...........\n");
    printf("\nplease enter your card number : ");
    scanf("%ld", &enteredCardNum);

    if (enteredCardNum == cardNum) {
        while (attempt < 3) {
            printf("Enter PIN (secret account code ): ");
            scanf("%d", &enteredPIN);
            if (PIN == enteredPIN) {
                printf("PIN accepted.\n");
                transaction(PIN);
                break;
            } else {
                attempt++;
                printf("Wrong PIN. Attempts left: %d\n", 3 - attempt);
            }
        }
        if (attempt == 3) {
            printf("Too many wrong PIN attempts. Card blocked.\n");
            return 0;
        }
    } else {
        printf("Invalid card number.\n");
        return 0;
    }
    return 0;
}

void transaction(int PIN) {
    int choice;
    double balance = 0.00;
    double amount;
    char transactions[5][50]; 
    int transactionCount = 0;

    do {
        printf("\nenter 1 for balance Inquery ----(checking how much money you currently have in your account)\n");
        printf("enter 2 for deposite amount ----(when you deposit money ,you're putting cash into your account to add to your balance )\n");
        printf("enter 3 for withdrow amount -----(when you withdrow money , to take money out of your account ,reducing your available balance)\n");
        printf("enter 4 for exit ----(do not want to any transation)\n");
        printf("enter 5 to change PIN------(change your current secret account code \n");
        printf("enter 6 for mini statement----(shows you the last 5 transaction)\n");
        printf("enter the option :");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                 printf("------------------");
                printf("\nyour bank balance is : %.2lf\n", balance);
                printf("-----------------------\n");
                break;
            case 2:
                
                printf("enter the amount to deposite : ");
                scanf("%lf",&amount);
                printf("------------------");
                if (amount > 0) {
                    if (amount <= 20000) {
                        balance += amount;
                        printf("\nyou have deposite : %.2lf \n", amount);
                        printf("your current bank balance is : %.2lf\n", balance);

                        

                        if (transactionCount < 5) {
                            snprintf(transactions[transactionCount], 50, "Deposit: +%.2lf", amount);
                            transactionCount++;
                        } else {
                            for (int i = 1; i < 5; i++)
                                strcpy(transactions[i - 1], transactions[i]);
                            snprintf(transactions[4], 50, "Deposit: +%.2lf", amount);
                        }
                    } else {
                        printf("you have cross the limit of deposition (at a time you can deposite only 20,000 )\n");
                    }
                } else {
                    printf("\ninvalid amount , enter the valid \n");
                }
                printf("-----------------------\n");
                break;
            case 3:
                
                printf("enter the amount to withdrow : ");
                scanf("%lf",&amount);
                 printf("------------------\n");
                if (amount > 0 && amount <= balance) {
                    balance -= amount;
                    printf("\nyou have withdrow : %.2lf\n", amount);
                    printf("your current bank balance : %.2lf \n", balance);
                   

                    if (transactionCount < 5) {
                        snprintf(transactions[transactionCount], 50, "Withdraw: -%.2lf", amount);
                        transactionCount++;
                    } else {
                        for (int i = 1; i < 5; i++)
                            strcpy(transactions[i - 1], transactions[i]);
                        snprintf(transactions[4], 50, "Withdraw: -%.2lf", amount);
                    }
                } else if (amount > balance) {
                    printf("insufficent balance ()\n");
                } else {
                    printf("enter invalid\n");
                }
                printf("-----------------------\n");
                break;
            case 4:
               printf("------------------");
                printf("\nThank you for using BANK ATM.\n");
                printf("Have a great day!\n");
                printf("-----------------------\n");
                break;
            case 5: { 
                 printf("------------------");
                int oldPINinput, newPINinput, confirmPINinput;
                printf("Enter your current PIN: ");
                scanf("%d", &oldPINinput);
                if (oldPINinput == PIN) {
                    printf("Enter new PIN: ");
                    scanf("%d", &newPINinput);
                    printf("Confirm new PIN: ");
                    scanf("%d", &confirmPINinput);
                    if (newPINinput == confirmPINinput) {
                        PIN = newPINinput;
                        printf("PIN successfully changed.\n");
                    } else {
                        printf("New PINs do not match. PIN change failed.\n");
                    }
                } else {
                    printf("Incorrect current PIN. PIN change failed.\n");
                }
                printf("-----------------------\n");
                break;
            }
            case 6: 
             printf("------------------\n");
                if (transactionCount == 0) {
                    printf("No transactions yet.\n");
                } else {
                    printf("\nLast %d transactions:\n", transactionCount);
                    for (int i = 0; i < transactionCount; i++) {
                        printf("%d. %s\n", i + 1, transactions[i]);
                    }
                }
                printf("-----------------------\n");
                break;
            default:
                printf("enter the valid option\n");
        }
    } while (choice != 4);
}
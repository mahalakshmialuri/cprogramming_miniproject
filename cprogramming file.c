#include <stdio.h>
#include <string.h>
struct Account {
    char account_number[20];
    char pin[5];
    float balance;
};
int verify_pin(struct Account user, char entered_pin[]) {
    return strcmp(user.pin, entered_pin) == 0;
}
void display_balance(struct Account user) {
    printf("Your current balance is: %.2f\n", user.balance);
}
void withdraw_cash(struct Account *user, float amount) {
    if (amount > 0 && amount <= user->balance) {
        user->balance -= amount;
        printf("Withdrew %.2f. New balance: %.2f\n", amount, user->balance);
    } else {
        printf("Invalid withdrawal amount.\n");
    }
}
int main() {
 struct Account user;
    char entered_pin[5];
    float withdrawal_amount;
    int choice;
    printf("Enter account number: ");
    scanf("%s", user.account_number);
    printf("Enter PIN: ");
    scanf("%s", user.pin);
    printf("Enter initial balance: ");
    scanf("%f", &user.balance);
    do {
        printf("\nATM Menu:\n");
        printf("1. Balance Inquiry\n");
        printf("2. Withdraw Cash\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                display_balance(user);
                break;
            case 2:
                printf("Enter withdrawal amount: ");
                scanf("%f", &withdrawal_amount);
                withdraw_cash(&user, withdrawal_amount);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 3);
    return 0;
}
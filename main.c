#include <stdio.h>
#include "myBank.h"


int main(){
int i=1;// a flag for input transactions
char c = ' ';

while(i){
printf("\nPlease choose a transaction type:\n");
        printf(" O-Open Account\n");
        printf(" B-Balance Inquiry\n");
        printf(" D-Deposit\n");
        printf(" W-Withdrawal\n");
        printf(" C-Close Account\n");
        printf(" I-Interest\n");
        printf(" P-Print\n");
        printf(" E-Exit\n");
scanf(" %c", &c);// O 456 O 345B903B902I5PE

switch (c)
{
	case'O':
    {
		double amount;
		
	
			printf("Please enter amount for deposit: ");
			if (scanf("%lf", &amount)==1){
				if (amount >= 0){
					open_acount( amount);
				}else{
					printf("Invalid Amount\n");
					
				}
	
			}else{
				printf("Failed to read the amount\n");
			}

		
    }
	    break;
	case 'B':{
		int account_number;
		
			printf("Please enter account number: ");
			if (scanf("%d", &account_number)==1){
				if (account_number>= 901 && account_number<= 950){
					check_balance( account_number);
					
					
				}else{
					printf("Invalid account number\n");
				
				}
	
			}else{
				printf("Failed to read the account number\n");
				
			}

		}
		break;
	case 'D':{
		int account_number;
	
		
			printf("Please enter account number: ");
			if (scanf("%d", &account_number)==1){
			
				if (account_number>= 901 && account_number<= 950){
			
					deposit(account_number);
					
				}else{
					printf("Invalid account number\n");
					
				}
	
			}else{
				printf("Failed to read the account number\n");
				
			}

		}
		break;
		
	case 'W':{
		int account_number;
		
			printf("Please enter account number: ");
			if (scanf("%d", &account_number)==1){
				if (account_number>= 901 && account_number<= 950){
					withdrawl (account_number);
					
				}else{
					printf("Invalid account number\n");
					
				}
	
			}else{
				printf("Failed to read the account number\n");
				
			}

		}
		break;
	
	case 'C':{
		int account_number;
		
			printf("Please enter account number: ");
			if (scanf("%d", &account_number)==1){
				if (account_number>= 901 && account_number<= 950){
					close( account_number);
					
				}else{
					printf("Invalid account number\n");
				}
	
			}else{
				printf("Failed to read the account number\n");
			}

		}
		break;
		
	case 'I':{
		double rate;
		
			printf("Please enter interest rate: ");
			if (scanf("%lf", &rate)==1){
				if(rate>=0)
					add_interest(rate);
				else
					printf("Invalid interest rate\n");
				
			}else{
				printf("Failed to read the interest rate\n");
				
			}

		}
		break;
		
	case'P':
		print_accounts();
		break;
	case'E':
		end();
		i=0;
		break;
		
	default:
		printf("Invalid transaction type\n");
		break;
		
		

}
}
return 0;
}




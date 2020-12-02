#include <stdio.h>
#include "myBank.h"

#define first_acount 901
#define close_status 0.0
#define open_status 1.0

double bank [50][2]={{close_status}};

int count=0; // this varaible will help us to know if there is a available account in the bank


void open_acount(double amount){
 	if(count<50){
	
	for(int i=0;i<50;i++){
		if(bank[i][0]== close_status){
			bank[i][1]=amount;
			bank[i][0]=open_status;
			printf("New account number is: %d \n",first_acount+i);
			count++;
			break;
		}
		
	
	}
	}
 	else{ 
 	printf("there is no an available account right now\n");
 	}
 }
void check_balance (int count_number){
	if(bank[count_number-first_acount][0]==open_status){
	 	printf("The balance of account number %d is: %.2f\n",count_number,bank[count_number-first_acount][1]);
 	}
 	else{ 
 	printf("This account is closed\n");
 	}
}
void deposit (int count_number){

	
 	if(bank[count_number-first_acount][0]==open_status){
 	double amount;
 	printf("Please enter the amount to deposit: ");
		if (scanf("%lf", &amount)==1){
			if (amount >= 0){
					bank[count_number-first_acount][1]+=amount;
 					printf("your new balance is: %.2f\n",bank[count_number-first_acount][1]);
								
			}else{
				printf("Cannot deposit a negative amount\n");
			}
	
		}else{
			printf("Failed to read the amount\n");
						
		}
 		
 	}
 	else{ 
 	printf("This account is closed\n");
 	}
}
void withdrawl (int count_number){
	if(bank[count_number-first_acount][0]==open_status){
		double amount;
		printf("Please enter the amount to withdraw: ");
		if (scanf("%lf", &amount)==1){
			if (amount>=0){
				if( (bank[count_number-first_acount][1]-amount)>=0){
 					bank[count_number-first_acount][1]-=amount;
 					printf("The new balance is: %.2f\n",bank[count_number-first_acount][1]);
 				}
 				else{ 
 					printf("Cannot withdraw more than the balance\n");
 				}
 			}else{
				printf("Cannot withdraw a negative amount\n");
			}
 		}
 	}
 	else{ 
 	printf("This account is closed\n");
 	}
 	
 	
}
void close(int count_number){
	if(bank[count_number-first_acount][0]==open_status){
		bank[count_number-first_acount][1]=0;
 		bank[count_number-first_acount][0]=close_status;
 		count--;
 		//printf("Closed account number %d\n", count_number);
 	}
 	else{ 
 		printf("This account is already closed\n");
 	}
}
 void add_interest(double rate){
 	
 	for(int i=0;i<50;i++){
 		if(bank[i][0]==open_status){
 		bank[i][1]*=(rate/100.0)+1;
 		}
 	}
}
 
void print_accounts(){
 	
 	for(int i=0;i<50;i++){
 		if(bank[i][0]==open_status){
 		printf("The balance of account number %d is: %.2f\n",first_acount+i,bank[i][1]);
 		}
 	}
}
void end(){
	
	 for(int i=0;i<50;i++){
 		if(bank[i][0]==open_status){
 			close(first_acount+i);
 		}
 	}
 	
}
 
void clearInput(){
	char clear;
 	while((clear=getchar() )!='\n' && clear!= EOF);
}
 
	
	

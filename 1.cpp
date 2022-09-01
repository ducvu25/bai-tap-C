#include <stdio.h>
#include <string.h>
#include <fstream>


struct Bill{
    int id = -1;
    char nameCustomer[20];
    char phoneNumber[20];
    float price;
};

void addNewBill(Bill bill[], int Size){
    int check; // Check that the user wants to continue typing or not
    for(int i=0; i<Size; i++){
        if(bill[i].id == -1){
            printf("Enter the bill's ID: ");
            scanf("%d",&bill[i].id);
            for(int j = 0; j<i; j++){
                if(bill[i].id == bill[j].id ){
                    printf("\nID already exists, please type again: ");
                    scanf("%d", &bill[i].id);
                }
            }
            fflush(stdin);// Clear counting memory
            printf("\nEnter the customer's name: ");
            gets(bill[i].nameCustomer) ;
            printf("\nEnter the customer's phone number: ");
            gets(bill[i].phoneNumber) ;
            printf("\nEnter the bill's total price:");
            scanf("%f",&bill[i].price); 
            printf("Do you want to countinue typing? If yes enter 1, to stop enter 0: ");
            scanf("%d", &check);
            if(check == 0) break; // Check that the user wants to continue typing or not
        }
    }
}
void deleteBill(Bill bill[], int Size){
    int id;
    printf("Enter the bill's ID wants to delete: ");
    scanf("%d",&id);
    for(int i=0; i< Size;i++){
        if(bill[i].id == id){
            for(int j = i; j<Size - 1;j++){
                strcpy(bill[j].nameCustomer,bill[j+1].nameCustomer);
                strcpy(bill[j].phoneNumber,bill[j+1].phoneNumber);
                bill[j].price = bill[j+1].price;
            }
            break;
        }
        if(bill[i].id == -1 || i==(Size -1)){
            bill[i].id = -1;
        }
    }
}
void updateBill(Bill bill[], int Size){
    printf("Enter the bill's ID wants to update: \n");
    int id,check = -1;
    scanf("%d",&id);
    for(int i=0; i< Size; i++){
        if(bill[i].id == id){
                fflush(stdin);
            printf("Enter the new bill's information");
            printf("\nEnter the customer's name: ");
            gets(bill[i].nameCustomer);
            printf("\nEnter the customer's phone number: ");
            gets(bill[i].phoneNumber);
            printf( "Enter the bill total price: ");
            scanf("%f",&bill[i].price);
            check = 1;
        }

    }
    if(check == -1){
        printf( "ID does not exist");
    }
}
void searchBill(Bill bill[], int Size){
    printf("Enter the bill's ID wants to search: ");
    int id, check = -1;
    scanf("%d",&id);
    for(int i=0;i<Size; i++){
        if(bill[i].id == id){
            printf( "\n===========================================================================================\n");
            printf("ID: %d\n",bill[i].id);
            printf("Customer's name: %s\n", bill[i].nameCustomer);
            printf("Phone number: %s\n", bill[i].phoneNumber);
            printf("Total price: %f\n",bill[i].price);
            printf("==================================================================================================\n");
             check = 1;
             break;
             }
    }
    if(check == -1){
        printf("ID does not exist");
    }
}
void displayBill(Bill bill[], int Size){
    printf("===========================================================================================\n");
    for(int i = 0; i< Size; i++){
        if(bill[i].id == -1) break;
        printf("ID: %d\n", bill[i].id);
            printf("Customer's name: %s\n", bill[i].nameCustomer);
            printf("Phone number: %s\n", bill[i].phoneNumber);
            printf("Total price: %f\n",bill[i].price);
    }
}
int main()
{
    int Size, choice;// Bill array size
    do {
    printf( "Enter the number of elements in the array: ");
    scanf("%d",&Size);
    if (Size<20) {
    printf( "\nThis is not enough enlements, please re-enter");
    }
    }
    while (Size<20);
     Bill bill[Size];
    // Enter the 1st to 20th database
    do{
       printf("\nMain funcions: ");
       printf( "\n1: Add new bill");
       printf ("\n2: Delete bill using ID");
       printf("\n3: Update bill using ID");
       printf("\n4: Search bill using ID");
       printf ("\n5: Ending project");
       printf( "\nEnter the number corresponding to the function to conduct: \n");
       scanf("%d",&choice);
       switch (choice){
    case 1:
        addNewBill(bill, Size);
        displayBill(bill,Size);
        printf("\n=========================================================================================\n");
        break;
    case 2:
        deleteBill(bill, Size);
        Size--;
        displayBill(bill,Size);
        printf("\n==========================================================================================\n");
        break;
        case 3:
        updateBill(bill,Size);
        displayBill(bill,Size);
        printf("\n==========================================================================================\n");
        break;
    case 4:
        searchBill(bill,Size);
        break;
    case 5: return 0;
    default:
        printf("Wrong number, please enter again");
        break;
       }
    }while(true);
}

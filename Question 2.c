#include<stdio.h>
#include<string.h>
 void customerInfo() {
 	char ch[50];
 	int n;
 	printf("Enter customer name :");
 	scanf("%s", ch);
 	printf("\nEnter customer CNIC number :");
 	scanf("%d", &n);
 	printf("\n=====Customer Information====\n");
 	printf("\nName : %s\n", ch);
 	printf("CNIC : %d\n",n);
 	printf("Customer Information saved!");
 }
  void displayInventory(int stock[], int price[], int size) {
  	printf("\n=====Inventory Details=====\n");
  	printf("\nProduct code\tQuantity\tprice\n");
  	for(int i=0; i<size; i++) {
  		printf("%03d\t\t%d\t\t%d\n", i+1, stock[i], price[i]);
	  }
  }
  void addToCart(int stock[], int price[], int cart[], int size) {
  	 int code, quantity;
  	  printf("Enter product code :");
  	  scanf("%d", &code);
  	  printf("Enter Quantity :");
  	  scanf("%d", &quantity);
  	  if(stock[code-1]>=quantity) {
  	  	 cart[code-1]+= quantity;
  	  	 stock[code-1]-=quantity;
  	  	 printf("Added to cart\n");
		}else {
			printf("story, not enough stock\n");
		}
  }
   float totalBill(int cart[], int price[], int size) {
   	 float total=0;
   	 for(int i=0; i<size; i++) {
   	 	total+=cart[i] * price[i];
		}
		return total;
   }
   float applyPromo(float total) {
   	char code[20];
   	printf("Enter promo code(or 'no'):");
   	scanf("%s", code);
   	if(strcmp(code, "Eid2025")==0) {
   		printf("Promo applied! 25% off\n");
   		total=total * 0.75;
	   }
	   return total;
   }
   void showInvoice(float total) {
   	printf("\n-----Invoice-----\n");
   	printf("Final Bill : %.2f\n", total);
   	printf("--------------\n");
   }
 int main(){
 	int stock[4]={50,10,20,8};
 	int price[4]={100,200,300,150};
 	int cart[4]={0};
 	int choice;
 	float bill;

     do{
     	printf("\n====Supermarket Menu====\n");
     	printf("1. Customer Info\n2. Display Inventory\n3. Add item to cart\n4.Display Total Bill\n");
     	printf("5.Exit\n");
     	printf("Enter choice :");
     	scanf("%d", &choice);
     	switch(choice) {
     		case 1 : customerInfo(); break;
     		case 2 : displayInventory(stock, price, 4); break;
     		case 3 : addToCart(stock, price,cart, 4); break;
     		case 4 : 
     		       bill=totalBill(cart, price, 4);
     		       bill = applyPromo(bill);
     		       showInvoice(bill);
     		       break;
     		case 5 : printf("Exiting system\n"); break;
			default : printf("Invalid choice\n");         
		 }
	 } while(choice!=5);
	return 0;
} 

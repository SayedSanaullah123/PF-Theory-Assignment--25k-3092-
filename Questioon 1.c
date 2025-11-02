#include<stdio.h>
  void isbn(int isbn[], int n); 
  void bookTitle(char bookTitle[100][50], int n); 
  void inputprices(float prices[], int n);
  void inputquantities(int quantity[], int n);
  void processSale(int isbns[], int quantities[], int n) {
  	 int searchIsbn , sold , found =0;
  	 printf("Enter ISBN to sell :");
  	 scanf("%d", &searchIsbn);
  	 
  	 for(int i=0; i<n; i++) {
  	 	if(isbns[i]==searchIsbn) {
  	 		found=1;
  	 		printf("Enter number of copies sold:");
  	 		scanf("%d", &sold);
  	 		if(quantities[i]>=sold) {
  	 			quantities[i]-=sold;
  	 			printf("Sale processed successfully!\n");
  	 			printf("Remaining stock: %d\n", quantities[i]);
			   }else {
			   	printf("Not enough stock avaible!\n");
			   }
			       break;
		   }
	   }
	   if(!found) {
	   	printf("Book not found!\n");
	   }
  }
  void lowStockReport(int isbns[], char titles[][50], float prices[], int quantities[], int n) {
  	 printf("\n=======Low Stock Report =====\n");
  	  int found=0;
  	   for(int i=0; i<n; i++) {
  	   	if(quantities[i]<5) {
  	   		printf("ISBN: %d | Title: %s | price: %.2f | quantities: %d\n", isbns[i],titles[i],prices[i],quantities[i]);
  	   		  found = 1;
        }
    }
    if (!found) {
        printf(" All books have sufficient stock.\n");
    }

   }
   
 int main(){
   int arr[100];
   char bookname[100][50];
   float price[100];
   int quantities[100];
   int n=0, choice;
   
   	printf("Enter number of books :");
   	scanf("%d", &n);
   	 
      getchar(); 
	  
   	    do {
   	    	printf("\n=====LIBERTY BOOKS MENU====\n");
   	    	printf("1. Add New books\n2. Process a sale\n3. Generate low stock Report\n");
   	    	printf("4. Exit\n");
			   printf("Enter your choice: ");
			   scanf("%d", &choice);
			   getchar();
			  switch(choice) {
			  	 case 1 : 
			  	     isbn(arr, n); 	
                     bookTitle(bookname, n);
   	                  inputprices(price, n);
   	                    inputquantities(quantities , n); 
						   break;  
				  case 2 : 
				            processSale(arr, quantities, n);
				                  break;
				  case 3 :
				  	      lowStockReport(arr, bookname, price, quantities, n);
				  	               break;
				  case 4 :
				  	   printf("Exitig program...\n");
				  	           break;
				  default :
				       printf("Invalid choice! please try again.\n");		   
			  }
				
			
		   } while(choice!=4);
		   
	return 0;	   
}
     
 void isbn(int isbn[], int n) { //Defination Function
 	 for(int i=0; i<n; i++){
 	 	printf("\nEnter international standard book number %d :", i+1);
 	 	scanf("%d", &isbn[i]);
	  }  
 }  
 //BookTitle Function
 void bookTitle(char bookTitle[100][50], int n) {
 	 for(int i=0; i<n; i++){
 	
 	 	printf("Enter title of Book %d :", i+1);
 	 	scanf("%[^\n]", bookTitle[i]);
		  getchar();
	  }
	  printf("\nYou entered these book titles:\n");
	  for(int i=0; i<n; i++) {
	  	printf("%d . %s\n", i + 1, bookTitle[i]);
	  } 
 }
    //Bookprice Function
    void inputprices(float prices[], int n) {
   	 for(int i=0; i<n; i++) {
   	 	printf("\nEnter price of book %d : ", i+1);
   	 	scanf("%f", &prices[i]);
		}   
	       
   } 
    void inputquantities(int quantity[], int n){
    	for(int i=0; i<n; i++) {
    		printf("Enter quantity for book %d : ", i+1);
    		scanf("%d", &quantity[i]); 
		}
	}

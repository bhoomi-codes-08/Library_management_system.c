#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Library Management System----------

struct book{

    char name[100];
    char author[100];
    int id;
    float price;
    int issued;
};

int main(){

    struct book b;
    int choice,searchid;
    int n = 0;
    int found;

    FILE *fptr;
    while(1){

        printf("\n----Library Management system----\n");
        printf("1.Add book\n");
        printf("2.display book\n");
        printf("3.Search by id\n");
        printf("4.issueed\n");
        printf("5.return\n");
        printf("6.Exist\n");
        printf("Enter choice\n");
        scanf("%d",&choice);

        if(choice == 1){

            fptr = fopen("Library.txt" , "a");
            printf("Enter name,Author,id,price : ");
            scanf("%99s %99s %d %f" , b.name,b.author,&b.id,&b.price);
            b.issued = 0;

            fprintf(fptr , "%s %s %d %f %d\n" , b.name,b.author,b.id,b.price,b.issued);
            printf("Book added successfully!\n");

            fclose(fptr);
        }

        else if(choice == 2){

            fptr = fopen("Library.txt","r");
            if(fptr == NULL){
                printf("Book not found!");
                continue;
            }

            while(fscanf(fptr,"%99s %99s %d %f %d",b.name,b.author,&b.id,&b.price,&b.issued) == 5){
                printf("Name: %s || Author: %s || ID: %d || price: %f || Status: %s\n",b.name,b.author,b.id,b.price,b.issued?"issued":
                "Available");

            }
            fclose(fptr);
        }

        else if(choice == 3){

            printf("Enter id to search : ");
            scanf("%d",&searchid);

            fptr =  fopen("Library.txt","r");

            if(fptr == NULL){
                printf("No book found!\n");
                continue;
            }
                found = 0;
            while(fscanf(fptr,"%99s %99s %d %f %d",b.name,b.author,&b.id,&b.price,&b.issued) == 5){
                if(b.id == searchid){
                    printf("Found !\n Name: %s || Author: %s || Id : %d || price : %f || Status : %s\n",b.name,b.author,b.id,b.price,
                        b.issued?"issued":"Available");
                    found = 1;
                    break;
                }
            }

            fclose(fptr);
            if(!found)printf("No book found!\n");
        }

        else if(choice == 4){

            printf("Enter id to issued:");
            scanf("%d",&searchid);

            FILE *temp = fopen("temp.txt","w");
            fptr = fopen("Library.txt","r");

            found = 0;
            while(fscanf(fptr,"%99s %99s %d %f %d",b.name,b.author,&b.id,&b.price,&b.issued) == 5){
                if(b.id ==  searchid && b.issued == 0){
                    b.issued = 1;
                    found = 1;
                    
                }
              fprintf(temp,"%s %s %d %f %d\n",b.name,b.author,b.id,b.price,b.issued);
                
            }

            fclose(fptr);
            fclose(temp);
            remove("Library.txt");
            rename("temp.txt","Library.txt");

            if(found)printf("Book has issued succesfully!");

            else{
            
            printf("Book has not issued!");

            }

                

        }


        else if(choice == 5){

            printf("Enter id to Return:");
            scanf("%d",&searchid);

            FILE *temp = fopen("temp.txt","w");
            fptr = fopen("Library.txt","r");
            found =  0;
            while(fscanf(fptr,"%99s %99s %d %f %d",b.name,b.author,&b.id,&b.price,&b.issued) == 5){
                if(b.id ==  searchid && b.issued == 1){
                    b.issued = 0;
                    found = 1;
                  
                }
                  fprintf(temp,"%s %s %d %f %d\n",b.name,b.author,b.id,b.price,b.issued);
                
            }
           
            fclose(fptr);
            fclose(temp);
            remove("Library.txt");
            rename("temp.txt","Library.txt");

            if(found)printf("Book has Return succesfully!");
            else{
            printf("Book has not Return!");
            }

        }

        else if(choice == 6){
            printf("....Exisiing.....\n");
            break;

        }


        else{
            printf("INVALID CHOICE");
        }

       
    }
     

    return 0;
    
}


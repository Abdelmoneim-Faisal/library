#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int counter=4;
struct library {
int id;
int quantity;
char name[150];
}books[6];
FILE* Library;
void Insert (){
    Library = fopen("books.txt","a");
    printf("Enter the id of the book : ");
    scanf("%d",&books[counter].id);
    printf("Enter the quantity of the book : ");
    scanf("%d",&books[counter].quantity);
    printf("Enter the name of the book : ");
    gets(books[counter].name);
    gets(books[counter].name);
    fprintf(Library,"\n%d\t",books[counter].id);
    fprintf(Library,"%d\t",books[counter].quantity);
    fprintf(Library,"%s",books[counter].name);
    fclose(Library);
    counter++;
}
void Delete (struct library n[],int counter_n){
        Library = fopen("books.txt","r");
       for(int i=0;i<counter;i++){
    fscanf(Library,"%d\t%d\t",&n[i].id,&n[i].quantity);
    fgets(n[i].name,16,Library);}
Library=fopen("books.txt","w");
    int key;
    printf("Enter the ID : ");
    scanf("%d",&key);
    for (int c=0;c<counter_n;c++)
    {
        if(n[c].id==key){continue;}
        fprintf(Library,"%d\t",n[c].id);
    fprintf(Library,"%d\t",n[c].quantity);
    fprintf(Library,"%s",n[c].name);
    }
    fclose(Library);
    counter--;
}
void SearchById (){
int id,i;
printf("Enter the ID : ");
scanf("%d",&id);
printf("\n");
for (i=0;i<counter;i++){
    if (books[i].id==id){
      printf("book : %s\nquantity : %d\n",books[i].name,books[i].quantity);
   return;
    }
}
if (i>=counter){
    printf("Book isn't found !");
}
while(!feof(Library)){
    SearchById();
}
}
void SearchByName(struct library arr[],int low,int high){
    int temp_id,temp_q,counterLoop,a;
    //char nameOf[150][150];
    char tempname[20];


    struct library temp;

    /* Magdy sort*/

    int l, k;

     for(l=1;l<=counter;l++)
	for(k=0;k<=counter-l;k++)
	  if(strcmp(arr[k].name,arr[k+1].name)>0)
	  {
            temp=arr[k];
            arr[k]=arr[k+1];
            arr[k+1]=temp;


	  }


    /*End Magdy sort*/


    /*STRAT SORT */
//    do
//    {
//        for (a=0;a<counter-1;a++)
//        {counterLoop=0;
//            if (arr[a].name[0]>arr[a+1].name[0])
//            {
//                temp_id=arr[a].id;
//                arr[a].id=arr[a+1].id;
//                arr[a+1].id=temp_id;
//                temp_q=arr[a].quantity;
//                arr[a].quantity=arr[a+1].quantity;
//                arr[a+1].quantity=temp_q;
//                strcpy(tempname,arr[a].name);
//                strcpy(arr[a].name,arr[a+1].name);
//                strcpy(arr[a+1].name,tempname);
//                counterLoop++;
//            }
//        }
//
//    }while (counterLoop>0);
    /* END SORT*/

    char newName[20];
    printf("Enter the name of the book : ");
gets(newName);
gets(newName);
    int middle;
    while (low <= high)
    {
        middle = (low+high)/2;
        if (strcmp(arr[middle].name,newName)==0){
                printf("ID : %d\nQuantity : %d\n",arr[middle].id,arr[middle].quantity);
        break;
        }
        else if (newName[0]<arr[middle].name[0]){
            high=middle-1;
        }
        else {
                low= middle+1;
        }
    }
    if (low > high){
            printf("Book isn't found !\n");
    }
}
void DisplaySorted (struct library arr[],int n){
int temp_id,temp_q,counterLoop,a;char tempName[20];
    struct library temp;

    /* Magdy sort*/
    int l, k;
    //int size=(sizeof (books)) / (sizeof (books[0]));;
    //printf("The size is %d",size);
     for(l=1;l<=counter;l++)
	for(k=0;k<=counter-l;k++)
	  {//if(arr[k].name=="") break;
	      if(strcmp(arr[k].name,arr[k+1].name)>0)
	  {
            temp=arr[k];
            arr[k]=arr[k+1];
            arr[k+1]=temp;

        for (a=0;a<counter;a++)
        printf("%d\t%d\t%s\n",arr[a].id,arr[a].quantity,arr[a].name);
        printf("\n*******\n");
	  }
	  }
/*for (a=0;a<counter;a++)
{
    printf("%d\t%d\t%s\n",arr[a].id,arr[a].quantity,arr[a].name);
}*/
}
void DisplayUnsorted (){
Library = fopen("books.txt","r");
    char Text[200];
    while(!feof(Library))
    {   fgets(Text,200,Library);
        printf("%s",Text);
    }
}
void loadBooks (struct library m[]){
counter=0;
Library = fopen("books.txt","r");
while (!feof(Library))
{
 fscanf(Library,"%d\t%d\t",&m[counter].id,&m[counter].quantity);
 fgets(m[counter].name,150,Library);
 counter++;
}
fclose(Library);
//printf("The counter is %d",counter);
}

int main()
{
    int menuno;
    char answer[3];
    if((Library = fopen("books.txt","r"))== NULL){
        printf("File couldn't been opened");
    }else {
      printf("Welcome To Our Library !\n");
    do {
    loadBooks(books);

   // printf("Name is: %s",books[6].name);
    printf("Enter 1 to insert a book(ID,Name,Quantity) \n");
    printf("Enter 2 to delete a book from the library by it's ID\n");
    printf("Enter 3 to search for a book by it's ID \n");
    printf("Enter 4 to search for a book by it's name \n");
    printf("Enter 5 to display all the books in the library sorted by their names\n");
    printf("Enter 6 to display all the books unsorted \n");
    scanf("%d",&menuno);
    printf("\n");
    switch(menuno){
        case 1:
            Insert();
        break;
       case 2:
           Delete(books,counter);
        break;
       case 3:
           SearchById();
        break;
    case 4:
        SearchByName(books,0,counter-1);
        break;
    case 5:
        DisplaySorted(books,6);
        break;
    case 6:
        DisplayUnsorted();
        break;
    default:
        printf("Wrong operation !\n");
    }
    printf("\n");
    printf("\nDo you want to perform any additional operation ?(Enter yes or no .)\n");
    scanf("%s",answer);
    printf("\n");
    for (int i=0;answer[i]!='\0';i++){
            if(answer[i]>= 'a'&&answer[i]<= 'z') {
         answer[i] = answer[i] - 32;
      }
    }
    }
    while (answer[0]=='Y'&&answer[1]=='E'&&answer[2]=='S');
    fclose(Library);
    }
    return 0;
}

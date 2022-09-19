#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <dos.h>
#include <string.h>

void menu(void);
void password(void);
void datafun(void);
void searchfun(void);
void listfun(void);
void updatefun(void);

int main(){
    password();
    getch();
}


void datafun(){
    system("cls");
    FILE *fptr;
    char ID[100];
    char name[100];
    char amount[100];
    char age[100];
    char address[100];

    fptr=fopen("user.txt","ab+");
    if(fptr==NULL){
        printf("There is no file.");
    }
    else{
        printf("ID :  \t");
        gets(ID);
        printf("Name :  \t");
        gets(name);
        printf("Amount :  \t");
        gets(amount);
        printf("Age :  \t");
        gets(age);
        printf("Address :  \t");
        gets(address);
        fprintf(fptr, "%s %s %s %s %s" ,ID,name,amount,age,address);
    }
    fclose(fptr);
    system("cls");
    char ch;
    printf("Press y for add new data.");
    Sleep(1000);
    fflush(stdin);
    while((ch=getch())=='y'){
        menu();
    }


}


void searchfun(){
    FILE*fptr;
    int flag=0;
    int res;
    char ID[100];
    char name[100];
    char amount[100];
    char age[100];
    char address[100];
    char name1[100];
    system("cls");
    fflush(stdin);
    printf("Enter the name that you wanna search.");
    gets(name1);
    fptr=fopen("user.txt","r");

    while(fscanf(fptr,"%s %s %s %s %s \n",ID, name,amount,age,address)!=EOF){
        res=strcmp(name,name1);
        if(res==0){
            printf("user found");
            printf("ID: \t%s" ,ID);
            printf("Name: \t%s",name);
            printf("Amount: \t%s", amount);
            printf("Age: \t%s", age);
            printf("Address: \t%s", address);
            flag=1;
            Sleep(1000);
            printf("Press y for go back menu.");
        while(getch()=='y'){
            menu();
        }
        }
    }
    if(flag==0){
        system("cls");
        printf("No record");;
        printf("Press a to enter user again or double y to open menu.");
        if(getch()=='a'){
            system("cls");
            searchfun();
        }
}
    fclose(fptr);

}

void listfun(){
    FILE*fptr;
    char ID[100];
    char name[100];
    char amount[100];
    char age[100];
    char address[100];
    int f;
    fptr=fopen("user.txt","r");
    system("cls");
    while(fscanf(fptr,"%s %s %s %s %s", ID,name,amount,age,address)!=EOF){

            printf("ID: \t%s" ,ID);
            printf("Name: \t%s",name);
            printf("Amount: \t%s", amount);
            printf("Age: \t%s", age);
            printf("Address: \t%s", address);
             f=1;
             printf("\n\n");
    }
    Sleep(1000);
    printf("Enter y for go back menu");
    while(getch()=='y'){
        menu();
    }
    fclose(fptr);
}

void updatefun(){
    FILE *fptr,*fptr1;
    char ID[100];
    char name[100];
    char amount[100];
    char age[100];
    char address[100];
    char ID1[100];
    char name1[100];
    char amount1[100];
    char age1[100];
    char address1[100];
    int res,f=0;
    fptr=fopen("user.txt", "r");
	fptr1=fopen("temp.txt","a");
	system("cls");

    printf("Enter the name: ");
    gets(name1);
    while(fscanf(fptr,"%s %s %s %s %s \n" ,ID,name,amount,age,address)!=EOF){
       res=strcmp(name,name1);
       if(res==0)
       {
           f=1;
           printf("Enter new ID:");
           scanf("%s", ID1);
           printf("Enter new name:");
           scanf("%s" , name1);
           printf("Enter new amount:");
           scanf("%s", amount1);
           printf("Enter new age:");
           scanf("%s", age1);
           printf("Enter new address:");
           scanf("%s", address1);
           fprintf(fptr1, "%s %s %s %s %s \n",name,ID1,amount1,age1,address1);

       }else{
       fprintf(fptr1,"%s %s %s %s %s \n",name,ID,amount,age,address);
    }

}
if(f==0){
    printf("User not found");
}
    fclose(fptr);
    fclose(fptr1);
    fptr=fopen("user.txt","w");
    fclose(fptr);
    fptr=fopen("user.txt","a");
    fptr1=fopen("temp.txt","r");
    while(fscanf(fptr1," %s %s %s %s %s\n", ID,name,amount,age,address)!=EOF){
        fprintf(fptr," %s %s %s %s %s\n", ID,name,amount,age,address);

}
    fclose(fptr);
    fclose(fptr1);
    fptr1=fopen("temp.txt","w");
    fclose(fptr1);
    printf("\n Press y for menu");
    fflush(stdin);
    if(getch()=='y'){
    menu();
}

}

void password(void){
	char passwords[20]={"123"};
	int j;
	int z;
	char name[40]="WELCOME";
	z=strlen(name);
	for(j=0;j<=16;j++){
		Sleep(50);
		printf("\xDB");
	}
	for(j=0;j<=z;j++){
		Sleep(60);
		printf(" %c",name[j]);
	}
	for(j=0;j<=16;j++){
		Sleep(50);
		printf("\xDB");
	}
	gotoxy(30,4);
	printf("Password:");
	char ch,pass[20];
	char w='*';
	int i=0;
	while(ch!=13){
		ch=getch();
		if(ch!=13 && ch!=8){
			printf("%c",w);
			pass[i]=ch;
			i++;
		}
			}
	pass[i]='\0';
	if(strcmp(pass,passwords)==0){
		gotoxy(30,6);
		printf("CORRECT PASSWORD.");
		Sleep(1000);
		menu();
	}
	else{
		gotoxy(30,6);
		printf("You entered the wrong password.");
		Sleep(700);
		system("cls");
		password();
}

}



void menu(){
    syste("cls");
    printf("1.Insert Data");
    printf("2.Search");
    printf("3.List");
    printf("4.Update");

    switch(getch()){
    case '1':
        datafun();
        break;
    case'2':
        searchfun();
        break;
    case'3':
        listfun();
        break;
    case'4':
        updatefun();
        break;

    default:
        system("cls");
        printf("Invalid Enter");
        getch();




    }



}



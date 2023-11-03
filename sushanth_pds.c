
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>
#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"


// global constant declarations   (not to use semicolons)
#define ENTER 13
#define TAB 9
#define BKSP 8

// defining usefull functions
void password(void);
void menu(void);
void userPanel(void);
void bookPanel(void);
void endScreen(void);

// defining user functions 
void addUser(void);
void listUser(void);
void deleteUser(void);

// defining book Functions 
void addBook(void);
void listBook(void);
void deleteBook(void);

// calling password function to verify password 
void main(void){
    password();
}
 
    int passTerminator = 1;
    int bookStock = 0;
    char rentName[255], bookName[255];



// Password: "maars"...password function code
void password(){

    system("cls"); /* it clears the screen */
    fflush(stdin);

    char pwd[255];
    char code[255] = {"maars"};
    int i = 0;
	char ch;

    printf( ANSI_COLOR_BLUE"::::::::::::::::::::::::::\n");
    printf(ANSI_COLOR_MAGENTA"::: LOGIN YOUR DETAILS :::\n");
    printf(ANSI_COLOR_BLUE"::::::::::::::::::::::::::\n\n");

	printf(ANSI_COLOR_GREEN"ENTER YOUR PASSWORD AND CLICK ENTER \n");
	printf(ANSI_COLOR_YELLOW"PASSWORD:\t");

	while(1)
    {

		ch = getch(); 

		if(ch == ENTER || ch == TAB)
        {
			pwd[i] = '\0';
			break;
		}
        else if(ch == BKSP)
        {
			if(i > 0)
            {
				i--;
				printf("\b \b"); // for backspace 
				
			}
		}
        else
        {
			pwd[i++] = ch;
			printf("* \b");	// to replace password character with * 
		}
	}

    fflush(stdin);

    
    if(strcmp(code, pwd) == 0)         /*VERIFYING THE PASSWORD*/
    {
        printf("\nCorrect Password!");
        Sleep(2000);  // delays by 2000 milli seconds or 2 seconds , present in unistd.h header file 
        menu();
    }
    else
    {
        printf("\nInvaild Password!");
        (passTerminator == 5) ? exit(0) : passTerminator++;   //entering wrong pasword 5 times consecuitively results in termination of programme
        //exit(0) will exit the programme if you enter the password wrong more than 5 times straight , and is present in stdlib header file 
        
		Sleep(2000);// delays by 2000 milli seconds or 2 seconds , present in unistd.h header file 
        password();
    }
}

// menu function code block 
void menu(){
    
    system("cls"); //clears the screen 
    fflush(stdin);//claers the buffer

    int number;

    printf(ANSI_COLOR_BLUE":::::::::::::::::::::::::::::::::::\n");
    printf(ANSI_COLOR_MAGENTA":::: LIBRARY MANAGEMENT SYSTEM :::: \n");
    printf(ANSI_COLOR_BLUE":::::::::::::::::::::::::::::::::::\n\n");
    printf(ANSI_COLOR_CYAN"> 1. USER ADMINISTRATION DASHBOARD \n");
    printf(ANSI_COLOR_CYAN"> 2. LIBRARY INVENTORY CONTROL SYSTEM \n\n");
    printf(ANSI_COLOR_GREEN"> ENTER YOUR CHOICE AND PRESS ENETR \n");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
    {
        case 1:
            userPanel();
            break;
        case 2:
            bookPanel();
            break;
        default:
            printf("\n>>> Invaild Input! <<<");
            Sleep(2000);
            menu();
    }
}

// user administration dashboard codeblock


void userPanel(){

    system("cls");
    fflush(stdin);

    int number;

    printf(ANSI_COLOR_BLUE":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf(ANSI_COLOR_MAGENTA"::: LIBRARY RESOURCE MANAGEMENT PLATFORM - USER ADMINISTRATION DASHBOARD  ::: \n");
    printf(ANSI_COLOR_BLUE":::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    printf(ANSI_COLOR_YELLOW"> 1. Add User \n");
    printf(ANSI_COLOR_YELLOW"> 2. List User \n");
    
    printf(ANSI_COLOR_YELLOW"> 3. Delete User \n");
    printf(ANSI_COLOR_YELLOW"> 4. Open Main Menu \n");
    printf(ANSI_COLOR_YELLOW"> 5. Close the Program... \n\n");

    printf(ANSI_COLOR_RED">> ENTER YOUR CHOICE: ");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
    {
        case 1:
            addUser();
            break;
    

        case 2:
            listUser();
            break;
        
        
        case 3:
            deleteUser();
            break;
        case 4:
            menu();
            break;
        case 5:
            endScreen();
            break;
        default:
            printf(ANSI_COLOR_RED"\nINVALID INPUT LOL REDIRECTING TO THE MAIN DASHBOARD\n");
            Sleep(2000);
            userPanel();
    }
}

/* LIBRARY INVENTORY CONTROL SYSTEM CODEBLOCK */


void bookPanel(){

    system("cls");
    fflush(stdin);

    int number;

    printf(ANSI_COLOR_BLUE"::::::::::::::::::::::::::::::::::::::::::::::::\n");
    printf(ANSI_COLOR_MAGENTA">>> LIBRARY INVENTORY CONTROL SYSTEM<<< \n");
    printf(ANSI_COLOR_BLUE"::::::::::::::::::::::::::::::::::::::::::::::::\n\n");
    printf(ANSI_COLOR_YELLOW"> 1. Add Book \n");
    printf(ANSI_COLOR_YELLOW"> 2. List Book \n");
    printf(ANSI_COLOR_YELLOW"> 3. Delete Book \n");
    printf(ANSI_COLOR_YELLOW"> 4. Open Main Menu \n");
    printf(ANSI_COLOR_YELLOW"> 5. Close the Program... \n");

    printf(ANSI_COLOR_GREEN"\nENTER YOUR CHOICE AND CLICK ENTER : ");
    scanf("%d",&number);

    fflush(stdin);

    switch(number)
    {
        case 1:
            addBook();
            break;
    
        case 2:
            listBook();
            break;
        case 3:
            deleteBook();
            break;
        case 4:
            menu();
            break;
        case 5:
            endScreen();
            break;
        default:
            printf(ANSI_COLOR_RED"Invaild Input!");
            Sleep(2000);
            bookPanel();
    }
}



// FINAL END SCREEN 
void endScreen(){

    system("cls");
    fflush(stdin);

    printf(ANSI_COLOR_GREEN":::::::::::::::::::::::::::::::::::::::::::::::::::\n");
    
    
    printf(ANSI_COLOR_CYAN">>> ");
    printf("  MAKERS : ");
    printf(ANSI_COLOR_RED"M ");
    printf(ANSI_COLOR_BLUE"A ");
    printf(ANSI_COLOR_YELLOW"A ");
    printf(ANSI_COLOR_GREEN"R ");
    printf(ANSI_COLOR_MAGENTA"S ");
    printf(ANSI_COLOR_CYAN"  >>");
    printf(ANSI_COLOR_RED"\nMusham_sushanth\n");
    printf(ANSI_COLOR_BLUE"Anand\n");
    printf(ANSI_COLOR_YELLOW"Anjali\n");
    printf(ANSI_COLOR_GREEN"Rahuladitya\n");
    printf(ANSI_COLOR_MAGENTA"Harshita");
    
    
    
    
    printf(ANSI_COLOR_GREEN"\n:::::::::::::::::::::::::::::::::::::::::::::::::::\n\n");

   
    printf("ENTER ANY KEY TO GO EXIT PROGRAM\n");
    getchar();
    exit(0); /*exits the program*/
}


//below are functions for user panel 
void addUser(){
    
label1:  /*dividing the entire code into groups(labels)*/
    
    system("cls");
    fflush(stdin);

    char fname[255], lname[255]; 
    char gender;
    double sid, phone, balance;   //double has 8 bytes storage 

    FILE *pF = fopen("user_Records.txt", "ab+");

    if(pF != NULL)
    {
        printf(ANSI_COLOR_YELLOW"Enter the First Name: ");
        gets(fname) ;

        printf(ANSI_COLOR_YELLOW"Enter the Last Name: ");
        gets(lname);

        printf(ANSI_COLOR_YELLOW"Enter Gender [M/F]: ");
        scanf("%c",&gender);

        printf(ANSI_COLOR_YELLOW"Enter Student ID: ");
        scanf("%lf",&sid);
         

         fflush(stdin);


        printf(ANSI_COLOR_YELLOW"Enter Phone Number: ");
        scanf("%lf",&phone);

        fprintf(pF, "%s;%s;%c;%.0lf;%.0lf \n", fname, lname, gender, sid, phone);

        printf(ANSI_COLOR_GREEN"\n  ::: NEW USER ADDED SUCCESSFULLY ::: \n");

    }
    else
    {
        printf(ANSI_COLOR_RED"UNEXPECTED ERROR OCCURED\n");
    }

    fclose(pF); 

    fflush(stdin);

    

    char input;
    printf(ANSI_COLOR_CYAN"\n DO YOU WISH TO ADD MORE USERS [Y/N]: ");
    scanf("%c",&input);

    if(input == 'Y' || input=='y')
    {
        goto label1; /*it goes to that block of code,it is present in */
    }
    else if(input=='N' || input=='n')
    {
        printf(ANSI_COLOR_CYAN"\n DIRECTING BACK TO USER ADMINISTRATION DASHBOARD");
        Sleep(2000); /*it waits 2000 milli seconds before going back to user panel*/
        userPanel();
    }
    else
    {
        printf(ANSI_COLOR_RED"\nWRONG ENTRY DIRECTING BACK TO USER ADMINISTRATION DASHBOARD ");
        Sleep(2000);/*delays by 2000 milli seconds*/
        userPanel();
    }
}

// Lists all the user records from user_Records.txt file which we saved in the pc 
void listUser(){
    
    system("cls");
    fflush(stdin);
    
    FILE *pF = fopen("user_Records.txt", "r");

    char fname[255], lname[255], gender[5];
    double sid, phone;
    int counter=0;

    printf(ANSI_COLOR_MAGENTA"::::::::::::::::::::::::::::::::::\n");
    printf(ANSI_COLOR_BLUE"        ::: USERS DATA ::: \n");
    printf(ANSI_COLOR_MAGENTA"::::::::::::::::::::::::::::::::::\n\n");
    
    while(fscanf(pF, "%[^;];%[^;];%[^;];%lf;%lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {  
       strcat(fname, " ");
       strcat(fname, lname);  /*fname=fname+" " + lname*/
       

        printf(ANSI_COLOR_YELLOW":::::::::::::::::::::::::::::::\n");
        printf(ANSI_COLOR_GREEN"> Full Name: %s \n", fname);
        printf(ANSI_COLOR_GREEN"> Last Name: %s \n", lname); 
        printf(ANSI_COLOR_GREEN"> Gender: %s \n", gender);
        printf(ANSI_COLOR_GREEN"> Student-ID: %.0lf \n", sid);
        printf(ANSI_COLOR_GREEN"> Phone No.: %.0lf \n", phone);
        printf(ANSI_COLOR_YELLOW"::::::::::::::::::::::::::::::::\n");

        counter++; 
    }

    fclose(pF);

    if(counter == 0)
    {
        printf(ANSI_COLOR_RESET":::::::::::::::::::::::::::::::::::::\n");
        printf(ANSI_COLOR_RED":::>>> USER NOT FOUND...\n");    /*if he was found then counter value would have been 1*/
        printf(ANSI_COLOR_RESET":::::::::::::::::::::::::::::::::::::\n\n");
    }

    printf(ANSI_COLOR_RESET"PRESS ANY BUTTON TO GO BACK TO USER ADMINISTRATION DASHBOARD.\n");
    getch();
    userPanel();
}


// deletes the user information from user_Records.txt file 
void deleteUser(){

    system("cls");
    fflush(stdin);

    char fname[255], lname[255], gender[5];
    char fname1[255], lname1[255], gender1[5];
    double sid, sid1, phone, phone1;

    int compare, flag=0;

    char find[255];
    printf(ANSI_COLOR_GREEN"Enter the first name of the person you want to delete the detail: ");
    gets(find);

    fflush(stdin);

    FILE *pF = fopen("user_Records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");

    while(fscanf(pF, "%[^;];%[^;];%[^;];%lf;%lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        
        compare = strcmp(find, fname);
        if(compare == 0)
        {
            printf(ANSI_COLOR_BLUE"\n:::::::::::::::::::::::::::\n");   
            printf(ANSI_COLOR_MAGENTA"    ::: USER DELETED ::: \n"); /*somehow this code is deleting the user details*/ 
            printf(ANSI_COLOR_BLUE"::::::::::::::::::::::::::::\n\n");
            printf(ANSI_COLOR_RESET"GOING BACK TO USER DASHBOARD...");


            flag = 1; /*we are confirming that this code is executed already*/
        }
        else
        {
            fprintf(pT, "%s;%s;%s;%.0lf;%.0lf \n",fname, lname, gender, sid, phone);
        }
    }

    fclose(pF);
    fclose(pT);

    fflush(stdin);

    pF = fopen("user_Records.txt", "w");
    fclose(pF);

    if(flag == 0)
    {
        printf(ANSI_COLOR_CYAN"\n\n:::::::::::::::::::::::::::\n");
        printf(ANSI_COLOR_RED":::  USER NOT FOUND   :::\n");
        printf(ANSI_COLOR_CYAN":::::::::::::::::::::::::::::::\n\n");
        printf(ANSI_COLOR_RED"GOING BACK TO USER PANEL...");
    }

    pF = fopen("user_Records.txt", "a");
    pT = fopen("temporary.txt", "r");

    while(fscanf(pT, "%[^;];%[^;];%[^;];%lf;%lf \n", fname, lname, gender, &sid, &phone) != EOF)
    {
        fprintf(pF, "%s;%s;%s;%.0lf;%.0lf \n", fname, lname, gender, sid, phone);
    }

    fclose(pF);
    fclose(pT);

    pT = fopen("temporary.txt", "w");
    fclose(pT);

    fflush(stdin);

    Sleep(2000);
    userPanel();
}



/*LIBRARY INVENTORY CONTROL SYSTEM sub functions code*/
void addBook(){

label3:

    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double bookid, quantity;

    FILE *pF = fopen("book_Records.txt", "ab+");

    if(pF != NULL) /*basically it returns null if some error has occured(the pointer will not point to anything)*/
    {
        printf(ANSI_COLOR_YELLOW"ENTER BOOK NAME: ");
        gets(name);

        printf(ANSI_COLOR_YELLOW"ENTER BOOK AUTHOR: ");
        gets(author);

        printf(ANSI_COLOR_YELLOW"ENTER BOOK PUBLISHER: ");
        gets(publisher);

        fflush(stdin); /*we are clearing the buffer*/

        printf(ANSI_COLOR_YELLOW"ENTER BOOK ID: ");
        scanf("%lf",&bookid);  

        printf(ANSI_COLOR_YELLOW"ENTER BOOK QUANTITY: ");
        scanf("%lf",&quantity);

        fprintf(pF, "%s;%s;%s;%.0lf;%.0lf \n", name, author, publisher, bookid, quantity);
     
        printf(ANSI_COLOR_GREEN"\n::: BOOK ADDED SUCCESSFULLY ::: \n");
    }
    else
    {
        printf(ANSI_COLOR_RED"SOME UNEXPECTED ERROR OCCURED\n");
    }

    fclose(pF); 

    fflush(stdin);

    char input;
    printf(ANSI_COLOR_MAGENTA"\nDO YOU WANT TO ADD MORE BOOKS [Y/N]: ");
    scanf("%c",&input);

    if(input == 'y' || input=='Y')
    {
        goto label3; /*again going back to add book code to add more books*/
    }
    else if(input=='n' || input=='N')
    {
          printf(ANSI_COLOR_RESET"\n GOING BACK TO LIBRARY INVENTORY CONTROL SYSTEM....");

        Sleep(2000);
        bookPanel();
    }
    else
    {
        printf(ANSI_COLOR_RESET"\nINVALID INPUT REDIRECTING BACK TO  LIBRARY INVENTORY CONTROL SYSTEM");
        Sleep(2000);
        bookPanel();
    }
}



/*list book code */


void listBook(){

    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double quantity, bookid;
    int counter=0;

    FILE *pF = fopen("book_Records.txt", "r");

    printf(ANSI_COLOR_MAGENTA":::::::::::::::::::::::::::::::\n");
    printf(ANSI_COLOR_BLUE"::: List of Books Record ::: \n");
    printf(ANSI_COLOR_MAGENTA":::::::::::::::::::::::::::::::\n\n");

    while(fscanf(pF, "%[^;];%[^;];%[^;];%lf;%lf \n", name, author, publisher, &bookid, &quantity) != EOF) /*eof = end of file..if we dont get this erro rthen we proceed */
    {
        printf(ANSI_COLOR_GREEN"::::::::::::::::::::::::::::::::\n");
        printf(ANSI_COLOR_RESET"::>> BOOK NAME :  %s \n", name);
        printf(ANSI_COLOR_RESET"::>> AUTHOR    : %s \n", author);
        printf(ANSI_COLOR_RESET"::>> PUBLISHER : %s\n", publisher);
        printf(ANSI_COLOR_RESET"::>> BOOK ID   : %.0lf \n", bookid);
        printf(ANSI_COLOR_RESET"::>> VOLUME    : %.0lf \n", quantity);
        printf(ANSI_COLOR_GREEN"::::::::::::::::::::::::::::::::\n\n\n");+
        counter++;
    }

    fclose(pF);

    if(counter == 0)
    {
        printf(ANSI_COLOR_CYAN":::::::::::::::::::::::::::::::::::::\n");
        printf(ANSI_COLOR_CYAN":::::::::::::::::::::::::::::::::::::\n");
        printf(ANSI_COLOR_RED"        :::NO BOOKS FOUND ...\n");
        printf(ANSI_COLOR_CYAN":::::::::::::::::::::::::::::::::::::\n\n");
    }

    printf(ANSI_COLOR_RESET"ENTER ANY BUTTON TO GO TO LIBRARY INVENTORY CONTROL SYSTEM\n");
    getch();
    bookPanel();
}

/*deleting book code */
void deleteBook(){

    system("cls");
    fflush(stdin);

    char name[255], author[255], publisher[255];
    double bookid, quantity;

    char name1[255], author1[255], publisher1[255];
    double bookid1, quantity1;

    int flag=0;
    int compare;

    char find[255];
    printf(ANSI_COLOR_RED"ENTER THE NAME OF THE BOOK YOU WANT TO DELETE: ");
    gets(find);

    fflush(stdin);

    FILE *pF = fopen("book_Records.txt", "r");
    FILE *pT = fopen("temporary.txt", "a");

    while(fscanf(pF, "%[^;];%[^;];%[^;];%lf;%lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        compare = strcmp(find, name);

        if(compare == 0)
        {
            printf(ANSI_COLOR_RESET"\n:::::::::::::::::::::::::::::::::::::::::::::\n");
            printf(ANSI_COLOR_GREEN":::>> Record Deleted <<:::\n");
            printf(ANSI_COLOR_RESET":::::::::::::::::::::::::::::::::::::::::::::::\n\n");
            printf(ANSI_COLOR_GREEN"DIRECTING BACK TO LIBRARY INVENTORY CONTROL SYSTEM...");

            flag = 1;
        }
        else
        {
            fprintf(pT, "%s;%s;%s;%.0lf;%.0lf \n", name, author, publisher, bookid, quantity);
        }
    }

    fclose(pF);
    fclose(pT);
 
    fflush(stdin); 

    pF = fopen("book_Records.txt", "w");
    fclose(pF);

    if(flag == 0)
    {
        printf(ANSI_COLOR_CYAN"\n\n:::::::::::::::::::::::::::\n");
        printf(ANSI_COLOR_RED"::>> NO BOOK FOUND <<::\n");
        printf(ANSI_COLOR_CYAN":::::::::::::::::::::::::::::::\n\n");
        printf(ANSI_COLOR_GREEN"REDIRECTING TO LIBRARY INVENTORY CONTROL SYSTEM...");
    }

    pF = fopen("book_Records.txt", "a");
    pT = fopen("temporary.txt", "r");

    while(fscanf(pT, "%[^;];%[^;];%[^;];%lf;%lf \n", name, author, publisher, &bookid, &quantity) != EOF)
    {
        fprintf(pF, "%s;%s;%s;%.0lf;%.0lf \n", name, author, publisher, bookid, quantity);
    }

    fclose(pF);
    fclose(pT);

    pT = fopen("temporary.txt", "w");
    fclose(pT);

    Sleep(2000);
    bookPanel();

}




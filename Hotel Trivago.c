// ADMIN LOGIN DETAILS, Username: admin, Password: pass
// CUSTOMER LOGIN DETAILS, Username: user, Password: pass

#include<stdio.h>
#include<conio.h>
#include<ctype.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

void add();
void list();
void delete1();
void search();
void usermain();
void adminmain();
void userlogin();
void adminlogin();
int isPhoneNumberValid(const char *phoneNumber);
int isEmailValid(const char *email);
int isInteger(const char *str);
int isDateValid(const char *date);

struct CustomerDetails  //STRUCTURE DECLARATION
{
	char roomnumber[10];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];
	char email[20];
	char period[10];
	char arrivaldate[10];
}s;  //An instance of the structure is declared with the name s, which will be used to store customer details

int main()  // MAIN FUNCTION
{
    char option;
    printf("\n");
    printf("   ***********************  |WELCOME TO HOTEL TRIVAGO|  ************************ \n");
    printf("\n");
    printf("\n--------------------------");
    printf(" \n Enter 1 - ADMIN LOGIN");
    printf("\n--------------------------");
    printf(" \n Enter 2 - CUSTOMER LOGIN");
    printf("\n--------------------------");
    printf("\n");
    printf(" Enter your Option:");
    scanf("%d", &option);
    if(option==1)
        adminmain();
    else if(option==2)
        usermain();
    else
        printf("\nInvalid Input\nPlease choose 1 or 2\n***** THANK YOU *****\n");
        exit(0);
}

void adminlogin()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="admin";
    char pass[10]="pass";  //The entered username and password are compared with predefined values admin and pass
    do
{
	system("cls");

    printf(" ----- LOGIN HOTEL TRIVAGO ----- \n");
    printf(" \n ENTER USERNAME:");
	scanf("%s", &uname);
	printf(" \n ENTER PASSWORD:");
	while(i<10)  //User is prompted to enter their username and password
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
	printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL");
	break;  //If the login is successful username and password match, a success message is displayed
	}
	else
	{
		printf("\n\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		getch();  //If login fails, an unsuccessful message is displayed, and the a value is incremented
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\n\nSorry you have entered the wrong username and password for four times!!!");
		getch();
		}
		system("cls");  //If the user fails to login four times, a message is displayed, and the loop terminates
}

void userlogin()
{
	int a=0,i=0;
    char uname[10],c=' ';
    char pword[10],code[10];
    char user[10]="user";
    char pass[10]="pass";  //The entered username and password are compared with predefined values admin and pass
    do
{
	system("cls");

    printf(" ----- LOGIN HOTEL TRIVAGO ----- \n");
    printf(" \n ENTER USERNAME:");
	scanf("%s", &uname);
	printf(" \n ENTER PASSWORD:");
	while(i<10)  //User is prompted to enter their username and password
	{
	    pword[i]=getch();
	    c=pword[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	pword[i]='\0';
	i=0;
		if(strcmp(uname,user)==0 && strcmp(pword,pass)==0)
	{
	printf("  \n\n\n       WELCOME !!!! LOGIN IS SUCCESSFUL");
	break;  //If the login is successful username and password match, a success message is displayed
	}
	else
	{
		printf("\n\n        SORRY !!!!  LOGIN IS UNSUCESSFUL");
		a++;
		getch();  //If login fails, an unsuccessful message is displayed, and the a value is incremented
	}
}
	while(a<=2);
	if (a>2)
	{
		printf("\n\nSorry you have entered the wrong username and password for four times!!!");
		getch();
		}
		system("cls");  //If the user fails to login four times, a message is displayed, and the loop terminates
}

void adminmain(){  // MAIN FUNCTION FOR ADMIN
	int i=0;

	time_t t;
	time(&t);
	char customername;
	char choice;
    adminlogin();
    system("cls");  //Calls the login() function to initiate the login process and then clears the console screen
	while (1)  // INFINITE LOOP
	{
		system("cls");
		 for(i=0;i<80;i++)
		printf("-");  //A series of lines are printed to create a menu display with different options, The user is prompted to enter a choice
		printf("\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf(" \n Enter 1 - Book a room");
		printf("\n------------------------");
		printf(" \n Enter 2 - View Customer Record");
		printf("\n----------------------------------");
		printf(" \n Enter 3 - Delete Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 4 - Search Customer Record");
		printf("\n-----------------------------------");
		printf(" \n Enter 5 - Exit");
		printf("\n-----------------");
		printf("\n");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time:%s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");
        printf("\n Enter your choice for menu:");
		choice=getche();
		choice=toupper(choice);  //Gets a character input from the user using getche(), Then, the entered character is converted to uppercase
		switch(choice)  // SWITCH STATEMENT
		{
			case '1':
				add();break;
			case '2':
				list();break;
			case '3':
				delete1();break;
			case '4':
				search();break;
			case '5':
				system("cls");
				printf("\n\n\t   ***** THANK YOU *****");
				printf("\n\t FOR TRUSTING OUR SERVICE");
				exit(0);  //Exits the program
				break;
			default:
				system("cls");
				printf("\nIncorrect Input");
				printf("\nPress any key to continue");
				getch();
		}
	}
}

void usermain(){  // MAIN FUNCTION FOR CUSTOMER
	int i=0;

	time_t t;
	time(&t);
	char customername;
	char choice;
    userlogin();
    system("cls");  //Calls the login() function to initiate the login process and then clears the console screen
	while (1)  // INFINITE LOOP
	{
		system("cls");
		 for(i=0;i<80;i++)
		printf("-");  //A series of lines are printed to create a menu display with different options, The user is prompted to enter a choice
		printf("\n");
		printf("   ******************************  |MAIN MENU|  ***************************** \n");
		for(i=0;i<80;i++)
		printf("-");
		printf("\n");
		printf(" \n Enter 1 - Book a room");
		printf("\n------------------------");
		printf(" \n Enter 2 - View Customer Record");
		printf("\n----------------------------------");
		printf(" \n Enter 3 - Exit");
		printf("\n-----------------");
		printf("\n");
		printf("\n");
		for(i=0;i<80;i++)
		printf("-");
	    printf("\nCurrent date and time:%s",ctime(&t));
	    for(i=0;i<80;i++)
		printf("-");
		printf("\n Enter your choice for menu:");
		choice=getche();
		choice=toupper(choice);  //Gets a character input from the user using getche(), Then, the entered character is converted to uppercase
		switch(choice)  // SWITCH STATEMENT
		{
			case '1':
				add();break;
            case '2':
				list();break;
			case '3':
				system("cls");
				printf("\n\n\t   ***** THANK YOU *****");
				printf("\n\t FOR TRUSTING OUR SERVICE");
				exit(0);  //Exits the program
				break;
			default:
				system("cls");
				printf("\nIncorrect Input");
				printf("\nPress any key to continue");
				getch();
		}
	}
}

void add()
{
	FILE *f;
	char test;
	f=fopen("add.txt","a+");  //Opens the file named "add.txt" in "a+" i.e append and read mode. If the file doesn't exist, it will be created
	if(f==0)
	{   f=fopen("add.txt","w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!!");
		printf("\n Process completed press any key to continue!! ");
		getch();
	}
	while(1)  //The code enters an infinite loop using while (1) to continuously add customer details
	{
		system("cls");
		printf("Enter Customer Details:");
		printf("\n**************************");
		do {
        printf("\nEnter Room Number (integer): ");
        scanf("%s",s.roomnumber);
        if (!isInteger(s.roomnumber)) {
            printf("Invalid room number format. Please enter an integer.\n");
        }
        } while (!isInteger(s.roomnumber));
		fflush(stdin);
		printf("Enter Name: ");
		scanf("%s",s.name);
		printf("Enter Address: ");
		scanf("%s",s.address);
		do {
        printf("Enter Phone Number (10 digits): ");
        scanf("%s", s.phonenumber);
        if (!isPhoneNumberValid(s.phonenumber)) {
            printf("Invalid phone number format. Please enter a 10-digit integer.\n");
        }
        } while (!isPhoneNumberValid(s.phonenumber));
		printf("Enter Nationality: ");
		scanf("%s",s.nationality);
		do {
        printf("Enter Email (must contain '@'): ");
        scanf("%s", s.email);
        if (!isEmailValid(s.email)) {
            printf("Invalid email format. Please include '@' in the email.\n");
        }
        } while (!isEmailValid(s.email));
		do {
        printf("Enter Period (integer): ");
        scanf("%s", s.period);
        if (!isInteger(s.period)) {
            printf("Invalid period format. Please enter an integer.\n");
        }
        } while (!isInteger(s.period));
		do {
        printf("Enter Arrival Date (dd/mm/yyyy): ");
        scanf("%s", s.arrivaldate);
        if (!isDateValid(s.arrivaldate)) {
            printf("Invalid date format. Please enter a valid date in the format dd/mm/yyyy.\n");
        }
        } while (!isDateValid(s.arrivaldate));
		fwrite(&s,sizeof(s),1,f);   //The entered customer details are written to the file using fwrite()
		fflush(stdin);  //It is used to clear the input buffer
		printf("\n\n1 Room is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test=getche();
		if(test==27)  //If the user presses the Esc key (ASCII == 27 is Esc), the loop breaks
			break;
	}
	fclose(f);
}

// Function to check if a string is a valid integer
int isInteger(const char *str) {
    int len = strlen(str);
    for (int i = 0; i < len; i++) {
        if (!isdigit(str[i])) {
            return 0; // Not a valid integer
        }
    }
    return 1; // Valid integer
}

int isDateValid(const char *date) {  // Function to check if a date string is valid (dd/mm/yyyy)
    int day, month, year;
    if (sscanf(date, "%d/%d/%d", &day, &month, &year) != 3) {
        return 0; // Format doesn't match
    }

    if (year < 1000 || year > 9999 || month < 1 || month > 12 || day < 1 || day > 31) {
        return 0; // Out of range values
    }

    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {      // Additional validation for specific months with 30 or 31 days
        return 0;
    } else if (month == 2) { // February
        if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) { // Leap year
            if (day > 29) {
                return 0;
            }
        } else { // Non-leap year
            if (day > 28) {
                return 0;
            }
        }
    }

    return 1; // Valid date
}

int isPhoneNumberValid(const char *phoneNumber) {   // Function to validate phone number (10-digit integer)
    int len = strlen(phoneNumber);
    if (len != 10) {
        return 0; // Invalid length
    }

    for (int i = 0; i < len; i++) {
        if (!isdigit(phoneNumber[i])) {
            return 0; // Contains non-digit characters
        }
    }

    return 1; // Valid phone number
}

int isEmailValid(const char *email) {  // Function to validate email (contains '@')
    int len = strlen(email);
    int hasAtSymbol = 0;

    for (int i = 0; i < len; i++) {
        if (email[i] == '@') {
            hasAtSymbol = 1;
            break;
        }
    }

    return hasAtSymbol; // 1 if email contains '@', 0 otherwise
}

void list()
{
	FILE *f;
	int i;
	if((f=fopen("add.txt","r"))==NULL)  //Opens the file add.txt in read mode
		exit(0);
	system("cls");
	printf("ROOM    ");  //Print out column headers for different customer details
	printf("NAME\t ");
	printf("\t\tADDRESS ");
	printf("\tPHONENUMBER ");
	printf("\tNATIONALITY ");
	printf("\tEMAIL ");
	printf("\t\t\t  PERIOD ");
	printf("\t ARRIVALDATE \n");

	for(i=0;i<138;i++)  //A loop prints a line of hyphens to create a separator between headers and data
		printf("-");
	while(fread(&s,sizeof(s),1,f)==1)  //Another loop reads customer details from the file using fread() and prints them out in tabular format
	{

		printf("\n%s \t%s \t\t%s \t%s \t%s  \t%s  \t     %s  \t  %s",s.roomnumber, s.name , s.address , s.phonenumber ,s.nationality ,s.email,s.period,  s.arrivaldate);
	}
	printf("\n");
	for(i=0;i<138;i++)
		printf("-");

	fclose(f);
	getch();
}

void delete1()
{
	FILE *f,*t;  //Declares file pointers f and t, an integer i for flagging, and a character array roomnumber to store the room number for deletion
	int i=1;
	char roomnumber[20];
	if((t=fopen("temp.txt","w"))==NULL)  //Opens a temporary file named "temp.txt" for writing
	exit(0);
	if((f=fopen("add.txt","r"))==NULL)  //Opens the file "add.txt" for reading
	exit(0);
	system("cls");
	printf("Enter the Room Number of the hotel to be deleted from the database: \n");
	fflush(stdin);
	scanf("%s",roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0)  //A loop reads each customer record from the file and checks if the room number matches the one provided by the user. If it matches, the i flag is set to 0
		{       i=0;
			continue;
		}
		else
			fwrite(&s,sizeof(s),1,t);
	}
	if(i==1)  //This means the provided room number was not found in the records. In this case
	{
		printf("\n\n Records of Customer in this  Room number is not found!!");

		getch();
		fclose(f);
		fclose(t);
		main();
	}
	fclose(f);
	fclose(t);
	remove("add.txt");
	rename("temp.txt","add.txt");  //The temporary file "temp.txt" is renamed to "add.txt", effectively replacing the original file with the updated records.
	printf("\n\nThe Customer is successfully removed....");
	fclose(f);
	fclose(t);
	getch();
}

void search()
{
system("cls");
	FILE *f;
	char roomnumber[20];
	int flag=1;  //Declares a file pointer f, a character array roomnumber to store the room number for search, and an integer flag flag to indicate whether the customer was found
	f=fopen("add.txt","r+");  //Opens the file "add.txt" for both reading and writing
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Enter Room number of the customer to search its details: \n");  //The user is prompted to enter the room number of the customer they want to search
	scanf("%s", roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)  //If the flag remains 1, it means the provided room number was not found in the records
	{
		if(strcmp(s.roomnumber,roomnumber)==0){
			flag=0;
			printf("\n\tRecord Found\n ");
			printf("\nRoom Number:\t%s",s.roomnumber);
			printf("\nName:\t%s",s.name);
			printf("\nAddress:\t%s",s.address);
			printf("\nPhone number:\t%s",s.phonenumber);
			printf("\nNationality:\t%s",s.nationality);
			printf("\nEmail:\t%s",s.email);
			printf("\nPeriod:\t%s",s.period);
			printf("\nArrival date:\t%s",s.arrivaldate);
			flag=0;
			break;
		}
	}
	if(flag==1){
		printf("\n\tRequested Customer could not be found!");
	}
	getch();
	fclose(f);
}

          //****************************************************************************//
         //*******************DEPARTMENT INFORMATION SYSTEM **************************//
        //**************************************************************************//
       //*****************Coded by : MUHAMMAD HASHIM SHAFIQ***********************//
      //************************************************************************//
     //**********************CIIT/SP14-BCS-142/ISB****************************//
    //**********************************************************************//
   //**********************hashimshafiq0@gmail.com************************//
  //********************************************************************//


//************************************ HEADER FILES ***************************//

// list of header files
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>

//*******************************************************************************//

//*********************************** GLOBAL FILES *****************************//

// Global Variables or Files that can be accessed from anywhere in the program
FILE *fp,*ft,*ftt;

//*****************************************************************************//

//*************************** STUDENT STRUCTURE DEFINATION ********************//

struct student
{
	int std_id;
	char std_name[20];
	char std_fth_name[20];
	char std_class[5];
	float std_cgpa;
	char std_gender[7];
	int std_age;	
};
struct student std;

//*****************************************************************************//

//*********************** TEACHER STRUCTURE DEFINATION ***********************//

struct teacher
{
	int tch_id;
	char tch_name[20];
	char tch_fth_name[20];
	char tch_class[5];
	char tch_subject[10];
	char tch_quali[10];
};
struct teacher tch;

//***************************************************************************//

//******************************* FUNCTIONS DECLARATIONS **********************//
//******************************* MAIN FUNCTIONS ****************************//
void intro_main(void);  // Main Intro of software or project
void MaximizeWindow(void); // Maximizr the console screen
void gotoxy(int,int);  // change the location of the cursor on the screen
void loading(void);   // display loading bar on the screen
void t(void); // display current time
void password(void); // check the password to restrict
void main_menu(void); // Display main menu on the screen containing Teacher & Student choice
//**************************************************************************//

//****************************** STUDENT FUNCTIIONS ***********************//
void sub_menu_student(FILE *fp); // display the sub-menu for the student
int checkid_std(int); //check id of student
void add_std_info(FILE *fp); // get data from the function get_std_data and add student information in the file
void display_std(FILE *fp); // displaying student data 
void edit_std_info(FILE *fp); // Editing Student record
void del_std_info(FILE *fp); // delete student information from the record
void search_std_info(FILE *fp); // display search student information from a record
void search_std_name(FILE *fp); // search student information by name
void search_std_gender(FILE *fp); // search student information by gender
void search_std_class(FILE *fp); // search student information by class
void search_std_cgpa(FILE *fp);  // search student information by cgpa
void search_std_age(FILE *fp);  // search student information by age

//*************************************************************************//

//*************************** TEACHERS FUNCTIONS *************************//
void sub_menu_teacher(FILE *ftt); // display the sub-menu for the teacher
int checkid_tch(int); //check id of teacher
void add_tch_info(FILE *ftt); // get data from the function get_tch_data and add teacher information in the file
void display_tch(FILE *ftt); // displaying teacher data
void edit_tch_info(FILE *ftt); // Editing teacher record
void del_tch_info(FILE *ftt); // delete teacher information from the record
void search_tch_info(FILE *ftt); // display search teacher information from a record
void search_tch_name(FILE *ftt); // search teacher information by name
void search_tch_class(FILE *ftt); // search teacher information by class
void search_tch_subject(FILE *ftt); // search teacher information by subject
//**********************************************************************************//


//******************************** MAIN FUNCTION **********************************//

main()
{
	//MaximizeWindow();
	fp = fopen("record.dat","rb+");
	if(fp==NULL)
	{
		fp = fopen("record.dat","wb+");
		if(fp==NULL)
		{
			gotoxy(30,22);
			printf("Cannot Open or Create File!");
			getch();
			exit(0);
		}
	}
	ftt=fopen("recordt.dat","rb+");
	if(ftt==NULL)
	{
		ftt = fopen("recordt.dat","wb+");
		if(ftt==NULL)
		{
			gotoxy(30,22);
			printf("Cannot Open or Create File!");
			getch();
			exit(0);
		}
	}

	password();
}

//***********************************************************************************//

//******************************* DEFINATION OF GOTOXY FUNCTION ***********************//

void gotoxy(int x, int y)
{
	static HANDLE h = NULL; 
	if(!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y }; 
	SetConsoleCursorPosition(h,c);
}

//****************************************************************************************//

//******************************* DEFINATION OF MAXIMIZE WINDOWS  FUNCTION ***********************//

void MaximizeWindow()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD NewSBSize = GetLargestConsoleWindowSize(hOut);
    SMALL_RECT DisplayArea = {0, 0, 0, 0};
 	SetConsoleScreenBufferSize(hOut, NewSBSize);
	DisplayArea.Right = NewSBSize.X - 1;
    DisplayArea.Bottom = NewSBSize.Y - 1;
 	SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);
 }
 
 //******************************************************************************************//
 
//******************************* DEFINATION OF PASSWORD FUNCTION ***********************//

void password(void)
 {
 	char password[10]={"hashim"};
 	system("cls");
    char d[]="Password Protected";
    char ch,pass[10];
    int i=0,j;
    gotoxy(10,4);
    for(j=0;j<20;j++)
    {
    	printf("*");
    }
    for(j=0;j<strlen(d);j++)
    {
   		printf("%c",d[j]);
    }
   for(j=0;j<20;j++)
   {
   		printf("*");
   }
   gotoxy(10,10);
   gotoxy(15,7);
   printf("Enter Password:");
   while(ch!=13)
   {
		ch=getch();

		if(ch!=13 && ch!=8)
		{
			putch('*');
			pass[i] = ch;
			i++;
		}
   }
   pass[i] = '\0';
   if(strcmp(pass,password)==0)
   {
		gotoxy(30,15);
		system("color 0a");
		printf("Password Matched");
		getch();
		loading();
		getch();
   }
   else
   {
   		gotoxy(15,16);
	 	system("color 4");
	 	printf("\aWarning!! Incorrect Password");
	 	getch();
	 	system("cls");
	 	//main();
   }
 }
 
//**************************************************************************************//

//******************************* DEFINATION OF LOADING ANIMATION FUNCTION ***********************//

void loading()
{
	system("cls");
    int r,q;
    gotoxy(36,10);
    printf("Loading...");
    gotoxy(30,11);
    for(r=1;r<=20;r++)
	{
    	for(q=0;q<=10000000;q++);
    	printf("%c",177);
	}
    main_menu();
}

//**************************************************************************************//

//******************************* DEFINATION OF MAIN MENU FUNCTION ***********************//
 
void main_menu()
{
	char choice;
	while(1)
	{
		system("cls");
		gotoxy(55,1);
		t();
		gotoxy(18,4);
		printf("******** Departmental Information System ********");
		gotoxy(30,6);
		printf("1. Student Record");
		gotoxy(30,8);
		printf("2. Teacher Record");
		gotoxy(30,10);
		printf("3. Exit");
		gotoxy(30,12);
		printf("Your Choice ? ");
		//scanf("%d",&choice);
		choice = getche();
		fflush(stdin);
		switch(choice)
		{
			case '1':
				 sub_menu_student(fp);
				 break;
			case '2':
				 sub_menu_teacher(ftt);
				 break;
			case '3':
				//fclose(fp);
				//fclose(ftt);
				exit(0);
			default:
				 gotoxy(30,22);
				 printf("Enter Valid Choice");
				 getch();
		}
	}
}

//**************************************************************************************//

//******************************* DEFINATION OF SUB MENU STUDENT FUNCTION ***********************//

void sub_menu_student(FILE *fp)
{
	char choice;
	while(1)
	{
		system("cls");
		gotoxy(55,1);
		t();
		gotoxy(18,4);
		printf("***************** STUDENTS SECTION *****************");
		gotoxy(30,6);
		printf("1. Add Record");
		gotoxy(30,8);
		printf("2. Edit Record");
		gotoxy(30,10);
		printf("3. Display All Records");
		gotoxy(30,12);
		printf("4. Delete Record");
		gotoxy(30,14);
		printf("5. Search Record");
		gotoxy(30,16);
		printf("6. Back to Main Menu");
		gotoxy(30,18);
		printf("Your Choice ? ");
		choice = getche();
		fflush(stdin);
		switch(choice)
		{
			case '1':
				add_std_info(fp);
				break;
			case '2':
				edit_std_info(fp);
				break;
			case '3':
				display_std(fp);
				break;
			case '4':
				del_std_info(fp);
				break;
			case '5':
				search_std_info(fp);
			case '6':
				main_menu();
				break;
			default:
				gotoxy(30,22);
				printf("Enter Valid Choice\n\n");
				getch();
		}
	}
}

//**************************************************************************************//

//******************************* DEFINATION OF TIME AND DATE FUNCTION ***********************//

void t(void)
{
	time_t t;
	time(&t);
	printf("%s",ctime(&t));
}

//**************************************************************************************//

//******************************* DEFINATION OF CHECK ID FUNCTION ***********************//

int checkid_std(int id)  
{
	rewind(fp);
	while(fread(&std,sizeof(std),1,fp)==1)
		if(std.std_id==id)
			return 0;
	return 1;
}

//**************************************************************************************//

//******************************* DEFINATION OF ADD STUDENT INFO FUNCTION ***********************//

void add_std_info(FILE *fp)
{
	
	char choice;
	int r;
	int id=0;
		system("cls");
		gotoxy(18,4);
		printf("************* Enter Student Information *************");
		gotoxy(30,6);
		printf("Enter ID : ");
		scanf("%d",&id);
		if(checkid_std(id)==0)
		{
			gotoxy(30,22);
			printf("ID Already Exist !!!");
			getch();
			add_std_info(fp);
		}
		std.std_id = id;
		gotoxy(30,8);
		fflush(stdin);
		printf("Enter Name : ");
		gets(std.std_name);
		gotoxy(30,10);
		fflush(stdin);
		printf("Enter Father Name : ");
		gets(std.std_fth_name);
		fflush(stdin);
		gotoxy(30,12);
		printf("Enter Class : ");
		gets(std.std_class);
		fflush(stdin);
		gotoxy(30,14);
		printf("Enter Gender : ");
		gets(std.std_gender);
		fflush(stdin);
		gotoxy(30,16);
		printf("Enter CGPA : ");
		scanf("%f",&std.std_cgpa);
		gotoxy(30,18);
		printf("Enter Age : ");
		scanf("%d",&std.std_age);
		fflush(stdin);
		fseek(fp,0,SEEK_END);
		fwrite(&std,sizeof(std),1,fp);
		fclose(fp);
		fp = fopen("record.dat","rb+");
		gotoxy(30,22);
		printf("The record is sucessfully saved");
		gotoxy(30,23);
		fflush(stdin);
		printf("Save any more?(Y / N):");
		choice = getch();
		if(choice == 'y' || choice == 'Y')
			add_std_info(fp);
		else 
			sub_menu_student(fp);
	}


//**************************************************************************************//

//******************************* DEFINATION OF DISPLAY STUDENT FUNCTION ***********************//

void display_std(FILE *fp)
{
	//fp = fopen("record.dat","rb+");
	int y=10;
	system("cls");
	gotoxy(10,4);
	printf("********************** STUDENT RECORD ***************************");
	gotoxy(10,6);
	printf("ID       NAME      F.NAME      CLASS      GENDER      CGPA     AGE");
	gotoxy(10,8);
	printf("*****************************************************************");
	//filehandler_std();
	rewind(fp);	
	while(fread(&std,sizeof(std),1,fp)==1)
	{
		gotoxy(10,y);
		printf("%d",std.std_id);
		gotoxy(17,y);
		printf("%s",std.std_name);
		gotoxy(30,y);
		printf("%s",std.std_fth_name);
		gotoxy(42,y);
		printf("%s",std.std_class);
		gotoxy(55,y);
		printf("%s",std.std_gender);
		gotoxy(64,y);
		printf("%0.2f",std.std_cgpa);
		gotoxy(73,y);
		printf("%d",std.std_age);
		y++;
	}
	gotoxy(30,22);
	printf("Press Any Key.....");
	getch();
}

//**************************************************************************************//

//******************************* DEFINATION OF EDIT STUDENT INFO FUNCTION ***********************//

void edit_std_info(FILE *fp)
{
	int id;
	char choice;
	char temp[20];
	system("cls");
	gotoxy(18,4);
	printf("************* Enter Student Information *************");
	gotoxy(30,6);
	printf("Enter ID : ");
	scanf("%d",&id);
	if(checkid_std(id)!=0)
		{
			gotoxy(30,22);
			printf("ID Not Exist !!!");
			getch();
			edit_std_info(fp);
		}
	rewind(fp);
	while(fread(&std,sizeof(std),1,fp)==1)
	{
		if(id==std.std_id)
		{
			std.std_id = id;
			gotoxy(30,8);
			fflush(stdin);
			printf("Enter New Name : ");
			gets(temp);
			if(strlen(temp)>0)
				strcpy(std.std_name,temp);
			gotoxy(30,10);
			fflush(stdin);
			printf("Enter New Father Name : ");
			gets(temp);
			if(strlen(temp)>0)
				strcpy(std.std_fth_name,temp);
			fflush(stdin);
			gotoxy(30,12);
			printf("Enter New Class : ");
			gets(temp);
			if(strlen(temp)>0)
				strcpy(std.std_class,temp);
			fflush(stdin);
			gotoxy(30,14);
			printf("Enter New Gender : ");
			gets(temp);
			if(strlen(temp)>0)
				strcpy(std.std_gender,temp);
			fflush(stdin);
			gotoxy(30,16);
			printf("Enter New CGPA : ");
			gets(temp);
			if(strlen(temp)>0)
				std.std_cgpa = atof(temp);
			gotoxy(30,18);
			printf("Enter New Age : ");
			gets(temp);
			if(strlen(temp)>0)
				std.std_age = atoi(temp);
			fflush(stdin);
			fseek(fp,-(sizeof(std)),SEEK_CUR);
			fwrite(&std,sizeof(std),1,fp);
			break;
		}
        
	}
	fclose(fp);
	fp = fopen("record.dat","rb+");
	gotoxy(30,21);
	printf("Successfull Modified !!!");
	gotoxy(30,22);
	printf("Modify More (Y / N) ? ");
	choice = getche();
	if(choice == 'y' || choice == 'Y')
		edit_std_info(fp);
	else
		sub_menu_student(fp);
}

//**************************************************************************************//

//******************************* DEFINATION OF DELETE STUDENT FUNCTION ***********************//

void del_std_info(FILE *fp)
{
	int id;
	char choice;
	system("cls");
	gotoxy(18,4);
	printf("************* Enter Student Information *************");
	gotoxy(30,6);
	printf("Enter ID to Delete Record : ");
	scanf("%d",&id);
	if(checkid_std(id)!=0)
		{
			gotoxy(30,22);
			printf("ID Not Exist !!!");
			getch();
			del_std_info(fp);
		}
	ft = fopen("temp.dat","wb");
	rewind(fp);
	while(fread(&std,sizeof(std),1,fp)==1)
	{
		if(id!=std.std_id)
		{
			fwrite(&std,sizeof(std),1,ft);
		}
	}
	fclose(fp);
	fclose(ft);
	remove("record.dat");
	rename("temp.dat","record.dat");
	
	fp = fopen("record.dat","rb+");
	gotoxy(30,22);
	printf("Record Succeessfully Deleted !");
	gotoxy(30,23);
	printf("Delete Another Record (Y / N) ? ");
	choice = getche();
	fflush(stdin);
	if(choice=='y'||choice=='Y')
		del_std_info(fp);
	else
		sub_menu_student(fp);
}

//**************************************************************************************//

//******************************* DEFINITION OF SEARCH STUDENT INFO FUNCTION ***********************//

void search_std_info(FILE *fp)
{
	char choice;
	while(1)
	{
	
		system("cls");
		gotoxy(18,4);
		printf("************* Student Search Section *************");
		gotoxy(30,6);
		printf("1. Serach by Name ");
		gotoxy(30,8);
		printf("2. Serach by CGPA ");
		gotoxy(30,10);
		printf("3. Serach by Age ");
		gotoxy(30,12);
		printf("4. Serach by Gender ");
		gotoxy(30,14);
		printf("5. Search by Class ");
		gotoxy(30,16);
		printf("6. Back to Student Menu ");
		gotoxy(30,18);
		printf("Your Choice ? ");
		choice = getche();
		fflush(stdin);
		switch(choice)
		{
			case '1':
				search_std_name(fp);
				break;
			case '2':
				search_std_cgpa(fp);
				break;
			case '3':
				search_std_age(fp);
				break;
			case '4':
				search_std_gender(fp);
				break;
			case '5':
				search_std_class(fp);
				break;
			case '6':
				sub_menu_student(fp);
				break;
			default:
				gotoxy(30,22);
				printf("Enter a Valid Choice ");
				getch();
		}
	}   
}

//**************************************************************************************//

//******************************* DEFINATION OF SEARCH STUDENT BY NAME FUNCTION ***********************//

void search_std_name(FILE *fp)
{
	fflush(stdin);
	system("cls");
	char name[20];
	int y=10;
	gotoxy(18,4);
	printf("************* Student Search Section *************");
	gotoxy(30,6);
	printf("Enter Student Name : ");
	gets(name);
	fflush(stdin);
	//filehandler_std();
	system("cls");
	gotoxy(10,4);
	printf("********************** STUDENT RECORD ***************************");
	gotoxy(10,6);
	printf("ID       NAME      F.NAME      CLASS      GENDER      CGPA     AGE");
	gotoxy(10,8);
	printf("*****************************************************************");
	rewind(fp);
	while(fread(&std,sizeof(std),1,fp)==1)
	{
		if(strcmp(name,std.std_name)==0)
		{
			
			gotoxy(10,y);
			printf("%d",std.std_id);
			gotoxy(17,y);
			printf("%s",std.std_name);
			gotoxy(30,y);
			printf("%s",std.std_fth_name);
			gotoxy(42,y);
			printf("%s",std.std_class);
			gotoxy(55,y);
			printf("%s",std.std_gender);
			gotoxy(64,y);
			printf("%0.2f",std.std_cgpa);
			gotoxy(73,y);
			printf("%d",std.std_age);
			y=y+1;
		}
		
	}
	gotoxy(30,22);
	printf("Press Any Key.....");
	getch();
}

//**************************************************************************************//

//******************************* DEFINATION OF SEARCH STUDENT BY CGPA FUNCTION ***********************//
		
void search_std_cgpa(FILE *fp)
{
	
	system("cls");
	float cgpa;
	int y=10;
	gotoxy(18,4);
	printf("************* Student Search Section *************");
	gotoxy(30,6);
	printf("Enter Student CGPA : ");
	scanf("%f",&cgpa);
	system("cls");
	gotoxy(10,4);
	printf("********************** STUDENT RECORD ***************************");
	gotoxy(10,6);
	printf("ID       NAME      F.NAME      CLASS      GENDER      CGPA     AGE");
	gotoxy(10,8);
	printf("*****************************************************************");
	rewind(fp);
	while(fread(&std,sizeof(std),1,fp)==1)
	{
		if(cgpa==std.std_cgpa)
		{
			
			gotoxy(10,y);
			printf("%d",std.std_id);
			gotoxy(17,y);
			printf("%s",std.std_name);
			gotoxy(30,y);
			printf("%s",std.std_fth_name);
			gotoxy(42,y);
			printf("%s",std.std_class);
			gotoxy(55,y);
			printf("%s",std.std_gender);
			gotoxy(64,y);
			printf("%0.2f",std.std_cgpa);
			gotoxy(73,y);
			printf("%d",std.std_age);
			y=y+1;
		}
		
	}
	gotoxy(30,22);
	printf("Press Any Key.....");
	getch();
}

//**************************************************************************************//

//******************************* DEFINATION OF SEARCH STUDENT BY AGE FUNCTION ***********************//

void search_std_age(FILE *fp)
{
	
	system("cls");
	int age;
	int y=10;
	gotoxy(18,4);
	printf("************* Student Search Section *************");
	gotoxy(30,6);
	printf("Enter Student Age : ");
	scanf("%d",&age);
	system("cls");
	gotoxy(10,4);
	printf("********************** STUDENT RECORD ***************************");
	gotoxy(10,6);
	printf("ID       NAME      F.NAME      CLASS      GENDER      CGPA     AGE");
	gotoxy(10,8);
	printf("*****************************************************************");
	rewind(fp);
	while(fread(&std,sizeof(std),1,fp)==1)
	{
		if(age==std.std_age)
		{
			
			gotoxy(10,y);
			printf("%d",std.std_id);
			gotoxy(17,y);
			printf("%s",std.std_name);
			gotoxy(30,y);
			printf("%s",std.std_fth_name);
			gotoxy(42,y);
			printf("%s",std.std_class);
			gotoxy(55,y);
			printf("%s",std.std_gender);
			gotoxy(64,y);
			printf("%0.2f",std.std_cgpa);
			gotoxy(73,y);
			printf("%d",std.std_age);
			y=y+1;
		}
		
	}
	gotoxy(30,22);
	printf("Press Any Key.....");
	getch();
}

//**************************************************************************************//

//******************************* DEFINATION OF SEARCH STUDENT BY GENDER FUNCTION ***********************//

void search_std_gender(FILE *fp)
{
	fflush(stdin);
	system("cls");
	char gender[7];
	int y=10;
	gotoxy(18,4);
	printf("************* Student Search Section *************");
	gotoxy(30,6);
	printf("Enter Student Gender (M / F) : ");
	gets(gender);
	fflush(stdin);
	
	system("cls");
	gotoxy(10,4);
	printf("********************** STUDENT RECORD ***************************");
	gotoxy(10,6);
	printf("ID       NAME      F.NAME      CLASS      GENDER      CGPA     AGE");
	gotoxy(10,8);
	printf("*****************************************************************");
	rewind(fp);
	while(fread(&std,sizeof(std),1,fp)==1)
	{
		if(strcmp(gender,std.std_gender)==0)
		{
			
			gotoxy(10,y);
			printf("%d",std.std_id);
			gotoxy(17,y);
			printf("%s",std.std_name);
			gotoxy(30,y);
			printf("%s",std.std_fth_name);
			gotoxy(42,y);
			printf("%s",std.std_class);
			gotoxy(55,y);
			printf("%s",std.std_gender);
			gotoxy(64,y);
			printf("%0.2f",std.std_cgpa);
			gotoxy(73,y);
			printf("%d",std.std_age);
			y=y+1;
		}
		
	}
	gotoxy(30,22);
	printf("Press Any Key.....");
	getch();
}

//**************************************************************************************//

//****************** DEFINATION OF SEARCH STUDENT BY CLASS FUNCTION *******************//

void search_std_class(FILE *fp)
{
	fflush(stdin);
	system("cls");
	char cl[5];
	int y=10;
	gotoxy(18,4);
	printf("************* Student Search Section *************");
	gotoxy(30,6);
	printf("Enter Student Class : ");
	gets(cl);
	fflush(stdin);
	
	system("cls");
	gotoxy(10,4);
	printf("********************** STUDENT RECORD ***************************");
	gotoxy(10,6);
	printf("ID       NAME      F.NAME      CLASS      GENDER      CGPA     AGE");
	gotoxy(10,8);
	printf("*****************************************************************");
	rewind(fp);
	while(fread(&std,sizeof(std),1,fp)==1)
	{
		if(strcmp(cl,std.std_class)==0)
		{
			
			gotoxy(10,y);
			printf("%d",std.std_id);
			gotoxy(17,y);
			printf("%s",std.std_name);
			gotoxy(30,y);
			printf("%s",std.std_fth_name);
			gotoxy(42,y);
			printf("%s",std.std_class);
			gotoxy(55,y);
			printf("%s",std.std_gender);
			gotoxy(64,y);
			printf("%0.2f",std.std_cgpa);
			gotoxy(73,y);
			printf("%d",std.std_age);
			y=y+1;
		}
		
	}
	gotoxy(30,22);
	printf("Press Any Key.....");
	getch();
}

//**************************************************************************************//
//************************END OF STUDENT FUNCTION**************************************//
//*************************************************************************************//

//*************************************************************************************//
//*********************  TEACHER SECTION STARTS HERE *********************************//
//***********************************************************************************//


//******************************* DEFINATION OF SUB-MENU-TEACHER FUNCTION ***********************//
 
void sub_menu_teacher(FILE *ftt)
{
	char choice;
	while(1)
	{
	
		system("cls");
		gotoxy(55,1);
		t();
		gotoxy(18,4);
		printf("***************** TEACHERS SECTION *****************\n\n");
		gotoxy(30,6);
		printf("1. Add Record");
		gotoxy(30,8);
		printf("2. Edit Record");
		gotoxy(30,10);
		printf("3. Display All Records");
		gotoxy(30,12);
		printf("4. Delete Record");
		gotoxy(30,14);
		printf("5. Search Record");
		gotoxy(30,16);
		printf("6. Back to Main Menu");
		gotoxy(30,18);
		printf("Your Choice ? ");
		choice = getche();
		fflush(stdin);
		switch(choice)
		{
			case '1':
				add_tch_info(ftt);
				break;
			case '2':
				edit_tch_info(ftt);
				break;
			case '3':
				display_tch(ftt);
				break;
			case '4':
				del_tch_info(ftt);
				break;
			case '5':
				search_tch_info(ftt);
				break;
			case '6':
				main_menu();
				break;
			default:
				gotoxy(30,22);
				printf("Enter Valid Choice\n\n");
				getch();
		}
	}
}

//**************************************************************************************//

//******************************* DEFINATION OF CHECK ID FUNCTION ***********************//

int checkid_tch(int id)  
{
	rewind(ftt);
	while(fread(&tch,sizeof(tch),1,ftt)==1)
		if(tch.tch_id==id)
			return 0;
	return 1;
}

//**************************************************************************************//

//******************************* DEFINATION OF ADD TEACHER INFO FUNCTION ***********************//

void add_tch_info(FILE *ftt)
{
	
		char choice;
		int r;
		int id=0;
		system("cls");
		gotoxy(18,4);
		printf("************* Enter Teacher Information *************");
		gotoxy(30,6);
		printf("Enter ID : ");
		scanf("%d",&id);
		if(checkid_tch(id)==0)
		{
			gotoxy(30,22);
			printf("ID Already Exist !!!");
			getch();
			add_tch_info(ftt);
		}
		tch.tch_id = id;
		gotoxy(30,8);
		fflush(stdin);
		printf("Enter Name : ");
		gets(tch.tch_name);
		gotoxy(30,10);
		fflush(stdin);
		printf("Enter Father Name : ");
		gets(tch.tch_fth_name);
		fflush(stdin);
		gotoxy(30,12);
		printf("Enter Assigned Class : ");
		gets(tch.tch_class);
		fflush(stdin);
		gotoxy(30,14);
		printf("Enter Assigned Subject : ");
		gets(tch.tch_subject);
		fflush(stdin);
		gotoxy(30,16);
		printf("Enter Highest Degree : ");
		gets(tch.tch_quali);
		fflush(stdin);		
		fseek(ftt,0,SEEK_END);
		fwrite(&tch,sizeof(tch),1,ftt);
		fclose(ftt);
		ftt = fopen("recordt.dat","rb+");
		gotoxy(30,22);
		printf("The record is sucessfully saved");
		gotoxy(30,23);
		fflush(stdin);
		printf("Save any more?(Y / N):");
		choice = getch();
		if(choice == 'y' || choice == 'Y')
			add_tch_info(ftt);
		else 
			sub_menu_teacher(ftt);
	}


//**************************************************************************************//

//******************************* DEFINATION OF DISPLAY TEACHER FUNCTION ***********************//

void display_tch(FILE *ftt)
{
	int y=10;
	system("cls");
	gotoxy(10,4);
	printf("********************** TEACHER RECORD ***************************");
	gotoxy(10,6);
	printf("ID       NAME      F.NAME      CLASS      SUBJECT      STUDY");
	gotoxy(10,8);
	printf("*****************************************************************");
	
	rewind(ftt);	
	while(fread(&tch,sizeof(tch),1,ftt)==1)
	{
		gotoxy(10,y);
		printf("%d",tch.tch_id);
		gotoxy(17,y);
		printf("%s",tch.tch_name);
		gotoxy(30,y);
		printf("%s",tch.tch_fth_name);
		gotoxy(42,y);
		printf("%s",tch.tch_class);
		gotoxy(55,y);
		printf("%s",tch.tch_subject);
		gotoxy(64,y);
		printf("%s",tch.tch_quali);
		y++;
	}
	gotoxy(30,22);
	printf("Press Any Key.....");
	getch();
}

//**************************************************************************************//

//******************************* DEFINATION OF EDIT TEACHER INFO FUNCTION ***********************//

void edit_tch_info(FILE *ftt)
{
	int id;
	char temp[20];
	char choice;
	system("cls");
	gotoxy(18,4);
	printf("************* Enter Teacher Information *************");
	gotoxy(30,6);
	printf("Enter ID : ");
	scanf("%d",&id);
	if(checkid_tch(id)!=0)
		{
			gotoxy(30,22);
			printf("ID Doesnot Exist !!!");
			getch();
			edit_tch_info(ftt);
		}
	rewind(ftt);
	while(fread(&tch,sizeof(tch),1,ftt)==1)
	{
		if(id==tch.tch_id)
		{
			tch.tch_id = id;
			gotoxy(30,8);
			fflush(stdin);
			printf("Enter New Name : ");
			gets(temp);
			if(strlen(temp)>0)
				strcpy(tch.tch_name,temp);
			gotoxy(30,10);
			fflush(stdin);
			printf("Enter New Father Name : ");
			gets(temp);
			if(strlen(temp)>0)
				strcpy(tch.tch_fth_name,temp);
			fflush(stdin);
			gotoxy(30,12);
			printf("Enter New Assigned Class : ");
			gets(temp);
			if(strlen(temp)>0)
				strcpy(tch.tch_class,temp);
			fflush(stdin);
			gotoxy(30,14);
			printf("Enter New Assigned Subject : ");
			gets(temp);
			if(strlen(temp)>0)
				strcpy(tch.tch_subject,temp);
			fflush(stdin);
			gotoxy(30,16);
			printf("Enter New Qualification : ");
			gets(temp);
			if(strlen(temp)>0)
				strcpy(tch.tch_quali,temp);
			fflush(stdin);
			fseek(ftt,-(sizeof(tch)),SEEK_CUR);
			fwrite(&tch,sizeof(tch),1,ftt);
			break;
		}
        
	}
	fclose(ftt);
	ftt = fopen("recordt.dat","rb+");
	gotoxy(30,21);
	printf("Successfully Modified !!!");
	gotoxy(30,22);
	printf("Modify More (Y / N) ? ");
	choice = getche();
	if(choice == 'y' || choice == 'Y')
		edit_tch_info(ftt);
	else
		sub_menu_teacher(ftt);
}

//**************************************************************************************//

//******************************* DEFINATION OF DELETE TEACHER FUNCTION ***********************//

void del_tch_info(FILE *ftt)
{
	int id;
	char choice;
	system("cls");
	gotoxy(18,4);
	printf("************* Enter Teacher Information *************");
	gotoxy(30,6);
	printf("Enter ID to Delete Record : ");
	scanf("%d",&id);
	if(checkid_tch(id)!=0)
		{
			gotoxy(30,22);
			printf("ID Not Exist !!!");
			getch();
			del_tch_info(ftt);
		}
	ft = fopen("temp.dat","wb");
	rewind(ftt);
	while(fread(&tch,sizeof(tch),1,ftt)==1)
	{
		if(id!=tch.tch_id)
		{
			fwrite(&tch,sizeof(tch),1,ft);
		}
	}
	fclose(ftt);
	fclose(ft);
	
	remove("recordt.dat");
	rename("temp.dat","recordt.dat");
	fopen("recordt.dat","rb+");
	gotoxy(30,22);
	printf("Record Succeessfully Deleted !");
	gotoxy(30,23);
	printf("Delete Another Record (Y / N) ? ");
	choice = getche();
	fflush(stdin);
	if(choice=='y'||choice=='Y')
		del_tch_info(ftt);
	else
		sub_menu_teacher(ftt);
}

//**************************************************************************************//

//******************************* DEFINATION OF SEARCH STUDENT INFO FUNCTION ***********************//

void search_tch_info(FILE *ftt)
{
	char choice;
	while(1)
	{
	
		system("cls");
		gotoxy(18,4);
		printf("************* Teacher Search Section *************");
		gotoxy(30,6);
		printf("1. Serach by Name ");
		gotoxy(30,8);
		printf("2. Serach by Assigned Class ");
		gotoxy(30,10);
		printf("3. Serach by Assigned Sunject ");
		gotoxy(30,12);
		printf("4. Back to Menu ");
		gotoxy(30,14);
		printf("Your Choice ? ");
		choice = getche();
		fflush(stdin);
		switch(choice)
		{
			case '1':
				search_tch_name(ftt);
				break;
			case '2':
				search_tch_class(ftt);
				break;
			case '3':
				search_tch_subject(ftt);
				break;
			case '4':
				sub_menu_teacher(ftt);
				break;
			default:
				gotoxy(30,22);
				printf("Enter a Valid Choice ");
				getch();
		}
	}   
}

//**************************************************************************************//

//******************************* DEFINATION OF SEARCH TEACHER BY NAME FUNCTION ***********************//

void search_tch_name(FILE *ftt)
{
	fflush(stdin);
	system("cls");
	char name[20];
	int y=10;
	gotoxy(18,4);
	printf("************* Teacher Search Section *************");
	gotoxy(30,6);
	printf("Enter Teacher Name : ");
	gets(name);
	fflush(stdin);
	
	system("cls");
	gotoxy(10,4);
	printf("********************** TEACHER RECORD ***************************");
	gotoxy(10,6);
	printf("ID       NAME      F.NAME      CLASS      SUBJECT      STUDY");
	gotoxy(10,8);
	printf("*****************************************************************");
	rewind(ftt);
	while(fread(&tch,sizeof(tch),1,ftt)==1)
	{
		if(strcmp(name,tch.tch_name)==0)
		{
			
			gotoxy(10,y);
			printf("%d",tch.tch_id);
			gotoxy(17,y);
			printf("%s",tch.tch_name);
			gotoxy(30,y);
			printf("%s",tch.tch_fth_name);
			gotoxy(42,y);
			printf("%s",tch.tch_class);
			gotoxy(55,y);
			printf("%s",tch.tch_subject);
			gotoxy(64,y);
			printf("%s",tch.tch_quali);
			y=y+1;
		}
		
	}
	gotoxy(30,22);
	printf("Press Any Key.....");
	getch();
}

//**************************************************************************************//

//********************** DEFINATION OF SEARCH TEACHER BY ASSIGNED CLASS FUNCTION *****************//
void search_tch_class(FILE *ftt)
{
	fflush(stdin);
	system("cls");
	char clas[20];
	int y=10;
	gotoxy(18,4);
	printf("************* Teacher Search Section *************");
	gotoxy(30,6);
	printf("Enter Assigned Class : ");
	gets(clas);
	fflush(stdin);
	
	system("cls");
	gotoxy(10,4);
	printf("********************** TEACHER RECORD ***************************");
	gotoxy(10,6);
	printf("ID       NAME      F.NAME      CLASS      SUBJECT      STUDY");
	gotoxy(10,8);
	printf("*****************************************************************");
	rewind(ftt);
	while(fread(&tch,sizeof(tch),1,ftt)==1)
	{
		if(strcmp(clas,tch.tch_class)==0)
		{
			
			gotoxy(10,y);
			printf("%d",tch.tch_id);
			gotoxy(17,y);
			printf("%s",tch.tch_name);
			gotoxy(30,y);
			printf("%s",tch.tch_fth_name);
			gotoxy(42,y);
			printf("%s",tch.tch_class);
			gotoxy(55,y);
			printf("%s",tch.tch_subject);
			gotoxy(64,y);
			printf("%s",tch.tch_quali);
			y=y+1;
		}
		
	}
	gotoxy(30,22);
	printf("Press Any Key.....");
	getch();
}

		
//**************************************************************************************//

//**************** DEFINATION OF SEARCH TEACHER BY ASSIGNED SUBJECT FUNCTION ****************//

void search_tch_subject(FILE *ftt)
{
	fflush(stdin);
	system("cls");
	char sub[10];
	int y=10;
	gotoxy(18,4);
	printf("************* Teacher Search Section *************");
	gotoxy(30,6);
	printf("Enter Assigned Subject : ");
	gets(sub);
	fflush(stdin);
	
	system("cls");
	gotoxy(10,4);
	printf("********************** TEACHER RECORD ***************************");
	gotoxy(10,6);
	printf("ID       NAME      F.NAME      CLASS      SUBJECT      STUDY");
	gotoxy(10,8);
	printf("*****************************************************************");
	rewind(ftt);
	while(fread(&tch,sizeof(tch),1,ftt)==1)
	{
		if(strcmp(sub,tch.tch_subject)==0)
		{
			
			gotoxy(10,y);
			printf("%d",tch.tch_id);
			gotoxy(17,y);
			printf("%s",tch.tch_name);
			gotoxy(30,y);
			printf("%s",tch.tch_fth_name);
			gotoxy(42,y);
			printf("%s",tch.tch_class);
			gotoxy(55,y);
			printf("%s",tch.tch_subject);
			gotoxy(64,y);
			printf("%s",tch.tch_quali);
			y=y+1;
		}
		
	}
	gotoxy(30,22);
	printf("Press Any Key.....");
	getch();
}

//**************************************************************************************//
//************************END OF STUDENT FUNCTION**************************************//
//*************************************************************************************//


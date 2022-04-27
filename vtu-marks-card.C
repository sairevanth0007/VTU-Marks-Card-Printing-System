#include<conio.h>
#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<process.h>
struct student
{
 char usn[11];
 char name[25];
 int marks[9];
 int credits[9];
 char grade[9];
 int points[9];
 float sgpa;
}st;
 FILE *fptr;
void write_student();
void display_sp(char n[10]);
void sdisplay_sp(char n[10]);
void modify_student();
void delete_student();
void class_result();
void sclass_result();
void result(char uno[10]);
void intro();
void entry_menu();
void slogin();
void dlogin();
void rec(char n[11]);
void main()
{
  char ch;
  intro();
  do
    {
      clrscr();
      printf("\n\n\n\tMAIN MENU");
      printf("\n\n\t01. STUDENT MENU");
      printf("\n\n\t02. DEPARTMENT MENU");
      printf("\n\n\t03. EXIT");
      printf("\n\n\tPlease Select Your Option (1-3) ");
      ch=getche();
      switch(ch)
      {
	 case '1': clrscr();
	       slogin();
	       break;
	  case '2': dlogin();
		break;
	  case '3':exit(0);
	  default :printf("\a");
    }
    }while(ch!='3');
}


void write_student()
   {
   char len[10],qbz[11];
   int f,u,i,flag=-1;
   float gc=0,c=0;
   FILE *fr;
    fptr=fopen("student.dat","ab");
    printf("\nPlease Enter The New Details of student \n");
   label:fflush(stdin);
    printf("\nEnter The usn number of the student ");
    scanf("%s",st.usn);
    st.usn[11]='\0';
    strcpy(qbz,st.usn);
    u=strlen(qbz);
    strcpy(len,"3br18cs");
    f=strncmp(qbz,len,7);
    fr=fopen("student.dat","rb");
    rewind(fr);
    if(f==0&&u==10)
    {
	while(fread(&st,sizeof(st),1,fr)>0)
	{
	 if(strcmp(st.usn,qbz)==0)
	  {
	     printf("usn already exists\n");
	     getch();
	     fclose(fptr);
	     goto label;
	   }
	 }
    }
   else
   {
   printf("enter in correct format\n");
   getch();
   goto label;
   }
    fclose(fptr);
    fptr=fopen("student.dat","ab");
    fflush(stdin);
    strcpy(st.usn,qbz);
   name: printf("\n\nEnter The Name of student ");
    gets(st.name);
    for(i=0;i<strlen(st.name);i++)
    {
      if(st.name[i]>64&&st.name[i]<91||st.name[i]>96&&st.name[i]<123||st.name[i]==32)
      {
      flag=0;
      }
      else
      {
      flag=1;
      break;
      }
    }
    if(flag==1)
    {
    printf("please enter only characters\n");
    goto name;
    }
    fflush(stdin);
  mana: printf("\nEnter The marks in management,entrepreneurship for it industry out of 100 : ");
    scanf("%d",&st.marks[0]);
    if((st.marks[0])>100&&(st.marks[0])>-1)
    {
    printf("enter the marks below 100\n");
    goto mana;
    }
    fflush(stdin);
    if((st.marks[0])>40)
    {
    st.credits[0]=3;
    }
    else
    {
    st.credits[0]=0;
    }
  comp: printf("\nEnter The marks in computer netorks and security out of 100 : ");
    scanf("%d",&st.marks[1]);
    if((st.marks[1])>100&&(st.marks[1])>-1)
    {
    printf("enter the marks below 100\n");
    goto comp;
    }
	if((st.marks[1])>40)
    {
    st.credits[1]=4;
    }
    else
    {
    st.credits[1]=0;
    }
  data: printf("\nEnter The marks in database management system out of 100 : ");
    scanf("%d",&st.marks[2]);
    if((st.marks[2])>100&&(st.marks[2])>-1)
    {
    printf("enter the marks below 100\n");
    goto data;
    }
	if((st.marks[2])>40)
    {
    st.credits[2]=4;
    }
    else
    {
    st.credits[2]=0;
    }
  autom: printf("\nEnter The marks in automata theory and computability out of 100 : ");
    scanf("%d",&st.marks[3]);
    if((st.marks[3])>100&&(st.marks[3])>-1)
    {
    printf("enter the marks below 100\n");
    goto autom;
    }
	if((st.marks[3])>40)
    {
    st.credits[3]=3;
    }
    else
    {
    st.credits[3]=0;
    }
  pyth: printf("\nEnter The marks in application development using python out of 100 : ");
    scanf("%d",&st.marks[4]);
    if((st.marks[4])>100&&(st.marks[4])>-1)
    {
    printf("enter the marks below 100\n");
    goto pyth;
    }
	if((st.marks[4])>40)
    {
    st.credits[4]=3;
    }
    else
    {
    st.credits[4]=0;
    }
  unix: printf("\nEnter The marks in unix programming out of 100 : ");
    scanf("%d",&st.marks[5]);
    if((st.marks[5])>100&&(st.marks[5])>-1)
    {
    printf("enter the marks below 100\n");
    goto unix;
    }
	if((st.marks[5])>40)
    {
    st.credits[5]=3;
    }
    else
    {
    st.credits[5]=0;
    }
  complab: printf("\nEnter The marks in computer network laboratory out of 100 : ");
    scanf("%d",&st.marks[6]);
    if((st.marks[6])>100&&(st.marks[6])>-1)
    {
    printf("enter the marks below 100\n");
    goto complab;
    }
	if((st.marks[6])>40)
    {
    st.credits[6]=2;
    }
    else
    {
    st.credits[6]=0;
    }
  datalab: printf("\nEnter The marks in DBMS laboratory with mini project out of 100 : ");
    scanf("%d",&st.marks[7]);
    if((st.marks[7])>100&&(st.marks[7])>-1)
    {
    printf("enter the marks below 100\n");
    goto datalab;
    }
	if((st.marks[7])>40)
    {
    st.credits[7]=2;
    }
    else
    {
    st.credits[7]=0;
    }
  env: printf("\nEnter The marks in Environmental studies out of 100 : ");
    scanf("%d",&st.marks[8]);
    if((st.marks[8])>100&&(st.marks[8])>-1)
    {
    printf("enter the marks below 100\n");
    goto env;
    }
   if((st.marks[8])>40)
    {
    st.credits[8]=1;
    }
    else
    {
    st.credits[8]=0;
    }
  for(i=0;i<9;i++)
    {
       if(st.marks[i]>=90)
       {
	 st.grade[i]='O';
	 st.points[i]=10;
       }
       else if(st.marks[i]>=80 &&st.marks[i]<90)
       {
	 st.grade[i]='S';
	 st.points[i]=9;
       }
       else if(st.marks[i]>=70 &&st.marks[i]<80)
       {
	 st.grade[i]='A';
	 st.points[i]=8;
       }
       else if(st.marks[i]>=60 &&st.marks[i]<70)
       {
	 st.grade[i]='B';
	 st.points[i]=7;
       }
       else if(st.marks[i]>=50 &&st.marks[i]<60)
       {
	 st.grade[i]='C';
	 st.points[i]=6;
       }
       else if(st.marks[i]>=45 &&st.marks[i]<50)
       {
	 st.grade[i]='D';
	 st.points[i]=5;
       }
       else if(st.marks[i]>=40 &&st.marks[i]<45)
       {
	 st.grade[i]='E';
	 st.points[i]=4;
       }
       else
       {
	 st.grade[i]='F';
	 st.points[i]=0;
       }
    }
      for(i=0;i<9;i++)
       {
	 gc=gc+(st.points[i]*st.credits[i]);
	 c=c+st.credits[i];
       }
       st.sgpa=gc/c;
       fwrite(&st,sizeof(st),1,fptr);
       fclose(fptr);
       printf("\n\nStudent Record Has Been Created ");
       getch();
       entry_menu();
}


void display_sp(char n[10])
{
    int flag=0;
    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
     if(strcmp(st.usn,n)==0)
	{
	 clrscr();
	    printf("\nRoll number of student : %s",st.usn);
	    printf("\nName of student : %s",st.name);
	    printf("\nMarks in management,entrepreneurship for it industry with grade and credits: %d   %c  %d",st.marks[0],st.grade[0],st.credits[0]);
	    printf("\nMarks in computer netorks and security with grade and credits: %d  %c  %d",st.marks[1],st.grade[1],st.credits[1]);
	    printf("\nMarks in database management system with grade and credits: %d  %c  %d",st.marks[2],st.grade[2],st.credits[2]);
	    printf("\nMarks in automata theory and computability and grade and credits: %d  %c  %d",st.marks[3],st.grade[3],st.credits[3]);
	    printf("\nMarks in application development using python with grade and credits : %d  %c  %d",st.marks[4],st.grade[4],st.credits[4]);
	    printf("\nMarks in unix programming with grade and credits: %d  %c  %d",st.marks[5],st.grade[5],st.credits[5]);
	    printf("\nMarks in computer network laboratory with grade and credits: %d  %c  %d",st.marks[6],st.grade[6],st.credits[6]);
	    printf("\nMarks in DBMS laboratory with mini project with grade and credits: %d  %c  %d",st.marks[7],st.grade[7],st.credits[7]);
	    printf("\nMarks in Environmental studies with grade and credits: %d  %c  %d",st.marks[8],st.grade[8],st.credits[8]);
	    printf("\nSGPA : %.2f\n",st.sgpa);
	 flag=1;
	}
    }
    fclose(fptr);
if(flag==0)
 printf("\n\nrecord not exist");
    getch();
    entry_menu();
}

void sdisplay_sp(char n[10])
{
    int flag=0;
    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
     if(strcmp(st.usn,n)==0)
	{
	 clrscr();
	    printf("\nRoll number of student : %s",st.usn);
	    printf("\nName of student : %s",st.name);
	    printf("\nMarks in management,entrepreneurship for it industry : %d",st.marks[0]);
	    printf("\nMarks in computer netorks and security : %d",st.marks[1]);
	    printf("\nMarks in database management system : %d",st.marks[2]);
	    printf("\nMarks in automata theory and computability : %d",st.marks[3]);
	    printf("\nMarks in application development using python : %d",st.marks[4]);
	    printf("\nMarks in unix programming : %d",st.marks[5]);
	    printf("\nMarks in computer network laboratory : %d",st.marks[6]);
	    printf("\nMarks in DBMS laboratory with mini project : %d",st.marks[7]);
	    printf("\nMarks in Environmental studies : %d",st.marks[8]);
	 flag=1;
	}
    }
    fclose(fptr);
if(flag==0)
 printf("\n\nrecord not exist");
    getch();
    result(n);
}


void modify_student()
{
    int found=0,i,flag=-1;
    float gc=0,c=0;
    char no[10];
    clrscr();
    printf("\n\n\tTo Modify ");
    printf("\n\n\tPlease Enter The USN of student");
    scanf("%s",no);
    fptr=fopen("student.dat","rb+");
    while((fread(&st,sizeof(st),1,fptr))>0 && found==0)
    {
    if(strcmp(st.usn,no)==0)
	   {
	    printf("\nUSN of student : %s",st.usn);
	    printf("\nName of student : %s",st.name);
	    printf("\nMarks in management,entrepreneurship for it industry : %d",st.marks[0]);
	    printf("\nMarks in computer netorks and security : %d",st.marks[1]);
	    printf("\nMarks in database management system : %d",st.marks[2]);
	    printf("\nMarks in automata theory and computability : %d",st.marks[3]);
	    printf("\nMarks in application development using python : %d",st.marks[4]);
	    printf("\nMarks in unix programming : %d",st.marks[5]);
	    printf("\nMarks in computer network laboratory : %d",st.marks[6]);
	    printf("\nMarks in DBMS laboratory with mini project : %d",st.marks[7]);
	    printf("\nMarks in Environmental studies : %d",st.marks[8]);
	    printf("\nPlease Enter The New Details of student \n");
	    strcpy(st.usn,no);
	    st.usn[11]='\0';
	    fflush(stdin);
	   name:  printf("\n\nEnter The Name of student ");
	    gets(st.name);
	   for(i=0;i<strlen(st.name);i++)
	    {
	      if(st.name[i]>64&&st.name[i]<91||st.name[i]>96&&st.name[i]<123||st.name[i]==32)
	       {
		 flag=0;
	       }
	      else
	       {
		 flag=1;
		 break;
	       }
	    }
	   if(flag==1)
	   {
	     printf("please enter only characters\n");
	     goto name;
	   }
	mana: printf("\nEnter The marks in management,entrepreneurship for it industry out of 100 : ");
	    scanf("%d",&st.marks[0]);
	    if((st.marks[0])>100&&(st.marks[0])>-1)
	    {
	      printf("enter the marks below 100\n");
	      goto mana;
	    }
	       if((st.marks[0])>40)
	       {
		 st.credits[0]=3;
	       }else
	       {
		st.credits[0]=0;
	       }
	comp: printf("\nEnter The marks in computer netorks and security out of 100 : ");
	    scanf("%d",&st.marks[1]);
	    if((st.marks[1])>100&&(st.marks[1])>-1)
	    {
	      printf("enter the marks below 100\n");
	      goto comp;
	    }
	       if((st.marks[1])>40)
	       {
		 st.credits[1]=4;
	       }else
	       {
		st.credits[1]=0;
	       }
	data: printf("\nEnter The marks in database management system out of 100 : ");
	    scanf("%d",&st.marks[2]);
	    if((st.marks[2])>100&&(st.marks[2])>-1)
	    {
	      printf("enter the marks below 100\n");
	      goto data;
	    }
	       if((st.marks[2])>40)
	       {
		 st.credits[2]=4;
	       }else
	       {
		st.credits[2]=0;
	       }
	autom: printf("\nEnter The marks in automata theory and computability out of 100 : ");
	    scanf("%d",&st.marks[3]);
	    if((st.marks[3])>100&&(st.marks[3])>-1)
	    {
	       printf("enter the marks below 100\n");
	       goto autom;
	    }
	       if((st.marks[3])>40)
	       {
		 st.credits[3]=3;
	       }else
	       {
		st.credits[3]=0;
	       }
	pyth: printf("\nEnter The marks in application development using python out of 100 : ");
	    scanf("%d",&st.marks[4]);
	    if((st.marks[4])>100&&(st.marks[4])>-1)
	    {
	       printf("enter the marks below 100\n");
	       goto pyth;
	     }
		if((st.marks[4])>40)
	       {
		 st.credits[4]=3;
	       }else
	       {
		st.credits[4]=0;
	       }
	unix: printf("\nEnter The marks in unix programming out of 100 : ");
	     scanf("%d",&st.marks[5]);
	     if((st.marks[5])>100&&(st.marks[5])>-1)
	     {
	       printf("enter the marks below 100\n");
	       goto unix;
	      }
		 if((st.marks[5])>40)
	       {
		 st.credits[5]=3;
	       }else
	       {
		st.credits[5]=0;
	       }
	complab: printf("\nEnter The marks in computer network laboratory out of 100 : ");
	      scanf("%d",&st.marks[6]);
	      if((st.marks[6])>100&&(st.marks[6])>-1)
	      {
		printf("enter the marks below 100\n");
		goto complab;
	      }
		 if((st.marks[6])>40)
	       {
		 st.credits[6]=2;
	       }else
	       {
		st.credits[6]=0;
	       }
	datalab: printf("\nEnter The marks in DBMS laboratory with mini project out of 100 : ");
	      scanf("%d",&st.marks[7]);
	      if((st.marks[7])>100&&(st.marks[7])>-1)
	      {
		printf("enter the marks below 100\n");
		goto datalab;
	       }
	       if((st.marks[7])>40)
	       {
		 st.credits[7]=2;
	       }else
	       {
		st.credits[7]=0;
	       }
	env: printf("\nEnter The marks in Environmental studies out of 100 : ");
	      scanf("%d",&st.marks[8]);
	      if((st.marks[8])>100&&(st.marks[8])>-1)
	      {
		 printf("enter the marks below 100\n");
		 goto env;
	       }
	       if((st.marks[8])>40)
	       {
		 st.credits[8]=1;
	       }else
	       {
		st.credits[8]=0;
	       }

	    for(i=0;i<9;i++)
	    {
	     if(st.marks[i]>=90)
	     {
	      st.grade[i]='O';
	      st.points[i]=10;
	     }
	     else if(st.marks[i]>=80 &&st.marks[i]<90)
	     {
	      st.grade[i]='S';
	      st.points[i]=9;
	     }
	     else if(st.marks[i]>=70 &&st.marks[i]<80)
	     {
	      st.grade[i]='A';
	      st.points[i]=8;
	     }
	     else if(st.marks[i]>=60 &&st.marks[i]<70)
	     {
	      st.grade[i]='B';
	      st.points[i]=7;
	     }
	     else if(st.marks[i]>=50 &&st.marks[i]<60)
	     {
	      st.grade[i]='C';
	      st.points[i]=6;
	     }
	     else if(st.marks[i]>=45 &&st.marks[i]<50)
	     {
	      st.grade[i]='D';
	      st.points[i]=5;
	     }
	     else if(st.marks[i]>=40 &&st.marks[i]<45)
	     {
	      st.grade[i]='E';
	      st.points[i]=4;
	     }
	     else
	     {
	     st.grade[i]='F';
	     st.points[i]=0;
	     }
	    }
	    for(i=0;i<9;i++)
	     {
	       gc=gc+st.points[i]*st.credits[i];
	       c=c+st.credits[i];
	     }
	    st.sgpa=gc/c;
	    fseek(fptr,-(long)sizeof(st),1);
	    fwrite(&st,sizeof(st),1,fptr);
	    printf("\n\n\t Record Updated");
	    found=1;
	   }
	 }
    fclose(fptr);
    if(found==0)
    printf("\n\n Record Not Found ");
    getch();
    entry_menu();
}


void delete_student()
   {
    char no[11];
    int flag=-1,j=1;
    FILE *fptr2,*fptr;
    clrscr();
    printf("\n\n\n\tDelete Record");
    fptr=fopen("student.dat","rb");
    rewind(fptr);
    printf("\nUSN of students :\n");
      while((fread(&st,sizeof(st),1,fptr))>0)
    {
      printf("%d. %s\n",j,st.usn);
      j++;
    }
    printf("\n\nPlease Enter The USN of student You Want To Delete");
    scanf("%s",no);
    no[11]='\0';
    rewind(fptr);
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
    if(strcmp(st.usn,no)==0)
       {
       flag=0 ;
       }
    }
    if(flag==0)
    {
    fptr2=fopen("Temp.dat","wb");
    rewind(fptr);
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
       if(strcmp(st.usn,no)!=0)
       {
      fwrite(&st,sizeof(st),1,fptr2);
       }
    }
    fclose(fptr2);
    fclose(fptr);
    remove("student.dat");
    rename("Temp.dat","student.dat");
    printf("Rcord deleted\n");
    getch();
    }
    else
    {
    printf("\n\n\trecord not found ..");
    }
    getch();
    entry_menu();
}


void sclass_result(char uno[10])
    {
    int z=0,i,j;
    struct student  found[10],temp;
     clrscr();
     fptr=fopen("student.dat","rb");
     if(fptr==NULL)
     {
       printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File");
       printf("\n\n\n Program is closing ....");
       getch();
       exit(0);
     }

      printf("\n\n\t\tALL STUDENTS RESULT \n\n");
      printf("==============================================================================\n");
      printf("USN.        Name          M   C   D   A   P   U   CL   DL   ENV        SGPA\n");
      printf("==============================================================================\n");

      while((fread(&st,sizeof(st),1,fptr))>0)
     {
     found[z]=st;
     z++;
     }
       for(i=0;i<z;i++)
	{
	 for(j=0;j<z;j++)
	  {
	    if(found[i].sgpa>found[j].sgpa)
	    {
		temp=found[i];
		found[i]=found[j];
		found[j]=temp;
	    }
	}
    }
    for(i=0;i<z;i++)
    {
      printf("%-7s %-14s %-3d %-3d %-3d %-3d %-3d %-3d %-3d  %-3d  %-3d        %-3.2f \n",found[i].usn,found[i].name,found[i].marks[0],found[i].marks[1],found[i].marks[2],found[i].marks[3],found[i].marks[4],found[i].marks[5],found[i].marks[6],found[i].marks[7],found[i].marks[8],found[i].sgpa);
    }
     fclose(fptr);
     getch();
    result(uno);
}


void class_result()
       {
    int z=0,i,j;
    struct student  found[10],temp;
     clrscr();
     fptr=fopen("student.dat","rb");
     if(fptr==NULL)
     {
       printf("ERROR!!! FILE COULD NOT BE OPEN\n\n\n Go To Entry Menu to create File");
       printf("\n\n\n Program is closing ....");
       getch();
       exit(0);
     }

      printf("\n\n\t\tALL STUDENTS RESULT \n\n");
      printf("==============================================================================\n");
      printf("USN.        Name          M   C   D   A   P   U   CL   DL   ENV        SGPA\n");
      printf("==============================================================================\n");
      while((fread(&st,sizeof(st),1,fptr))>0)
     {
     found[z]=st;
     z++;
     }
       for(i=0;i<z;i++)
	{
	 for(j=0;j<z;j++)
	  {
	    if(strcmp(found[i].usn,found[j].usn)<0)
	    {
		temp=found[i];
		found[i]=found[j];
		found[j]=temp;
	    }
	}
    }
    for(i=0;i<z;i++)
    {
       printf("%-7s %-14s %-3d %-3d %-3d %-3d %-3d %-3d %-3d  %-3d  %-3d        %-3.2f \n",found[i].usn,found[i].name,found[i].marks[0],found[i].marks[1],found[i].marks[2],found[i].marks[3],found[i].marks[4],found[i].marks[5],found[i].marks[6],found[i].marks[7],found[i].marks[8],found[i].sgpa);
    }
     fclose(fptr);
     getch();
     entry_menu();
}


void result(char uno[10])
   {
    int ans;
    char ch;
    clrscr();
    printf("\n\n\nRESULT MENU");
    printf("\n\n\n1. Class Result\n\n2. Student Marks Card\n\n3.Back to Main Menu");
    printf("\n\n\nEnter Choice ? ");
    scanf("%d",&ans);
    switch(ans)
    {
     case 1 :sclass_result(uno);
	    break;
     case 2 :clrscr();
	rec(uno);
	break;
     case 3: break;
     default:  printf("\a");
    }
 }


void intro()
{
 clrscr();
 gotoxy(36,7);
 printf("VTU");
 gotoxy(33,9);
 printf("MARKS CARD");
 gotoxy(26,11);
 printf("PROJECT ONLY FOR 5th SEM");
 printf("\n\n\n\n\tCOLLEGE :\n\n\t\t Bellary Institute of Technology and Management\n");
 getch();
}


void entry_menu()
{
    char ch2;
   clrscr();
  printf("\n\n\n\tENTRY MENU");
  printf("\n\n\t1.CREATE STUDENT RECORD");
  printf("\n\n\t2.DISPLAY CLASS RESULT ");
  printf("\n\n\t3.SEARCH STUDENT RECORD ");
  printf("\n\n\t4.MODIFY STUDENT RECORD");
  printf("\n\n\t5.DELETE STUDENT RECORD");
  printf("\n\n\t6.BACK TO MAIN MENU");
  printf("\n\n\tPlease Enter Your Choice (1-6) ");
  ch2=getche();
  switch(ch2)
  {
    case '1': clrscr();
	  write_student();
	  break;
    case '2': class_result();break;
    case '3':  {
	   char usn[10];
	   clrscr();
	   printf("\n\n\tPlease Enter The USN number ");
	   scanf("%s",usn);
	   display_sp(usn);
	   }
	   break;
      case '4': modify_student();break;
      case '5': delete_student();break;
      case '6': return;
      default:printf("\a");entry_menu();
   }
}


void slogin()
{
    char n[11];
    int flag=0;
    clrscr();
    printf("\n\n\n\tEnter your usn\n");
    scanf("%s",n);
    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
     if(strcmp(st.usn,n)==0)
	{
	 flag=1;
	 }
    }
    if(flag==1)
    {
    result(n);
    }
    else
    {
    printf("\n\n\tNo records found usn\n");
    getch();
    return;
    }

}


void dlogin()
{
  int i,j=0;
  char pass[5]={'1','2','3','4','\0'},cp[10],c;
  clrscr();
  cp:printf("\n\n\n\tEnter the 4 digit department password\n");
  for(i=0;i<4;i++)
  {
  c=getch();
  printf("*");
  cp[i]=c;
  }
  cp[i]='\0';
  if(strcmp(pass,cp)==0)
  {
   printf("\n\n\tlogin successful");
   getch();
   entry_menu();
  }
  else
  {
    if(j==2)
    {
    printf("\n\nYou are not a authorised user\n");
    getch();
    return;
    }
    printf("\n\nWrong Password\n\n");
    j++;
    goto cp;
  }
  getch();
}
void rec(char n[11])
{
struct student ser;
int flag=0,i,sumc=0,cuml=0;

    fptr=fopen("student.dat","rb");
    while((fread(&st,sizeof(st),1,fptr))>0)
    {
     if(strcmp(st.usn,n)==0)
	{
	 clrscr();
	 ser=st;
	 flag=1;
	 }
     }

      fclose(fptr);
if(flag==0)
{
 printf("\n\nrecord not exist");
    getch();
 result(n);
}
else
{
       int gd = DETECT, gm;


      int left = 10, top = 10;
    int right = 637, bottom = 470;


    initgraph(&gd, &gm,"c:/TURBOC3/BGI");
     gotoxy(19,2);
     printf("VISVESVARAYA TECHNOLOGICAL UNIVERSITY,BELEGAVI");
     gotoxy(35,3);
     printf("KARNATAKA, INDIA");
     gotoxy(38,4);
     printf("GRADE CARD");
     gotoxy(24,5);
     printf("BE Computer Science & Engineering 2021");
     gotoxy(4,7);
     printf("Name of the Student : %s",ser.name);
     gotoxy(63,7);
     printf("USN : %s",ser.usn);
     gotoxy(4,8);
     printf("Name of the College : BALLARI INSTITUTE OF TECHNOLOGY & MANAGEMENT,BALLIARI");
     gotoxy(4,11);
     printf("SL No");
     gotoxy(5,14);
     printf("1");
     gotoxy(5,15);
     printf("2");
     gotoxy(5,16);
     printf("3");
     gotoxy(5,17);
     printf("4");
     gotoxy(5,18);
     printf("5");
     gotoxy(5,19);
     printf("6");
     gotoxy(5,20);
     printf("7");
     gotoxy(5,21);
     printf("8");
     gotoxy(5,22);
     printf("9");
     gotoxy(12,11);
     printf("Course ");
     gotoxy(13,12);
     printf("Code");
     gotoxy(12,14);
     printf("18CS51");
     gotoxy(12,15);
     printf("18CS52");
     gotoxy(12,16);
     printf("18CS53");
     gotoxy(12,17);
     printf("18CS54");
     gotoxy(12,18);
     printf("18CS55");
     gotoxy(12,19);
     printf("18CS56");
     gotoxy(12,20);
     printf("18CSl57");
     gotoxy(12,21);
     printf("18CSl58");
     gotoxy(12,22);
     printf("18CIV59");
     gotoxy(27,11);
     printf("Title of Course");
     gotoxy(29,14);
     printf("ME");
     gotoxy(29,15);
     printf("CNS");
     gotoxy(29,16);
     printf("DBMS");
     gotoxy(29,17);
     printf("ATC");
     gotoxy(29,18);
     printf("Python");
     gotoxy(29,19);
     printf("USP");
     gotoxy(29,20);
     printf("CN Lab");
     gotoxy(29,21);
     printf("DBMS Lab");
     gotoxy(29,22);
     printf("ENV");
     gotoxy(50,11);
     printf("Credits ");
     gotoxy(50,12);
     printf(" given");
     gotoxy(53,14);
     printf("3");
     gotoxy(53,15);
     printf("4");
     gotoxy(53,16);
     printf("4");
     gotoxy(53,17);
     printf("3");
     gotoxy(53,18);
     printf("3");
     gotoxy(53,19);
     printf("3");
     gotoxy(53,20);
     printf("2");
     gotoxy(53,21);
     printf("2");
     gotoxy(53,22);
     printf("1");
     gotoxy(58,11);
     printf("Credits ");
     gotoxy(58,12);
     printf(" Erned");
     for(i=0;i<9;i++)
     {
     gotoxy(60,14+i);
     printf("%d",ser.credits[i]);
     sumc=sumc+ser.credits[i];
     }
     gotoxy(66,11);
     printf("Letter");
     gotoxy(66,12);
     printf("Grade");
     for(i=0;i<9;i++)
     {
     gotoxy(68,14+i);
     printf("%c",ser.grade[i]);
     }
     gotoxy(74,11);
     printf("Grade");
     gotoxy(74,12);
     printf("Point");
     for(i=0;i<9;i++)
     {
     gotoxy(74,14+i);
     printf("%d",ser.points[i]);
     }
     gotoxy(11,25);
     printf("Credit Register");
     for(i=0;i<9;i++)
     {
     cuml=cuml+(ser.credits[i]*ser.points[i]);
     }
     gotoxy(13,25);
     printf("\n\n\t\t25\t\t%d\t     %d\t\t%.2f",sumc,cuml,ser.sgpa);
     gotoxy(27,25);
     printf("Credits Erned");
     gotoxy(47,25);
     printf("C x G");
     gotoxy(62,25);
     printf("SGPA");
     gotoxy(4,25);
     printf("\n\n\n\n     Medium of instruction: English");
     gotoxy(63,256);
     printf("\t\t\tDate : %s",__DATE__);
    // rectangle function
    setcolor(12);
    rectangle(left, top, right, bottom);    //boder1
    rectangle(15,15,634,465);             //boder2
    setcolor(3);
    rectangle(20,150,629,350);             //marks box
    line(20,200,629,200);                 //heding sep line   (all end lines)
    rectangle(65,150,65,350);            //sl vertical line
    rectangle(155,150,155,350);          //course code
    rectangle(387,150,387,350);          //sub name
    rectangle(447,150,447,350);          //credits assigned
    rectangle(513,150,513,350);          //erned
    rectangle(576,150,576,350);          //leter grade
    setcolor(3);
    rectangle(75,440,565,375);             //credits box'
    line(75,400,565,400);
    rectangle(201,440,201,375);
    rectangle(320,440,320,375);
    rectangle(440,440,440,375);
    getch();

      closegraph();
    result(n);

}
}

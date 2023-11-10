//Header files
#include <stdio.h>
#include<string.h>
#include<windows.h>
#include<conio.h>
struct username
{
    char pass[50];
    char username[50];
    char fname[50];
    char lname[50];

}un[50];//structure for storing the details of user
struct passenger {
    int t_no[50], age[50];
   char mob[50][11],from[50][50],to[50][50],name[50][50],cl[50][5];
   char gender[50],date[50][50],deprt[50][50],arrival[50][50];
   
} psngr; //structure for storing the details of passenger

struct train
{
    
    char train_name[10][50], from[10][50], to[10][50], deprt[10][10], arrival[10][10],d[10][12];
    int train_no[10];
    double sl[10], a3[10], a2[10], a1[10];

}t;//structure for storing the details of passenger's ticket


//function to check if the train is their or not
int check_train(struct passenger psngr,struct train t,int l)
 { int temp=0;
 
    for(int i =0;i<10;i++)
    {

        if(t.train_no[i]==psngr.t_no[l])
        {
         temp=1;
         break;
        }
    }
    return temp;
}

// function to check if the train entered by the user exists
int cmpfrom(struct passenger psngr, struct train t, int s_no)
{
    int flag = 0;
    for (int i = 0; i < 10; i++)
    {
        if (strcasecmp(psngr.from[s_no], t.from[i]) == 0)
        {
            flag = 1;
            break; // A train is enroute to the passenger's destination.
        }
        else
        {

            flag = 0;
        }
    }
   return flag;
}

//function to check if the train goes to the place entered by user    
int cmpto(struct passenger psngr, struct train t, int s_no)
{
    int flag = 0;
    for (int i = 0; i < 10; i++)
    {
        if (strcasecmp(psngr.to[s_no], t.to[i]) == 0)
        {
            flag = 1;
            break; // A train is enroute to the passenger's destination.
        }
        else
        {

            flag = 0;
        }
    }
   return flag;
}

int i=0;//declaring the index of passengers accounts

//function to move the cursor in andesired position
void gotoxy(int x,int y){
        COORD c;
        c.X=x;
        c.Y=y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

//menu funcion
int menu()
{   
    int ch;
    printf("[1] : Create Account:  \n");
    printf("[2] : Login:  \n");
    printf("[3] : Exit:  \n");
    printf("   Enter your choice :  ");
    scanf("%d",&ch);
    return ch; 
}

//function to create an account
void createaccount()
{
    
    FILE *fp;//declaring a file pointer
    
    
    system("cls");//for clearing the terminla screen
    
    gotoxy(57,3);

    puts("<--<<Create Account>>-->");
    printf("\n\n");
    printf("    Enter First Name: ");
    fflush(stdin);//
    gets(un[i].fname);
    printf("\n");
    printf("    Enter Last Name: ");
    gets(un[i].lname);
    printf("\n");
    printf("    Enter Username: ");
    scanf("%s",un[i].username);
    printf("\n");
    printf("    Enter Password: ");
    scanf("%s",un[i].pass);
    
    
   fp = fopen("accounts.txt","a");

    if (fp == NULL)
    {
        printf("\nError opened file\n");
        
    }
    
    
    
 fprintf(fp, "FN : %s, LN : %s, UN : %s, PWD : %s \n",un[i].fname,un[i].lname,un[i].username,un[i].pass);  
    fclose (fp);
    system("cls");
    gotoxy(55,20);
    printf(" Account Created Successfully.");
    gotoxy(75,25);
    printf("Press any key to continue...");
    getch();
    system("cls");
    i++;
    
}

//function of login
int login()
{   int index;
    char uname[50],pss[50];//user input variables that will be compared with existing variables
    FILE *fp;
   
    system("cls");
    gotoxy(53,3);
    
    printf("<--<<LOGIN TO YOUR ACCOUNT>>->\n\n");
    printf(" Enter Username: ");
    scanf("%s",uname);
    printf("\n");
    printf(" Enter Password: ");
    scanf("%s",pss);
    ///Reading from file
    fp = fopen("accounts.txt", "r+");
   

    if(fp==NULL)
    {
        printf("\"File not found\"");
        
    }
   
    int found_uname = 0;
    int found_pwd = 0;
    char temp1[100];
    char temp2[100];
    while(fgets(temp1, 100, fp) != NULL){
        
if(strstr(temp1,uname) != NULL ){
            found_uname = 1;
            
        }
        if(strstr(temp1,pss) != NULL){
            found_pwd = 1;
            
        }
    
        }

     
    if(found_uname != 0){
        if(found_pwd != 0){
            int out;
            printf(" \n Username And Password is Correct.\n");
            printf(" Press 1 to continue...");
            scanf("%d",&out);
            getchar();
            if(out==1)
            {
            printf("WELCOME");
            }
            
        }
        else{
                printf("Incorrect Password! \nSignin with Correct Password.\n");
                fclose(fp);

                return 0;
                
        }
    }
    else {
        printf("User doesnot exist in database! \nPlease create account first.\n");
        fclose(fp);
        return 0;
        
    }
    
    fclose(fp);
    system("cls");
    return 1;
    
}

//function to choose between createaccount or login
int  log_sign()
{
    {
        fscreen :
        switch (menu())
        {
        case 1:
            createaccount();
            break;
        
        case 2:
            
            
            if(login() == 0){
                goto fscreen;
            }         
            break;

        case 3:
            exit(0);
        default:
            printf("Invalid Choice! ");
            goto fscreen;
            break;
        }
       

    }
    
    
    return 0;   
}



void insert_train()
{
    //struct train t;
   int m=2001;
   for(int i=0;i<10;i++)
   {
    t.train_no[i]=m;
    m++;
   }

    strcpy(t.train_name[0], "rajdhani express");
    strcpy(t.train_name[1], "purushottam express");
    strcpy(t.train_name[2], "duronto express");
    strcpy(t.train_name[3], "east coast express");
    strcpy(t.train_name[4], "konark express");
    strcpy(t.train_name[5], "sampark kranti express");
    strcpy(t.train_name[6], "puri jodhpur express");
    strcpy(t.train_name[7], "prasanti express");
    strcpy(t.train_name[8], "kharagpur express");
    strcpy(t.train_name[9], "intercity express");

    strcpy(t.from[0],"bhubaneshwar");
    strcpy(t.from[1],"mumbai");
    strcpy(t.from[2],"kolkata");
    strcpy(t.from[3],"ajmer");
    strcpy(t.from[4],"andhra pradeh");
    strcpy(t.from[5],"bangalore");
    strcpy(t.from[6],"dehradoon");
    strcpy(t.from[7],"bhubaneshwar");
    strcpy(t.from[8],"madhya pradesh");
    strcpy(t.from[9],"assam");
    
    strcpy(t.to[0], "new delhi");
    strcpy(t.to[1], "lucknow");
    strcpy(t.to[2], "prayagraj");
    strcpy(t.to[3], "hyderabad");
    strcpy(t.to[4], "puri");
    strcpy(t.to[5], "dehradun");
    strcpy(t.to[6], "jodhpur");
    strcpy(t.to[7], "pune");
    strcpy(t.to[8], "kharagpur");
    strcpy(t.to[9], "west bengal");

    strcpy(t.d[0],"10/11/2023");
    strcpy(t.d[1],"10/11/2023");
    strcpy(t.d[2],"12/11/2023");
    strcpy(t.d[3],"11/11/2023");
    strcpy(t.d[4],"15/11/2023");
    strcpy(t.d[5],"18/11/2023");
    strcpy(t.d[6],"19/11/2023");
    strcpy(t.d[7],"13/11/2023");
    strcpy(t.d[8],"17/11/2023");
    strcpy(t.d[9],"20/11/2023");

    t.sl[0] = 1035.00;
    t.sl[1] = 1400.00;
    t.sl[2] = 1050.00;
    t.sl[3] = 1280.00;
    t.sl[4] = 1430.00;
    t.sl[5] = 1500.00;
    t.sl[6] = 1700.00;
    t.sl[7] = 1200.00;
    t.sl[8] = 1650.00;
    t.sl[9] = 1150.00;

    t.a1[0] = 4800.00;
    t.a1[1] = 4580.00;
    t.a1[2] = 4370.00;
    t.a1[3] = 4200.00;
    t.a1[4] = 4600.00;
    t.a1[5] = 4500.00;
    t.a1[6] = 4900.00;
    t.a1[7] = 4370.00;
    t.a1[8] = 4550.00;
    t.a1[9] = 4700.00;

    t.a2[0] = 3500.00;
    t.a2[1] = 3200.00;
    t.a2[2] = 3160.00;
    t.a2[3] = 3690.00;
    t.a2[4] = 3490.00;
    t.a2[5] = 3500.00;
    t.a2[6] = 3380.00;
    t.a2[7] = 3280.00;
    t.a2[8] = 3480.00;
    t.a2[9] = 3700.00;

    t.a3[0] = 2590.00;
    t.a3[1] = 2480.00;
    t.a3[2] = 2890.00;
    t.a3[3] = 2500.00;
    t.a3[4] = 2670.00;
    t.a3[5] = 2400.00;
    t.a3[6] = 2200.00;
    t.a3[7] = 2280.00;
    t.a3[8] = 2370.00;
    t.a3[9] = 2900.00;

    strcpy(t.deprt[0], "8:00");
    strcpy(t.deprt[1], "9:30");
    strcpy(t.deprt[2], "11:45");
    strcpy(t.deprt[3], "18:00");
    strcpy(t.deprt[4], "20:30");
    strcpy(t.deprt[5], "12:25");
    strcpy(t.deprt[6], "14:50");
    strcpy(t.deprt[7], "21:45");
    strcpy(t.deprt[8], "13:15");
    strcpy(t.deprt[9], "7:45");

    strcpy(t.arrival[0], "21:00");
    strcpy(t.arrival[1], "20:55");
    strcpy(t.arrival[2], "23:30");
    strcpy(t.arrival[3], "5:10");
    strcpy(t.arrival[4], "8:25");
    strcpy(t.arrival[5], "23:45");
    strcpy(t.arrival[6], "6:00");
    strcpy(t.arrival[7], "10:30");
    strcpy(t.arrival[8], "8:15");
    strcpy(t.arrival[9], "20:10"); 
}

//function to cancel ticket
void ticket_cancel(int c_t)
{  
    strcpy(psngr.name[c_t-1],"NA");
    psngr.t_no[c_t-1]=0;
    strcpy(psngr.from[c_t-1],"NA");
    strcpy(psngr.to[c_t-1],"NA");
    strcpy(psngr.mob[c_t-1],"NA");
    strcpy(psngr.cl[c_t-1],"NA");
    psngr.gender[c_t-1]='\0';
    psngr.age[c_t-1]=0;
    strcpy(psngr.date[c_t-1],"NA");
    strcpy(psngr.deprt[c_t-1],"NA");
    strcpy(psngr.arrival[c_t-1],"NA");

}

int main()
{   
    char ch;
    int j,num_tick,i,c_t, can,k,r;
    insert_train();
    printf("\033[1;35m");
    printf("                           RAILWAY TICKETING SYSTEM                             \n");
    printf("\033[1;0m");
    printf("--------------------------------------------------------------------------------\n");
    start:
    log_sign();
    printf("\033[1;34m");
    printf("\nYou have successfully logged in!");
    printf("\033[1;0m");
    goto cont;
    cont:
    printf("\033[1;33m");
    printf("\nOPTIONS:\n");
    printf("\033[1;0m");
    printf("\033[1;35m");
    printf("A. VIEW TRAINS\n");
    printf("B. BOOK TICKET\n");
    printf("C.VIEW ALL BOOKINGS\n");
    printf("D. CANCEL TICKET\n");
    printf("E. LOG OUT\n");
    printf("\033[1;0m");
    printf("ENTER CHOICE: ");
    scanf(" %c", &ch);
    switch (ch) {
        case 'A':
        // Implement viewing of trains
         
         for (i = 0; i < 10; i++)
         {
            printf("train_no: %d\t train_name:%s\t from:%s\t to:%s\t deprt:%s\t arrival:%s\t sl:%lf\t a1:%lf\t a2:%lf\t a3:%lf", t.train_no[i], t.train_name[i], t.from[i], t.to[i], t.deprt[i], t.arrival[i], t.sl[i], t.a1[i], t.a2[i], t.a3[i]);
            printf("\n");
         }
        printf("\nPress 0 to exit");
        scanf("%d", &j);
        if (j == 0)
        goto cont;
        break;
        case 'B':
            // Implement booking a ticket
            printf("\nEnter no. of tickets:");
            
            scanf("%d",&num_tick);
            getchar();
            for(int i=0;i<num_tick;i++)
            {
            printf("\n                                       PASSENGER%d                                      ",i+1);
            printf("\nEnter name:",i);
            gets(psngr.name[i]);
            label1:
            printf("\nEnter gender M(male)/F(female)/O(others):");
            scanf(" %c",&psngr.gender[i]);
            
            if(psngr.gender[i] == 'M' || psngr.gender[i] == 'F' || psngr.gender[i] == 'm' || psngr.gender[i] == 'f' || psngr.gender[i] == 'o' || psngr.gender[i] == 'O'){
                goto label2;
            }
            else {
                printf("\nEnter valid gender!");
                goto label1;
            }
            label2:
            printf("\nEnter age(years):");
            scanf("%d",&psngr.age[i]);
            if(psngr.age[i]<0)
            {
                printf("\nEnter valid age");
                goto label2;

            }
            label3:
            printf("\nEnter train number:");
            scanf("%d",&psngr.t_no[i]);
            getchar();
            
           if(check_train(psngr,t,i)==0)
           {
                printf("\nENTER VALID TRAIN NO.");
                goto label3;
           }
           label4:
            printf("\n1. Sleeper class SL\n2. Three Tier Air Conditioned Class (3AC)\n3. Two Tier Air Conditioned Class (2AC)\n4. First Class Air Conditioned (1AC)\n");
            printf("\nEnter class in the form SL/3AC/2AC/1AC:");
           
                    gets(psngr.cl[i]);
                    if(!(strcasecmp(psngr.cl[i],"SL")==0||strcasecmp(psngr.cl[i],"3AC")==0||strcasecmp(psngr.cl[i],"2AC")==0||strcasecmp(psngr.cl[i],"1AC")==0))
                    {
                        printf("\nEnter valid string!");
                        goto label4;
                    }
            label5:
            printf("\nEnter mobile number:");
            scanf("%s",psngr.mob[i]);
            getchar();
            
            if(psngr.mob[i][0]==0)
            {
            printf("\nEnter a valid mobile number");
            goto label5;
            }
            label6:
            
            printf("\nFROM:");
            gets(psngr.from[i]);
            if(cmpfrom(psngr,t,i)==0)
            {
            printf("\nNo Train Is From %s",psngr.from[i]);
            goto label6;
            }
            for(int g=0;g<10;g++)
             {
                  if(psngr.t_no[i]==t.train_no[g])
                  {
                    r=g;
                    break;
                  }
            }
            strcpy(psngr.deprt[i],t.deprt[r]);
            strcpy(psngr.arrival[i],t.arrival[r]);
            
            label7:
            
           printf("\nTO:");
            gets(psngr.to[i]);
            if(cmpto(psngr,t,i)==0)
            {
         printf("\nNo Train Is Enroute to %s",psngr.to[i]);
            goto label7;
            }
            label8:
            
            printf("\nEnter date of departure in dd/mm/yyyy format:");
            gets(psngr.date[i]);
            int flag=0;
            for(int q=0;q<10;q++)
            { 
                if(strcmp(psngr.date[i],t.d[q])==0)
                { flag=1;
                   break;
                }
                
            }
            if(flag==0)
            {
                printf("\n INVALID DATE");
                    goto label8;
            }

            
            if(i<num_tick-1){
            printf("\nPress 0 to exit or 1 to continue");
            scanf("%d",&j);
            getchar();
            if(j==1)
            {
                continue;
            }
            else{
                goto cont;
            }
            }
            else{
            printf("\033[1;31m");
printf("\nALL TICKETS BOOKED.EXITING TO MAIN MENU");
printf("\033[1;0m");
goto cont;
            }}
            
            
          
            case 'C':
            printf("\033[1;35m");
            printf("                                         ALL TICKETS                                         ");
            printf("\033[1;0m");
            for(int m=0;m<num_tick;m++)
            {   
                
                printf("\nPASSENGER%d",m+1);
                printf("\nTICKET NO:%d",m+1);
                printf("\nNAME :%s",psngr.name[m]);
                printf("\nMOBILE NO.:%s",psngr.mob[m]);
                printf("\nFROM:%s                             TO:%s",psngr.from[m],psngr.to[m]);
                printf("\nGENDER:%c",psngr.gender[m]);
                printf("\nCLASS:%s",psngr.cl[m]);
                printf("\nAGE:%d",psngr.age[m]);
                printf("\nTRAIN NO.:%d",psngr.t_no[m]);
                printf("\nDEPARTURE DATE:%s",psngr.date[m]);
                printf("\nDEPARTURE TIME:%s",psngr.deprt[m]);
                printf("\nARRIVAL TIME:%s",psngr.arrival[m]);

            
            
           
          for(int i=0;i<10;i++)
    {
       if(!strcasecmp(psngr.to[m],t.to[i]))
       k=i;
    }
    char c[4];
    
    if(!(strcasecmp(psngr.cl[m],"SL")))
    printf("\nFARE:%lf",t.sl[k]);
    if(!(strcasecmp(psngr.cl[m],"3AC")))
    printf("\nFARE:%lf",t.a3[k]);
    if(!(strcasecmp(psngr.cl[m],"2AC")))
    printf("\nFARE:%lf",t.a2[k]);
    if(!(strcasecmp(psngr.cl[m],"1AC")))
    printf("\nFARE:%lf",t.a1[k]);
    }
    printf("\nPress 0 to exit");
            scanf("%d", &j);
            if (j == 0)
            {
                goto cont;
            }
    case 'D':
    printf("\033[1;31m");
         printf("\nNo. of tickets to be canceled:");
         printf("\033[1;0m");
         scanf("%d",&can);
         getchar();
         for(int m=0;m<can;m++)
         {
             printf("\nTICKET NO.:");
             scanf("%d",&c_t); 
             getchar();
             if(psngr.name[c_t]=="")
             printf("\nNo such ticket exists.");
             else
             {
             ticket_cancel(c_t);
             }
         }
             printf("\nPress 0 to exit");
            scanf("%d", &j);
             if (j == 0)
             goto cont;
             break;

       case 'E':
              goto start;

        default:
            printf("\nINVALID CHOICE");
            goto cont;
            }
            return 0;
 }
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <time.h>
#include<ctype.h>
int id_Handler();
int age_calculation();
int add();
void displayAll();
int isLeapYear();
void claim_Handler();
int detail_Searcher();
void search();
int ag;
typedef struct
{
    char name[256];
    char contactNumber[15];
    char address[55];
    int age;
    int id;
    long claimLimit;
    char history[555];
}information;
int age_calculation(){
     int DaysInMon[] = {31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31};
    int days, month, year;
    information t1;
    char dob[100];
    time_t ts;
    struct tm *ct;
 
    /* enter date of birth */
    printf("Enter subscriber's date of birth (DD/MM/YYYY): ");
    scanf("%d/%d/%d",&days,&month, &year);
 
    /*get current date.*/
    ts = time(NULL);
    ct = localtime(&ts);
 
    printf("Current Date: %d/%d/%d\n",
            ct->tm_mday, ct->tm_mon + 1, ct->tm_year + 1900);
 
    days = DaysInMon[month - 1] - days + 1;
 
 
    /* calculating age in no of days, years and months */
    days = days + ct->tm_mday;
    month = (12 - month) + (ct->tm_mon);
    year = (ct->tm_year + 1900) - year - 1;
 
 
    if (days >= DaysInMon[ct->tm_mon]) 
    {
            days = days - (DaysInMon[ct->tm_mon]);
            month = month + 1;
    }
 
    if (month >= 12) 
    {
            year = year + 1;
            month = month - 12;
    }
 	ag=year;
    /* print age */
    printf("\n## Hey you are  %d years %d months and %d days old. ##\n", year, month, days);
 
    if (year >= 15 && year <= 20)
    {
        printf("\n\t\t\tPlan 120 (RM) \t Plan 150 (RM) \t Plan200(RM)");
        printf("\nYearly Claim Limit \t 120,000 \t 150,000 \t 200,000");
        printf("\nLifespan Claim Limit \t 600,000 \t 750,000 \t 1,000,000 \n\n\n");

        printf("Types of Claim \t\t Eligibility Amount (RM)");
        printf("\n\t\t\t Plan 120 \t Plan 150 \t Plan 200");
        printf("\nRoom Charges \t\t 120/day \t 150/day \t 200/day");
        printf("\nICU Charges \t\t 250/day \t 400/day \t 700/day");
        printf("\nHospital Supplies\nand Services");
        printf("\nSurgical Fees\t\t\t As Charged");
        printf("\nOther Fees\n");
        add();

    }

    else if (year >= 21 && year <=40)
    {
         printf("\n\t\t\tPlan 150 (RM) \t Plan200(RM)");
        printf("\nYearly Claim Limit \t 150,000 \t 200,000");
        printf("\nLifespan Claim Limit \t 750,000 \t 1,000,000 \n\n\n");

        printf("Types of Claim \t\t Eligibility Amount (RM)");
        printf("\n\t\t\t Plan 150 \t Plan 200");
        printf("\nRoom Charges \t\t 150/day \t 200/day");
        printf("\nICU Charges \t\t 400/day \t 700/day");
        printf("\nHospital Supplies\nand Services");
        printf("\nSurgical Fees\t\t\t As Charged");
        printf("\nOther Fees\n");
        add();
    }
    else if (year >= 41 && year <=54)
    {
        printf("\n\t\t\tPlan200(RM)");
        printf("\nYearly Claim Limit \t 200,000");
        printf("\nLifespan Claim Limit  \t 1,000,000 \n\n\n");

        printf("Types of Claim \t\t Eligibility Amount (RM)");
        printf("\n\t\t\t Plan 200");
        printf("\nRoom Charges \t\t 200/day");
        printf("\nICU Charges \t\t 700/day");
        printf("\nHospital Supplies\nand Services");
        printf("\nSurgical Fees\t\t\t As Charged");
        printf("\nOther Fees\n");
		add();
	}
}
int isLeapYear(int year, int mon) 
{
    int flag = 0;
    if (year % 100 == 0) 
    {
            if (year % 400 == 0) 
            {
                    if (mon == 2) 
                    {
                            flag = 1;
                    }
            }
    } 
    else if (year % 4 == 0) 
    {
            if (mon == 2) 
            {
                    flag = 1;
            }
    }
    return (flag);
}



char fname[]={"info.txt"};//file name where storing take place
int add()
{
	int plan_Select;
    char temp_Policy[55],acl[55];
    FILE *fp;
    information t1;
    int age;int controller=0,controller_Update,choice;
    fp=fopen(fname,"ab");
    age=ag;
    printf("\nEnter your name:");
    fflush(stdin);
    gets(t1.name);
    printf("Enter your number:");
    fflush(stdin);
    scanf("%s",&t1.contactNumber);
    printf("Enter address:");
    fflush(stdin);
    gets(t1.address);
    int iid=id_Handler();
    t1.id=iid;
    printf("Enter if there is any severe medical history: ");
    fflush(stdin);
    gets(t1.history);
    fwrite(&t1,sizeof(information),1,fp);
    fflush(stdin);
    fclose(fp);
    printf("\n\nYour id is %d",t1.id);
}

int id_Handler()
{
    FILE*fq;
    int id,new_Id;
    fq=fopen("Id.c","r");
    if(fq==NULL)
    {
        fq=fopen("Id.c","w");
        fclose(fq);
    }
    fscanf(fq,"%d", &id);
    //printf("%d",id);
    fclose(fq);
    fq=fopen("Id.c","w");
    new_Id=id+1;
    fprintf(fq,"%d",new_Id);
    fclose(fq);
    return id;
}
void displayAll()
{
    FILE *fp;
    information t;
    fp=fopen(fname,"rb");

    printf("\n========================================================\n\n");
    printf("\t\t All  Details\n\n");
    printf("========================================================\n\n");
    //char line[10000];
    //while ( fgets(line, 100, fp) != NULL )
    {
      //  printf("%s",line);
    }
    while(1)
    {
        fread(&t,sizeof(t),1,fp);
        if(feof(fp))
        {
            break;
        }
        printf("\nId %d",t.id);
        printf("\nAge %d",t.age);
        printf("\nName %s",t.name);
        printf("\nNumber %s",t.contactNumber);
        printf("\nAddress: %s",t.address);
        printf("\nHistory: %s",t.history);
    }
printf("========================================================\n\n");

fclose(fp);
}
int main()
{
    char claimtype[2][100]={"Yearly Claim Limit","Lifespan Claim Limit"};
    char choice;
    char ch;
    int total_amt, no_subscriber;
    printf("\n *****ZeeMediLife Insurance Company*****\n");

    do
    {
        printf("\n\nSlect services:\n\n");
        printf("<< Insurance Plan Subsription\t\tPress 1\n<< Claim Process\t\t\tPress 2\n<< Accounts details\t\t\tPress 3\n<< Seeking Subsribers\t\t\tPress 4 \n\t Type 's' to exit");
        fflush(stdin);
        printf("\n\nChoose what you want to do (1-4): ");
        ch = tolower(getchar());
        switch (ch)
        {
            case '1':
                printf("\n<< Request for Claim \t\tPress 1\n<< display Claim Informations\tPress 2\n");
                fflush(stdin);
                choice = getchar();
                switch (choice)
                {
                    case '1':
                        age_calculation();

                        break;
                    case '2':
                        displayAll();
                        break;
                }
                break;
                
            case '2':
                claim_Handler();
            case '3':
                
                printf("\n<< Total claims for lifespan subscribers\t\t\tPress 1\n<< Yearly billing limit Total number of subscribers\t\tPress 2\n");
                fflush(stdin);
                // account_details(total_amt, no_subscriber);
                choice = getchar();
                switch (choice)
                {
                case '1':
                    
                    printf("Total amount requested by lifespan subscribers : Rs.");
                    break;
                
                case '2':
                    printf("Yearly claim limit total number of subscribers: ");
                    break;
                default:
                    printf("\nInvalid Input\n");
                }
                break;
            case '4':
                printf("\n<< Seek by Subscriber ID\tPress 1 \n");
                printf("<< Seek by Name\t\t\tPress 2\n");
                printf("<< Seek by Plan Name\t\tpress 3\n");
                printf("<< Seek By Claim Limit Type\tPress 4\n");
                printf("<< Seek by Age\t\t\tPress 5\n ");

                fflush(stdin);
                choice = getchar();
                
                switch(choice)
                {
                    case '1':
            			detail_Searcher();
                    	break;
                    case '2':
                        search();
                        break;
                    
                }
                break;
        }

    }while (ch!='s');
                    
}
void claim_Handler()
{
    int days,type_Ward;
    float room_Charge,service_Charge,surgical_Fees,other_Fees,total_Charge;
    printf("\nWelcome to the claim section\n");
    printf("Enter the following details for the claim:\n");
    printf("Enter the days of hospitalization: ");
    scanf("%d",&days);
    printf("Press\n1 for normal ward\n2 for ICU\n");
    scanf("%d",&type_Ward);
    switch(type_Ward)
    {
        case 1:
            printf("Enter the room charge per day: ");
            scanf("%f",&room_Charge);
            printf("Enter the Hospital Supplies and Services charge: ");
            scanf("%f",&service_Charge);
            printf("Enter the Surgical Fees: ");
            scanf("%f",&surgical_Fees);
            printf("Enter if there is any other fees: ");
            scanf("%f",&other_Fees);
            total_Charge=(room_Charge*days)+service_Charge+surgical_Fees+other_Fees;
            printf("Total submitted charge amount is: %.2f",total_Charge);
        break;

        case 2:
            printf("Enter the ICU charge per day: ");
            scanf("%f",&room_Charge);
            printf("Enter the Hospital Supplies and Services charge: ");
            scanf("%f",&service_Charge);
            printf("Enter the Surgical Fees: ");
            scanf("%f",&surgical_Fees);
            printf("Enter if there is any other fees: ");
            scanf("%f",&other_Fees);
            total_Charge=(room_Charge*days)+service_Charge+surgical_Fees+other_Fees;
            printf("Total submitted charge amount is: %.2f",total_Charge);
        break;

        default:
            printf("Invalid");
    }
    long Limit=detail_Searcher();
    if(Limit==0)
    {

    }
    else if(total_Charge>Limit)
    {
        //printf("\nSorry not available");
        printf("\nOpt for the differing amount to deposit %ld",(total_Charge-Limit));
    }
    else
    {
        printf("\nProceed for the next steps");
    }

}
void search()
{
FILE *fp;
information t;
int found=0;
char name[20];

fp=fopen(fname,"rb");

printf("\nEnter the  Name:");
fflush(stdin);
scanf("%s",&name);

while(1)
{
    /*char line[10000];
    while ( fgets(line, 100, fp) != NULL )
    {

        if(strcmp(line,name)==0)
        {
            printf("\nDetail Found\n");
            printf("%s",line);
        }
    }*/
    fread(&t,sizeof(information),1,fp);

    if(feof(fp))
    {
        break;
    }
	if(strcmp(name,t.name)==0)
	{
	printf("\n========================================================\n\n");
	printf("\t\t Details of searched one\n\n");
	printf("========================================================\n\n");
	
	printf("%s\t",t.name);
	printf("%s\t",t.address);
	printf("%s\t",t.contactNumber);
	printf("%d\t\n\n",t.age);
	
	printf("========================================================\n\n");
	
	}
}
if(found==0)
{
printf("\nSorry No Record Found");
}
fclose(fp);
}
int detail_Searcher()
{
    FILE *fp;
    information t;
    int id,found=0;
    long cLimit=0;
    fp=fopen(fname,"rb");

    printf("\nEnter the id:");
    scanf("%d",&id);
    while(1)
    {
        fread(&t,sizeof(t),1,fp);

        if(feof(fp))
        {
        break;
        }
        if(t.id==id)
        {
            found=1;
            printf("\n========================================================\n\n");
            printf("\t\t Details\n\n");
            printf("========================================================\n\n");
            printf("\n\t%s\t",t.name);
            printf("\n\t%d",t.age);
            printf("\n\t%ld",t.claimLimit);
            printf("\n\t%s",t.address);
            printf("\n\t%s",t.contactNumber);
            printf("\n\t%s",t.history);
            printf("========================================================\n\n");
            cLimit=t.claimLimit;
        }
    }
    if(found==0)
    {
        printf("\nSorry No Record Found");
        cLimit=0;
    }
    fclose(fp);
    return cLimit;
}

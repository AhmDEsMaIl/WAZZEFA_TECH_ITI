//#include<Clinc_System.h>

#include"Clinc_System.h"
#include <stdio.h>
#include <stdlib.h>

static Patient_Info arr[Size];
static int Pointer;
static char Reverse[Numb_Reverse]= {1,1,1,1,1};
static int Password=1234;
enum State Check_Password (int Pass)
{
    if(Pass==Password)
    {
        return Ok_State;
    }
    else
    {

        Error_State;
    }
}
enum State ID_Search_Repeated (int ID)
{
    for(char i=0; i<Pointer; i++)
    {
        //printf("\ni=%d\n",i);
        if(arr[i].ID==ID)
        {
            return Error_State;
        }
    }
    return Ok_State;
}

enum State ID_Search (int ID,char *index)
{
    for(char i=0; i<Pointer; i++)
    {
        //printf("\ni=%d\n",i);
        if(arr[i].ID==ID)
        {
            *index=i;
            return Ok_State;
        }
    }
    return Error_State;
}

enum State Add_Patient (void)
{
    int Temp_ID;
    char index;
    if(Pointer>=Size)
    {
        return Arr_Full;
    }
    printf("Please Enter ID\n");
    scanf("%d",&Temp_ID);
    //printf("Temp%d",Temp_ID);
    if(ID_Search_Repeated(Temp_ID)==Ok_State)
    {
        arr[Pointer].ID=Temp_ID;
        printf("Please Enter Name\n");
        scanf("%s",arr[Pointer].Name);
        printf("Please Enter Gender\n");
        scanf("%s",arr[Pointer].Gender);
        printf("Please Enter Age\n");
        scanf("%d",&(arr[Pointer].Age));
        arr[Pointer].Reservation=-1;
        Pointer++;
        return  Ok_State;

    }
    else
    {
        return  Error_State;

    }

}

void Scan_Edit_Data(char index)
{
    char choice;
    ("-------------------------------------------\n");
    printf("If you want to edit ID press 1\nIf you want to edit Name press 2\nIf you want to edit Gender press 3\nIf you want to edit age press 4\n");
    printf("-------------------------------------------\n");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("-------------------------------------------\n");
        printf("Plz Enter Your ID\n");
        printf("-------------------------------------------\n");
        scanf("%d",&(arr[index].ID));
        printf("-------------------------------------------\n");
        printf("Done\n");
        printf("-------------------------------------------\n");

        break;
    case 2:
        printf("-------------------------------------------\n");
        printf("Plz Enter Your Name\n");
        printf("-------------------------------------------\n");
        scanf("%s",arr[index].Name);
        printf("-------------------------------------------\n");
        printf("Done\n");
        printf("-------------------------------------------\n");

        break;
    case 3:
        printf("-------------------------------------------\n");
        printf("Plz Enter Your Gender\n");
        printf("-------------------------------------------\n");
        scanf("%s",arr[index].Gender);
        printf("-------------------------------------------\n");
        printf("Done\n");
        printf("-------------------------------------------\n");

        break;
    case 4:
        printf("-------------------------------------------\n");
        printf("Plz Enter Your Age\n");
        printf("-------------------------------------------\n");
        scanf("%d",&(arr[index].Age));
        printf("-------------------------------------------\n");
        printf("Done\n");
        printf("-------------------------------------------\n");


        break;
    default:
        printf("-------------------------------------------\n");
        printf("Wrong Choice\n");
        printf("-------------------------------------------\n");

        Scan_Edit_Data(index);
    }
}
enum State Edit_Patient (void)
{
    char index;
    int ID;
    printf("-------------------------------------------\n");
    printf("Please Enter ID\n");
    printf("-------------------------------------------\n");

    scanf("%d",&ID);
    if(ID_Search(ID,&index)==Ok_State)
    {
        Scan_Edit_Data(index);
        return Ok_State;
    }
    else
    {
        return Error_State;
    }
}
void Scan_Reserveation_Data(char index)
{
    char choice;
    if(Reverse[Numb_Reverse-Numb_Reverse])
    {
        printf("-------------------------------------------------------------\n");
        printf("If you want your Reserveation From 2    pm to   3:30 press 1\n");
        printf("--------------------------------------------------------------\n");


    }
    if(Reverse[Numb_Reverse-Numb_Reverse+1])
    {
        printf("-------------------------------------------------------------\n");
        printf("If you want your Reserveation From 2:30 pm to   3    press 2\n");
        printf("--------------------------------------------------------------\n");


    }
    if(Reverse[Numb_Reverse-Numb_Reverse+2])
    {
        printf("-------------------------------------------------------------\n");
        printf("If you want your Reserveation From 3    pm to   3:30 press 3\n");
        printf("--------------------------------------------------------------\n");


    }
    if(Reverse[Numb_Reverse-Numb_Reverse+3])
    {
        printf("-------------------------------------------------------------\n");
        printf("If you want your Reserveation From 4    pm to   4:30 press 4\n");
        printf("--------------------------------------------------------------\n");


    }
    if(Reverse[Numb_Reverse-Numb_Reverse+4])
    {
        printf("------------------------------------------------------------\n-");
        printf("If you want your Reserveation From 4:30 pm to   5    press 5\n");
        printf("--------------------------------------------------------------\n");


    }
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("-------------------------------------------\n");
        printf("Your Reversation is Done\n");
        printf("-------------------------------------------\n");

        Reverse[0]=0;
        arr[index].Reservation=0;
        break;
    case 2:
        printf("-------------------------------------------\n");
        printf("Your Reversation is Done\n");
        printf("-------------------------------------------\n");
        Reverse[1]=0;
        arr[index].Reservation=1;

        break;
    case 3:
        printf("-------------------------------------------\n");
        printf("Your Reversation is Done\n");
        printf("-------------------------------------------\n");
        Reverse[2]=0;
        arr[index].Reservation=2;

        break;
    case 4:
        printf("-------------------------------------------\n");
        printf("Your Reversation is Done\n");
        printf("-------------------------------------------\n");
        Reverse[3]=0;
        arr[index].Reservation=3;

        break;
    case 5:
        printf("-------------------------------------------\n");
        printf("Your Reversation is Done\n");
        printf("-------------------------------------------\n");
        Reverse[4]=0;
        arr[index].Reservation=4;

        break;
    default:
        printf("-------------------------------------------\n");
        printf("Wrong Choice\n");
        printf("-------------------------------------------\n");
        Scan_Edit_Data(index);
    }
}
enum State Reserve_Slot (void)
{
    char index;
    int ID;
    printf("Please Enter ID\n");
    scanf("%d",&ID);
    if(ID_Search(ID,&index)==Ok_State)
    {
        Scan_Reserveation_Data(index);
        return Ok_State;
    }
    else
    {
        return Error_State;
    }
}
enum State Cancel_Reserve (void)
{
    char index;
    char temp;
    int ID;
    printf("-------------------------------------------\n");
    printf("Please Enter ID\n");
    printf("-------------------------------------------\n");
    scanf("%d",&ID);
    if(ID_Search(ID,&index)==Ok_State)
    {
        temp=arr[index].Reservation;
        Reverse[temp]=1;
        arr[index].Reservation=-1;
        return Ok_State;
    }
    else
    {
        return Error_State;
    }
}
void View_Patient_records(void)
{
    char i;
    for (i=0; i<Pointer; i++)
    {
        printf("-----------------%d--------------------",i+1);
        printf("\nID is %d\n",arr[i].ID);
        printf("Name is %s\n",arr[i].Name);
        printf("Gender is %s\n",arr[i].Gender);
        printf("Age is %d\n",arr[i].Age);
        printf("Reservation is %d\n",arr[i].Reservation+1);
        printf("----------------------------------------\n");
    }
}
void View_Today_Reservation(void)
{
    char i;
    for (i=0; i<Pointer; i++)
    {
        printf("-------------------------------%d-------------------------------",i+1);
        printf("\nyour ID is %d\n",arr[i].ID);
        switch(arr[i].Reservation)
        {
        case 0:
            printf("your Reserveation From 2    pm to   3:30\n");
            break;
        case 1:
            printf("your Reserveation From 2:30 pm to   3   \n");
            break;
        case 2:
            printf("your Reserveation From 3    pm to   3:30 \n");
            break;
        case 3 :
            printf("your Reserveation From 4    pm to   4:30 \n");
            break ;
        case 4 :
            printf("you want your Reserveation From 4:30 pm to   5 \n");
            break;

        }
        printf("---------------------------------------------------------------------\n");
    }
}

void APP_fun_Admin(char Choice)
{
    switch(Choice)
    {
    case 1:
        if(Add_Patient()==Ok_State)
        {
            printf("-------------------------------------------\n");
            printf("Fine\nYour Data has been Stored\n");
            printf("-------------------------------------------\n");

        }
        else if(Add_Patient()==Arr_Full)
        {
            printf("-------------------------------------------\n");
            printf("Menory is FULL\n");
            printf("-------------------------------------------\n");
        }
        else
        {
            printf("-------------------------------------------\n");
            printf("This ID Is Repeated\nEnter Another ID\n");
            printf("-------------------------------------------\n");

            APP_fun_Admin(Choice);
        }
        break;
    case 2:
        if(Edit_Patient()==Ok_State)
        {
            printf("-------------------------------------------\n");
            printf("\nYour Data Is Edited\n");
            printf("-------------------------------------------\n");

        }
        else
        {
            printf("-------------------------------------------\n");
            printf("This ID Is NOT Found\nEnter Another ID\n");
            printf("-------------------------------------------\n");
            APP_fun_Admin(Choice);
        }
        break;
    case 3:
        if(Reserve_Slot()==Ok_State)
        {
            printf("-------------------------------------------\n");
            printf("Your Reservation is Saved\n");
            printf("-------------------------------------------\n");
        }
        else
        {
            printf("-------------------------------------------\n");
            printf("This ID Is NOT Found\n");
            printf("-------------------------------------------\n");
            APP_fun_Admin(Choice);
        }
        break;
    case 4:
        if(Cancel_Reserve()==Ok_State)
        {
            printf("-------------------------------------------\n");
            printf("Your Reservation is Removed\n");
            printf("-------------------------------------------\n");

        }
        else
        {
            printf("-------------------------------------------\n");
            printf("This ID Is NOT Found\n");
            printf("-------------------------------------------\n");
            APP_fun_Admin(Choice);
        }
        break;
    default:
        printf("-------------------------------------------\n");
        printf("Wrong Choice\nPLZ Enter Right Choice\n");
        printf("-------------------------------------------\n");
        APP_fun_Admin(Choice);

    }

}
void APP_fun_User(char Choice)
{
    switch(Choice)
    {
    case 1:
        View_Patient_records();
        break;
    case 2:
        View_Today_Reservation();
        break;
    default:
        printf("-------------------------------------------\n");
        printf("Wrong Choice\nPLZ Enter Right Choice");
        printf("-------------------------------------------\n");
        APP_fun_User(Choice);

    }
}

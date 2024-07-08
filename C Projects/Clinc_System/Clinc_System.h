#ifndef  Clinc_System
#define  Clinc_System

typedef struct
{
    char Name[12];
    char Gender[8];
    int Age;
    int ID;
    int Reservation;
}Patient_Info;

enum State
{
    Ok_State,
    Error_State,
    Arr_Full,
};

#define  Size           5
#define  Numb_Reverse   5
/////////////////////////////// /////////////////////////////////Admin Mode////////////////////////////////////
enum State Add_Patient (void);

enum State ID_Search (int ID,char* index);

enum State Edit_Patient (void);

enum State ID_Search_Repeated (int ID);

void Scan_Edit_Data(char index);

void Scan_Reserveation_Data(char index);

enum State Reserve_Slot (void);

enum State Cancel_Reserve (void);

void APP_fun_Admin(char Choice);

enum State Check_Password (int Pass);

/////////////////////////////// /////////////////////////////////User Mode////////////////////////////////////

void View_Patient_records (void);

void View_Today_Reservation (void);

void APP_fun_User(char Choice);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif // Clinc_System

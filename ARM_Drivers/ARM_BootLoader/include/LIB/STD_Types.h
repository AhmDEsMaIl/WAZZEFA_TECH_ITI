
#ifndef  STD_Types_H_
#define  STD_Types_H_

typedef enum
{
	E_OK,
	E_NOK,
	E_NOK_OUT_OF_RANGE,
	E_NOK_NULL_PTR,
}ReturnType_State_t;

typedef enum
{
	IDLE,
	BUSY
}Module_State_t;
typedef unsigned char 			u8		;
typedef signed   char 			s8      ;
typedef unsigned short 			u16		;
typedef signed   short 			s16     ;
typedef unsigned int 			u32		;
typedef signed   int 			s32     ;

typedef unsigned long long 		u64		;
typedef signed   long long   	s64     ;
typedef float                   f32     ;
typedef double					f64     ;


#define NULL_Ptr		    		(void *)0

#define NULL       		    		      0

typedef void(* PtrToFunc_void)(void);

#endif 		/*End of file : STD_Types.h*/



/****************** "DHRYSTONE" Benchmark Program ***************************/
#define Version "C, Version 2.2"

#include <am.h>
#include <klib-macros.h>
#include <klib.h>

static uint32_t uptime_ms() { return io_read(AM_TIMER_UPTIME).us; }

#define Start_Timer() Begin_Time = uptime_ms()
#define Stop_Timer() End_Time = uptime_ms()

#define NUMBER_OF_RUNS 50 /* Default number of runs */
#define PASS2

#ifdef NOSTRUCTASSIGN
#define structassign(d, s) memcpy(&(d), &(s), sizeof(d))
#else
#define structassign(d, s) d = s
#endif

#ifdef NOENUM
#define Ident_1 0
#define Ident_2 1
#define Ident_3 2
#define Ident_4 3
#define Ident_5 4
typedef int Enumeration;
#else
typedef enum { Ident_1, Ident_2, Ident_3, Ident_4, Ident_5 } Enumeration;
#endif
/* for boolean and enumeration types in Ada, Pascal */

/* General definitions: */

#define Null 0
/* Value of a Null pointer */

typedef int One_Thirty;
typedef int One_Fifty;
typedef char Capital_Letter;
typedef int Boolean;
typedef char Str_30[31];
typedef int Arr_1_Dim[50];
typedef int Arr_2_Dim[50][50];

typedef struct record {
  struct record *Ptr_Comp;
  Enumeration Discr;
  union {
    struct {
      Enumeration Enum_Comp;
      int Int_Comp;
      char Str_Comp[31];
    } var_1;
    struct {
      Enumeration E_Comp_2;
      char Str_2_Comp[31];
    } var_2;
    struct {
      char Ch_1_Comp;
      char Ch_2_Comp;
    } var_3;
  } variant;
} Rec_Type, *Rec_Pointer;

/* Global Variables: */

Rec_Pointer Ptr_Glob, Next_Ptr_Glob;
int Int_Glob;
Boolean Bool_Glob;
char Ch_1_Glob, Ch_2_Glob;
int Arr_1_Glob[50];
int Arr_2_Glob[50][50];

Enumeration Func_1();
/* forward declaration necessary since Enumeration may not simply be int */

#ifndef REG
Boolean Reg = false;
#define REG
/* REG becomes defined as empty */
/* i.e. no register variables   */
#else
Boolean Reg = true;
#undef REG
#define REG register
#endif

Boolean Done;

long Begin_Time, End_Time, User_Time;
float Microseconds, Dhrystones_Per_Second;

/* end of variables for time measurement */

static char memory[1024];
static char *free_mem = &memory[0];

static char *myalloc(size_t size) {
  while ((unsigned long)free_mem % 4 != 0)
    free_mem++;
  char *ret = free_mem;
  free_mem += size;
  return ret;
}

void Proc_6(Enumeration, Enumeration *);
void Proc_3(Rec_Pointer *);
void Proc_7(One_Fifty a, One_Fifty b, One_Fifty *c);
Boolean Func_2(Str_30, Str_30);
void Proc_8(Arr_1_Dim, Arr_2_Dim, int, int);
Boolean Func_3(Enumeration);

void Proc_1(Ptr_Val_Par)
    /******************/
    REG Rec_Pointer Ptr_Val_Par;
/* executed once */
{
  REG Rec_Pointer Next_Record = Ptr_Val_Par->Ptr_Comp;
  /* == Ptr_Glob_Next */
  /* Local variable, initialized with Ptr_Val_Par->Ptr_Comp,    */
  /* corresponds to "rename" in Ada, "with" in Pascal           */

  structassign(*Ptr_Val_Par->Ptr_Comp, *Ptr_Glob);
  Ptr_Val_Par->variant.var_1.Int_Comp = 5;
  Next_Record->variant.var_1.Int_Comp = Ptr_Val_Par->variant.var_1.Int_Comp;
  Next_Record->Ptr_Comp = Ptr_Val_Par->Ptr_Comp;
  Proc_3(&Next_Record->Ptr_Comp);
  /* Ptr_Val_Par->Ptr_Comp->Ptr_Comp
     == Ptr_Glob->Ptr_Comp */
  if (Next_Record->Discr == Ident_1)
  /* then, executed */
  {
    Next_Record->variant.var_1.Int_Comp = 6;
    Proc_6(Ptr_Val_Par->variant.var_1.Enum_Comp,
           &Next_Record->variant.var_1.Enum_Comp);
    Next_Record->Ptr_Comp = Ptr_Glob->Ptr_Comp;
    Proc_7(Next_Record->variant.var_1.Int_Comp, 10,
           &Next_Record->variant.var_1.Int_Comp);
  } else /* not executed */
    structassign(*Ptr_Val_Par, *Ptr_Val_Par->Ptr_Comp);
} /* Proc_1 */

void Proc_2(Int_Par_Ref)
    /******************/
    /* executed once */
    /* *Int_Par_Ref == 1, becomes 4 */
    One_Fifty *Int_Par_Ref;
{
  One_Fifty Int_Loc;
  Enumeration Enum_Loc;

  Int_Loc = *Int_Par_Ref + 10;
  do /* executed once */
    if (Ch_1_Glob == 'A')
    /* then, executed */
    {
      Int_Loc -= 1;
      *Int_Par_Ref = Int_Loc - Int_Glob;
      Enum_Loc = Ident_1;
    }                          /* if */
  while (Enum_Loc != Ident_1); /* true */
} /* Proc_2 */

void Proc_3(Ptr_Ref_Par)
    /******************/
    /* executed once */
    /* Ptr_Ref_Par becomes Ptr_Glob */
    Rec_Pointer *Ptr_Ref_Par;

{
  if (Ptr_Glob != Null)
    /* then, executed */
    *Ptr_Ref_Par = Ptr_Glob->Ptr_Comp;
  Proc_7(10, Int_Glob, &Ptr_Glob->variant.var_1.Int_Comp);
} /* Proc_3 */

void Proc_4() { /* without parameters */

  /*******/
  /* executed once */
  Boolean Bool_Loc;

  Bool_Loc = Ch_1_Glob == 'A';
  Bool_Glob = Bool_Loc | Bool_Glob;
  Ch_2_Glob = 'B';
} /* Proc_4 */

void Proc_5() { /* without parameters */

  /*******/
  /* executed once */ Ch_1_Glob = 'A';
  Bool_Glob = false;
} /* Proc_5 */

/* Procedure for the assignment of structures,          */
/* if the C compiler doesn't support this feature       */
#ifdef NOSTRUCTASSIGN
memcpy(d, s, l) register char *d;
register char *s;
register int l;
{
  while (l--)
    *d++ = *s++;
}
#endif

#ifndef REG
#define REG
/* REG becomes defined as empty */
/* i.e. no register variables   */
#else
#undef REG
#define REG register
#endif

extern int Int_Glob;
extern char Ch_1_Glob;

void Proc_6(Enum_Val_Par, Enum_Ref_Par)
    /*********************************/
    /* executed once */
    /* Enum_Val_Par == Ident_3, Enum_Ref_Par becomes Ident_2 */
    Enumeration Enum_Val_Par;
Enumeration *Enum_Ref_Par;
{
  *Enum_Ref_Par = Enum_Val_Par;
  if (!Func_3(Enum_Val_Par))
    /* then, not executed */
    *Enum_Ref_Par = Ident_4;
  switch (Enum_Val_Par) {
  case Ident_1:
    *Enum_Ref_Par = Ident_1;
    break;
  case Ident_2:
    if (Int_Glob > 100)
      /* then */
      *Enum_Ref_Par = Ident_1;
    else
      *Enum_Ref_Par = Ident_4;
    break;
  case Ident_3: /* executed */
    *Enum_Ref_Par = Ident_2;
    break;
  case Ident_4:
    break;
  case Ident_5:
    *Enum_Ref_Par = Ident_3;
    break;
  } /* switch */
} /* Proc_6 */

void Proc_7(One_Fifty Int_1_Par_Val, One_Fifty Int_2_Par_Val,
            One_Fifty *Int_Par_Ref) {
  One_Fifty Int_Loc;

  Int_Loc = Int_1_Par_Val + 2;
  *Int_Par_Ref = Int_2_Par_Val + Int_Loc;
} /* Proc_7 */

void Proc_8(Arr_1_Par_Ref, Arr_2_Par_Ref, Int_1_Par_Val, Int_2_Par_Val)
    /*********************************************************************/
    /* executed once      */
    /* Int_Par_Val_1 == 3 */
    /* Int_Par_Val_2 == 7 */
    Arr_1_Dim Arr_1_Par_Ref;
Arr_2_Dim Arr_2_Par_Ref;
int Int_1_Par_Val;
int Int_2_Par_Val;
{
  REG One_Fifty Int_Index;
  REG One_Fifty Int_Loc;

  Int_Loc = Int_1_Par_Val + 5;
  Arr_1_Par_Ref[Int_Loc] = Int_2_Par_Val;
  Arr_1_Par_Ref[Int_Loc + 1] = Arr_1_Par_Ref[Int_Loc];
  Arr_1_Par_Ref[Int_Loc + 30] = Int_Loc;
  for (Int_Index = Int_Loc; Int_Index <= Int_Loc + 1; ++Int_Index)
    Arr_2_Par_Ref[Int_Loc][Int_Index] = Int_Loc;
  Arr_2_Par_Ref[Int_Loc][Int_Loc - 1] += 1;
  Arr_2_Par_Ref[Int_Loc + 20][Int_Loc] = Arr_1_Par_Ref[Int_Loc];
  Int_Glob = 5;
} /* Proc_8 */

Enumeration Func_1(Ch_1_Par_Val, Ch_2_Par_Val)
/*************************************************/
/* executed three times                                         */
/* first call:      Ch_1_Par_Val == 'H', Ch_2_Par_Val == 'R'    */
/* second call:     Ch_1_Par_Val == 'A', Ch_2_Par_Val == 'C'    */
/* third call:      Ch_1_Par_Val == 'B', Ch_2_Par_Val == 'C'    */
Capital_Letter Ch_1_Par_Val;
Capital_Letter Ch_2_Par_Val;
{
  Capital_Letter Ch_1_Loc;
  Capital_Letter Ch_2_Loc;

  Ch_1_Loc = Ch_1_Par_Val;
  Ch_2_Loc = Ch_1_Loc;
  if (Ch_2_Loc != Ch_2_Par_Val)
    /* then, executed */
    return (Ident_1);
  else { /* not executed */
    Ch_1_Glob = Ch_1_Loc;
    return (Ident_2);
  }
} /* Func_1 */

Boolean Func_2(Str_1_Par_Ref, Str_2_Par_Ref)
/*************************************************/
/* executed once */
/* Str_1_Par_Ref == "DHRYSTONE PROGRAM, 1'ST STRING" */
/* Str_2_Par_Ref == "DHRYSTONE PROGRAM, 2'ND STRING" */
Str_30 Str_1_Par_Ref;
Str_30 Str_2_Par_Ref;
{
  REG One_Thirty Int_Loc;
  Capital_Letter Ch_Loc;

  Int_Loc = 2;
  while (Int_Loc <= 2) /* loop body executed once */
    if (Func_1(Str_1_Par_Ref[Int_Loc], Str_2_Par_Ref[Int_Loc + 1]) == Ident_1)
    /* then, executed */
    {
      Ch_Loc = 'A';
      Int_Loc += 1;
    } /* if, while */
  if (Ch_Loc >= 'W' && Ch_Loc < 'Z')
    /* then, not executed */
    Int_Loc = 7;
  if (Ch_Loc == 'R') {
    /* then, not executed */
    return (true);
  } else { /* executed */
    if (strcmp(Str_1_Par_Ref, Str_2_Par_Ref) > 0) {
      Int_Loc += 7;
      Int_Glob = Int_Loc;
      return (true);
    } else /* executed */
      return (false);
  } /* if Ch_Loc */
} /* Func_2 */

Boolean Func_3(Enum_Par_Val)
/***************************/
/* executed once        */
/* Enum_Par_Val == Ident_3 */
Enumeration Enum_Par_Val;
{
  Enumeration Enum_Loc;

  Enum_Loc = Enum_Par_Val;
  if (Enum_Loc == Ident_3)
    /* then, executed */
    return (true);
  else /* not executed */
    return (false);
} /* Func_3 */

Boolean pass = true;
Boolean check(int cond) {
  if (!cond)
    pass = false;
  return cond;
}

int main()
/*****/
/* main program, corresponds to procedures        */
/* Main and Proc_0 in the Ada version             */
{
  One_Fifty Int_1_Loc;
  REG One_Fifty Int_2_Loc;
  One_Fifty Int_3_Loc;
  REG char Ch_Index;
  Enumeration Enum_Loc;
  Str_30 Str_1_Loc;
  Str_30 Str_2_Loc;
  REG int Run_Index;
  REG int Number_Of_Runs;

  ioe_init();

  Number_Of_Runs = NUMBER_OF_RUNS;

  /* Initializations */

  Next_Ptr_Glob = (Rec_Pointer)myalloc(sizeof(Rec_Type));
  Ptr_Glob = (Rec_Pointer)myalloc(sizeof(Rec_Type));

  Ptr_Glob->Ptr_Comp = Next_Ptr_Glob;
  Ptr_Glob->Discr = Ident_1;
  Ptr_Glob->variant.var_1.Enum_Comp = Ident_3;
  Ptr_Glob->variant.var_1.Int_Comp = 40;
  strcpy(Ptr_Glob->variant.var_1.Str_Comp, "DHRYSTONE PROGRAM, SOME STRING");
  strcpy(Str_1_Loc, "DHRYSTONE PROGRAM, 1'ST STRING");

  Arr_2_Glob[8][7] = 10;
  /* Was missing in published program. Without this statement,    */
  /* Arr_2_Glob [8][7] would have an undefined value.             */
  /* Warning: With 16-Bit processors and Number_Of_Runs > 32000,  */
  /* overflow may occur for this array element.                   */

  printf("Dhrystone Benchmark, Version %s\n", Version);

  Done = false;
  while (!Done) {

    printf("Trying %d runs through Dhrystone.\n", Number_Of_Runs);

    /***************/
    /* Start timer */
    /***************/

    Start_Timer();

    for (Run_Index = 1; Run_Index <= Number_Of_Runs; ++Run_Index) {

      Proc_5();
      Proc_4();
      /* Ch_1_Glob == 'A', Ch_2_Glob == 'B', Bool_Glob == true */
      Int_1_Loc = 2;
      Int_2_Loc = 3;
      strcpy(Str_2_Loc, "DHRYSTONE PROGRAM, 2'ND STRING");
      Enum_Loc = Ident_2;
      Bool_Glob = !Func_2(Str_1_Loc, Str_2_Loc);
      /* Bool_Glob == 1 */
      while (Int_1_Loc < Int_2_Loc) { /* loop body executed once */
        Int_3_Loc = 5 * Int_1_Loc - Int_2_Loc;
        /* Int_3_Loc == 7 */
        Proc_7(Int_1_Loc, Int_2_Loc, &Int_3_Loc);
        /* Int_3_Loc == 7 */
        Int_1_Loc += 1;
      } /* while */
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
      Proc_8(Arr_1_Glob, Arr_2_Glob, Int_1_Loc, Int_3_Loc);
      /* Int_Glob == 5 */
      Proc_1(Ptr_Glob);
      for (Ch_Index = 'A'; Ch_Index <= Ch_2_Glob; ++Ch_Index)
      /* loop body executed twice */
      {
        if (Enum_Loc == Func_1(Ch_Index, 'C'))
        /* then, not executed */
        {
          Proc_6(Ident_1, &Enum_Loc);
          strcpy(Str_2_Loc, "DHRYSTONE PROGRAM, 3'RD STRING");
          Int_2_Loc = Run_Index;
          Int_Glob = Run_Index;
        }
      }
      /* Int_1_Loc == 3, Int_2_Loc == 3, Int_3_Loc == 7 */
      Int_2_Loc = Int_2_Loc * Int_1_Loc;
      Int_1_Loc = Int_2_Loc / Int_3_Loc;
      Int_2_Loc = 7 * (Int_2_Loc - Int_3_Loc) - Int_1_Loc;
      /* Int_1_Loc == 1, Int_2_Loc == 13, Int_3_Loc == 7 */
      Proc_2(&Int_1_Loc);
      /* Int_1_Loc == 5 */

    } /* loop "for Run_Index" */

    /**************/
    /* Stop timer */
    /**************/

    Stop_Timer();

    User_Time = End_Time - Begin_Time;

    Done = true;
  }

  if (!check(Int_Glob == 5)) {
    printf("Int_Glob:            %d\n", Int_Glob);
    printf("        should be:   %d\n", 5);
  }
  if (!check(Bool_Glob == 1)) {
    printf("Bool_Glob:           %d\n", Bool_Glob);
    printf("        should be:   %d\n", 1);
  }
  if (!check(Ch_1_Glob == 'A')) {
    printf("Ch_1_Glob:           %c\n", Ch_1_Glob);
    printf("        should be:   %c\n", 'A');
  }
  if (!check(Ch_2_Glob == 'B')) {
    printf("Ch_2_Glob:           %c\n", Ch_2_Glob);
    printf("        should be:   %c\n", 'B');
  }
  if (!check(Arr_1_Glob[8] == 7)) {
    printf("Arr_1_Glob[8]:       %d\n", Arr_1_Glob[8]);
    printf("        should be:   %d\n", 7);
  }
  if (!check(Arr_2_Glob[8][7] == Number_Of_Runs + 10)) {
    printf("Arr_2_Glob[8][7]:    %d\n", Arr_2_Glob[8][7]);
    printf("        should be:   Number_Of_Runs + 10\n");
  }

  if (!check((int)Ptr_Glob->Discr == 0)) {
    printf("Ptr_Glob->Discr:             %d\n", Ptr_Glob->Discr);
    printf("        should be:   %d\n", 0);
  }
  if (!check(Ptr_Glob->variant.var_1.Enum_Comp == 2)) {
    printf("Ptr_Glob->Enum_Comp:         %d\n",
           Ptr_Glob->variant.var_1.Enum_Comp);
    printf("        should be:   %d\n", 2);
  }
  if (!check(Ptr_Glob->variant.var_1.Int_Comp == 17)) {
    printf("Ptr_Glob->Int_Comp:          %d\n",
           Ptr_Glob->variant.var_1.Int_Comp);
    printf("        should be:   %d\n", 17);
  }
  if (!check(strcmp(Ptr_Glob->variant.var_1.Str_Comp,
                    "DHRYSTONE PROGRAM, SOME STRING") == 0)) {
    printf("Ptr_Glob->Str_Comp:          %s\n",
           Ptr_Glob->variant.var_1.Str_Comp);
    printf("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  }

  if (!check((int)Next_Ptr_Glob->Discr == 0)) {
    printf("Next_Ptr_Glob->Discr:             %d\n", Next_Ptr_Glob->Discr);
    printf("        should be:   %d\n", 0);
  }
  if (!check(Next_Ptr_Glob->variant.var_1.Enum_Comp == 1)) {
    printf("Next_Ptr_Glob->Enum_Comp:         %d\n",
           Next_Ptr_Glob->variant.var_1.Enum_Comp);
    printf("        should be:   %d\n", 1);
  }
  if (!check(Next_Ptr_Glob->variant.var_1.Int_Comp == 18)) {
    printf("Next_Ptr_Glob->Int_Comp:          %d\n",
           Next_Ptr_Glob->variant.var_1.Int_Comp);
    printf("        should be:   %d\n", 18);
  }
  if (!check(strcmp(Next_Ptr_Glob->variant.var_1.Str_Comp,
                    "DHRYSTONE PROGRAM, SOME STRING") == 0)) {
    printf("Next_Ptr_Glob->Str_Comp:          %s\n",
           Next_Ptr_Glob->variant.var_1.Str_Comp);
    printf("        should be:   DHRYSTONE PROGRAM, SOME STRING\n");
  }

  if (!check(Int_1_Loc == 5)) {
    printf("Int_1_Loc:           %d\n", Int_1_Loc);
    printf("        should be:   %d\n", 5);
  }
  if (!check(Int_2_Loc == 13)) {
    printf("Int_2_Loc:           %d\n", Int_2_Loc);
    printf("        should be:   %d\n", 13);
  }
  if (!check(Int_3_Loc == 7)) {
    printf("Int_3_Loc:           %d\n", Int_3_Loc);
    printf("        should be:   %d\n", 7);
  }
  if (!check(Enum_Loc == 1)) {
    printf("Enum_Loc:            %d\n", Enum_Loc);
    printf("        should be:   %d\n", 1);
  }

  if (!check(strcmp(Str_1_Loc, "DHRYSTONE PROGRAM, 1'ST STRING") == 0)) {
    printf("Str_1_Loc:           %s\n", Str_1_Loc);
    printf("        should be:   DHRYSTONE PROGRAM, 1'ST STRING\n");
  }
  if (!check(strcmp(Str_2_Loc, "DHRYSTONE PROGRAM, 2'ND STRING") == 0)) {
    printf("Str_2_Loc:           %s\n", Str_2_Loc);
    printf("        should be:   DHRYSTONE PROGRAM, 2'ND STRING\n");
  }

  printf("Finished in %d ms\n", (int)User_Time);
  printf("==================================================\n");
  printf("Dhrystone %s\n", pass ? "PASS" : "FAIL");

  return (pass ? 0 : 1);
}

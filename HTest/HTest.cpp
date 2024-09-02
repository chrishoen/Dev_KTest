/*==============================================================================
Description:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include "stdafx.h"

#include <conio.h>
#include <ctype.h>

#define  _HTEST_CPP_
#include "HTest.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor

HTest::HTest()
   :
   mRandomGen(mRandomDevice()),
   mRandomInt(0, 99)
{
   reset();
}

void HTest::reset()
{
   mInString[0] = 0;
}

void HTest::show()
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Generate output.

void HTest::doGenOut1()
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Run test.

bool HTest::doTest()
{
   return true;
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Run test.

void HTest::doRun1()
{
   printf("start\n");
   mRandomGen.seed();

   int tChar;
   int tValue = 0;
   while (true)
   {
      tValue = mRandomInt(mRandomGen);
      printf("here    %d  $  ", tValue);
      tChar = getchar();

      // Test for exit.
      if (tChar == 'e')
      {
         printf("\r\ndone\n");
         return;
      }

      // Goto the beginning of the previous line, clear it, 
      // and return to the beginning of it.
      printf("\033[F\r                                     \r");
   }
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Run test.

void HTest::doRun2()
{
   printf("start\n");

   int tValue = 0;
   int tCount = 0;
   int tRet = 0;
   while (true)
   {
      printf("here    %d  $  ", tCount++);

      // Input an integer. This does a CRLF to the next line.
      tRet = scanf("%d", &tValue);
      // Test for exit.
      if (tRet == 0)
      {
         printf("\r\ndone\n");
         return;
      }
      // Goto the beginning of the previous line, clear it, 
      // and return to the beginning of it.
      printf("\033[F\r                                     \r");
   }
}

// \033[A move cursor up on line
// \033[F move cursor to the beginning of the previous line
// \n linefeed
// \r carriage return 

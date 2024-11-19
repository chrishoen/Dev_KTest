/*==============================================================================
Description:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include "stdafx.h"

#include <conio.h>
#include <ctype.h>

#define  _TESTSUB2_CPP_
#include "TestSub2.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor

TestSub2::TestSub2()
{
   reset(9, 9);
}

void TestSub2::reset(int aN1, int aN2)
{
   mInString[0] = 0;
   std::random_device tDev;
   std::seed_seq tSeed{ tDev(), tDev(), tDev(), tDev(), tDev(), tDev() };
   mRandomGen.seed(tSeed);
   mRandomInt1.reset();
   mRandomInt1.param(std::uniform_int_distribution<>::param_type(0, aN1));
   mRandomInt2.reset();
   mRandomInt2.param(std::uniform_int_distribution<>::param_type(0, aN2));
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Run test.

void TestSub2::doTest(int aN1, int aN2)
{
   printf("start\n");
   reset(aN1, aN2);

   while (true)
   {
      // Two random ints, max is the first one.
      int tTemp1 = mRandomInt1(mRandomGen);
      int tTemp2 = mRandomInt2(mRandomGen);
      int tValue1 = tTemp1;
      int tValue2 = tTemp2;
      if (tTemp1 < tTemp2)
      {
         tValue1 = tTemp2;
         tValue2 = tTemp1;
      }

      // Subtract.
      int tValue3 = tValue1 - tValue2;
      int tInput = 0;
      int tRet = 0;
      char tString[100];

      // Loop to get the user result.
      while (true)
      {
         printf("%3d - %3d $  ", tValue1, tValue2);

         // Input a string at the cursor.
         fgets(tString, 99, stdin);
         if (strlen(tString) == 0)
         {
            printf("done\n");
            return;
         }

         // Get an integer value from the string.
         tRet = sscanf(tString, "%d", &tInput);
         // Test for exit.
         if (tRet == 0)
         {
            printf("done\n");
            return;
         }

         // Test the value.
         if (tInput == tValue3)
         {
            break;
         }
         printf("fail\n");
      }
   }
}


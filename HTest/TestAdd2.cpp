/*==============================================================================
Description:
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************
#include "stdafx.h"

#include <conio.h>
#include <ctype.h>

#include "someAlphaParms.h"

#define  _TESTADD2_CPP_
#include "TestAdd2.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor

TestAdd2::TestAdd2()
{
   reset();
}

void TestAdd2::reset()
{
   mInString[0] = 0;
   std::random_device tDev;
   std::seed_seq tSeed{ tDev(), tDev(), tDev(), tDev(), tDev(), tDev() };
   mRandomGen.seed(tSeed);
   mRandomInt1.reset();
   mRandomInt1.param(std::uniform_int_distribution<>::param_type(0, Some::gAlphaParms.mN1));
   mRandomInt2.reset();
   mRandomInt2.param(std::uniform_int_distribution<>::param_type(0, 18));
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Run test.

void TestAdd2::doTest()
{
   printf("start\n");
   reset();

   while (true)
   {
      int tValue1 = mRandomInt1(mRandomGen);
      int tValue2 = mRandomInt2(mRandomGen);
      int tValue3 = tValue1 + tValue2;
      int tInput = 0;
      int tRet = 0;
      char tString[100];

      while (true)
      {
         printf("%3d + %3d $  ", tValue1, tValue2);

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


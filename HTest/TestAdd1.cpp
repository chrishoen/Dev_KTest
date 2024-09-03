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

#define  _TESTADD1_CPP_
#include "TestAdd1.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Constructor

TestAdd1::TestAdd1()
{
   reset();
}

void TestAdd1::reset()
{
   mInString[0] = 0;
   std::random_device tDev;
   std::seed_seq tSeed{ tDev(), tDev(), tDev(), tDev(), tDev(), tDev() };
   mRandomGen.seed(tSeed);
   mRandomInt.reset();
   mRandomInt.param(std::uniform_int_distribution<>::param_type(0, Some::gAlphaParms.mN1));
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Run test.

void TestAdd1::doTest()
{
   printf("start\n");
   reset();

   while (true)
   {
      int tValue1 = mRandomInt(mRandomGen);
      int tValue2 = mRandomInt(mRandomGen);
      int tValue3 = tValue1 + tValue2;
      int tInput = 0;
      int tRet = 0;
      char tString[100];
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
      if (tInput != tValue3)
      {
         printf("fail\n");
      }
   }
}


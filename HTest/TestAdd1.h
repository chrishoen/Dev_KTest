#pragma once

/*==============================================================================
==============================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include <random>

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This class implements a general purpose shared storage object. It contains
// status counters and flags.

class TestAdd1
{
public:

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Constants.

   static const int cMaxStringSize = 100;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members:

   // Output.
   char mInString[cMaxStringSize];

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members:

   // Random number generator for random timer delay.
   std::default_random_engine mRandomGen;
   std::uniform_int_distribution<> mRandomInt;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods:

   // Constructor.
   TestAdd1();
   void reset();

   // Tests.
   void doTest();
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Global instance

#ifdef _TESTADD1_CPP_
          TestAdd1 gTestAdd1;
#else
   extern TestAdd1 gTestAdd1;
#endif

//******************************************************************************
//******************************************************************************
//******************************************************************************

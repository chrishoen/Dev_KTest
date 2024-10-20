
#include "stdafx.h"

#include "risBaseDir.h"

#include "cmnPaths.h"
#include "someAlphaParms.h"

#include "MainInit.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Initialize.

void main_initialize()
{
   printf("ATest **********************************************BEGIN\n");

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Process configuration.

   // Set the program current working directory and the base 
   // directory to the program bin directory.
   Ris::chdirBaseDirectoryToBin();

   // Initialize file paths.
   Cmn::initialize_paths_cli();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Read parameters files.

   // Read parms file.
   Some::gAlphaParms.reset();
   Some::gAlphaParms.readSection("default");

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Initialize print facility.

   // Initialize print.
   Prn::resetPrint();
   Prn::initializePrint();

   // Initialize print filters.
   Prn::setFilter(Prn::Show0, true);
   Prn::setFilter(Prn::Show1, false);
   Prn::setFilter(Prn::Show2, false);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Finalize.

void main_finalize()
{
   // Finalize file paths.
   Cmn::finalize_paths();

   // Finalize print facility.
   Prn::finalizePrint();

   printf("ATest **********************************************END\n");
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
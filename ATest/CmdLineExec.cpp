#include "stdafx.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <Windows.h>
#include "string.h"

#include "someAlphaParms.h"
#include "HTest.h"
#include "TestAdd2.h"
#include "TestSub2.h"
#include "CmdLineExec.h"

//******************************************************************************
//******************************************************************************
//******************************************************************************

CmdLineExec::CmdLineExec()
{
}

void CmdLineExec::reset()
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************
// This class is the program command line executive. It processes user
// command line inputs and executes them. It inherits from the command line
// command executive base class, which provides an interface for executing
// command line commands. It provides an override execute function that is
// called by a console executive when it receives a console command line input.
// The execute function then executes the command.

void CmdLineExec::execute(Ris::CmdLineCmd* aCmd)
{
   if(aCmd->isCmd("RESET"))   reset();
   if (aCmd->isCmd("RUN1"))   executeRun1(aCmd);
   if (aCmd->isCmd("ADD2"))   executeAdd2(aCmd);
   if (aCmd->isCmd("SUB2"))   executeSub2(aCmd);

   if (aCmd->isCmd("GO1"))    executeGo1(aCmd);
   if (aCmd->isCmd("GO2"))    executeGo2(aCmd);
   if (aCmd->isCmd("GO3"))    executeGo3(aCmd);
   if (aCmd->isCmd("GO4"))    executeGo4(aCmd);
   if (aCmd->isCmd("GO5"))    executeGo5(aCmd);
   if (aCmd->isCmd("GO6"))    executeGo6(aCmd);

   if (aCmd->isCmd("PARMS"))  executeParms(aCmd);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeRun1(Ris::CmdLineCmd* aCmd)
{
   gHTest.doRun1();
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeAdd2(Ris::CmdLineCmd* aCmd)
{
   aCmd->setArgDefault(1, 999);
   aCmd->setArgDefault(2, 999);
   int tN1 = aCmd->argInt(1);
   int tN2 = aCmd->argInt(2);
   Prn::print(0, "Add2 %d %d", tN1, tN2);
   gTestAdd2.doTest(tN1, tN2);
}

void CmdLineExec::executeSub2(Ris::CmdLineCmd* aCmd)
{
   aCmd->setArgDefault(1, 999);
   aCmd->setArgDefault(2, 999);
   int tN1 = aCmd->argInt(1);
   int tN2 = aCmd->argInt(2);
   Prn::print(0, "Sub2 %d %d", tN1, tN2);
   gTestSub2.doTest(tN1, tN2);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo1(Ris::CmdLineCmd* aCmd)
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo2(Ris::CmdLineCmd* aCmd)
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo3(Ris::CmdLineCmd* aCmd)
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo4(Ris::CmdLineCmd* aCmd)
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo5(Ris::CmdLineCmd* aCmd)
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo6(Ris::CmdLineCmd* aCmd)
{
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeParms(Ris::CmdLineCmd* aCmd)
{
}

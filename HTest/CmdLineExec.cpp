#include "stdafx.h"

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <Windows.h>
#include "string.h"

#include "someAlphaParms.h"
#include "HTest.h"
#include "TestAdd1.h"
#include "TestAdd2.h"
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
   if (aCmd->isCmd("ADD1"))   executeAdd1(aCmd);
   if (aCmd->isCmd("ADD2"))   executeAdd2(aCmd);

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

void CmdLineExec::executeAdd1(Ris::CmdLineCmd* aCmd)
{
   gTestAdd1.doTest();
}

void CmdLineExec::executeAdd2(Ris::CmdLineCmd* aCmd)
{
   gTestAdd2.doTest();
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo1(Ris::CmdLineCmd* aCmd)
{
   CONSOLE_FONT_INFOEX tInfo;
   memset(&tInfo, 0, sizeof(tInfo));
   tInfo.cbSize = sizeof(tInfo);
   HANDLE tHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   if (!GetCurrentConsoleFontEx(tHandle, FALSE, &tInfo))
   {
      Prn::print(0, "FAIL %d", GetLastError());
   }
   Prn::print(0, "dwFontSize.X %d", tInfo.dwFontSize.X);
   Prn::print(0, "dwFontSize.Y %d", tInfo.dwFontSize.Y);
   Prn::print(0, "dwFontSize.Y %d", tInfo.nFont);
}

//******************************************************************************
//******************************************************************************
//******************************************************************************

void CmdLineExec::executeGo2(Ris::CmdLineCmd* aCmd)
{
   CONSOLE_FONT_INFOEX tInfo;
   memset(&tInfo, 0, sizeof(tInfo));
   tInfo.cbSize = sizeof(tInfo);
   HANDLE tHandle = GetStdHandle(STD_OUTPUT_HANDLE);
   if (!GetCurrentConsoleFontEx(tHandle, FALSE, &tInfo))
   {
      Prn::print(0, "FAIL1 %d", GetLastError());
   }
   Prn::print(0, "dwFontSize.X %d", tInfo.dwFontSize.X);
   Prn::print(0, "dwFontSize.Y %d", tInfo.dwFontSize.Y);
   Prn::print(0, "dwFontSize.Y %d", tInfo.nFont);


   tInfo.dwFontSize.X = 24;
   tInfo.dwFontSize.Y = 32;
   if (!SetCurrentConsoleFontEx(tHandle, FALSE, &tInfo))
   {
      Prn::print(0, "FAIL2 %d", GetLastError());
   }
   Prn::print(0, "done");
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
   Some::gAlphaParms.reset();
   Some::gAlphaParms.readSection("default");
   Some::gAlphaParms.show();
}

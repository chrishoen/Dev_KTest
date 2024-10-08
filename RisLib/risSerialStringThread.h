#pragma once

/*==============================================================================
Serial port string thread.
==========================================================================*/

//******************************************************************************
//******************************************************************************
//******************************************************************************

#include <string>

#include "risThreadsThreads.h"
#include "risThreadsQCall.h"
#include "risSerialStringPort.h"

namespace Ris
{

//******************************************************************************
//******************************************************************************
//******************************************************************************
// Serial string thread.
//
// This is a thread that provides the execution context string
// communication via a serial port.
//
// It contains a serial string port.
//
// 
// The thread is structured around a while loop that does a read call to
// receive a string on the serial port.
//
// The thread provides serialized access to the serial port and associated 
// state variables and it provides the context for the blocking of the 
// read call.
//
// An instance of this thread is created as a child thread of a parent thread
// that performs string processing. The parent creates the child and
// registers a receive string qcall callback to it. When the child thread
// receives a string it invokes the string qcall to pass it to the parent
// for processing.

class SerialStringThread : public Ris::Threads::BaseThread
{
private:
   typedef Ris::Threads::BaseThread BaseClass;
public:

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Constants.

   static const int cMaxStringSize = 2000;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   // Serial settings
   SerialSettings mSettings;

   // Serial string port.
   SerialStringPort mSerialStringPort;

   // Program trace index.
   int mTI;

   // Rx string.
   char mRxString[cMaxStringSize];

   // If true then the serial port is open. If false then it is closed
   // because of an error.
   bool mConnectionFlag;

   // This is a qcall that is invoked when a session is established or
   // disestablished. It is registered by the parent thread at
   // initialzation. It is called when the serial port is disconnected
   // because of an error and when it is reconnected.
   typedef Ris::Threads::QCall1<bool> SessionQCall;
   SessionQCall mSessionQCall;

   // This is a function pointer that is called when a session is
   // established or disestablished. It is registered by the parent thread
   // at initialzation. It is called when the serial port is disconnected
   // because of an error and when it is reconnected. It is called in
   // the context of this thread.
   std::function<void(bool)> mSessionCallback;

   // This is a qcall callback that is called when a string is received.
   // It is registered by the parent thread at initialzation.
   typedef Ris::Threads::QCall1<std::string*> RxStringQCall;
   RxStringQCall mRxStringQCall;

   // This is a function pointer callback that is called when a string is
   // received. It is registered by the parent thread at initialzation.
   // It is called in the context of this thread.
   std::function<void(std::string*)> mRxStringCallback;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Members.

   // Metrics.
   int mErrorCount;
   int mRestartCount;
   int mRxCount;
   int mTxCount;

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Constructor.
   SerialStringThread(SerialSettings& aSettings);
   ~SerialStringThread();

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods, thread base class overloads.

   // Initialize and open the serial port.
   void threadInitFunction()override;

   // Execute a while loop that does receive calls. The loop exits
   // when the serial port is closed and the termination flag is true.
   void threadRunFunction()override;

   // Print.
   void threadExitFunction()override;

   // Set the termination flag, close the serial port and wait for the thread
   // to terminate.
   void shutdownThread()override; 

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Notify the parent thread that a session has changed. This is called by
   // the threadRunFunction when a new session is established or an existing
   // session is disestablished. It invokes the mSessionQCall that is
   // registered at initialization. The session is disestablished if the 
   // serial port is closed because of an error and it is established if
   // it is successfully reopened.
   virtual void processSessionChange(bool aEstablished);

   // Pass a received string to the parent thread. This is called by the
   // threadRunFunction when a string is received. It invokes the
   // mRxStringQCall that is registered at initialization.
   void processRxString(char* aString);

   //***************************************************************************
   //***************************************************************************
   //***************************************************************************
   // Methods.

   // Send a null terminated string via the serial port. Append terminator
   // bytes as specified in the settings. Return the number of bytes 
   // transferred or a negative error code.
   int doSendString(const char* aString);

   // Send a null terminated string via the serial port. Append terminator
   // bytes as specified in the settings. The string is deleted after
   // transmission. Return the number of bytes transferred or a negative
   // error code.
   int doSendString(std::string* aString);
};

//******************************************************************************
//******************************************************************************
//******************************************************************************
}//namespace


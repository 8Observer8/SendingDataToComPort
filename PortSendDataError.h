#ifndef PORTSENDDATAERROR_H
#define PORTSENDDATAERROR_H

#include "PortError.h"

class PortSendDataError : public PortError
{
public:
    PortSendDataError( const std::string &portName,
                       const std::string &functionName ) :
        PortError( portName, functionName )
    {
        m_message = "Error: unable to send data to the port \"" +
                m_portName + "\"" + " in the function " +
                "\"" + m_functionName + "\"";
    }
};

#endif // PORTSENDDATAERROR_H

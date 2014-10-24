#ifndef PORTOPENERROR_H
#define PORTOPENERROR_H

#include "PortError.h"

class PortOpenError : public PortError
{
public:
    PortOpenError( const std::string &portName,
                   const std::string &functionName ) :
        PortError( portName, functionName )
    {
        m_message = "Error: unable to open the port \"" +
                m_portName + "\"" + " in the function " +
                "\"" + m_functionName + "\"";
    }
};

#endif // PORTOPENERROR_H

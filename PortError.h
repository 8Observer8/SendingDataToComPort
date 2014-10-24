#ifndef PORTERROR_H
#define PORTERROR_H

#include <stdexcept>
#include <string>

class PortError : public std::runtime_error
{
public:
    PortError( const std::string &portName,
               const std::string &functionName ) : std::runtime_error( "" ),
        m_portName( portName ),
        m_functionName( functionName )
    {
    }

    virtual ~PortError() throw()
    {
    }

    virtual const char *what() const throw()
    {
        return m_message.c_str();
    }

protected:
    std::string m_message;
    std::string m_portName;
    std::string m_functionName;
};

#endif // PORTERROR_H

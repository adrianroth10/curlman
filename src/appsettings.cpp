#include "appsettings.h"

AppSettings::AppSettings() {
    int defaultHeadersSize = 20;
    bool isWebsocket = false;
}




const int AppSettings::getDefaultHeadersSize() const
{
    return defaultHeadersSize;
}

const int AppSettings::getIsWebsocket() const
{
    return isWebsocket;
}
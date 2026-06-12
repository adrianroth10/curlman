#ifndef APPSETTINGS_H
#define APPSETTINGS_H

class AppSettings
{
public:
    AppSettings();


    const int getDefaultHeadersSize() const;
    const int getIsWebsocket() const;

private:
    int defaultHeadersSize = 20;
    bool isWebsocket = false;
};

#endif // APPSETTINGS_H

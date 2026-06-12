#include "mainwindow.h"
#include "appsettings.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <curl/curl.h>

int main(int argc, char *argv[])
{
    curl_global_init(CURL_GLOBAL_DEFAULT);

    AppSettings settings;

    QApplication a(argc, argv);

    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "test_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            a.installTranslator(&translator);
            break;
        }
    }

    MainWindow w(settings);
    w.show();

    int result = QApplication::exec();

    curl_global_cleanup();

    return result;
}

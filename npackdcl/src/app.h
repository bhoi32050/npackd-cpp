#ifndef APP_H
#define APP_H

#include <time.h>

#include <QJsonObject>
#include <QtCore/QCoreApplication>

#include "repository.h"
#include "commandline.h"
#include "job.h"
#include "clprogress.h"

/**
 * NpackdCL
 */
class App: public QObject
{
    Q_OBJECT
private:
    CommandLine cl;
    CLProgress clp;

    bool debug;
    bool interactive;

    static void printJSON(const QJsonObject & obj);

    /**
     * @brief defines the NPACKD_CL variable and adds the NpackdCL package to
     *     the local repository
     * @return error message
     */
    QString addNpackdCL();

    void usage();
    QString path();
    QString place();
    QString add();
    QString remove();
    QString addRepo();
    QString setRepo();
    QString removeRepo();
    QString search();
    QString list();
    QString info();
    QString update();
    QString detect();
    QString listRepos();
    QString which();
    QString where();
    QString check();
    QString getInstallPath();
    QString setInstallPath();

    bool confirm(const QList<InstallOperation *> ops, QString *title,
            QString *err);
    QString printDependencies(bool onlyInstalled,
            const QString parentPrefix, int level, PackageVersion *pv);
    void processInstallOperations(Job *job,
            const QList<InstallOperation *> &ops, DWORD programCloseType,
            bool interactive=true);
    QStringList sortPackageVersionsByPackageTitle(
            QList<PackageVersion *> *list);
public slots:
    /**
     * Process the command line.
     *
     * @return exit code
     */
    int process();
};

#endif // APP_H

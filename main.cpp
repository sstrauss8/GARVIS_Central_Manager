#include "mainwindow.h"
#include <QApplication>
#include "tutorialwizard.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //TutorialWizard wizard;
    //wizard = TutorialWizard::m_pInstance;
    //wizard.show();
    //wizard.setVisible(false);

    return a.exec();
}

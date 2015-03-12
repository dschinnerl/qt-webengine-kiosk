/****************************************************************************
**
** Copyright (C) 2011 Sergey Dryabzhinsky
** All rights reserved.
** Contact: Sergey Dryabzhinsky (sergey.dryabzhinsky@gmail.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights.  These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QApplication>
#include "mainwindow.h"



int main(int argc, char * argv[])
{
    QApplication app(argc, argv);
    app.setApplicationName("Qt WebEngine Kiosk");

    QCommandLineParser parser;
    parser.setApplicationDescription("A kiosk browser based on Qt's Chromium-derived WebEngine component");
    parser.addHelpOption();
    parser.addVersionOption();

    QList<QCommandLineOption> options = QList<QCommandLineOption>({
            {{"clear-cache","C"}, "Clear cached request data"},
            {{"uri","u"}, "Set starting url to <uri>", "uri"},
            {{"monitor", "m"}, "Display window on the <n>th monitor", "n"},
            {{"config", "c"}, "Use <file> to configure this instance of qt-webengine-kiosk", "file"}
            });

    parser.addOptions(options);
    parser.process(app);



    MainWindow *browser = new MainWindow();
    browser->init(parser);

    // executes browser.cleanupSlot() when the Qt framework emits aboutToQuit() signal.
    QObject::connect(qApp, SIGNAL(aboutToQuit()),
                     browser, SLOT(cleanupSlot()));

    int ret = app.exec();
    qDebug() << "Application return:" << ret;

}

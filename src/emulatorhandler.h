/***
 * Copyright (c) 2013, Dan Hasting
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the organization nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ***/

#ifndef EMULATORHANDLER_H
#define EMULATORHANDLER_H

#include <QCryptographicHash>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QObject>
#include <QProcess>

#include "common.h"


class EmulatorHandler : public QObject
{
    Q_OBJECT
public:
    explicit EmulatorHandler(QWidget *parent = 0);
    void startEmulator(QDir romDir, QString romFileName, QString zipFileName = "",
                       QDir ddDir = QDir(), QString ddFileName = "", QString ddZipName = "");
    void stopEmulator();

    QString lastOutput;

signals:
    void finished();
    void showLog();
    void started();
    void statusUpdate(QString message, int timeout);

private:
    void updateStatus(QString message, int timeout = 0);

    QStringList parseArgString(QString argString);

    QProcess *emulatorProc;
    QWidget *parent;

private slots:
    void checkStatus(int status);
    void cleanTemp();
    void emitFinished();
    void readOutput();
};

#endif // EMULATORHANDLER_H

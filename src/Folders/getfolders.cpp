/* libfuoten - Qt based library to access the ownCloud/Nextcloud News App API
 * Copyright (C) 2016 Buschtrommel / Matthias Fehring
 * https://www.buschmann23.de/entwicklung/bibliotheken/libfuoten/
 * https://github.com/Buschtrommel/libfuoten
 *
 * Folders/getfolders.cpp
 *
 * This library is free software: you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#include "getfolders_p.h"
#include "../error.h"

using namespace Fuoten;

GetFolders::GetFolders(QObject *parent) :
    Component(* new GetFoldersPrivate, parent)
{
    setApiRoute(QStringLiteral("/folders"));
    setExpectedJSONType(Component::Object);
}


GetFolders::GetFolders(GetFoldersPrivate &dd, QObject *parent) :
    Component(dd, parent)
{
    setApiRoute(QStringLiteral("/folders"));
    setExpectedJSONType(Component::Object);
}



void GetFolders::execute()
{
    if (inOperation()) {
        return;
    }

    setInOperation(true);

    sendRequest();
}


void GetFolders::successCallback()
{
    if (storageHandler()) {
        storageHandler()->foldersRequested(jsonResult());
    }

    setInOperation(false);
    Q_EMIT succeeded(jsonResult());
}



void GetFolders::extractError(QNetworkReply *reply)
{
    setError(new Error(reply, this));
    setInOperation(false);
    Q_EMIT failed(error());
}



bool GetFolders::checkOutput()
{
    return Component::checkOutput();
}

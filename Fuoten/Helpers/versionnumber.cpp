/* libfuoten - Qt based library to access the ownCloud/Nextcloud News App API
 * Copyright (C) 2016 Buschtrommel / Matthias Fehring
 * https://www.buschmann23.de/entwicklung/bibliotheken/libfuoten/
 * https://github.com/Buschtrommel/libfuoten
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

#include "versionnumber.h"
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QRegularExpressionMatchIterator>

using namespace Fuoten;

VersionNumber::VersionNumber()
{
    d = new VersionNumberData;
}



VersionNumber::VersionNumber(int maj, int min, int mic)
{
    d = new VersionNumberData;
    setMaj(maj);
    setMin(min);
    setMic(mic);
}



VersionNumber::VersionNumber(const QString &versionString)
{
    d = new VersionNumberData;
    loadFromString(versionString);
}



VersionNumber::VersionNumber(const VersionNumber &other) : d(other.d)
{

}


void VersionNumber::loadFromString(const QString &versionString)
{
    if (versionString.isEmpty()) {
        setMaj(0);
        setMin(0);
        setMic(0);
    }

    QRegularExpression re(QStringLiteral("\\d+"));
    QRegularExpressionMatchIterator i = re.globalMatch(versionString);

    if (i.hasNext()) {
        setMaj(i.next().captured(0).toInt());

        if (i.hasNext()) {
            setMin(i.next().captured(0).toInt());

            if (i.hasNext()) {
                setMic(i.next().captured(0).toInt());
            } else {
                setMic(0);
            }
        } else {
            setMin(0);
            setMic(0);
        }
    } else {
        setMaj(0);
        setMin(0);
        setMic(0);
    }
}





void VersionNumber::setMaj(int maj) { d->maj = maj; }

void VersionNumber::setMin(int min) { d->min = min; }

void VersionNumber::setMic(int mic) { d->mic = mic; }


int VersionNumber::maj() const { return d->maj; }

int VersionNumber::min() const { return d->min; }

int VersionNumber::mic() const { return d->mic; }




bool VersionNumber::isNull() const
{
    return (d->maj == 0 && d->min == 0 && d->mic == 0);
}


QString VersionNumber::toString() const
{
    return QStringLiteral("%1.%2.%3").arg(QString::number(maj()), QString::number(min()), QString::number(mic()));
}


bool VersionNumber::operator!=(const VersionNumber &other) const
{
    return (d->maj != other.maj() || d->min != other.min() || d->mic != other.mic());
}


bool VersionNumber::operator==(const VersionNumber &other) const
{
    return (d->maj == other.maj() && d->min == other.min() && d->mic == other.mic());
}


bool VersionNumber::operator<(const VersionNumber &other) const
{
    if (d->maj < other.maj()) {
        return true;
    } else if (d->maj > other.maj()) {
        return false;
    } else {
        if (d->min < other.min()) {
            return true;
        } else if (d->min > other.min()) {
            return false;
        } else {
            if (d->mic < other.mic()) {
                return true;
            } else {
                return false;
            }
        }
    }
}


bool VersionNumber::operator<=(const VersionNumber &other) const
{
    if (d->maj > other.maj()) {
        return false;
    } else {
        if (d->min > other.min()) {
            return false;
        } else {
            if (d->mic > other.mic()) {
                return false;
            } else {
                return true;
            }
        }
    }
}



bool VersionNumber::operator>(const VersionNumber &other) const
{
    if (d->maj > other.maj()) {
        return true;
    } else if (d->maj < other.maj()) {
        return false;
    } else {
        if (d->min > other.min()) {
            return true;
        } else if (d->min < other.min()) {
            return false;
        } else {
            if (d->mic > other.mic()) {
                return true;
            } else {
                return false;
            }
        }
    }
}



bool VersionNumber::operator>=(const VersionNumber &other) const
{
    if (d->maj < other.maj()) {
        return false;
    } else {
        if (d->min < other.min()) {
            return false;
        } else {
            if (d->mic < other.mic()) {
                return false;
            } else {
                return true;
            }
        }
    }
}

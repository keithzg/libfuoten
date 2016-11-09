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

#ifndef FUOTEN
#define FUOTEN

#include "fuoten_global.h"
#include <QMetaType>

namespace Fuoten {

/*!
 * \brief Provides global enumerations.
 *
 * \headerfile "" <Fuoten/FuotenEnums>
 */
class FUOTENSHARED_EXPORT FuotenEnums {
    Q_GADGET
public:

    /*!
     * \brief Object types.
     */
    enum Type {
        Feed    = 0,    /**< Feed */
        Folder  = 1,    /**< Folder */
        Starred = 2,    /**< Starred items/articles */
        All     = 3,    /**< All items/articles */
        Item    = 4     /**< Item/Article */
    };
#if QT_VERSION >= QT_VERSION_CHECK(5, 5, 0)
    Q_ENUM(Type)
#else
    Q_ENUMS(Type)
#endif

    /*!
     * \brief Sorting role.
     */
    enum SortingRole {
        ID          = 0,    /**< Sort by database ID */
        Name        = 1,    /**< Sort by name/title */
        Time        = 2,    /**< Sort by time */
        UnreadCount = 3,    /**< Sort by unread item count */
        FeedCount   = 4,    /**< Sort by feed count (only applicable to folders) */
        FolderName  = 5     /**< Sort by folder name (only applicable to feeds) */
    };
#if QT_VERSION >= QT_VERSION_CHECK(5, 5, 0)
    Q_ENUM(SortingRole)
#else
    Q_ENUMS(SortingRole)
#endif

    /*!
     * \brief Actions for the local queue.
     */
    enum QueueAction {
        MarkAsRead      = 0,    /**< The item has been marked as read. */
        MarkAsUnread    = 1,    /**< The item has been marked as unread. */
        Star            = 2,    /**< The item has been starred. */
        Unstar          = 3     /**< The item has been unstarred. */
    };
#if QT_VERSION >= QT_VERSION_CHECK(5, 5, 0)
    Q_ENUM(QueueAction)
#else
    Q_ENUMS(QueueAction)
#endif

private:
    FuotenEnums();
    ~FuotenEnums();
};
}

#if QT_VERSION < QT_VERSION_CHECK(5, 5, 0)
Q_DECLARE_METATYPE(Fuoten::FuotenEnums::Type)
Q_DECLARE_METATYPE(Fuoten::FuotenEnums::SortingRole)
Q_DECLARE_METATYPE(Fuoten::FuotenEnums::QueueAction)
#endif

#endif // FUOTEN


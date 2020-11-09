/****************************************************************************
**
** Copyright (c) 2020 Open Mobile Platform LLC.
**
****************************************************************************/

/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef PERMISSIONFILTERPROXYMODEL_H
#define PERMISSIONFILTERPROXYMODEL_H

#include <QSortFilterProxyModel>

class PermissionFilterProxyModel : public QSortFilterProxyModel
{
    Q_OBJECT
    Q_PROPERTY(QString permissionType READ permissionType WRITE setPermissionType NOTIFY permissionTypeChanged)
public:
    PermissionFilterProxyModel(QObject *parent = nullptr);

    Q_INVOKABLE void remove(int currentIndex);
    Q_INVOKABLE void setCapability(int currentIndex, int capability);

    bool filterAcceptsRow(int sourceRow, const QModelIndex &sourceParent) const override;

    QString permissionType() const;
    void setPermissionType(const QString &permissionType);

signals:
    void permissionTypeChanged(QString permissionType);

private:
    QString m_permissionType;
};

#endif // PERMISSIONFILTERPROXYMODEL_H
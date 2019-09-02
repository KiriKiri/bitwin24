// Copyright (c) 2017-2018 The Bitwin24 developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZBWICONTROLDIALOG_H
#define ZBWICONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zbwi/zerocoin.h"
#include "privacydialog.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZBWIControlDialog;
}

class CZBWIControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZBWIControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZBWIControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZBWIControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZBWIControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZBWIControlDialog(QWidget *parent);
    ~ZBWIControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZBWIControlDialog *ui;
    WalletModel* model;
    PrivacyDialog* privacyDialog;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_PRECOMPUTE,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZBWIControlWidgetItem;

private slots:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZBWICONTROLDIALOG_H

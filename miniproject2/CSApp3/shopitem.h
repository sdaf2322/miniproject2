#ifndef SHOPITEM_H
#define SHOPITEM_H

#include "clientitem.h"
#include "productitem.h"

#include <QTreeWidgetItem>

class ShopItem : public QTreeWidgetItem
{
public:
    explicit ShopItem(int id = 0, int = 0, QString = "", int = 0, QString = "", QString = "", QString = "", QString = "", QString = "");

    QString getShopdate() const;
    QString getQuantity() const;
    QString getOption() const;
    int getClientID() const;
    int getProductID() const;
    int id() const;
    void setShopdate(QString&);
    void setQuantity(QString&);
    void setOption(QString&);

    bool operator==(const ShopItem &other) const;

private:
    int cid, pid;

};

#endif // SHOPITEM_H

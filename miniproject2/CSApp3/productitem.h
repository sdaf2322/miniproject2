#ifndef PRODUCTITEM_H
#define PRODUCTITEM_H

#include <QTreeWidgetItem>

class ProductItem : public QTreeWidgetItem
{
public:
    explicit ProductItem(int id = 0, QString = "", QString = "", QString = "", QString = "");

    QString getProductName() const;
    void setProductName(QString&);
    QString getPrice() const;
    void setPrice(QString&);
    QString getProductType() const;
    void setProductType(QString&);
    QString getOption() const;
    void setOption(QString&);
    int getID() const;
    bool operator==(const ProductItem &other) const;
};

#endif // PRODUCTITEM_H

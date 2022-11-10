#ifndef SHOPMANAGERFORM_H
#define SHOPMANAGERFORM_H

#include <QWidget>
#include <QHash>

#include "shopitem.h"
#include "clientmanagerform.h"
#include "productmanagerform.h"

class QMenu;
class QTreeWidgetItem;

namespace Ui {
class ShopManagerForm;
}

class ShopManagerForm : public QWidget
{
    Q_OBJECT



public:
    explicit ShopManagerForm(QWidget *parent, ClientManagerForm*, ProductManagerForm*);
    ~ShopManagerForm();
    const QMap<int, ShopItem*>& getList();
    void LoadData();

private slots:
    /* QTreeWidget을 위한 슬롯 */
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);
    void showContextMenu(const QPoint &);
    void removeItem();              /* QAction을 위한 슬롯 */
    void on_addPushButton_clicked();
    void on_searchPushButton_clicked();

    void get_Product_Info(int);
    void on_productTreeWidget_itemClicked(QTreeWidgetItem *item, int column);
    void removeOption();
    void on_searchProductPushButton_clicked();
    void on_searchProductTreeWidget_itemClicked(QTreeWidgetItem *item, int column);
    void productTreeWidget_clear();

private:
    int makeId();
    QList<int> clientIDList;
    QList<int> productIDList;
    QMap<int, ShopItem*> shopList;
    QStringList list;

    ClientManagerForm* cm;
    ProductManagerForm* pm;

    Ui::ShopManagerForm *ui;
    QMenu* menu;

};
#endif // SHOPMANAGERFORM_H

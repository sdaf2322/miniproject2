#ifndef PRODUCTMANAGERFORM_H
#define PRODUCTMANAGERFORM_H

#include <QWidget>
#include <QHash>

#include "productitem.h"

class QMenu;
class QTreeWidgetItem;

namespace Ui {
class ProductManagerForm;
}

class ProductManagerForm : public QWidget
{
    Q_OBJECT

public:
    explicit ProductManagerForm(QWidget *parent = nullptr);
    ~ProductManagerForm();
    const QMap<int, ProductItem*>& getList();
    void LoadData();

    ProductItem* search(int id);

signals:
    void Add_Product_Info(int);
    void Remove_Product_Info();
    void Remove_productTreeWidget_Item();

private slots:
    /* QTreeWidget을 위한 슬롯 */
    void on_treeWidget_itemClicked(QTreeWidgetItem *item, int column);
    void showContextMenu(const QPoint &);
    void removeItem();              /* QAction을 위한 슬롯 */
    void on_addPushButton_clicked();
    void on_modifyPushButton_clicked();
    void on_searchPushButton_clicked();

private:
    int makeId();

    QMap<int, ProductItem*> productList;

    Ui::ProductManagerForm *ui;
    QMenu* menu;

};

#endif // PRODUCTMANAGERFORM_H

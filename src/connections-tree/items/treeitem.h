#ifndef TREEITEM_H
#define TREEITEM_H

#define QT_SHAREDPOINTER_TRACK_POINTERS
#include <QSharedPointer>
#include <QWeakPointer>
#include <QString>
#include <QIcon>
#include <QList>
#include <QWidget>

class QMenu;

namespace ConnectionsTree {

class TabWidget;

class TreeItem {
public:

    class ParentView {

    public:        
        virtual QWidget* getParentWidget() = 0;

    };

    virtual QString getDisplayName() const = 0;
    virtual QIcon getIcon() const = 0;
    virtual QList<QSharedPointer<TreeItem>> getAllChilds() const = 0;
    virtual uint childCount() const = 0;
    virtual QSharedPointer<TreeItem> child(int row) const = 0;
    virtual const TreeItem* parent() const = 0;

    virtual bool onClick(ParentView& treeView, TabWidget& tabs) = 0;
    virtual void onWheelClick(ParentView& treeView, TabWidget& tabs) = 0;
    virtual QSharedPointer<QMenu> getContextMenu(ParentView& treeView, TabWidget& tabs) = 0;

    virtual bool isLocked() const = 0;
    virtual bool isEnabled() const = 0;

    virtual ~TreeItem() {}
};

}
#endif // TREEITEM_H

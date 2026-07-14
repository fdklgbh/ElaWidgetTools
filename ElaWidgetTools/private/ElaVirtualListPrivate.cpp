#include "ElaVirtualListPrivate.h"

#include <QAbstractItemModel>
#include <QPoint>

#include "ElaVirtualList.h"

ElaVirtualListPrivate::ElaVirtualListPrivate(QObject* parent)
    : QObject(parent)
{
}

ElaVirtualListPrivate::~ElaVirtualListPrivate()
{
}

// 计算当前可见行范围, 范围变化时发出 itemRequestData 供外部按需填充数据
void ElaVirtualListPrivate::_requestVisibleData()
{
    Q_Q(ElaVirtualList);
    QAbstractItemModel* model = q->model();
    if (!model || model->rowCount() <= 0)
    {
        return;
    }
    int startIndex = q->indexAt(QPoint(0, 0)).row();
    if (startIndex < 0)
    {
        startIndex = 0;
    }
    int endIndex = q->indexAt(QPoint(0, q->viewport()->height() - 1)).row();
    if (endIndex < 0)
    {
        endIndex = model->rowCount() - 1;
    }
    if (startIndex == _lastRequestStart && endIndex == _lastRequestEnd)
    {
        return;
    }
    _lastRequestStart = startIndex;
    _lastRequestEnd = endIndex;
    Q_EMIT q->itemRequestData(startIndex, endIndex);
}

#include "ElaPopularCardPrivate.h"

#include <QPropertyAnimation>
#include <QTimer>

#include "ElaApplication.h"
#include "ElaPopularCard.h"
#include "ElaPopularCardFloater.h"

ElaPopularCardPrivate::ElaPopularCardPrivate(QObject* parent)
    : QObject{parent}
{
}

ElaPopularCardPrivate::~ElaPopularCardPrivate()
{
}

void ElaPopularCardPrivate::_showFloater()
{
    Q_Q(ElaPopularCard);
    q->update();
    _isFloating = true;
    _pHoverYOffset = 0;
    _floatTimer->stop();
    _floater->showFloater();
}

void ElaPopularCardPrivate::_startHoverAnimation(bool isHover)
{
    Q_Q(ElaPopularCard);
    QPropertyAnimation* hoverAnimation = new QPropertyAnimation(this, "pHoverYOffset");
    connect(hoverAnimation, &QPropertyAnimation::valueChanged, q, [=]() { q->update(); });
    hoverAnimation->setDuration(130);
    hoverAnimation->setStartValue(_pHoverYOffset);
    hoverAnimation->setEndValue(isHover ? 6 : 0);
    hoverAnimation->start(QAbstractAnimation::DeleteWhenStopped);
    QPropertyAnimation* opacityAnimation = new QPropertyAnimation(this, "pHoverOpacity");
    opacityAnimation->setDuration(130);
    opacityAnimation->setStartValue(_pHoverOpacity);
    opacityAnimation->setEndValue(isHover ? 1 : 0);
    opacityAnimation->start(QAbstractAnimation::DeleteWhenStopped);
}

void ElaPopularCardPrivate::_doHoverStateCheck()
{
    Q_Q(ElaPopularCard);
    if (ElaApplication::containsCursorToItem(q) || ElaApplication::containsCursorToItem(_floater))
    {
        return;
    }
    // 手势滚动会截获鼠标事件, 此时 Leave 事件不会送达, 需要主动恢复悬停状态
    _hoverCheckTimer->stop();
    _floatTimer->stop();
    if (_isFloating)
    {
        _floater->hideFloater();
    }
    _startHoverAnimation(false);
}

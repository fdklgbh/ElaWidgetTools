#include "ElaVirtualList.h"

#include <QPainter>
#include <QResizeEvent>
#include <QStandardItemModel>

#include "ElaScrollBar.h"
#include "ElaTheme.h"
#include "ElaVirtualListStyle.h"
#include "private/ElaVirtualListPrivate.h"
Q_PROPERTY_CREATE_Q_CPP(ElaVirtualList, int, ItemHeight)
Q_PROPERTY_CREATE_Q_CPP(ElaVirtualList, bool, IsTransparent)

// 隔行变色需同步到 QListView 基类, 由 ElaVirtualListStyle 的 PE_PanelItemViewRow 分支绘制背景, 不能使用宏生成
void ElaVirtualList::setIsAlternatingRowColors(bool IsAlternatingRowColors)
{
	Q_D(ElaVirtualList);
	d->_pIsAlternatingRowColors = IsAlternatingRowColors;
	setAlternatingRowColors(IsAlternatingRowColors);
	Q_EMIT pIsAlternatingRowColorsChanged();
}

bool ElaVirtualList::getIsAlternatingRowColors() const
{
	return d_ptr->_pIsAlternatingRowColors;
}

ElaVirtualList::ElaVirtualList(QWidget *parent) : QListView(parent), d_ptr(new ElaVirtualListPrivate())
{
	Q_D(ElaVirtualList);
	d->q_ptr = this;
	d->_pItemHeight = 40;
	d->_pIsTransparent = true;
	d->_pIsAlternatingRowColors = false;
	d->_themeMode = eTheme->getThemeMode();
	setObjectName("ElaVirtualList");
	setStyleSheet("#ElaVirtualList{background-color:transparent;}");
	setMouseTracking(true);
	setSpacing(0);

	d->_listViewStyle = new ElaVirtualListStyle(style());
	d->_listViewStyle->setItemHeight(d->_pItemHeight);
	setStyle(d->_listViewStyle);

	// 内置占位模型: 使用 setItemCount 声明总行数时由它承载行数, 数据经 itemRequestData 信号按需填充
	d->_internalModel = new QStandardItemModel(this);
	setModel(d->_internalModel);

	ElaScrollBar *vScrollBar = new ElaScrollBar(this);
	vScrollBar->setIsAnimation(true);
	setVerticalScrollBar(vScrollBar);
	connect(vScrollBar, &ElaScrollBar::valueChanged, this, [=](int)
	{
		d->_requestVisibleData();
	});
	ElaScrollBar *hScrollBar = new ElaScrollBar(this);
	setHorizontalScrollBar(hScrollBar);
	setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
	setHorizontalScrollMode(QAbstractItemView::ScrollPerPixel);
	setVerticalScrollMode(QAbstractItemView::ScrollPerPixel);

	setUniformItemSizes(true);

	setLayoutMode(QListView::Batched);
	setBatchSize(100);

	connect(eTheme, &ElaTheme::themeModeChanged, this, [=](ElaThemeType::ThemeMode themeMode)
	{
		d->_themeMode = themeMode;
		viewport()->update();
	});
}

ElaVirtualList::~ElaVirtualList()
{
}

void ElaVirtualList::setItemCount(int count)
{
	Q_D(ElaVirtualList);
	if (count < 0)
	{
		count = 0;
	}
	d->_itemCount = count;
	// 仅在仍使用内置占位模型时同步行数; 已通过 setModel 挂接外部模型时只记录计数
	if (model() == d->_internalModel)
	{
		d->_internalModel->setRowCount(count);
	}
	d->_lastRequestStart = -1;
	d->_lastRequestEnd = -1;
	d->_requestVisibleData();
}

int ElaVirtualList::getItemCount() const
{
	return d_ptr->_itemCount;
}

void ElaVirtualList::paintEvent(QPaintEvent *event)
{
	Q_D(ElaVirtualList);
	if (!d->_pIsTransparent)
	{
		QPainter painter(viewport());
		painter.save();
		painter.setRenderHints(QPainter::Antialiasing);
		painter.setPen(Qt::NoPen);
		painter.setBrush(ElaThemeColor(d->_themeMode, DialogBase));
		painter.drawRect(rect());
		painter.restore();
	}
	QListView::paintEvent(event);
}

void ElaVirtualList::resizeEvent(QResizeEvent *event)
{
	Q_D(ElaVirtualList);
	QListView::resizeEvent(event);
	d->_requestVisibleData();
}
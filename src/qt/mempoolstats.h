// Copyright (c) 2022 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_QT_MEMPOOLSTATS_H
#define BITCOIN_QT_MEMPOOLSTATS_H

#include <QEvent>
#include <QWidget>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QGraphicsView>

#include <policy/fees.h>

class ClientModel;

class ClickableTextItem : public QObject, public QGraphicsSimpleTextItem
{
    Q_OBJECT
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
Q_SIGNALS:
    void objectClicked(QGraphicsItem*);
};

class ClickableRectItem : public QObject, public QGraphicsRectItem
{
    Q_OBJECT
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
Q_SIGNALS:
    void objectClicked(QGraphicsItem*);
};


class MempoolStats : public QWidget
{
    Q_OBJECT

public:
    explicit MempoolStats(QWidget *parent = Q_NULLPTR);
    void setClientModel(ClientModel *model);

public Q_SLOTS:
    void drawChart();
    void drawHorzLines(
			const qreal x_increment,
			QPointF current_x_bottom,
			const int amount_of_h_lines,
			qreal maxheight_g,
			qreal maxwidth,
			qreal bottom,
			size_t max_txcount_graph,
			QFont LABELFONT
			);
    void drawFeeRanges(qreal bottom, QFont LABELFONT);
    void drawFeeRects(qreal bottom, int display_up_to_range, QFont LABELFONT);

private:
    ClientModel* m_clientmodel = Q_NULLPTR;

    QGraphicsView *m_gfx_view;
    QGraphicsScene *m_scene;

    virtual void resizeEvent(QResizeEvent* event) override;
    virtual void showEvent(QShowEvent* event) override;

    int m_selected_range = -1;
};

#endif // BITCOIN_QT_MEMPOOLSTATS_H

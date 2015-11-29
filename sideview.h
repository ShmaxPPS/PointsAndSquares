#ifndef SIDEVIEW_H
#define SIDEVIEW_H

#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsView>
#include <QObject>


class GameManager;

enum SideState { PRESSED, HOVERED, ENABLED, DISABLED };

class SideView : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    SideView(size_t width, size_t height, GameManager* game_manager);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void pressSideView();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent* event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent* event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent* event);

signals:
    void callSideRedraw();

public:
    SideState state;

private:
    size_t width_;
    size_t height_;
    QBrush brush_;
    GameManager* game_manager_;
    QGraphicsView* main_view_;
};


#endif // SIDEVIEW_H

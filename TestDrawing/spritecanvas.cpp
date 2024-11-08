#include "SpriteCanvas.h"
#include <QPainter>
#include <QMouseEvent>
#include <QDebug>

SpriteCanvas::SpriteCanvas(QWidget* parent) : QWidget(parent) {}

void SpriteCanvas:: paintEvent(QPaintEvent* event)  {
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, false);
    painter.setBrush(QColor(0,0,0,127));
    painter.setPen(Qt::NoPen);

    qDebug() << "paintEvent triggered, isDrawing:" << isDrawing;

    // Draw all stored rectangles
    for (const QPoint &point : drawnPoints) {
        QRect rect(point.x(), point.y(), gridSize, gridSize);
        painter.drawRect(rect);  // Draw each grid cell
    }


    if (isDrawing) {
        QPoint snappedPos = QPoint(lastPos.x() / gridSize * gridSize, lastPos.y() / gridSize * gridSize);
        QRect rect(snappedPos.x(), snappedPos.y(), gridSize, gridSize);
        painter.drawRect(rect);
    }


}

void SpriteCanvas::mousePressEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton) {
        isDrawing = true;
        lastPos = event->pos();
        QPoint snappedPos = QPoint(lastPos.x() / gridSize * gridSize, lastPos.y() / gridSize * gridSize);

        if(isErasing && drawnPoints.contains(snappedPos)){
            drawnPoints.remove(snappedPos);
        }

        // add if not there
        if (!drawnPoints.contains(snappedPos)) {
            drawnPoints.insert(snappedPos);
            update();
        }



    }
}

void SpriteCanvas::mouseMoveEvent(QMouseEvent *event)  {
    if (isDrawing) {
        lastPos = event->pos();  // Update the position while the mouse is moving
        QPoint snappedPos = QPoint(lastPos.x() / gridSize * gridSize, lastPos.y() / gridSize * gridSize);


        if (!drawnPoints.contains(snappedPos)) {
            drawnPoints.insert(snappedPos);
            update();  // Redraw the widget to reflect the new drawing
        }
    }
}

void SpriteCanvas::mouseReleaseEvent(QMouseEvent *event)  {
    if (event->button() == Qt::LeftButton) {
        isDrawing = false;  // Stop drawing when the mouse is released
    }
}

void SpriteCanvas::setEraserStatus(bool status){

}



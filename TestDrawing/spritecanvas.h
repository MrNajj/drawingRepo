#ifndef SPRITECANVAS_H
#define SPRITECANVAS_H

#include <QWidget>

class SpriteCanvas : public QWidget{

    Q_OBJECT


public:
    explicit SpriteCanvas(QWidget* parent = nullptr);

    void paintEvent(QPaintEvent *event) override;  // Paint the canvas
    void mousePressEvent(QMouseEvent *event) override;  // Mouse press event
    void mouseMoveEvent(QMouseEvent *event) override;  // Mouse move event
    void mouseReleaseEvent(QMouseEvent *event) override;  // Mouse release event
    void setEraserStatus(bool status);





private:
    static const int gridSize = 10;  // Size of each pixel in the grid
    QColor brushColor;
    bool isDrawing;
    QPoint lastPos;
    QSet<QPoint> drawnPoints;  // set of drawn pixels to stop overlap
    bool isErasing;


};

#endif // SPRITECANVAS_H

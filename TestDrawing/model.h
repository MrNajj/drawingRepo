#ifndef MODEL_H
#define MODEL_H

#include<QObject>
#include<QTimer>
#include<QString>


class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr);

    // Slots to receive signals from mainwindow
public slots:
    void enableEraser(bool status);


    // Signals to be sent to mainwindow when necessary
signals:


    // Some data internals and methods required for Model's logic
private:

};
#endif // MODEL_H

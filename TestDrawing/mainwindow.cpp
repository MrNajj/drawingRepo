#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spritecanvas.h"
#include "model.h"

MainWindow::MainWindow(Model& model, QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    SpriteCanvas *spriteCanvas = new SpriteCanvas(this);

    spriteCanvas->setGeometry(0,0,256,256);





}

MainWindow::~MainWindow()
{
    delete ui;
}

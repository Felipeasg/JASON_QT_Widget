#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMap>

#include <QJsonValue>
#include <QJsonArray>
#include <QJsonObject>

#include "jsonripper.h"

#include <QDebug>
#include <QFile>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Coloca
    m_Widgets[ WidgetID::TempoTotal ] << ui->labelTempoTotal;
    m_Widgets[ WidgetID::TempoTotal ] << ui->lineEditTempoTotal;

    m_Widgets[ WidgetID::Dte ] << ui->labelDte;
    m_Widgets[ WidgetID::Dte ] << ui->lineEditDte;

    m_Widgets[ WidgetID::Densidade ] << ui->labelDensidade;
    m_Widgets[ WidgetID::Densidade ] << ui->lineEditDensidade;

    QFile inputFile("widgets.json");

    if (!inputFile.open(QIODevice::ReadOnly)) {
        qWarning("Couldn't open widgets file.");
        return;
    }

    QByteArray saveData = inputFile.readAll();

    QJsonDocument loadDoc(QJsonDocument::fromJson(saveData));
    QJsonObject jsonObj = loadDoc.object();

    QJsonArray widgetsArray = jsonObj["widgets"].toArray();

    for (int levelIndex = 0; levelIndex < widgetsArray.size(); ++levelIndex) {
        QJsonObject widget = widgetsArray[levelIndex].toObject();

        qDebug() << widget["id"].toInt();
        qDebug() << widget["name"].toString();
        qDebug() << widget["visible"].toBool();

        this->setHidden(widget["id"].toInt(), !widget["visible"].toBool());
    }

//    this->setHidden(WidgetID::TempoTotal, true);
//    this->setHidden(WidgetID::Dte, false);
//    this->setHidden(WidgetID::Densidade, true);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setHidden(const int aIndex, const bool aHidden)
{
    // First you need to set all items visible otherwise the result won't be the desired ... I think.
    //    setAllVisible();

    for ( auto item : m_Widgets[ aIndex ] )
    {
        item->setHidden( aHidden );
    }
}

void MainWindow::setAllVisible()
{
    for ( auto items : m_Widgets )
    {
        for ( auto item : items )
        {
            item->setVisible( true );
        }
    }
}

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>

namespace Ui {
class MainWindow;
}


class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_ENUMS(WidgetID)

public:

    enum WidgetID { TempoTotal, Dte, Densidade };

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    QMap< int, QList< QWidget* > > m_Widgets;

    void setHidden( const int aIndex, const bool aHidden);
    void setAllVisible();
};

#endif // MAINWINDOW_H

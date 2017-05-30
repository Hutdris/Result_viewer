#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include <string>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
	void upper_click();
	void lower_click();
private:
	void RT_parser(const char* rt_path, vector<vector<float>> RTs);
	vector<vector<float>> RTs;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
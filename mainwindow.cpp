#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include <regex>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::upper_click() {
	QString upperPath = "stl_model/oriented_upper.stl";
	upperPath = QFileDialog::getOpenFileName(this, "Open upper stl file.");

	ui->openGLWidget->set_stlModel(upperPath.toStdString().c_str(), OpenGLWidget::Position::Upper);
	ui->openGLWidget->update();
}
void MainWindow::lower_click() {
	QString lowerPath = "stl_model/oriented_lower.stl";
	lowerPath = QFileDialog::getOpenFileName(this, "Open lower stl file.");

	ui->openGLWidget->set_stlModel(lowerPath.toStdString().c_str(), OpenGLWidget::Position::Lower);
	ui->openGLWidget->update();
}


void RT_parser(const char* rt_path, vector<vector<float>> RTs) {
	RTs.clear();
	/* mat sample
	[0.99993992, 0.0026732478, -0.010626714, -0.057727795;
	-0.002586487, 0.99996352, 0.0081693372, -0.033318516;
	0.010648117, -0.0081413519, 0.99991024, -0.08435066;
	0, 0, 0, 1]
	*/
	ifstream rtFile;
	regex float_pat("-?\d+\.?\d*");
	rtFile.open(rt_path);
	string line, mat_str;
	vector<float> mat(16, 0.0);
	while (std::getline(rtFile, line)) {
		mat_str.append(line.substr(1, line.size()-2).append(","));
		for (int i = 0; i < 3; i++) {
			std::getline(rtFile, line);
			mat_str.append(line.substr(0, line.size()-1).append(","));
		} 
		size_t prev = 0, pos = 0, idx = 0;
		while (pos != string::npos) {
			pos = mat_str.find(',', prev);
			mat.at(idx) = stof(mat_str.substr(prev, pos - prev));
			prev = pos + 1;
			idx++;

		}
		// mat is row major! should trasform to col major




	}


}

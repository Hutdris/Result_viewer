#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <fstream>
#include <iostream>
#include <string>
#include <regex>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);	

	QString upperPath = "stl_model/oriented_upper.stl";
	ui->openGLWidget->set_stlModel(upperPath.toStdString().c_str(), OpenGLWidget::Position::Upper);
	ui->openGLWidget->update();
	QString lowerPath = "stl_model/oriented_lower.stl";
	ui->openGLWidget->set_stlModel(lowerPath.toStdString().c_str(), OpenGLWidget::Position::Lower);
	ui->openGLWidget->update();
	QString rtPath = "tracing_result/RT.txt";
	this->RT_parser(rtPath.toStdString().c_str(), RT_result);
	ui->horizontalSlider->setMaximum(int(RT_result.size() - 1));
}

void MainWindow::ExportCurrentState() {
	int value = 0;
	RT_result;
	int idx = ui->horizontalSlider->value();
	ofstream od("current_state_.txt");
	for (size_t i = 0; i < 4; i++){ 	
		for (size_t j = 0; j < 4; j++) {
			od << RT_result.at(idx).at(i + j*4) << ',';
		}
		od<<endl;
	}
	
	od.close();
	/*
	ofstream od(file_name);
	for (auto itt = vec.begin(); itt != vec.end(); itt++) {
		od << *itt << endl;
	}
	od.close();
	vec.clear();
	*/
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::RT_parser(const char *rt_path, vector<vector<float>> &RTs) {
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
	while (std::getline(rtFile, line)) {
		mat_str.append(line.substr(1, line.size()-2).append(","));
		for (int i = 0; i < 3; i++) {
			std::getline(rtFile, line);
			mat_str.append(line.substr(0, line.size()-1).append(","));
		} 
		size_t prev = 0, pos = 0, idx = 0;
		vector<float> mat(16, 0.0);
		while (idx < 16) {
			pos = mat_str.find(',', prev);
			mat.at(idx) = stof(mat_str.substr(prev, pos - prev));
			prev = pos + 1;
			idx++;
		}
		// mat is row major! should trasform to col major
		vector<float> mat_t(16, 0.0);
		size_t trans[16] = { 0, 4, 8, 12,
						 1, 5, 9, 13,
						 2, 6, 10, 14,
						 3, 7, 11, 15 };
		for (size_t i = 0; i < 16; i++)
			mat_t.at(i) = mat.at(trans[i]);
		RTs.push_back(mat_t);
		mat_str = "";
	}


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

void MainWindow::rt_click() {
	QString rtPath = "tracing_result/RT.txt";
	rtPath = QFileDialog::getOpenFileName(this, "Open rt result.");
	this->RT_parser(rtPath.toStdString().c_str(), RT_result);
	ui->horizontalSlider->setMaximum(int(RT_result.size() - 1));
}
void MainWindow::sent_rt(int frame_idx) {
	float* pt = &(RT_result.at(frame_idx)[0]);
	ui->openGLWidget->updateRT(&(RT_result.at(frame_idx)[0]));
	ui->openGLWidget->update_tripointbyRT();
	ui->openGLWidget->update();
	
}

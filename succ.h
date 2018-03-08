#ifndef SUCC_H
#define SUCC_H

#include <QWidget>
#include <QProxyStyle>
#include "basewindow.h"
#include <QPushButton>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QFileDialog>

namespace Ui {
  class succ;
}

class succ : public BaseWindow
{
  Q_OBJECT

public:
  explicit succ(QWidget *parent = 0);
  ~succ();

  void  Interface();
  void  SetRect();



private:
        void initTitleBar();
        QPushButton *color_btn;
        QLineEdit   *color_text1,*color_text2,*color_text3;
        QHBoxLayout *hb;

        QHBoxLayout *hb1,*hb2,*hb3;

        QPushButton *btn_h,*btn_t,*btn_i;
        QLineEdit   *T_text ,*T_ico;
        QSpinBox *pSpinBox;
        void loadStyleSheet(const QString &sheetName);


public slots:
        void  SetColor();
        void  SetText();
        void  SetHeight();
        void  SetIco();


private:
  Ui::succ *ui;
};

#endif // SUCC_H

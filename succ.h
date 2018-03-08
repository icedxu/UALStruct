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
        QPushButton *m_pBtnColor;
        QPushButton *m_pBtnText;
        QPushButton *m_pBtnHeight;
        QPushButton *m_pBtnIco;

        QLineEdit   *m_pTextColorR;
        QLineEdit   *m_pTextColorG;
        QLineEdit   *m_pTextColorB;
        QLineEdit   *m_pText;
        QLineEdit   *m_pIco;

        QHBoxLayout *m_pColorLayout;
        QHBoxLayout *m_pSliderLayout;
        QHBoxLayout *m_pIcoLayout;
        QHBoxLayout *m_pTextLayout;


        QSpinBox *m_pSpinBox;

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

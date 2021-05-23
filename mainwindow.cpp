#include "mainwindow.h"
#include <QTextEdit>
#include <QCoreApplication>
#include <QString>
#include <QLabel>
#include <QApplication>
#include <QInputDialog>
#include <QDir>
MainWindow::MainWindow(QWidget* parent)

    : QMainWindow(parent)
{
    ButtonInsertOneString = new QPushButton("Вставить одну строку", this); // устанавливаем размер и положение кнопки
    ButtonInsertOneString->setGeometry(620, 20, 171, 31);
    connect(ButtonInsertOneString, SIGNAL(released()), this, SLOT(InsertString()));

    ButtonDeleteString = new QPushButton("Удалить строку", this); // устанавливаем размер и положение кнопки
    ButtonDeleteString->setGeometry(620, 70, 171, 32);
    connect(ButtonDeleteString, SIGNAL(released()), this, SLOT(DeleteString()));

    ButtonInsertSubstring = new QPushButton("Вставить подстроку", this);
    ButtonInsertSubstring->setGeometry(620, 120, 171, 32);
    connect(ButtonInsertSubstring, SIGNAL(released()), this, SLOT(InsertSubstring()));

    ButtonReplaceSymbol = new QPushButton("Заменить символ", this);
    ButtonReplaceSymbol->setGeometry(620, 170, 171, 32);
    connect(ButtonReplaceSymbol, SIGNAL(released()), this, SLOT(ReplaceSymbol()));

    ButtonReplaceSubstring = new QPushButton("Заменить подстроку", this);
    ButtonReplaceSubstring->setGeometry(620, 220,  171, 32);
    connect(ButtonReplaceSubstring, SIGNAL(released()), this, SLOT(ReplaceSubstring()));

    ButtonAlgoZeros = new QPushButton("Delete Zeros", this);
    ButtonAlgoZeros->setGeometry(620, 270,  171, 32);
    connect(ButtonAlgoZeros, SIGNAL(released()), this, SLOT(DeleteZeros()));


    ButtonIncreasingSubsequences = new QPushButton("Increasing Subsequences", this);
    ButtonIncreasingSubsequences->setGeometry(620, 320,  171, 32);
    connect(ButtonIncreasingSubsequences, SIGNAL(released()), this, SLOT(DeleteNonIncreasingSubsequences()));

    ButtonReplaceAsteriskSign = new QPushButton("Replace Asterisk Sign", this);
    ButtonReplaceAsteriskSign->setGeometry(620, 370, 171, 32);
    connect(ButtonReplaceAsteriskSign, SIGNAL(released()), this, SLOT(ReplaceAsteriskSign()));

    ButtonDeleteBraces = new QPushButton("Delete Braces", this);
    ButtonDeleteBraces->setGeometry(620, 420, 171, 32);
    connect(ButtonDeleteBraces, SIGNAL(released()), this, SLOT(DeleteBraces()));

    TextWindow = new QTextEdit(this);
    TextWindow->setGeometry(10, 0, 591, 551);
}

void MainWindow::DeleteZeros() {
    bool bOk;
    QString beg = QInputDialog::getText(0, "Delete Zeros",
        "beg:", QLineEdit::Normal, "", &bOk);
    if (bOk) {
        QString end = QInputDialog::getText(0, "Delete Zeros",
            "end:", QLineEdit::Normal, "", &bOk);
        if (bOk) {
            QString string = TextWindow->toPlainText();
            QStringList strList = string.split('\n');
            for (int i = beg.toInt() - 1; i <= end.toInt() - 1; ++i) {
                for (int j = 1; j < strList[i].size(); ++j) {
                    if (strList[i][j - 1] == '0' && strList[i][j] <= '9' && strList[i][j] >= '0') {
                        strList[i].remove(j - 1, 1);
                        j--;
                    } else {
                        break;
                    }
                }
            }
            PrintText(strList);
        }
    }
}

void MainWindow::DeleteNonIncreasingSubsequences() {
    QString string = TextWindow->toPlainText();
    QStringList strList = string.split('\n');
    bool bOk;
    QString begin = QInputDialog::getText(0, "Increasing Subsequences",
        "String:", QLineEdit::Normal, "", &bOk);
    if (bOk) {
        bool flag = true;//туть
        int i = begin.toInt(), beg = -1,end = -1;
        for (int j = 0; j < strList[i].size(); ++j) {
            if (strList[i][j] <= '9' && strList[i][j] >= '0') {
                end++;
                if (beg == -1) {
                    beg = j;
                    end = j;
                } else if (beg != -1 && j != 0 && strList[i][j - 1] > strList[i][j]) {
                    flag = false;
                }
            } else if ((beg != -1 && !flag) || ((end - beg) == 0 && beg != -1)) {
                strList[i].remove(beg, end - beg + 1);
                j = beg;
                beg = -1;
                end = -1;
                flag = true;
            } else if (flag) {
                beg = -1;
            }
        }
        if ((beg != -1 && !flag) || ((end - beg) == 0 && beg != -1)) {
            strList[i].remove(beg, end - beg + 1);
        }
        PrintText(strList);
    }
}
void MainWindow::PrintText(QStringList &strList) {
    TextWindow->clear();
    for (int i = 0; i < strList.size(); ++i) {
        TextWindow->insertPlainText(strList[i]);
        if (i != strList.size() - 1) {
            TextWindow->insertPlainText("\n");
        }
    }
}

void MainWindow::ReplaceAsteriskSign() {
    QString string = TextWindow->toPlainText();
    QStringList strList = string.split('\n');
    for (int i = 0; i < strList.size(); ++i) {
        int beg = -1, end = -1;
        for (int j = 0; j < strList[i].size(); ++j) {
            if (strList[i][j] == '*')
            {
                if (beg == -1) {
                    beg = j;
                    end = j;
                } else {
                    end++;
                }
            }
            else if (beg != -1 && end != beg) {
                strList[i].remove(beg, end - beg + 1);
                for (int x = beg; x < beg + (end - beg + 1) / 2; ++x)
                    strList[i].insert(x, '+');
                j = beg + (end - beg + 1) / 2;
                beg = -1;
                end = -1;
            } else if (end == beg) {
                beg = -1;
                end = -1;
            }
        }

        if (beg != -1 && end - beg > 0) {
            strList[i].remove(beg, end - beg + 1);
            for (int x = beg; x < beg + (end - beg + 1) / 2; ++x)
                strList[i].insert(x, '+');


        }
    }
    PrintText(strList);
}

void MainWindow::DeleteBraces() {
    QString string = TextWindow->toPlainText();
    QStringList strList = string.split('\n');
    bool bOk;
    QString beg = QInputDialog::getText(0, "Delete Braces",
        "String:", QLineEdit::Normal, "", &bOk);
    int begin = -1, end = -1;
    int i = beg.toInt() - 1;
    for (int j = 0; j < strList[0].size(); ++j){
        if (strList[i][j] == '{') {
            begin = j;
        }
        else if (strList[i][j] == '}') {
            end = j;
            strList[0].remove(begin, end - begin + 1);
            j = begin;
        }
    }
    PrintText(strList);

}
MainWindow::~MainWindow() {
}


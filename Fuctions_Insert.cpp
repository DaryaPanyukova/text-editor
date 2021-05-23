#include "mainwindow.h"
void MainWindow::InsertString() {
    QString string = TextWindow->toPlainText();
    QStringList strList = string.split('\n');
    bool bOk;

    QString str = QInputDialog::getText(0, "Insert String",
        "String:", QLineEdit::Normal, "", &bOk);

    if (bOk) {
        QString num = QInputDialog::getText(0, "Insert String",
            "Number:", QLineEdit::Normal, "", &bOk);
        if (bOk) {
        while (num.toInt() >= strList.size() || num.toInt() < 0) {
            num = QInputDialog::getText(0, "Insert String",
                "Number:", QLineEdit::Normal, "", &bOk);
        }
            if (bOk) {
                int n = num.toInt();
                strList.insert(strList.begin() + n, str); //n, string
                PrintText(strList);
                }
            }
        }
    }


void MainWindow::DeleteString() {
    bool bOk;
    QString string = TextWindow->toPlainText();
    QStringList strList = string.split('\n');
    QString num = QInputDialog::getText(0, "Delete String",
        "Number:", QLineEdit::Normal, "", &bOk);
    if (bOk) {
        while (num.toInt() >= strList.size() || num.toInt() < 1) {
            num = QInputDialog::getText(0, "Delete String",
                "Number:", QLineEdit::Normal, "", &bOk);
        }
        if (bOk) {
            int n = num.toInt();
            strList.erase(strList.begin() + n - 1);
            PrintText(strList);
        }
    }
}


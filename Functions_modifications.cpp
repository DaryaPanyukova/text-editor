#include "mainwindow.h"

void MainWindow::InsertSubstring() {
    bool bOk;
    QString substring = QInputDialog::getText(0, "Insert Substring",
        "Substring:", QLineEdit::Normal, "",
        &bOk);
    if (bOk) {
        QString string = TextWindow->toPlainText();
        QStringList strList = string.split('\n');
        QString string_n = QInputDialog::getText(0, "Insert Substring",
            "Number of String:", QLineEdit::Normal, "",  &bOk);
        if (bOk) {
            while (string_n.toInt() >= strList.size() || string_n.toInt() < 1) {
                string_n = QInputDialog::getText(0, "Insert Substring",
                    "Number of String:", QLineEdit::Normal, "", &bOk);
            }

            int n = string_n.toInt();
            QString string_m = QInputDialog::getText(0, "Insert Substring",
                "Position:", QLineEdit::Normal, "",
                &bOk);
            if (bOk) {
                int m = string_m.toInt();
                strList[n - 1].insert(m - 1, substring);
                PrintText(strList);
            }
        }
    }
}


void MainWindow::ReplaceSymbol() {
    bool bOk;

    QString str = TextWindow->toPlainText();
    QStringList strList = str.split('\n');
    QString symbol = QInputDialog::getText(0, "Replace Symbol",
        "Symbol:", QLineEdit::Normal, "",
        &bOk);
    if (bOk) {
        QString string_n = QInputDialog::getText(0, "Replace Symbol",
            "Number of String:", QLineEdit::Normal, "",  &bOk);
        if (bOk) {
            while (string_n.toInt() >= strList.size() || string_n.toInt() < 1) {
                string_n = QInputDialog::getText(0, "Insert Substring",
                    "Number of String:", QLineEdit::Normal, "", &bOk);
            }
        }
        if (bOk) {
            int n = string_n.toInt();
            QString string_m = QInputDialog::getText(0, "Replace Symbol",
                "Position:", QLineEdit::Normal, "", &bOk);
            if (bOk) {
                while (string_n.toInt() >= strList.size() || string_n.toInt() < 1) {
                    string_n = QInputDialog::getText(0, "Insert Substring",
                        "Number of String:", QLineEdit::Normal, "", &bOk);
                }
                if (bOk) {
                    int m = string_m.toInt();
                    strList[n - 1][m - 1] = symbol[0];
                    PrintText(strList);
                }
             }
        }
    }
}


void MainWindow::ReplaceSubstring() {
    bool bOk;
    QString new_substring = QInputDialog::getText(0, "Replace Substring",
        "New substring:", QLineEdit::Normal, "", &bOk);
    if (bOk) {
        QString substring_to_replace = QInputDialog::getText(0, "Replace Substring",
            "Substring to replace:", QLineEdit::Normal, "", &bOk);
        if (bOk) {
            QString string_begin = QInputDialog::getText(0, "Replace Substring",
                "Begin:", QLineEdit::Normal, "",
                &bOk);

            if (bOk) {
                int begin = string_begin.toInt() - 1;
                QString string_end = QInputDialog::getText(0, "Replace Substring",
                    "End:", QLineEdit::Normal, "",
                    &bOk);
                if (bOk) {
                    int end = string_end.toInt() - 1;
                    QString string = TextWindow->toPlainText();
                    QStringList strList = string.split('\n');

                    for (int i = begin; i <= end; ++i) {
                        int j = 0;
                        while ((j = strList[i].indexOf(substring_to_replace, j)) != -1) {
                            strList[i].remove(j, substring_to_replace.size());
                            strList[i].insert(j, new_substring);
                            ++j;
                        }
                    }
                   PrintText(strList);
                }
            }
        }
    }
}

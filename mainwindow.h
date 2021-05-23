#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QPushButton>
#include <QTextEdit>
#include <QWidget>
#include <QInputDialog>
namespace Ui {


class MainWindow;
}

class MainWindow : public QMainWindow {

Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    virtual ~MainWindow();

private slots:
    void DeleteString();
    void InsertSubstring();
    void InsertString();
    void ReplaceSymbol();
    void ReplaceSubstring();
    void DeleteZeros();
    void DeleteNonIncreasingSubsequences();
    void ReplaceAsteriskSign();
    void DeleteBraces();
    void PrintText(QStringList &);


private:
    QTextEdit *TextWindow;
    QPushButton *ButtonInsertOneString;
    QPushButton *ButtonInsertStrings;
    QPushButton *ButtonDeleteString;
    QPushButton *ButtonInsertSubstring;
    QPushButton *ButtonReplaceSymbol;
    QPushButton *ButtonReplaceSubstring;
    QPushButton *ButtonAlgoZeros;
    QPushButton *ButtonIncreasingSubsequences;
    QPushButton *ButtonReplaceAsteriskSign;
    QPushButton *ButtonDeleteBraces;
};


#endif // MAINWINDOW_H

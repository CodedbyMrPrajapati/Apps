#pragma once
#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>

class JsonDirectoryPage : public QWidget {
    Q_OBJECT

public:
    explicit JsonDirectoryPage(QWidget *parent = nullptr);

signals:
    void previewRequested(const QString &jsonPath, const QString &targetDir);

private slots:
    void onBrowseJson();
    void onBrowseTarget();
    void onPreview();

private:
    QLineEdit *jsonPathEdit;
    QLineEdit *targetDirEdit;
    QPushButton *previewButton;
};

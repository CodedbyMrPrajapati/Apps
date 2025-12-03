#include "jsonDirectoryPage.hpp"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFileDialog>

JsonDirectoryPage::JsonDirectoryPage(QWidget *parent)
    : QWidget(parent)
{
    
    QFile file("../styles/jsonDirPage.qss");
    if (file.open(QFile::ReadOnly)){
        QString style = QLatin1String(file.readAll());
        this->setStyleSheet(style);
    } else {
        throw std::invalid_argument("Error Loading StyleSheet");
    }

    // ------- Main Vertical Layout -------
    QVBoxLayout *root = new QVBoxLayout(this);
    root->setContentsMargins(48, 48, 48, 48);
    root->setSpacing(28);

    // ------- Title -------
    QLabel *title = new QLabel("Generate Directory Structure From JSON", this);
    root->addWidget(title);

    // ------- Subtitle -------
    QLabel *subtitle = new QLabel("Choose a JSON file and a destination folder to begin.", this);
    root->addWidget(subtitle);

    // ------- JSON File Label -------
    QLabel *jsonLabel = new QLabel("JSON File", this);
    root->addWidget(jsonLabel);

    // ROW: JSON Path + Browse
    QHBoxLayout *jsonRow = new QHBoxLayout();
    jsonPathEdit = new QLineEdit(this);
    jsonPathEdit->setPlaceholderText("Select your JSON file...");
    jsonPathEdit->setMinimumHeight(38);

    QPushButton *browseJsonBtn = new QPushButton("Browse", this);
    browseJsonBtn->setMinimumWidth(120);

    jsonRow->addWidget(jsonPathEdit);
    jsonRow->addWidget(browseJsonBtn);
    root->addLayout(jsonRow);

    // ------- Target Directory Label -------
    QLabel *targetLabel = new QLabel("Target Directory", this);
    root->addWidget(targetLabel);

    // ROW: Target Path + Browse
    QHBoxLayout *targetRow = new QHBoxLayout();
    targetDirEdit = new QLineEdit(this);
    targetDirEdit->setPlaceholderText("Select target folder...");
    targetDirEdit->setMinimumHeight(38);

    QPushButton *browseTargetBtn = new QPushButton("Browse Folder", this);
    browseTargetBtn->setMinimumWidth(140);

    targetRow->addWidget(targetDirEdit);
    targetRow->addWidget(browseTargetBtn);
    root->addLayout(targetRow);

    // ------- Preview Button -------
    previewButton = new QPushButton("Preview Structure", this);
    previewButton->setMinimumHeight(48);
    root->addWidget(previewButton, 0, Qt::AlignCenter);

    // ------- Connections -------
    connect(browseJsonBtn,   &QPushButton::clicked, this, &JsonDirectoryPage::onBrowseJson);
    connect(browseTargetBtn, &QPushButton::clicked, this, &JsonDirectoryPage::onBrowseTarget);
    connect(previewButton,   &QPushButton::clicked, this, &JsonDirectoryPage::onPreview);

    title->setObjectName("jsonTitle");
    subtitle->setObjectName("jsonSubtitle");

    jsonLabel->setObjectName("sectionLabel");
    targetLabel->setObjectName("sectionLabel");

    jsonPathEdit->setObjectName("pathInput");
    targetDirEdit->setObjectName("pathInput");

    browseJsonBtn->setObjectName("browseButton");
    browseTargetBtn->setObjectName("browseButton");

    previewButton->setObjectName("primaryButton");

}

void JsonDirectoryPage::onBrowseJson() {
    QString file = QFileDialog::getOpenFileName(this, "Select JSON File", "", "JSON Files (*.json)");
    if (!file.isEmpty())
        jsonPathEdit->setText(file);
}

void JsonDirectoryPage::onBrowseTarget() {
    QString dir = QFileDialog::getExistingDirectory(this, "Select Target Directory");
    if (!dir.isEmpty())
        targetDirEdit->setText(dir);
}

void JsonDirectoryPage::onPreview() {
    emit previewRequested(jsonPathEdit->text(), targetDirEdit->text());
}

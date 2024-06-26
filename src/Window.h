#ifndef QT_PROJECT_WINDOW_H
#define QT_PROJECT_WINDOW_H

#include <QButtonGroup>
#include <QCheckBox>
#include <QCloseEvent>
#include <QComboBox>
#include <QFileDialog>
#include <QGroupBox>
#include <QLabel>
#include <QLineEdit>
#include <QProcess>
#include <QProgressBar>
#include <QPushButton>
#include <QRadioButton>
#include <QWidget>
#include <string>
using namespace std;

class Window : public QWidget {
  Q_OBJECT
public:
  Window();

private:
  QGroupBox *url_area;
  QGroupBox *mode_area;
  QGroupBox *opt_area;
  QGroupBox *path_area;
  QGroupBox *status_area;

  QLineEdit *url;
  QButtonGroup *playlist_grp;
  QRadioButton *single;
  QRadioButton *multiple;
  QButtonGroup *type_grp;
  QRadioButton *video;
  QRadioButton *audio;
  QComboBox *quality;
  QComboBox *codec;
  QCheckBox *subs;

  QLineEdit *path;
  QPushButton *choosePath;
  QProcess *downloader = new QProcess;

  QPushButton *copy;
  QPushButton *download;
  QPushButton *stop;

  QLabel *status;
  QProgressBar *progress;

  string command;
  char percent[3];

  static string getSavedPath();

  void closeEvent(QCloseEvent *event) override;

  void initLayout();
  void initButtons();

  void showVidOpt() {
    quality->clear();
    quality->addItem("Calidad máxima");
    quality->addItem("1080p");
    quality->addItem("720p");
    quality->addItem("480p");
    codec->setEnabled(true);
  }

  void showAudOpt() {
    quality->clear();
    quality->addItem("Calidad máxima");
    quality->addItem("320k");
    quality->addItem("256k");
    quality->addItem("192k");
    codec->setDisabled(true);
  }

  void showCodecOpt() {
    codec->clear();
    codec->addItem("Códec por defecto");
    codec->addItem("VP9");
    codec->addItem("H.264");
    codec->addItem("AV1 (si está disponible)");
  }

  void chooseDir() {
    QString dir =
        QFileDialog::getExistingDirectory(nullptr, QString(), path->text());
    if (!dir.isEmpty()) {
      path->setText(dir);
    }
  }

  bool optionsOK(const QString &url_text, const QString &dir,
                 size_t youtube_url_pos);
  QStringList writeArgs(const QString &url_text, const QString &dir,
                        size_t youtube_url_pos, size_t youtube_share_pos);
  void startDownload();
  void stopJob();
  void copyCommand();
private slots:
  void getOutput();
  void getError();
  void checkStatus();
};

#endif // QT_PROJECT_WINDOW_H

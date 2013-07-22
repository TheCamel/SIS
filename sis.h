/*
SIS - SIS Is Secure - safe instant messaging based on a non-central server architecture
Copyright (C) 2013 Benoît Vernier <vernier.benoit@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SIS_H
#define SIS_H

#include <QtGui>
#include <QtNetwork>
#include <phonon/phonon>

#include <cryptopp/modes.h>
#include <cryptopp/aes.h>
#include <cryptopp/filters.h>
#include <cryptopp/osrng.h>
#include <cryptopp/rsa.h>
#include <cryptopp/ripemd.h>
#include <cryptopp/hex.h>

#include <map>
#include "friend.h"
#include "qmessageedit.h"
#include "qmessagesbrowser.h"
#include "qwindow.h"

using namespace std;
using namespace CryptoPP;

struct datas {
    int tabId;
    QWidget* container;
    QMessagesBrowser* browser;
    byte* key;
    Friend contact;
    quint16 messageSize;
};

class SIS : public QMainWindow
{
  Q_OBJECT

enum Type
{
    text, giveAES, replyAES, giveNick, replyNick, givePubK, replyPubK
};

public:
  SIS(QWidget *parent = 0);

private:
  QMessagesBrowser* state;
  QPushButton* button;

  QWindow* window;

  QSettings* settings;
  QString nickname;

  RSA::PrivateKey privateKey;
  RSA::PublicKey publicKey;

  AutoSeededRandomPool rng;

  QTcpServer* server;
  int port;

  map<QMessageEdit*, QTcpSocket*> edit_socket;
  map<QTcpSocket*, QMessageEdit*> socket_edit;

  map<QTcpSocket*, datas> networkMap;
  map<int, pair<QMessageEdit*, QTcpSocket*> > tabMap;

  void openTab(QTcpSocket* socket);
  void reOpenTab(QTcpSocket* socket);

private slots:
  void transfer();
  void newConversation();
  void dataReceived();
  void requestNewConnection();
  void connected();
  void disconnected();
  void closeTab(int);
  void moveTab(int from, int to);
  void closeAllTabs();
};

#endif // SIS_H

/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** BSD License Usage
** Alternatively, you may use this file under the terms of the BSD license
** as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of The Qt Company Ltd nor the names of its
**     contributors may be used to endorse or promote products derived
**     from this software without specific prior written permission.
**
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include <QtWidgets>
#include <QtNetwork>

#include "client.h"

#include <QDataStream>

Client::Client(QWidget *parent)
    : QObject(parent),
    tcpSocket(new QTcpSocket(this)) {
    data.setDevice(tcpSocket);
    data.setVersion(QDataStream::Qt_4_0);

    connect(tcpSocket, &QIODevice::readyRead, this, &Client::ReadGameState);
    Connect();
}

void Client::Connect()
{
    tcpSocket->abort();
    tcpSocket->connectToHost("192.168.1.76",
                             8765);
}

void Client::ReadGameState()
{
    data.startTransaction();


    if (!data.commitTransaction())
        return;
}

void Client::SendGameState() {
    data.startTransaction();

    if(!data.commitTransaction())
        return;
    qDebug() << JsonifyGameState();
    data << JsonifyGameState();
}

QString Client::JsonifyGameState() {
    QJsonObject game_state_json;
    QJsonArray card_array;
    for(CardInstance *card: game_state_.cards_in_play) {
        QJsonObject card_object;
        JsonifyCardInstance(card_object, card);
        card_array.append(card_object);
    }

    game_state_json["cards"] = card_array;
    return QString(QJsonDocument(game_state_json).toJson(QJsonDocument::Compact));
}

void Client::JsonifyCardInstance(QJsonObject &json, CardInstance *card) const {
    json["id"] = card->card.id;
    json["name"] = card->card.name;
    json["salvage"] = card->card.salvage;
    json["scrap"] = card->card.scrap;
    json["effects"] = card->card.effects;
    json["attack"] = card->card.attack;
    json["defense"] = card->card.defense;
    json["type"] = card->card.type;
    json["scrap_effect"] = card->card.scrap_effect;
    json["player_id"] = card->player_id;
    json["attack_modifier"] = card->attack_modifier;
    json["defense_modifier"] = card->defense_modifier;
    json["damage"] = card->damage;
    json["play_area"] = static_cast<int>(card->play_area);
}

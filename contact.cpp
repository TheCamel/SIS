/*
SIS - SIS Is Secure - safe instant messaging based on a non-central server architecture
Copyright (C) 2013-2014 Benoît Vernier <vernier.benoit@gmail.com>

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

#include "contact.h"

Contact::Contact()
{
    nickname = "Other";
}

Contact::Contact(RSA* key)
    : pubKey(key)
{
    nickname = "Other";
}

RSA* Contact::getPubKey()
{
    return pubKey;
}

void Contact::setNickname(QString name)
{
    nickname = name;
}

QString Contact::getNickname()
{
    return nickname;
}

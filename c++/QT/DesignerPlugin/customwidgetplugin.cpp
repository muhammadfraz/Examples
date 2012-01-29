/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the examples of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
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
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
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
** $QT_END_LICENSE$
**
****************************************************************************/

#include "FloatSlider.h"
#include "customwidgetplugin.h"

#include <QtPlugin>

//! [0]
FloatSliderPlugin::FloatSliderPlugin(QObject *parent)
    : QObject(parent)
{
    initialized = false;
}
//! [0]

//! [1]
void FloatSliderPlugin::initialize(QDesignerFormEditorInterface * /* core */)
{
    if (initialized)
        return;

    initialized = true;
}
//! [1]

//! [2]
bool FloatSliderPlugin::isInitialized() const
{
    return initialized;
}
//! [2]

//! [3]
QWidget *FloatSliderPlugin::createWidget(QWidget *parent)
{
    return new FloatSlider(parent);
}
//! [3]

//! [4]
QString FloatSliderPlugin::name() const
{
    return "FloatSlider";
}
//! [4]

//! [5]
QString FloatSliderPlugin::group() const
{
    return "Display Widgets [Examples]";
}
//! [5]

//! [6]
QIcon FloatSliderPlugin::icon() const
{
    return QIcon();
}
//! [6]

//! [7]
QString FloatSliderPlugin::toolTip() const
{
    return "";
}
//! [7]

//! [8]
QString FloatSliderPlugin::whatsThis() const
{
    return "";
}
//! [8]

//! [9]
bool FloatSliderPlugin::isContainer() const
{
    return false;
}
//! [9]

//! [10]
QString FloatSliderPlugin::domXml() const
{
    return "<ui language=\"c++\">\n"
           " <widget class=\"FloatSlider\" name=\"floatSlider\">\n"
//! [11]
           "  <property name=\"geometry\">\n"
           "   <rect>\n"
           "    <x>0</x>\n"
           "    <y>0</y>\n"
           "    <width>100</width>\n"
           "    <height>100</height>\n"
           "   </rect>\n"
           "  </property>\n"
//! [11]
           "  <property name=\"toolTip\" >\n"
           "   <string>The current time</string>\n"
           "  </property>\n"
           "  <property name=\"whatsThis\" >\n"
           "   <string>The float slider widget allows the user to select a float value.</string>\n"
           "  </property>\n"
           " </widget>\n"
           "</ui>\n";
}
//! [10]

//! [12]
QString FloatSliderPlugin::includeFile() const
{
    return "FloatSlider.h";
}
//! [12]

//! [13]
Q_EXPORT_PLUGIN2(customwidgetplugin, FloatSliderPlugin)
//! [13]
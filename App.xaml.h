﻿#pragma once
/**************************************************************************
* Copyright (C) 2016 by Savoir-faire Linux                                *
* Author: Jäger Nicolas <nicolas.jager@savoirfairelinux.com>              *
*                                                                         *
* This program is free software; you can redistribute it and/or modify    *
* it under the terms of the GNU General Public License as published by    *
* the Free Software Foundation; either version 3 of the License, or       *
* (at your option) any later version.                                     *
*                                                                         *
* This program is distributed in the hope that it will be useful,         *
* but WITHOUT ANY WARRANTY; without even the implied warranty of          *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
* GNU General Public License for more details.                            *
*                                                                         *
* You should have received a copy of the GNU General Public License       *
* along with this program.  If not, see <http://www.gnu.org/licenses/>.   *
**************************************************************************/
#include "App.g.h"

using namespace Windows::ApplicationModel::Activation;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Background;

namespace RingClientUWP
{

ref class App sealed
{
protected:
    virtual void OnLaunched(LaunchActivatedEventArgs^ e) override;
    virtual void OnActivated(IActivatedEventArgs^ e) override;

    void App_EnteredBackground(Platform::Object^ sender, EnteredBackgroundEventArgs^ e);
    void App_LeavingBackground(Platform::Object^ sender, LeavingBackgroundEventArgs^ e);

internal:
    App();

private:
    Frame^ rootFrame;
    void OnsummonWizard();
};

}
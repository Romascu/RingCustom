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
#include "SmartPanel.g.h"

using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Interop;

namespace RingClientUWP
{

delegate void ToggleSmartPan();
delegate void SummonMessageTextPage();
delegate void SummonVideoPage();
delegate void SummonWelcomePage();
delegate void SummonPreviewPage();
delegate void HidePreviewPage();

namespace Views
{

public ref class IncomingVisibility sealed : IValueConverter {
public:
    virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language);
    virtual Object^ ConvertBack(Object^ value, TypeName  targetType, Object^ parameter, String^ language);
    IncomingVisibility();
};

public ref class OutGoingVisibility sealed : IValueConverter {
public:
    virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language);
    virtual Object^ ConvertBack(Object^ value, TypeName  targetType, Object^ parameter, String^ language);
    OutGoingVisibility();
};

public ref class HasAnActiveCall sealed : IValueConverter {
public:
    virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language);
    virtual Object^ ConvertBack(Object^ value, TypeName  targetType, Object^ parameter, String^ language);
    HasAnActiveCall();
};

public ref class AccountTypeToSourceImage sealed : IValueConverter {
public:
    virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language);
    virtual Object^ ConvertBack(Object^ value, TypeName  targetType, Object^ parameter, String^ language);
    AccountTypeToSourceImage();
};

public ref class AccountSelectedToVisibility sealed : IValueConverter {
public:
    virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language);
    virtual Object^ ConvertBack(Object^ value, TypeName  targetType, Object^ parameter, String^ language);
    AccountSelectedToVisibility();
};

public ref class NewMessageBubleNotification sealed : IValueConverter {
public:
    virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language);
    virtual Object^ ConvertBack(Object^ value, TypeName  targetType, Object^ parameter, String^ language);
    NewMessageBubleNotification();
};

public ref class CollapseEmptyString sealed : IValueConverter {
public:
    virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language);
    virtual Object^ ConvertBack(Object^ value, TypeName  targetType, Object^ parameter, String^ language);
    CollapseEmptyString();
};

public ref class ContactStatusNotification sealed : IValueConverter {
public:
    virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language);
    virtual Object^ ConvertBack(Object^ value, TypeName  targetType, Object^ parameter, String^ language);
    ContactStatusNotification();
};

public ref class boolToVisibility sealed : IValueConverter {
public:
    virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language);
    virtual Object^ ConvertBack(Object^ value, TypeName  targetType, Object^ parameter, String^ language);
    boolToVisibility() {};
};

public ref class uintToVisibility sealed : IValueConverter {
public:
    virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language);
    virtual Object^ ConvertBack(Object^ value, TypeName  targetType, Object^ parameter, String^ language) {
        return nullptr;
    };
    uintToVisibility() {};
};

public ref class OneToVisibility sealed : IValueConverter {
public:
    virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language);
    virtual Object^ ConvertBack(Object^ value, TypeName  targetType, Object^ parameter, String^ language) {
        return nullptr;
    };
    OneToVisibility() {};
};

public ref class MoreThanOneToVisibility sealed : IValueConverter {
public:
    virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language);
    virtual Object^ ConvertBack(Object^ value, TypeName  targetType, Object^ parameter, String^ language) {
        return nullptr;
    };
    MoreThanOneToVisibility() {};
};

public ref class SelectedAccountToVisibility sealed : IValueConverter {
public:
    virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language);
    virtual Object^ ConvertBack(Object^ value, TypeName  targetType, Object^ parameter, String^ language) {
        return nullptr;
    };
    SelectedAccountToVisibility() {};
};

public ref class CallStatusToSpinnerVisibility sealed : IValueConverter {
public:
    virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language);
    virtual Object^ ConvertBack(Object^ value, TypeName  targetType, Object^ parameter, String^ language);
    CallStatusToSpinnerVisibility();
};

public ref class CallStatusForIncomingCallAnimatedEllipse sealed : IValueConverter {
public:
    virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language);
    virtual Object^ ConvertBack(Object^ value, TypeName  targetType, Object^ parameter, String^ language);
    CallStatusForIncomingCallAnimatedEllipse();
};

public ref class CallStatusForIncomingCallStaticEllipse sealed : IValueConverter {
public:
    virtual Object^ Convert(Object^ value, TypeName targetType, Object^ parameter, String^ language);
    virtual Object^ ConvertBack(Object^ value, TypeName  targetType, Object^ parameter, String^ language);
    CallStatusForIncomingCallStaticEllipse();
};


public ref class SmartPanel sealed
{
public:
    SmartPanel();
    void updatePageContent();

internal:
    enum class Mode { Minimized, Normal };
    event ToggleSmartPan^ toggleSmartPan;
    event SummonMessageTextPage^ summonMessageTextPage;
    event SummonVideoPage^ summonVideoPage;
    event SummonWelcomePage^ summonWelcomePage;
    event SummonPreviewPage^ summonPreviewPage;
    event HidePreviewPage^ hidePreviewPage;
    void setMode(RingClientUWP::Views::SmartPanel::Mode mode);

private:
    enum class MenuOpen {
        CONTACTS_LIST,
        ACCOUNTS_LIST,
        SHARE,
        DEVICE,
        SETTINGS
    } menuOpen;

    /* functions */
    void _addAccountBtn__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _createAccountYes__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _createAccountNo__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _smartList__SelectionChanged(Platform::Object^ sender, SelectionChangedEventArgs^ e);
    void _accountList__SelectionChanged(Platform::Object^ sender, SelectionChangedEventArgs^ e);
    void _ringTxtBx__Click(Platform::Object^ sender, KeyRoutedEventArgs^ e);
    void _rejectIncomingCallBtn__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _acceptIncomingCallBtn__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _callContact__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _cancelCallBtn__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void Grid_PointerEntered(Platform::Object^ sender, PointerRoutedEventArgs^ e);
    void Grid_PointerExited(Platform::Object^ sender, PointerRoutedEventArgs^ e);
    void generateQRcode();
    void _videoDeviceComboBox__SelectionChanged(Platform::Object^ sender, RoutedEventArgs^);
    void _videoResolutionComboBox__SelectionChanged(Platform::Object^ sender, RoutedEventArgs^);
    void _videoRateComboBox__SelectionChanged(Platform::Object^ sender, RoutedEventArgs^);
    void populateVideoDeviceSettingsComboBox();
    void populateVideoResolutionSettingsComboBox();
    void populateVideoRateSettingsComboBox();
    void checkStateAddAccountMenu();
    void checkStateEditionMenu();
    void ringTxtBxPlaceHolderDelay(String^ placeHolderText, int delayInMilliSeconds);
    void showLinkThisDeviceStep1();
    void OnstateChange(Platform::String ^callId, RingClientUWP::CallStatus state, int code);
    void _addDevice__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void OndevicesListRefreshed(Platform::Collections::Vector<Platform::String ^, std::equal_to<Platform::String ^>, true> ^devicesList);
    void _pinGeneratorYes__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _pinGeneratorNo__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void OnexportOnRingEnded(Platform::String ^accountId, Platform::String ^pin);
    void _closePin__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _shareMenuDone__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _editAccountMenuButton__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _acceptAccountModification__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _cancelAccountModification__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void OnaccountUpdated(RingClientUWP::Account ^account);
    void _passwordBoxAccountCreationCheck__PasswordChanged(Platform::Object^ sender, RoutedEventArgs^ e);
    void _accountTypeComboBox__SelectionChanged(Platform::Object^ sender, SelectionChangedEventArgs^ e);
    void _accountAliasTextBox__TextChanged(Platform::Object^ sender, TextChangedEventArgs^ e);
    void _accountAliasTextBoxEdition__TextChanged(Platform::Object^ sender, TextChangedEventArgs^ e);
    void _selectedAccountAvatarContainer__PointerEntered(Platform::Object^ sender, PointerRoutedEventArgs^ e);
    void _selectedAccountAvatarContainer__PointerReleased(Platform::Object^ sender, PointerRoutedEventArgs^ e);
    void _selectedAccountAvatarContainer__PointerExited(Platform::Object^ sender, PointerRoutedEventArgs^ e);
    void _smartList__PointerExited(Platform::Object^ sender, PointerRoutedEventArgs^ e);
    void Grid_PointerMoved(Platform::Object^ sender, PointerRoutedEventArgs^ e);
    void _registerOnBlockchainEdition__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _usernameTextBoxEdition__KeyUp(Platform::Object^ sender, KeyRoutedEventArgs^ e);
    void OnregisteredNameFound(RingClientUWP::LookupStatus status, const std::string& address, const std::string& name);
    void _RegisterState__Toggled(Platform::Object^ sender, RoutedEventArgs^ e);
    void _usernameTextBox__KeyUp(Platform::Object^ sender, KeyRoutedEventArgs^ e);
    void _deleteAccountEdition__Toggled(Platform::Object^ sender, RoutedEventArgs^ e);
    void _RegisterStateEdition__Toggled(Platform::Object^ sender, RoutedEventArgs^ e);
    void _ringTxtBx__KeyUp(Platform::Object^ sender, KeyRoutedEventArgs^ e);
    void _linkThisDeviceBtn__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _step2button__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _step1button__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _addAccountNo__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _addAccountYes__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void OnregistrationStateErrorGeneric(const std::string& accountId);
    void _PINTextBox__GotFocus(Platform::Object^ sender, RoutedEventArgs^ e);
    void OnregistrationStateRegistered();
    void OncallPlaced(Platform::String ^callId);
    void updateUnreadMessagesState();
    void selectMenu(MenuOpen menu);
    void Grid_PointerReleased(Platform::Object^ sender, PointerRoutedEventArgs^ e);
    void OnincomingAccountMessage(Platform::String ^accountId, Platform::String ^from, Platform::String ^payload);
    void _ringTxtBx__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _contactsListMenuButton__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _accountsMenuButton__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _shareMenuButton__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _devicesMenuButton__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _settingsMenuButton__Click(Platform::Object^ sender, RoutedEventArgs^ e);
    void _passwordForPinGenerator__KeyUp(Platform::Object^ sender, KeyRoutedEventArgs^ e);
    void requestPin();
};
}
}

// -*- C++ -*- generated by wxGlade 0.3.5.1 on Sat Aug 20 16:34:47 2005

#include "OVPrefDlg.h"

BEGIN_EVENT_TABLE( OVPrefDlg, wxDialog )
	EVT_BUTTON( ID_FONT, OVPrefDlg::OnFont )
	EVT_BUTTON( ID_BGCOLOR, OVPrefDlg::OnBgColor )
	EVT_BUTTON( ID_BGPICTURE, OVPrefDlg::OnBgPicture )
	EVT_BUTTON( ID_SOUNDTEST, OVPrefDlg::OnSoundTest )
	EVT_BUTTON( ID_COMMON_CLEAR, OVPrefDlg::OnCommonClear )
	EVT_BUTTON( ID_MODLIST_CLEAR, OVPrefDlg::OnModListClear )
	EVT_LIST_ITEM_SELECTED(ID_MODLIST, OVPrefDlg::OnModListItemSelected )
END_EVENT_TABLE()


OVPrefDlg::OVPrefDlg(wxWindow* parent, int id, const wxString& title, const wxPoint& pos, const wxSize& size, long style):
    wxDialog(parent, id, title, pos, size, wxDEFAULT_DIALOG_STYLE|wxCLIP_CHILDREN)
{
    // begin wxGlade: OVPrefDlg::OVPrefDlg
    notebook = new wxNotebook(this, -1, wxDefaultPosition, wxDefaultSize, 0);
    module_settings_page = new wxPanel(notebook, -1);
    module_list_page = new wxPanel(notebook, -1, wxDefaultPosition, wxDefaultSize, wxTAB_TRAVERSAL|wxCLIP_CHILDREN);
    common_page = new wxPanel(notebook, -1);
    sizer_13_staticbox = new wxStaticBox(common_page, -1, _("Sound"));
    sizer_15_staticbox = new wxStaticBox(common_page, -1, _("Other settings"));
    sizer_1_staticbox = new wxStaticBox(module_list_page, -1, _("Available modules:"));
    sizer_7_staticbox = new wxStaticBox(module_list_page, -1, _("Set the shortcut key to:"));
    sizer_22_staticbox = new wxStaticBox(module_settings_page, -1, _("Phonetic, Chewing, POJ, and Tibetan IME"));
    sizer_24_staticbox = new wxStaticBox(module_settings_page, -1, _("Generic (data table-based) input method"));
    sizer_25_staticbox = new wxStaticBox(module_settings_page, -1, _("Other modules"));
    sizer_3_staticbox = new wxStaticBox(common_page, -1, _("Candidate and notification window"));
    fontBtn = new wxButton(common_page, ID_FONT, _("Font"));
    label_1 = new wxStaticText(common_page, -1, _("Font: "));
    bgColorBtn = new wxButton(common_page, ID_BGCOLOR, _("Background Color"));
    imageBtn = new wxButton(common_page, ID_BGPICTURE, _("Image"));
    filePath_copy_copy = new wxStaticText(common_page, -1, _("Image Path: "));
    label_1_copy = new wxStaticText(common_page, -1, _("Opacity"));
    opacitySlider = new wxSlider(common_page, -1, 0, 0, 10, wxDefaultPosition, wxDefaultSize, wxSL_HORIZONTAL|wxSL_AUTOTICKS|wxSL_LABELS);
    label_2 = new wxStaticText(common_page, -1, _("Preview"));
    previewText = new wxTextCtrl(common_page, -1, _("OpenVanilla"), wxDefaultPosition, wxDefaultSize, wxTE_READONLY|wxTE_RICH|wxTE_CENTRE);
    label_5 = new wxStaticText(common_page, -1, _("(Opacity not in effect)"));
    label_3 = new wxStaticText(common_page, -1, _("Warning sound: "));
    soundFile = new wxTextCtrl(common_page, -1, wxT(""));
    soundTest = new wxButton(common_page, ID_SOUNDTEST, _("&Test"));
    label_4 = new wxStaticText(common_page, -1, _("IM toggle key: "));
    switchAlt = new wxCheckBox(common_page, -1, _("Alt"));
    switchCtrl = new wxCheckBox(common_page, -1, _("Ctrl"));
    switchShift = new wxCheckBox(common_page, -1, _("Shift"));
    label_15 = new wxStaticText(common_page, -1, _(" + "));
    const wxString switchKey_choices[] = {
        wxT("")
    };
    switchKey = new wxComboBox(common_page, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 1, switchKey_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    common_clear = new wxButton(common_page, ID_COMMON_CLEAR, _("Clear"));
    const wxString modList_choices[] = {
        wxT("")
    };
    modList = new wxCheckListBox(module_list_page, ID_MODLIST, wxDefaultPosition, wxDefaultSize, 1, modList_choices, wxLB_SINGLE|wxLB_HSCROLL);
    modlistAlt = new wxCheckBox(module_list_page, -1, _("Alt"));
    modlistShift = new wxCheckBox(module_list_page, -1, _("Shift"));
    modlistCtrl = new wxCheckBox(module_list_page, -1, _("Ctrl"));
    label_8_copy = new wxStaticText(module_list_page, -1, _("+"));
    const wxString modlistKey_choices[] = {
        _("None")
    };
    modlistKey = new wxComboBox(module_list_page, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 1, modlistKey_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    modlistClear = new wxButton(module_list_page, ID_MODLIST_CLEAR, _("Clear"));
    label_7 = new wxStaticText(module_list_page, -1, _("The selected module is loaded \nfrom the following library:\n"));
    label_6 = new wxStaticText(module_list_page, -1, _("Remove unused modules \ncan speed up loading.\nYou have to exit and restart \nexisting applications using \nOpenVanilla or this won't \ntake effect."));
    label_9 = new wxStaticText(module_settings_page, -1, _("Keyboard layout for Phonetics: "));
    const wxString phoneticKeyboardLayout_choices[] = {
        _("Standard Layout")
    };
    phoneticKeyboardLayout = new wxComboBox(module_settings_page, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 1, phoneticKeyboardLayout_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    label_9_copy = new wxStaticText(module_settings_page, -1, _("Keyboard layout of Chewing: "));
    const wxString chewingKeyboardLayout_choices[] = {
        _("Standard Layout")
    };
    chewingKeyboardLayout = new wxComboBox(module_settings_page, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 1, chewingKeyboardLayout_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    label_10 = new wxStaticText(module_settings_page, -1, _("Keyboard layout for POJ-Holo: "));
    const wxString pojKeyboardLayout_choices[] = {
        _("Use tone numbers (2, 3, 5, 7, 8) only")
    };
    pojKeyboardLayout = new wxComboBox(module_settings_page, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 1, pojKeyboardLayout_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    pojNoUnicode = new wxCheckBox(module_settings_page, -1, _("Do not output unicode characters but pure ASCII instead"));
    pojNoHanChars = new wxCheckBox(module_settings_page, -1, _("Do not show Han character candidates. (POJ-only output)"));
    label_11 = new wxStaticText(module_settings_page, -1, _("Keyboard layout for Tibetan: "));
    const wxString tibetanKeyboardLayout_choices[] = {
        _("Sambhota Keymap One")
    };
    tibetanKeyboardLayout = new wxComboBox(module_settings_page, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 1, tibetanKeyboardLayout_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    label_12 = new wxStaticText(module_settings_page, -1, _("Module: "));
    const wxString genericCombo_choices[] = {
        _("None")
    };
    genericCombo = new wxComboBox(module_settings_page, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 1, genericCombo_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    label_13 = new wxStaticText(module_settings_page, -1, _("Maximal radical length: "));
    const wxString genericMaxRadLength_choices[] = {
        _("5")
    };
    genericMaxRadLength = new wxComboBox(module_settings_page, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 1, genericMaxRadLength_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    spaceChoose1stCand = new wxCheckBox(module_settings_page, -1, _("Space key choose the 1st candidate"));
    showCandOnType = new wxCheckBox(module_settings_page, -1, _("Show candidates as you type"));
    commitAtMaxRad = new wxCheckBox(module_settings_page, -1, _("Commit at maximal radical length"));
    warningBeep = new wxCheckBox(module_settings_page, -1, _("Warning beep"));
    label_14 = new wxStaticText(module_settings_page, -1, _("Module: "));
    const wxString otherModCombo_choices[] = {
        _("None")
    };
    otherModCombo = new wxComboBox(module_settings_page, -1, wxT(""), wxDefaultPosition, wxDefaultSize, 1, otherModCombo_choices, wxCB_DROPDOWN|wxCB_SIMPLE|wxCB_READONLY);
    otherModPropList = new wxListCtrl(module_settings_page, -1, wxDefaultPosition, wxDefaultSize, wxLC_REPORT|wxSUNKEN_BORDER);
    output_filter_page = new wxPanel(notebook, -1);
    ok_btn = new wxButton(this, wxID_OK, _("&OK"));
    cancel_btn = new wxButton(this, wxID_CANCEL, _("&Cancel"));

    set_properties();
    do_layout();
    // end wxGlade

	otherModPropList->InsertColumn( 0, _("Property key") );
	otherModPropList->InsertColumn( 1, _("Value") );
}

#if !defined(__WXMSW__)
	#include "ovpref.xpm"
#endif

void OVPrefDlg::set_properties()
{
    // begin wxGlade: OVPrefDlg::set_properties
    SetTitle(_("Open Vanilla Preferences"));
    opacitySlider->SetSize(wxSize(176, 20));
    switchKey->SetSelection(-1);
    modList->SetSelection(0);
    modlistKey->SetSelection(-1);
    phoneticKeyboardLayout->SetSelection(0);
    chewingKeyboardLayout->SetSelection(0);
    pojKeyboardLayout->SetSelection(0);
    tibetanKeyboardLayout->SetSelection(0);
    genericCombo->SetSelection(-1);
    genericMaxRadLength->SetSelection(-1);
    otherModCombo->SetSelection(-1);
    ok_btn->SetDefault();
    // end wxGlade
	SetIcon(wxICON(ovpref_icon));
}


void OVPrefDlg::do_layout()
{
    // begin wxGlade: OVPrefDlg::do_layout
    wxBoxSizer* top_sizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* bottom_sizer = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* module_settings_sizer = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_23 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticBoxSizer* sizer_25 = new wxStaticBoxSizer(sizer_25_staticbox, wxVERTICAL);
    wxBoxSizer* sizer_33 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticBoxSizer* sizer_24 = new wxStaticBoxSizer(sizer_24_staticbox, wxVERTICAL);
    wxBoxSizer* sizer_32 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_31 = new wxBoxSizer(wxHORIZONTAL);
    wxStaticBoxSizer* sizer_22 = new wxStaticBoxSizer(sizer_22_staticbox, wxVERTICAL);
    wxBoxSizer* sizer_30 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_29 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_28 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_27 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_26_copy = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_26 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_16 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_17 = new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer* sizer_7 = new wxStaticBoxSizer(sizer_7_staticbox, wxVERTICAL);
    wxBoxSizer* sizer_8 = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_20_copy = new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer* sizer_1 = new wxStaticBoxSizer(sizer_1_staticbox, wxVERTICAL);
    wxBoxSizer* common_page_sizer = new wxBoxSizer(wxVERTICAL);
    wxStaticBoxSizer* sizer_15 = new wxStaticBoxSizer(sizer_15_staticbox, wxHORIZONTAL);
    wxStaticBoxSizer* sizer_13 = new wxStaticBoxSizer(sizer_13_staticbox, wxHORIZONTAL);
    wxStaticBoxSizer* sizer_3 = new wxStaticBoxSizer(sizer_3_staticbox, wxHORIZONTAL);
    wxBoxSizer* sizer_4 = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* candidate_window_sizer_copy = new wxBoxSizer(wxVERTICAL);
    wxBoxSizer* sizer_12_copy = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_11_copy = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer* sizer_2 = new wxBoxSizer(wxHORIZONTAL);
    sizer_2->Add(fontBtn, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_2->Add(label_1, 0, wxALL|wxFIXED_MINSIZE, 2);
    candidate_window_sizer_copy->Add(sizer_2, 1, wxALL|wxEXPAND, 2);
    sizer_11_copy->Add(bgColorBtn, 0, wxLEFT|wxRIGHT|wxFIXED_MINSIZE, 2);
    sizer_11_copy->Add(imageBtn, 0, wxLEFT|wxRIGHT|wxFIXED_MINSIZE, 2);
    candidate_window_sizer_copy->Add(sizer_11_copy, 0, wxALL|wxEXPAND, 2);
    candidate_window_sizer_copy->Add(filePath_copy_copy, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_12_copy->Add(label_1_copy, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxFIXED_MINSIZE, 2);
    sizer_12_copy->Add(opacitySlider, 1, wxALL, 2);
    candidate_window_sizer_copy->Add(sizer_12_copy, 0, wxALL|wxEXPAND, 2);
    sizer_3->Add(candidate_window_sizer_copy, 0, wxALL|wxEXPAND, 2);
    sizer_4->Add(label_2, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_4->Add(previewText, 1, wxALL|wxEXPAND|wxFIXED_MINSIZE, 2);
    sizer_4->Add(label_5, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_3->Add(sizer_4, 1, wxALL|wxEXPAND, 2);
    common_page_sizer->Add(sizer_3, 0, wxEXPAND, 0);
    sizer_13->Add(label_3, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxFIXED_MINSIZE, 2);
    sizer_13->Add(soundFile, 2, wxALL|wxFIXED_MINSIZE, 2);
    sizer_13->Add(soundTest, 0, wxALL|wxFIXED_MINSIZE, 2);
    common_page_sizer->Add(sizer_13, 0, wxALL|wxEXPAND, 2);
    sizer_15->Add(label_4, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_15->Add(switchAlt, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_15->Add(switchCtrl, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_15->Add(switchShift, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_15->Add(label_15, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_15->Add(switchKey, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_15->Add(common_clear, 0, wxALL|wxFIXED_MINSIZE, 2);
    common_page_sizer->Add(sizer_15, 0, wxALL|wxEXPAND, 2);
    common_page->SetAutoLayout(true);
    common_page->SetSizer(common_page_sizer);
    common_page_sizer->Fit(common_page);
    common_page_sizer->SetSizeHints(common_page);
    sizer_1->Add(modList, 1, wxALL|wxEXPAND, 1);
    sizer_16->Add(sizer_1, 1, wxALL|wxEXPAND, 2);
    sizer_20_copy->Add(modlistAlt, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_20_copy->Add(modlistShift, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_20_copy->Add(modlistCtrl, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_8->Add(sizer_20_copy, 0, wxALL|wxEXPAND, 2);
    sizer_8->Add(label_8_copy, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 2);
    sizer_8->Add(modlistKey, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxFIXED_MINSIZE, 2);
    sizer_7->Add(sizer_8, 1, wxEXPAND, 0);
    sizer_7->Add(modlistClear, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_17->Add(sizer_7, 1, wxALL|wxEXPAND, 2);
    sizer_17->Add(label_7, 1, wxALL|wxEXPAND, 4);
    sizer_17->Add(label_6, 0, wxALL|wxEXPAND, 4);
    sizer_16->Add(sizer_17, 0, wxALL, 2);
    module_list_page->SetAutoLayout(true);
    module_list_page->SetSizer(sizer_16);
    sizer_16->Fit(module_list_page);
    sizer_16->SetSizeHints(module_list_page);
    sizer_26->Add(label_9, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_26->Add(phoneticKeyboardLayout, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_22->Add(sizer_26, 1, wxEXPAND, 0);
    sizer_26_copy->Add(label_9_copy, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_26_copy->Add(chewingKeyboardLayout, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_22->Add(sizer_26_copy, 1, wxEXPAND, 0);
    sizer_27->Add(label_10, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_27->Add(pojKeyboardLayout, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_22->Add(sizer_27, 1, wxEXPAND, 0);
    sizer_28->Add(20, 0, 0, wxFIXED_MINSIZE, 0);
    sizer_28->Add(pojNoUnicode, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_22->Add(sizer_28, 1, wxEXPAND, 0);
    sizer_29->Add(20, 0, 0, wxFIXED_MINSIZE, 0);
    sizer_29->Add(pojNoHanChars, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_22->Add(sizer_29, 1, wxEXPAND, 0);
    sizer_30->Add(label_11, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_30->Add(tibetanKeyboardLayout, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_22->Add(sizer_30, 1, wxEXPAND, 0);
    module_settings_sizer->Add(sizer_22, 1, wxALL|wxEXPAND, 2);
    sizer_31->Add(label_12, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_31->Add(genericCombo, 1, wxALL|wxFIXED_MINSIZE, 2);
    sizer_24->Add(sizer_31, 0, wxEXPAND, 0);
    sizer_32->Add(label_13, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_32->Add(genericMaxRadLength, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_24->Add(sizer_32, 0, wxEXPAND, 0);
    sizer_24->Add(spaceChoose1stCand, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_24->Add(showCandOnType, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_24->Add(commitAtMaxRad, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_24->Add(warningBeep, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_23->Add(sizer_24, 1, wxALL|wxEXPAND, 2);
    sizer_33->Add(label_14, 0, wxALL|wxFIXED_MINSIZE, 2);
    sizer_33->Add(otherModCombo, 1, wxALL|wxFIXED_MINSIZE, 2);
    sizer_25->Add(sizer_33, 0, wxEXPAND, 0);
    sizer_25->Add(otherModPropList, 1, wxALL|wxEXPAND, 2);
    sizer_23->Add(sizer_25, 1, wxALL|wxEXPAND, 2);
    module_settings_sizer->Add(sizer_23, 1, wxEXPAND, 0);
    module_settings_page->SetAutoLayout(true);
    module_settings_page->SetSizer(module_settings_sizer);
    module_settings_sizer->Fit(module_settings_page);
    module_settings_sizer->SetSizeHints(module_settings_page);
    notebook->AddPage(common_page, _("Common"));
    notebook->AddPage(module_list_page, _("Modules List && Hotkeys"));
    notebook->AddPage(module_settings_page, _("Module Settings"));
    notebook->AddPage(output_filter_page, _("Output Filters"));
    top_sizer->Add(new wxNotebookSizer(notebook), 1, wxALL|wxEXPAND, 4);
    bottom_sizer->Add(ok_btn, 0, wxFIXED_MINSIZE, 0);
    bottom_sizer->Add(4, 0, 0, wxFIXED_MINSIZE, 0);
    bottom_sizer->Add(cancel_btn, 0, wxFIXED_MINSIZE, 2);
    top_sizer->Add(bottom_sizer, 0, wxALL|wxALIGN_RIGHT, 4);
    SetAutoLayout(true);
    SetSizer(top_sizer);
    top_sizer->Fit(this);
    top_sizer->SetSizeHints(this);
    Layout();
    // end wxGlade
}


void OVPrefDlg::OnFont(wxCommandEvent& evt)
{
	
}

void OVPrefDlg::OnBgColor(wxCommandEvent& evt)
{
	
}

void OVPrefDlg::OnBgPicture(wxCommandEvent& evt)
{
	
}

void OVPrefDlg::OnSoundTest(wxCommandEvent& evt)
{
	
}

void OVPrefDlg::OnCommonClear(wxCommandEvent& evt)
{
	
}

void OVPrefDlg::OnModListClear(wxCommandEvent& evt)
{
	
}


void OVPrefDlg::OnModListItemSelected(wxListEvent& evt)
{
}

// wxWidgets "Hello World" Program
 
// For compilers that support precompilation, includes "wx/wx.h".
#include <wx/wxprec.h>
 
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif
 
class MyApp : public wxApp
{
public:
    virtual bool OnInit();
};
 
class MyFrame : public wxFrame
{
public:
    MyFrame();
 
private:
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);
    wxButton *HelloWorld;
};
 
enum
{
    ID_Hello = 1,
    BUTTON_Hello = 2
};
 
wxIMPLEMENT_APP(MyApp);
 
bool MyApp::OnInit()
{
    MyFrame *frame = new MyFrame();
    frame->Show(true);
    return true;
}
 
MyFrame::MyFrame()
    : wxFrame(nullptr, wxID_ANY, "Hello World")
{
 
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
    HelloWorld = new wxButton(this, BUTTON_Hello, _T("Hello"),
      // shows a button on this window
    wxPoint(0,0), wxSize(30,30), 0); // with the text "hello World"
    // 按钮点击管用了
    Connect(BUTTON_Hello, wxEVT_COMMAND_BUTTON_CLICKED, 
      wxCommandEventHandler( MyFrame::OnAbout));
 
}
 
void MyFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
 
void MyFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets Hello World example",
                 "About Hello World", wxOK | wxICON_INFORMATION);
}
 
void MyFrame::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}
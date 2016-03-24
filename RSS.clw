; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CRSSDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "RSS.h"

ClassCount=16
Class1=CRSSApp
Class2=CRSSDlg
Class3=CAboutDlg

ResourceCount=16
Resource1=IDD_RSS_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_DIALOG7
Resource4=IDD_DIALOG4
Resource5=IDD_ABOUTBOX
Resource6=IDD_DIALOG1
Resource7=IDD_COLLECTION
Resource8=IDD_NEWCOLLECT
Class4=Cnews
Class5=Ccommets
Resource9=IDD_SET
Resource10=IDD_DIALOG6
Resource11=IDD_DIALOG3
Class6=Cmanagement
Resource12=IDD_DIALOG2
Class7=Cset
Resource13=IDD_DIALOG9
Class8=Ccollection
Class9=Cscience
Class10=Csports
Class11=Cplay
Class12=Chistory
Class13=Cblog
Class14=Cnewcollect
Resource14=IDD_DIALOG5
Class15=Caddcollection
Resource15=IDD_MANAGEMENT
Class16=Chelp
Resource16=IDD_DIALOG10

[CLS:CRSSApp]
Type=0
HeaderFile=RSS.h
ImplementationFile=RSS.cpp
Filter=N

[CLS:CRSSDlg]
Type=0
HeaderFile=RSSDlg.h
ImplementationFile=RSSDlg.cpp
Filter=D
LastObject=IDC_collection
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=RSSDlg.h
ImplementationFile=RSSDlg.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_RSS_DIALOG]
Type=1
Class=CRSSDlg
ControlCount=4
Control1=IDC_TAB,SysTabControl32,1342177282
Control2=IDC_MANAGEMENT,button,1342242816
Control3=IDC_INTRO,button,1342242816
Control4=IDC_collection,button,1342242816

[DLG:IDD_DIALOG1]
Type=1
Class=Cnews
ControlCount=7
Control1=IDC_LISTNEWS,SysListView32,1350631441
Control2=IDC_EDIT1,edit,1352735748
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816
Control5=IDC_BUTTON3,button,1342242816
Control6=IDC_EDIT2,edit,1350631552
Control7=IDC_STATIC,button,1342210055

[DLG:IDD_DIALOG2]
Type=1
Class=Ccommets
ControlCount=3
Control1=IDC_LISTCOMMENTS,SysListView32,1350631425
Control2=IDC_EDIT2,edit,1350631552
Control3=IDC_BUTTON2,button,1342242816

[DLG:IDD_DIALOG3]
Type=1
Class=Cscience
ControlCount=7
Control1=IDC_LISTSCIENCE,SysListView32,1350631441
Control2=IDC_EDITSCIENCE,edit,1352735748
Control3=IDC_BUTTON3,button,1342242816
Control4=IDC_BUTTON4,button,1342242816
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_BUTTON1,button,1342242816
Control7=IDC_STATIC,button,1342210055

[DLG:IDD_DIALOG4]
Type=1
Class=Csports
ControlCount=3
Control1=IDC_LISTSPORTS,SysListView32,1350631441
Control2=IDC_EDITSPORTS,edit,1352731780
Control3=IDC_BUTTON1,button,1342242816

[DLG:IDD_DIALOG5]
Type=1
Class=Cplay
ControlCount=7
Control1=IDC_EDIT3,edit,1352735748
Control2=IDC_LISTPLAY,SysListView32,1350631441
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816
Control5=IDC_EDIT1,edit,1350631552
Control6=IDC_BUTTON3,button,1342242816
Control7=IDC_STATIC,button,1342210055

[DLG:IDD_DIALOG6]
Type=1
Class=Chistory
ControlCount=7
Control1=IDC_EDIT4,edit,1352735748
Control2=IDC_LISTHISTORY,SysListView32,1350631425
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816
Control5=IDC_EDIT2,edit,1350631552
Control6=IDC_BUTTON3,button,1342242816
Control7=IDC_STATIC,button,1342210055

[CLS:Cnews]
Type=0
HeaderFile=news.h
ImplementationFile=news.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON3
VirtualFilter=dWC

[CLS:Ccommets]
Type=0
HeaderFile=commets.h
ImplementationFile=commets.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LISTCOMMENTS
VirtualFilter=dWC

[DLG:IDD_DIALOG7]
Type=1
Class=Cblog
ControlCount=7
Control1=IDC_EDIT2,edit,1352735748
Control2=IDC_LISTBLOG,SysListView32,1350631425
Control3=IDC_BUTTON1,button,1342242816
Control4=IDC_BUTTON2,button,1342242816
Control5=IDC_BUTTON3,button,1342242816
Control6=IDC_EDIT1,edit,1350631552
Control7=IDC_STATIC,button,1342210055

[DLG:IDD_MANAGEMENT]
Type=1
Class=Cmanagement
ControlCount=13
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_CHECK1,button,1342242819
Control5=IDC_CHECK2,button,1342242819
Control6=IDC_STATIC,static,1342308352
Control7=IDC_CHECK3,button,1342242819
Control8=IDC_STATIC,static,1342308352
Control9=IDC_CHECK4,button,1342242819
Control10=IDC_STATIC,static,1342308352
Control11=IDC_CHECK5,button,1342242819
Control12=IDC_STATIC,static,1342308352
Control13=IDC_CHECK6,button,1342242819

[CLS:Cmanagement]
Type=0
HeaderFile=management.h
ImplementationFile=management.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_CHECK3
VirtualFilter=dWC

[DLG:IDD_SET]
Type=1
Class=Cset
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816

[CLS:Cset]
Type=0
HeaderFile=set.h
ImplementationFile=set.cpp
BaseClass=CDialog
Filter=D
LastObject=Cset

[DLG:IDD_COLLECTION]
Type=1
Class=Ccollection
ControlCount=2
Control1=IDC_LIST2,SysListView32,1350631425
Control2=IDC_EDIT1,edit,1352735748

[CLS:Ccollection]
Type=0
HeaderFile=collection.h
ImplementationFile=collection.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LIST2
VirtualFilter=dWC

[CLS:Cscience]
Type=0
HeaderFile=science.h
ImplementationFile=science.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

[CLS:Csports]
Type=0
HeaderFile=sports.h
ImplementationFile=sports.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LISTSPORTS
VirtualFilter=dWC

[CLS:Cplay]
Type=0
HeaderFile=play.h
ImplementationFile=play.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_EDIT1

[CLS:Chistory]
Type=0
HeaderFile=history2.h
ImplementationFile=history2.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT2
VirtualFilter=dWC

[CLS:Cblog]
Type=0
HeaderFile=blog.h
ImplementationFile=blog.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

[CLS:Cnewcollect]
Type=0
HeaderFile=newcollect.h
ImplementationFile=newcollect.cpp
BaseClass=CDialog
Filter=D
LastObject=Cnewcollect

[DLG:IDD_NEWCOLLECT]
Type=1
Class=Cnewcollect
ControlCount=3
Control1=IDC_EDIT1,edit,1352729604
Control2=IDC_STATIC,static,1342308352
Control3=IDC_BUTTON1,button,1342242816

[DLG:IDD_DIALOG9]
Type=1
Class=Caddcollection
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_EDIT1,edit,1350631552
Control3=IDC_STATIC,static,1342308352

[CLS:Caddcollection]
Type=0
HeaderFile=addcollection.h
ImplementationFile=addcollection.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC

[DLG:IDD_DIALOG10]
Type=1
Class=Chelp
ControlCount=2
Control1=IDC_STATIC,static,1342308353
Control2=IDC_EDIT1,edit,1352735748

[CLS:Chelp]
Type=0
HeaderFile=help.h
ImplementationFile=help.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_EDIT1
VirtualFilter=dWC


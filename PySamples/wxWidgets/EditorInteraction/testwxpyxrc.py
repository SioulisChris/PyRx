import wx
from wx import xrc

import PyRxApp# = all the global methods like acutPrintf,
import PyRx# = Runtime runtime
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services
import PyEd# = editor

def OnPyInitApp():
    print("\nOnPyInitApp")
    print("Added command 'wxpyxrc'")

def OnPyUnloadApp():
    print("\nOnPyUnloadApp")

def OnPyLoadDwg():
    print("\nOnPyLoadDwg")

def OnPyUnloadDwg():
   print("\nOnPyUnloadDwg")
   
#command to launch the dialog
def PyRxCmd_wxpyxrc():
    try: 
        #CAcModuleResourceOverride
        resource = PyAp.ResourceOverride()
        dlg = TestDialog(None, -1, "")
        if dlg.ShowModal() == wx.ID_OK:
            print('woohoo')
    except Exception as err:
        print(err)
    finally:
        # explicitly cause the dialog to destroy itself
        dlg.Destroy()

class TestDialog(wx.Dialog):
    def __init__(
            self, parent, id, title, size=wx.DefaultSize, pos=wx.DefaultPosition,
            style=wx.DEFAULT_DIALOG_STYLE, name='ID_SELECTTEST'):
        wx.Dialog.__init__(self)   
        self.res = xrc.XmlResource('./selectTest.xrc')
        if not self.res.LoadDialog(self, parent, "ID_SELECTTEST"):
            raise Exception("failed to find xrc file") 
        
        self.getPointButton = xrc.XRCCTRL(self,'ID_BUTTON_GET_POINT')
        self.Bind(wx.EVT_BUTTON, self.onGetPoint,self.getPointButton)
        
        self.getDistButton = xrc.XRCCTRL(self,'ID_BUTTON_GET_DIST')
        self.Bind(wx.EVT_BUTTON, self.onGetDist,self.getDistButton)

        self.textPointResult = xrc.XRCCTRL(self,'ID_TEXTCTRL_POINT_RESULT')
        self.textDistResult = xrc.XRCCTRL(self,'ID_TEXTCTRL_DIST_RESULT')
        
        #PyAp.Application.setTitleThemeDark(self.GetHandle())
        #self.dark_bg_color = "#252525"  # Dark background color
        #self.dark_fg_color = "#FFFFFF"  # Dark foreground color
        #self.SetBackgroundColour(self.dark_bg_color)
        #self.set_dark_mode(self)
        
    def set_dark_mode(self, control):
        for child in control.GetChildren():
            child.SetForegroundColour(self.dark_fg_color)
            child.SetBackgroundColour(self.dark_bg_color)
            self.set_dark_mode(child)
        
    def onGetPoint(self, event):
        val = PyAp.Application().docManager().curDocument().editor().getPoint("\nGetPoint\n")
        if val[0] == PyEd.PromptStatus.eNormal :
            self.textPointResult.SetValue(val[1].__str__())
            
    def onGetDist(self, event):
        val = PyAp.Application().docManager().curDocument().editor().getDist("\nGetDist\n")
        if val[0] == PyEd.PromptStatus.eNormal :
            self.textDistResult.SetValue(val[1].__str__())




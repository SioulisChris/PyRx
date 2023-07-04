import PyRx
import PyGe
import PyGi
import PyDb
import PyAp
import PyEd
import wx

print("added command = wxpypr")


def PyRxCmd_wxpypr():
    try:
        res = PyAp.ResourceOverride()
        dlg = TestDialog(None, -1, "Plot", wx.Size(450, 250))
        if dlg.ShowModal() == wx.ID_OK:
            print("yay")
    except Exception as err:
        print(err)


class TestDialog(wx.Dialog):
    def __init__(
            self, parent, id, title, size, pos=wx.DefaultPosition,
            style=wx.DEFAULT_DIALOG_STYLE, name='dialog'):

        wx.Dialog.__init__(self)
        self.SetExtraStyle(wx.DIALOG_EX_CONTEXTHELP)
        self.Create(parent, id, title, pos, size, style, name)
        PyAp.Application.setTitleThemeDark(self.GetHandle())

        self.sbox = wx.StaticBox(self, -1, 'Preview:') 
        PyDb.Core.displayPreviewFromDwg("E:\\Floor Plan Sample.dwg", self.sbox.GetHandle())

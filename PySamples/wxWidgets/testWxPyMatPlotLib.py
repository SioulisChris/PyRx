
from numpy import arange, sin, pi

import matplotlib
matplotlib.use('WXAgg')
from matplotlib.backends.backend_wxagg import FigureCanvasWxAgg as FigureCanvas
from matplotlib.figure import Figure

import PyRx
import PyGe
import PyGi
import PyDb
import PyAp
import PyEd
import wx

def PyRxCmd_wxpy():
    try: 
        res = PyAp.ResourceOverride()
        dlg = TestDialog(None, -1, "Plot",wx.Size(500,300))
        if dlg.ShowModal() == wx.ID_OK:
            print("Yay!")
    except Exception as err:
        print(err)

        
class CanvasPanel(wx.Panel):
    def __init__(self, parent):
        wx.Panel.__init__(self, parent)
        self.figure = Figure(figsize=(1,1))
        self.axes = self.figure.add_subplot(111)
        self.canvas = FigureCanvas(self, -1, self.figure)
        self.sizer = wx.BoxSizer(wx.VERTICAL)
        self.sizer.Add(self.canvas, 1, wx.LEFT | wx.TOP | wx.GROW)
        self.SetSizer(self.sizer)
        self.Fit()

    def draw(self):
        t = arange(0.0, 3.0, 0.01)
        s = sin(2 * pi * t)
        self.axes.plot(t, s)
   
class TestDialog(wx.Dialog):
    def __init__(
            self, parent, id, title, size, pos=wx.DefaultPosition,
            style=wx.DEFAULT_DIALOG_STYLE
            ):

        wx.Dialog.__init__(self)
        self.Create(parent, id, title, pos, size, style)
        PyAp.Application.setTitleThemeDark(self.GetHandle())
        PyAp.Application.applyHostIcon(self.GetHandle())
        
        self.pltpanel = CanvasPanel(self)
        self.pltpanel.draw()


        
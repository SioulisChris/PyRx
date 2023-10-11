# import
import PyGe as Ge
import win32com.client
import pythoncom

def pnt2d(val: Ge.Point2d):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def vec2d(val: Ge.Vector2d):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def matrix2d(val: Ge.Matrix2d):
    return win32com.client.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def pnt3d(val: Ge.Point3d):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def vec3d(val: Ge.Vector3d):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def matrix3d(val: Ge.Matrix3d):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def ent(ent : AxApp24.IAcadEntity):
    return win32com.client.VARIANT(pythoncom.VT_DISPATCH, ent)

def dbo(obj : AxApp24.IAcadObject):
    return win32com.client.VARIANT(pythoncom.VT_DISPATCH, obj)

def entlist(ents : [AxApp24.IAcadEntity]):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_DISPATCH, ents)

def dbolist(objs : [AxApp24.IAcadObject]):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_DISPATCH, objs)

def ssfilterType(ints):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_I2, ints)

def ssfilterData(strings):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_VARIANT, strings)

def xyz(x,y,z=0):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, (x,y,x))

def coords(_coords):
    return win32com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, _coords)
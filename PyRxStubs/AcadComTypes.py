# import
import PyGe as Ge
import win32com.client as com
import pythoncom
import ComAcadApplication24 as AcadApp

def comPnt2d(val: Ge.Point2d):
    return com.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def comVec2d(val: Ge.Vector2d):
    return com.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def comMatrix2d(val: Ge.Matrix2d):
    return com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def comPnt3d(val: Ge.Point3d):
    return com.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def comVec3d(val: Ge.Vector3d):
    return com.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())

def comMatrix3d(val: Ge.Matrix3d):
    return com.client.VARIANT(pythoncom.VT_ARRAY | pythoncom.VT_R8, val.toList())
import os
import unittest

import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed

#requires win32com.client
host = Ap.Application.host()
if host == 'BRX':  
    import BxDb24 as AxDb
    import BxApp24 as Ax
else:
    import AxApp24 as AxDb
    import AxApp24 as Ax

print("testname = pyactivex")

class TestActiveX(unittest.TestCase):
    def test_get_app(self): 
        app = Ax.getApp()
        name : str = app.Name
        if host == 'BRX': 
            self.assertTrue('BricsCAD' in name)
        else:
            self.assertTrue('AutoCAD' in name)
            
    def test_get_dbx(self):
        if host == 'BRX': 
            return
        dbx = Ax.getDbx()
        path = ".\\testmedia\\06457.dwg"
        dbx.Open(path,None)
        for ent in dbx.ModelSpace:
            self.assertNotEqual(ent.ObjectID, 0)
            
        self.assertEqual(dbx.Name, path)
        self.assertNotEqual(dbx.ModelSpace.Count, 0)
        
    def test_add_point(self):
        app = Ax.getApp()
        point = app.ActiveDocument.ModelSpace.AddPoint((100,200,300))
        self.assertEqual(point.Coordinates, (100,200,300))
        point.Coordinates = (1,2,3)
        self.assertEqual(point.Coordinates, (1,2,3))
        
    def test_add_line(self):
        app = Ax.getApp()
        line = app.ActiveDocument.ModelSpace.AddLine((100,200,300),(400,500,600))
        self.assertEqual(line.StartPoint, (100,200,300))
        self.assertEqual(line.EndPoint, (400,500,600))
        line.StartPoint = (1,2,3)
        line.EndPoint = (4,5,6)
        self.assertEqual(line.StartPoint, (1,2,3))
        self.assertEqual(line.EndPoint, (4,5,6))
        
    def test_add_polyline(self):
        app = Ax.getApp()
        line = app.ActiveDocument.ModelSpace.AddLightWeightPolyline([0, 0, 10, 10, 20, 10])
        self.assertEqual(line.Coordinates, (0, 0, 10, 10, 20, 10))
        line.Coordinates = (1, 2, 3, 4, 5, 6)
        self.assertEqual(line.Coordinates, (1, 2, 3, 4, 5, 6))
        
    def test_add_mtext(self):
        app = Ax.getApp()
        mt = app.ActiveDocument.ModelSpace.AddMText((100,200,300),40,"Hello world")
        self.assertEqual(mt.InsertionPoint,(100,200,300))
        mt.InsertionPoint = (400,100,0)
        self.assertEqual(mt.InsertionPoint, (400,100,0))
        
    def test_Add3DFaceProps(self): 
        app = Ax.getApp()
        model = app.ActiveDocument.ModelSpace
        face = model.Add3DFace((0,0,0),(0,100,0),(100,100,0),(100,0,0))
        face.SetCoordinate(3,face.Coordinate(3))
        self.assertEqual(face.Coordinate(3), (100,0,0))
        
    def test_ent_copy(self): 
        app = Ax.getApp()
        model = app.ActiveDocument.ModelSpace
        line = model.AddLine((0,0,0),(100,100,0))
        lineCopy = line.Copy()
        self.assertEqual(line.StartPoint,lineCopy.StartPoint)
        self.assertEqual(line.EndPoint,lineCopy.EndPoint)

def PyRxCmd_pyactivex():
    try:
        suite = unittest.TestLoader().loadTestsFromTestCase(TestActiveX)
        print('TestActiveX')
        print(unittest.TextTestRunner(verbosity=0).run(suite))
    except Exception as err:
        print(err)

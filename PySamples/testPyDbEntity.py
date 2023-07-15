import os

import PyRx# = Runtime runtime 
import PyGe# = Geometry
import PyGi# = Graphics interface
import PyDb# = database
import PyAp# = application, document classes services 
import PyEd# = editor 


def OnPyInitApp():
    print("\nOnPyInitApp")
	
def OnPyUnloadApp():
    print("\nOnPyUnloadApp")
        
def OnPyLoadDwg():
   print("\nOnPyLoadDwg")
   print("\nrun pydbentitytest :")
	
def OnPyUnloadDwg():
   print("\nOnPyUnloadDwg")

def PyRxCmd_pydbentitytest():
	try:
		PyDbObjectOpenForRead()
	except Exception as err:
		 print(err)
		
def PyDbObjectOpenForRead():
	try:
		db = PyDb.HostApplicationServices().workingDatabase()  
		id = db.blockTableId()
		dbo = PyDb.DbObject(id, PyDb.OpenMode.kForRead)
		if dbo.isNullObj():
			print("\nFAIL")
		else:
			print("\nPASS({})".format(dbo.isA().name()))
	except Exception as err:
		print(err)		
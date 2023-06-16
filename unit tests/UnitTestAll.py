import UnitTestPyAcGe
import UnitTestPyDatabase
import UnitTestPyDbObject
import UnitTestPyDbObjectId
import UnitTestPyDbPoint
import UnitTestPyDbEval

print("testname = pytestall")

def PyRxCmd_pytestall():
    try:
      UnitTestPyAcGe.PyRxCmd_pyge()
      UnitTestPyDatabase.PyRxCmd_pydbtest()
      UnitTestPyDbObject.PyRxCmd_pydbobject()
      UnitTestPyDbObjectId.PyRxCmd_pydbobjectid()
      UnitTestPyDbPoint.PyRxCmd_pydbpoint()
      UnitTestPyDbEval.PyRxCmd_pydbeval()
    except Exception as err:
      print(err)

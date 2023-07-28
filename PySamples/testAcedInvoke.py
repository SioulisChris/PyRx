import PyRx as Rx
import PyGe as Ge
import PyGi as Gi
import PyDb as Db
import PyAp as Ap
import PyEd as Ed
import PyGs as Gs

#  (defun C:ADDNUM ( x / ) (+ x x))
def PyRxCmd_doit(CmDFlags = Ap.CmdFlags.SESSION):
    try:
        args = [(Rx.LispType.kText, "C:ADDNUM"),(Rx.LispType.kInt16,10),(Rx.LispType.kNone,0) ]
        result = Ed.Core.invoke(args)
        print(result)
      
    except Exception as err:
        print(err)
        
    #  (defun C:GETLASTENT () (entget(entlast)))
def PyRxCmd_doit2(CmDFlags = Ap.CmdFlags.SESSION):
    try:
        args = [(Rx.LispType.kText, "C:GETLASTENT"),(Rx.LispType.kNone,0) ]
        result = Ed.Core.invoke(args)
        print(result)
      
    except Exception as err:
        print(err)
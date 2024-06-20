import traceback
from pyrx_imp import Rx, Ge, Gi, Db, Ap, Ed

def OnPyInitApp() -> None:
    print("\nOnPyInitApp _onpyload")

def OnPyUnloadApp() -> None:
    print("\nOnPyUnloadApp _onpyload")
    
def OnPyReload() -> None:
    print("\nOnPyReload _onpyload")

def OnPyLoadDwg() -> None:
    print("\nOnPyLoadDwg _onpyload")

def OnPyUnloadDwg() -> None:
    print("\nOnPyUnloadDwg _onpyload")
    
def PyRxCmd_mycommand(CmdFlags=Ap.CmdFlags.TRANSPARENT) -> None:
    try:
        print("Hello world!")
    except Exception as err:
        traceback.print_exception(err)

def PyRxLisp_mylisp(args):
    try:
        return args
    except Exception as err:
        print(err)

Ap.Application.loadPythonModule("M:/Dev/Projects/PyRxGit/unitTests/UnitTestRunner.py")
Ap.Application.loadPythonModule("M:/Dev/Projects/PyRxGit/PyRxStubs/utility/genDoc.py")

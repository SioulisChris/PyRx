from pyrx_imp import Rx
from pyrx_imp import Ge
from pyrx_imp import Gi
from pyrx_imp import Db
from pyrx_imp import Ap
from pyrx_imp import Ed
from pyrx_imp import Gs

print("added command pyreaddwg")

# debug
def PyRxCmd_pydebug() -> None:
    import PyRxDebug
    PyRxDebug.startListener()

def PyRxCmd_pyreaddwg():
    try:
        db = Db.Database(False, True)
        db.readDwgFile("..\\dwg\\Floor Plan Sample.dwg")
        db.closeInput(True)
        entities = {}
        model = Db.BlockTableRecord(db.modelSpaceId(), Db.OpenMode.ForRead)

        for id in model.objectIds():
            classname = id.objectClass().name()
            if classname in entities:
                entities[classname] = entities[classname]+1
            else:
                entities[classname] = 1
        print(entities)
    except Exception as err:
        print(err)

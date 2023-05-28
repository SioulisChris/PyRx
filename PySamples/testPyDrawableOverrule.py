import PyRxApp  # = all the global methods like acutPrintf,
import PyRx  # = Runtime runtime
import PyGe  # = Geometry
import PyGi  # = Graphics interface
import PyDb  # = database
import PyAp  # = application, document classes services
import PyEd  # = editor

print("command = pydrawoverrule")
print("command = pystopoverrule")


class MyDrawableOverrule(PyGi.DrawableOverrule):
    def __init__(self):
        PyGi.DrawableOverrule.__init__(self)

    # override
    def isApplicable(self, subject):
        return True

    # override
    def worldDraw(self, subject, wd):
        try:
            # draw the subject first
            flag = self.baseWorldDraw(subject, wd)

            # cast subject to a line
            line = PyDb.Line.cast(subject)

            #circle info
            seg = PyGe.LineSeg3d(line.endPoint(), line.startPoint())
            cen = PyGe.Point3d(seg.midPoint())
            rad = seg.length() * 0.3

            # draw circle
            traits = wd.subEntityTraits()
            traits.setColor(1)
            geo = wd.geometry()
            geo.circle(cen, rad, PyGe.Vector3d.kZAxis)
            
            #draw text
            traits.setColor(2)
            testpos = cen + (seg.direction().perpVector().normalize() * 3)
            geo.text(testpos, PyGe.Vector3d.kZAxis,
                     seg.direction(), 10, 1.0, 0, "SUP Bruh")

            # returing false here will go to viewport
            return flag
        except Exception as err:
            print(err)


# put this in global space
overrule = MyDrawableOverrule()

# cmds


def PyRxCmd_pydrawoverrule():
    try:
        if overrule.addOverrule(PyDb.Line.desc(), overrule) == PyDb.ErrorStatus.eOk:
            overrule.setIsOverruling(True)
        else:
            print("fail")
    except Exception as err:
        PyRxApp.Printf(err)


def PyRxCmd_pystopoverrule():
    try:
        if overrule == None:
            return
        if overrule.removeOverrule(PyDb.Line.desc(), overrule) == PyDb.ErrorStatus.eOk:
            overrule.setIsOverruling(False)
    except Exception as err:
        PyRxApp.Printf(err)

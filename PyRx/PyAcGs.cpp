#include "stdafx.h"
#include "PyAcGs.h"
#include "PyGsManager.h"

using namespace boost::python;

BOOST_PYTHON_MODULE(PyGs)
{
    docstring_options local_docstring_options(true, true, true);
    makePyGsManagerWrapper();
  
}

void initPyGsModule()
{
    PyImport_AppendInittab(PyGsNamespace, &PyInit_PyGs);
}

#include "stdafx.h"
#include "PyDbIdMapping.h"

using namespace boost::python;

void makePyDbIdMappingWrapper()
{
    class_<PyDbIdMapping>("IdMapping")
        .def(init<>())
        ;
}

PyDbIdMapping::PyDbIdMapping()
    : m_imp(new AcDbIdMapping())
{
}

PyDbIdMapping::PyDbIdMapping(const AcDbIdMapping& mapping)
    : m_imp(new AcDbIdMapping())
{
    PyThrowBadEs(m_imp->copyFrom(&mapping));
}

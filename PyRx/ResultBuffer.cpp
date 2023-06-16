#include "stdafx.h"
#include "ResultBuffer.h"
#include "PyDbObjectId.h"
using namespace boost::python;

resbuf* listToResbuf(const boost::python::list& bpl)
{
    PyAutoLockGIL lock;
    try
    {
        //NULL is valid!
        const size_t listSize = boost::python::len(bpl);
        if (listSize == 0)
            return nullptr;

        resbuf* pRbRead = acutNewRb(RTLB);
        resbuf* pTail = pRbRead;

        for (size_t idx = 0; idx < listSize; idx++)
        {
            tuple tpl = extract<tuple>(bpl[idx]);
            if (boost::python::len(tpl) != 2)
                throw PyAcadErrorStatus(Acad::eInvalidInput);

            int code = extract<int>(tpl[0]);
            if (code < 5000)
            {
                switch (acdbGroupCodeToType(code))
                {
                case AcDb::kDwgText:
                {
                    int _code = code == 0 ? RTDXF0 : code;
                    AcString str = utf8_to_wstr(extract<char*>(tpl[1])).c_str();
                    pTail->rbnext = acutBuildList(_code, (const TCHAR*)str, 0);
                    if (pTail->rbnext != nullptr)
                        pTail = pTail->rbnext;
                    break;
                }
                case AcDb::kDwgInt8:
                {
                    int val = extract<int>(tpl[1]);
                    pTail->rbnext = acutBuildList(code, val, 0);
                    if (pTail->rbnext != nullptr)
                        pTail = pTail->rbnext;
                    break;
                }
                case AcDb::kDwgInt16:
                {
                    int val = extract<int>(tpl[1]);
                    pTail->rbnext = acutBuildList(code, val, 0);
                    if (pTail->rbnext != nullptr)
                        pTail = pTail->rbnext;
                    break;
                }
                case AcDb::kDwgInt32:
                {
                    int val = extract<int>(tpl[1]);
                    pTail->rbnext = acutBuildList(code, val, 0);
                    if (pTail->rbnext != nullptr)
                        pTail = pTail->rbnext;
                    break;
                }
                case AcDb::kDwgReal:
                {
                    double val = extract<double>(tpl[1]);
                    pTail->rbnext = acutBuildList(code, val, 0);
                    if (pTail->rbnext != nullptr)
                        pTail = pTail->rbnext;
                    break;
                }
                case AcDb::kDwg3Real:
                {
                    const auto val = asDblArray(extract<AcGePoint3d>(tpl[1]));
                    pTail->rbnext = acutBuildList(code, val, 0);
                    if (pTail->rbnext != nullptr)
                        pTail = pTail->rbnext;
                    break;
                }
                case AcDb::kDwgHandle:
                case AcDb::kDwgHardOwnershipId:
                case AcDb::kDwgSoftOwnershipId:
                case AcDb::kDwgHardPointerId:
                case AcDb::kDwgSoftPointerId:
                {
                    ads_name name = { 0L };
                    PyDbObjectId id = extract<PyDbObjectId>(tpl[1]);
                    if (acdbGetAdsName(name, id.m_id) == eOk)
                    {
                        pTail->rbnext = acutBuildList(code, name, 0);
                        if (pTail->rbnext != nullptr)
                            pTail = pTail->rbnext;
                    }
                }
                break;
                }
            }
            else
            {
                switch (code)
                {
                case RTT:
                case RTDXF0:
                case RTNIL:
                case RTDOTE:
                case RTVOID:
                case RTLB:
                case RTLE:
                case RTNONE:
                {
                    pTail->rbnext = acutBuildList(code, 0, 0);
                    if (pTail->rbnext != nullptr)
                        pTail = pTail->rbnext;
                    break;
                }
                case RTANG:
                case RTREAL:
                {
                    const double val = extract<double>(tpl[1]);
                    pTail->rbnext = acutBuildList(code, val, 0);
                    if (pTail->rbnext != nullptr)
                        pTail = pTail->rbnext;
                    break;
                }
                case RTORINT:
                case RT3DPOINT:
                {
                    const auto val = asDblArray(extract<AcGePoint3d>(tpl[1]));
                    pTail->rbnext = acutBuildList(code, val, 0);
                    if (pTail->rbnext != nullptr)
                        pTail = pTail->rbnext;
                    break;
                }
                case RTPOINT:
                {
                    const auto val = asDblArray(extract<AcGePoint2d>(tpl[1]));
                    pTail->rbnext = acutBuildList(code, val, 0);
                    if (pTail->rbnext != nullptr)
                        pTail = pTail->rbnext;
                    break;
                }
                case RTSHORT:
                {
                    const short val = extract<int>(tpl[1]);
                    pTail->rbnext = acutBuildList(code, val, 0);
                    if (pTail->rbnext != nullptr)
                        pTail = pTail->rbnext;
                    break;
                }
                case RTLONG:
                {
                    const int val = extract<int>(tpl[1]);
                    pTail->rbnext = acutBuildList(code, val, 0);
                    if (pTail->rbnext != nullptr)
                        pTail = pTail->rbnext;
                    break;
                }
                case RTLONG_PTR:
                case RTINT64:
                {
                    const int64_t val = extract<int64_t>(tpl[1]);
                    pTail->rbnext = acutBuildList(code, val, 0);
                    if (pTail->rbnext != nullptr)
                        pTail = pTail->rbnext;
                    break;
                }
                case RTSTR:
                {
                    //TODO extract<char*> seems to work on None, test
                    const AcString str = utf8_to_wstr(extract<char*>(tpl[1])).c_str();
                    pTail->rbnext = acutBuildList(code, (const TCHAR*)str, 0);
                    if (pTail->rbnext != nullptr)
                        pTail = pTail->rbnext;
                    break;
                }
                case RTPICKS:
                case RTENAME:
                {
                    {
                        ads_name name = { 0L };
                        const PyDbObjectId id = extract<PyDbObjectId>(tpl[1]);
                        if (acdbGetAdsName(name, id.m_id) == eOk)
                        {
                            pTail->rbnext = acutBuildList(code, name, 0);
                            if (pTail->rbnext != nullptr)
                                pTail = pTail->rbnext;
                        }
                    }
                }
                break;
#ifdef NEVER
                case RTRESBUF:
                {
                    list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rbinary.buf));
                }
                break;
#endif
                }
            }
        }
        //we created a RTLB, detach it and return next 
        resbuf* rbToReturn = pRbRead->rbnext;
        pRbRead->rbnext = nullptr;
        acutRelRb(pRbRead);
        return rbToReturn;
    }
    catch (...)
    {
        //TODO: throw something here
    }
    return nullptr;
}

boost::python::list resbufToList(resbuf* pRb)
{
    PyAutoLockGIL lock;
    boost::python::list list;
    for (resbuf* pTail = pRb; pTail != nullptr; pTail = pTail->rbnext)
    {
        if (pTail->restype < 5000)
        {
            switch (acdbGroupCodeToType(pTail->restype))
            {
            case AcDb::kDwgText:
                list.append(boost::python::make_tuple(pTail->restype, wstr_to_utf8(pTail->resval.rstring)));
                break;
            case AcDb::kDwgInt8:
                list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rint));
                break;
            case AcDb::kDwgInt16:
                list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rint));
                break;
            case AcDb::kDwgInt32:
                list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rlong));
                break;
            case AcDb::kDwgReal:
                list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rreal));
                break;
            case AcDb::kDwg3Real:
                list.append(boost::python::make_tuple(pTail->restype, asPnt3d(pTail->resval.rpoint)));
                break;
            case AcDb::kDwgHandle://TODO!! this is wrong?
            case AcDb::kDwgHardOwnershipId:
            case AcDb::kDwgSoftOwnershipId:
            case AcDb::kDwgHardPointerId:
            case AcDb::kDwgSoftPointerId:
            {
                AcDbObjectId id;
                if (acdbGetObjectId(id, pTail->resval.rlname) == eOk)
                    list.append(boost::python::make_tuple(pTail->restype, PyDbObjectId(id)));
            }
            break;
            }
        }
        else
        {
            switch (pTail->restype)
            {
            case RTT:
            case RTDXF0:
            case RTNIL:
            case RTDOTE:
            case RTVOID:
            case RTLB:
            case RTLE:
            case RTNONE:
                list.append(boost::python::make_tuple(pTail->restype, 0));
                break;
            case RTANG:
            case RTREAL:
                list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rreal));
                break;
            case RTORINT:
            case RT3DPOINT:
                list.append(boost::python::make_tuple(pTail->restype, asPnt3d(pTail->resval.rpoint)));
                break;
            case RTPOINT:
                list.append(boost::python::make_tuple(pTail->restype, asPnt2d(pTail->resval.rpoint)));
                break;
            case RTSHORT:
                list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rint));
                break;
            case RTLONG:
                list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rlong));
                break;
            case RTLONG_PTR:
            case RTINT64:
                list.append(boost::python::make_tuple(pTail->restype, pTail->resval.mnInt64));
                break;
            case RTSTR:
                list.append(boost::python::make_tuple(pTail->restype, wstr_to_utf8(pTail->resval.rstring)));
                break;
            case RTPICKS:
            case RTENAME:
            {
                AcDbObjectId id;
                if (acdbGetObjectId(id, pTail->resval.rlname) == eOk)
                    list.append(boost::python::make_tuple(pTail->restype, PyDbObjectId(id)));
            }
            break;
#ifdef NEVER
            case RTRESBUF:
            {
                list.append(boost::python::make_tuple(pTail->restype, pTail->resval.rbinary.buf));
            }
            break;
#endif
            }
        }
    }
    return list;
}

resbuf* acGePoint3dArrayToResbuf(const AcGePoint3dArray& ptArray)
{
    resbuf* ptList = NULL;        // overall list
    resbuf* lastRb = NULL;        // place holder to end of list
    resbuf* rb;
    int len = ptArray.length();
    for (int i = 0; i < len; i++) 
    {
        if ((rb = acutNewRb(RT3DPOINT)) == NULL) 
        {
            acutRelRb(ptList);
            return NULL;
        }
        const AcGePoint3d& p = ptArray.at(i);
        rb->resval.rpoint[0] = p.x;
        rb->resval.rpoint[1] = p.y;
        rb->resval.rpoint[2] = p.z;
        if (ptList == NULL) 
        {
            ptList = rb;
            lastRb = rb;
        }
        else 
        {
            lastRb->rbnext = rb;
            lastRb = rb;
        }
    }
    return ptList;
}

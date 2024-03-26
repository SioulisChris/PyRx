#pragma once
#include "PyRxObject.h"
class PyDbObject;
class PyDbObjectId;
class PyDbEntity;
class PyDbTransactionManager;
class PyDbHandle;
class PyDbAnnotationScale;
class PyDbDimStyleTableRecord;
class PyDbIdMapping;
class PyDbDatabaseReactor;
class PyDbDate;
class PyDbObjectContextManager;

void makePyDbDatabaseWrapper();
class PyDbDatabase : public PyRxObject
{
public:
    PyDbDatabase();
    PyDbDatabase(AcDbDatabase* pDb);
    PyDbDatabase(AcDbDatabase* pDb, bool autoDelete);
    PyDbDatabase(bool buildDefaultDrawing, bool noDocument);
    virtual ~PyDbDatabase() override = default;

    PyDbObjectId        addToBlock1(const PyDbObjectId&id, PyDbEntity& ent);
    boost::python::list addToBlock2(const PyDbObjectId& id, const boost::python::list& ent);
    PyDbObjectId        addToModelspace1(PyDbEntity& ent);
    boost::python::list addToModelspace2(const boost::python::list& ent);
    PyDbObjectId        addToCurrentspace1(PyDbEntity& ent);
    boost::python::list addToCurrentspace2(const boost::python::list& ent);
    PyDbObjectId        addAcDbObject(PyDbObject& obj);
    void                addReactor(PyDbDatabaseReactor& pReactor) const;
    double              angbase() const;
    bool                angdir() const;
    bool                annoAllVisible() const;
    bool                annotativeDwg() const;
    int                 approxNumObjects() const;
    Adesk::Int16        attmode() const;
    Adesk::Int16        aunits() const;
    Adesk::Int16        auprec() const;
    bool                blipmode() const;
    PyDbObjectId        byBlockLinetype() const;
    PyDbObjectId        byBlockMaterial() const;
    PyDbObjectId        byLayerLinetype() const;
    PyDbObjectId        byLayerMaterial() const;
    bool                cameraDisplay() const;
    double              cameraHeight() const;
    Adesk::Int16        cDynDisplayMode() const;
    double              celtscale() const;
    PyDbObjectId        celtype() const;
    AcDb::LineWeight    celweight() const;
    double              chamfera() const;
    double              chamferb() const;
    double              chamferc() const;
    double              chamferd() const;
    std::string         classDxfName(const PyRxClass& pClass);
    PyDbObjectId        clayer() const;
    void                closeInput(bool bCloseFile);
    PyDbObjectId        cmaterial() const;
    Adesk::Int16        cmljust() const;
    double              cmlscale() const;
    PyDbObjectId        cmlstyleID() const;
    PyDbObjectId        colorDictionaryId() const;
    PyDbObjectId        continuousLinetype() const;
    Adesk::Int16        coords() const;
    Adesk::UInt32       countEmptyObjects(const Adesk::Int32 flags);
    Adesk::UInt32       countHardReferences(const boost::python::list& pyids);
    PyDbObjectId        detailViewStyle() const;
    PyDbObjectId        detailViewStyleDictionaryId() const;
    bool                dimaso() const;
    Adesk::UInt8        dimAssoc() const;
    int                 dimfit() const;
    bool                dimsho() const;
    PyDbObjectId        dimstyle() const;
    PyDbObjectId        dimStyleTableId() const;
    int                 dimunit() const;
    void                disablePartialOpen();
    void                disableUndoRecording(bool disable);
    bool                dispSilh() const;
    Adesk::Int16        dragmode() const;
    PyDbObjectId        dragVisStyle() const;
    Adesk::UInt8        drawOrderCtl() const;
    Adesk::UInt8        dwfframe() const;
    bool                dwgFileWasSavedByAutodeskSoftware() const;
    void                dxfIn(const std::string& dxfFilename);
    void                dxfOut1(const std::string& dxfFilename);
    void                dxfOut2(const std::string& dxfFilename, int precision, AcDb::AcDbDwgVersion dwgVer, bool saveThumbnailImage);
    double              elevation() const;
    Adesk::UInt32       eraseEmptyObjects(const Adesk::Int32 flags);
    AcGePoint3d         extmax() const;
    AcGePoint3d         extmin() const;
    double              facetres() const;
    double              filletrad() const;
    bool                fillmode() const;
    void                forceWblockDatabaseCopy();
    std::string         geoCoordinateSystemId() const;
    bool                geoMarkerVisibility() const;
    double              get3dDwfPrec() const;
    boost::python::list objectIds() const;
    boost::python::list objectIdsOfType(const PyRxClass& _class);
    PyDbObjectId        getAcDbObjectId1(bool createIfNotFound, const PyDbHandle& objHandle);
    PyDbObjectId        getAcDbObjectId2(bool createIfNotFound, const PyDbHandle& objHandle, Adesk::UInt32 xRefId);
    PyDbObjectId        tryGetAcDbObjectId1(bool createIfNotFound, const PyDbHandle& objHandle);
    PyDbObjectId        tryGetAcDbObjectId2(bool createIfNotFound, const PyDbHandle& objHandle, Adesk::UInt32 xRefId);
    AcDb::PlotStyleNameType getCePlotStyleNameId(PyDbObjectId& id) const;
    bool                isAppRegistered(const std::string& pszAppName) const;
    std::string         dimapost() const;
    PyDbObjectId        dimblk() const;
    PyDbObjectId        dimblk1() const;
    PyDbObjectId        dimblk2() const;
    std::string         dimpost() const;
    PyDbObjectId        getDimstyleParentId(PyDbObjectId& childStyle) const;
    static AcDb::LineWeight getNearestLineWeight(int weight);
    boost::python::list getViewportArray() const;
    boost::python::list getVisualStyleList(); //TODO test
    PyDbObjectId        globalMaterial() const;
    PyDbObjectId        groupDictionaryId() const;
    void                insert1(PyDbObjectId& blockId, const std::string& pBlockName, PyDbDatabase& db, bool preserveSourceDatabase);
    void                insert2(PyDbObjectId& blockId, const std::string& pSourceBlockName, const std::string& pDestinationBlockName, PyDbDatabase& db, bool preserveSourceDatabase);
    void                insert3(const AcGeMatrix3d& xform, PyDbDatabase& db, bool preserveSourceDatabase);
    Adesk::UInt8        haloGap() const;
    PyDbHandle          handseed() const;
    bool                hasClass(const PyRxClass& pClass) const;
    Adesk::UInt8        hideText() const;
    bool                hpInherit() const;
    AcGePoint2d         hpOrigin() const;
    Adesk::UInt8        indexctl() const;
    AcDb::UnitsValue    insunits() const;
    PyDbObjectId        interfereVpVisStyle() const;
    Adesk::UInt16       intersectColor() const;
    Adesk::UInt8        intersectDisplay() const;
    bool                isBeingDestroyed() const;
    bool                isEMR() const;
    static bool         isObjectNonPersistent(const PyDbObjectId& id);
    Adesk::Int16        isolines() const;
    bool                isPartiallyOpened() const;
    bool                isPucsOrthographic(AcDb::OrthographicView& orthoView) const;
    bool                isUcsOrthographic(AcDb::OrthographicView& orthoView) const;
    static bool         isValidLineWeight(int weight);
    AcDb::JoinStyle     joinStyle() const;
    int                 lastSavedAsMaintenanceVersion() const;
    int                 lastSavedAsVersion() const;
    double              latitude() const;
    Adesk::UInt8        layerEval() const;
    Adesk::Int16        layerNotify() const;
    PyDbObjectId        layerTableId() const;
    PyDbObjectId        layerZero() const;
    PyDbObjectId        layoutDictionaryId()const;
    double              lensLength() const;
    Adesk::UInt8        lightGlyphDisplay() const;
    Adesk::UInt8		lightingUnits() const;
    bool				lightsInBlocks() const;
    bool				limcheck() const;
    AcGePoint2d			limmax() const;
    AcGePoint2d			limmin() const;
    PyDbObjectId		linetypeTableId() const;
    bool				lineWeightDisplay() const;
    void	            loadLineTypeFile(const std::string& ltn, const std::string& filename);
    double				loftAng1() const;
    double				loftAng2() const;
    double				loftMag1() const;
    double				loftMag2() const;
    Adesk::UInt8		loftNormals() const;
    Adesk::UInt16		loftParam() const;
    double				longitude() const;
    double				ltscale() const;
    Adesk::Int16		lunits() const;
    Adesk::Int16		luprec() const;
    int					maintenanceReleaseVersion() const;
    static void         markObjectNonPersistent(const PyDbObjectId& id, bool value);
    PyDbObjectId		materialDictionaryId() const;
    Adesk::Int16		maxactvp() const;
    AcDb::MeasurementValue measurement() const;
    bool				mirrtext() const;
    double				mleaderscale() const;
    PyDbObjectId		mleaderstyle() const;
    PyDbObjectId		mleaderStyleDictionaryId() const;
    PyDbObjectId		mLStyleDictionaryId() const;
    bool				msltscale() const;
    double				msOleScale() const;
    PyDbObjectId		namedObjectsDictionaryId() const;
    bool				needsRecovery() const;
    double				northDirection() const;
    Adesk::Int32		numberOfSaves() const;
    PyDbObjectContextManager objectContextManager() const;
    Adesk::UInt16		obscuredColor() const;
    Adesk::UInt8		obscuredLineType() const;
    bool				oleStartUp() const;
    int					originalFileMaintenanceVersion() const;
    std::string			originalFileName() const;
    int					originalFileSavedByMaintenanceVersion() const;
    int					originalFileSavedByVersion() const;
    int					originalFileVersion() const;
    bool				orthomode() const;
    PyDbObjectId		paperSpaceVportId() const;
    Adesk::Int8			pdfframe() const;
    Adesk::Int16		pdmode() const;
    double				pdsize() const;
    double				pelevation() const;
    AcGePoint3d			pextmax() const;
    AcGePoint3d			pextmin() const;
    Adesk::Int16		pickstyle() const;
    AcGePoint3d			pinsbase() const;
    bool				plimcheck() const;
    AcGePoint2d			plimmax() const;
    AcGePoint2d			plimmin() const;
    bool				plineEllipse() const;
    bool				plinegen() const;
    double				plinewid() const;
    PyDbObjectId		plotSettingsDictionaryId() const;
    bool				plotStyleMode() const;
    PyDbObjectId		plotStyleNameDictionaryId() const;
    Adesk::Int16		previewType() const;
    bool				psltscale() const;
    double				psolHeight() const;
    double				psolWidth() const;
    PyDbObjectId		pucsBase() const;
    PyDbObjectId		pucsname() const;
    AcGePoint3d			pucsorg() const;
    AcGeVector3d		pucsxdir() const;
    AcGeVector3d		pucsydir() const;
    boost::python::list purge(const boost::python::list& pyids);
    bool				qtextmode() const;
    void	            reclaimMemoryFromErasedObjects(const boost::python::list& erasedObjects);
    PyDbObjectId		regAppTableId() const;
    bool				regenmode() const;
    void                removeReactor(PyDbDatabaseReactor& pReactor) const;
    void                registerApp(const std::string& pszAppName);
    void                resetTimes();
    void                restoreForwardingXrefSymbols();
    void                restoreOriginalXrefSymbols();
    bool				retainOriginalThumbnailBitmap() const;
    Adesk::Int16	    saveproxygraphics() const;
    PyDbObjectId		scaleListDictionaryId() const;
    PyDbObjectId		sectionViewStyle() const;
    PyDbObjectId		sectionViewStyleDictionaryId() const;
    void	            set3dDwfPrec(double DwfPrec);
    void	            setAngbase(double angle);
    void	            setAngdir(bool dir);
    void	            setAnnoAllVisible(bool allvis);
    void	            setAttdia(bool dia);
    void	            setAttmode(Adesk::Int16 mode);
    void	            setAttreq(bool req);
    void	            setAunits(Adesk::Int16 aunits);
    void	            setAuprec(Adesk::Int16 auprec);
    void	            setBlipmode(bool mode);
    void	            setCameraDisplay(bool cameraDisplay);
    void	            setCameraHeight(double cameraHeight);
    void                setCannoscale(PyDbAnnotationScale& val);
    void	            setCDynDisplayMode(Adesk::Int16 val);
    void                setCecolor(const AcCmColor& color);
    void	            setCeltscale(double scale);
    void	            setCeltype(const PyDbObjectId& id);
    void	            setCelweight(AcDb::LineWeight weight);
    void	            setCePlotStyleName(AcDb::PlotStyleNameType, const PyDbObjectId& id);
    void                setCetransparency(const AcCmTransparency& transparency);
    void	            setChamfera(double val);
    void	            setChamferb(double val);
    void	            setChamferc(double val);
    void	            setChamferd(double val);
    void	            setClayer(const PyDbObjectId& id);
    void	            setCmaterial(const PyDbObjectId& id);
    void	            setCmljust(Adesk::Int16 just);
    void	            setCmlscale(double scale);
    void	            setCmlstyleID(const PyDbObjectId& id);
    void	            setCoords(Adesk::Int16 coords);
    void	            setCshadow(Adesk::UInt8 val);
    void	            setDelUsedObj(Adesk::Int16 deleteObj);
    void	            setDgnframe(Adesk::UInt8 val);
    void	            setDimaso(bool aso);
    void	            setDimAssoc(Adesk::UInt8 val);
    void	            setDimfit(int fit);
    void	            setDimsho(bool sho);
    void	            setDimstyle(const PyDbObjectId& id);
    void                setDimstyleData1(PyDbDimStyleTableRecord& pRec);
    void	            setDimstyleData2(const PyDbObjectId& id);
    void	            setDimunit(int unit);
    void	            setDispSilh(bool silh);
    void	            setDragmode(Adesk::Int16 mode);
    void	            setDragVisStyle(const PyDbObjectId& id);
    void	            setDrawOrderCtl(Adesk::UInt8 val);
    void	            setDwfframe(Adesk::UInt8);
    void	            setElevation(double elev);
    void	            setEndCaps(AcDb::EndCaps type);
    void	            setExtmax(const AcGePoint3d& max);
    void	            setExtmin(const AcGePoint3d& min);
    void	            setFacetres(double _facetres);
    void	            setFilletrad(double radius);
    void	            setFillmode(bool mode);
    void	            saveAs1(const std::string& fileName);
    void	            saveAs2(const std::string& fileName, const bool bBakAndRename, const AcDb::AcDbDwgVersion dwgVer);
    void	            setFingerprintGuid(const std::string& newGuid);
    void				setFullSaveRequired();
    void	            readDwgFile1(const char* fileName);
    void	            readDwgFile2(const char* fileName, int mode, bool bAllowCPConversion, const std::string& password);
    std::string			getFilename();
    PyDbObjectId		currentSpaceId() const;
    PyDbObjectId		blockTableId() const;
    PyDbObjectId		modelSpaceId() const;
    void	            setGeoMarkerVisibility(bool value);
    void	            setHaloGap(Adesk::UInt8 val);
    void                setHandseed(const PyDbHandle& handle);
    void	            setHideText(Adesk::UInt8 val);
    void	            setHpInherit(const bool inherit);
    void	            setHpOrigin(const AcGePoint2d& origin);
    void	            setHyperlinkBase(const std::string& val);
    void	            setIndexctl(Adesk::UInt8 val);
    void	            setInsbase(const AcGePoint3d& base);
    void	            setInsunits(const AcDb::UnitsValue units);
    void                setInterfereColor(const AcCmColor& color);
    void	            setInterfereObjVisStyle(const PyDbObjectId& id);
    void	            setInterfereVpVisStyle(const PyDbObjectId& id);
    void	            setIntersectColor(Adesk::UInt16 val);
    void	            setIntersectDisplay(Adesk::UInt8 val);
    void	            setIsolines(Adesk::Int16 isolines);
    void	            setJoinStyle(AcDb::JoinStyle style);
    void	            setLatitude(double lat);
    void	            setLayerEval(Adesk::UInt8 val);
    void	            setLayerNotify(Adesk::Int16 val);
    void	            setLensLength(const double _lensLength);
    void	            setLightGlyphDisplay(Adesk::UInt8 val);
    void	            setLightingUnits(Adesk::UInt8 val);
    void	            setLightsInBlocks(bool val);
    void	            setLimcheck(bool check);
    void	            setLimmax(const AcGePoint2d& max);
    void	            setLimmin(const AcGePoint2d& min);
    void	            setLineWeightDisplay(bool display);
    void	            setLoftAng1(double ang1);
    void	            setLoftAng2(double ang2);
    void	            setLoftMag1(double mag1);
    void	            setLoftMag2(double mag2);
    void	            setLoftNormals(Adesk::UInt8 value);
    void	            setLoftParam(Adesk::UInt16 flags);
    void	            setLongitude(double lng);
    void	            setLtscale(double scale);
    void	            setLunits(Adesk::Int16 lunits);
    void	            setLuprec(Adesk::Int16 prec);
    void	            setMaxactvp(Adesk::Int16 max);
    void	            setMeasurement(AcDb::MeasurementValue type);
    void	            setMirrtext(bool mirror);
    void	            setMLeaderscale(double scale);
    void	            setMLeaderstyle(const PyDbObjectId& objId);
    void	            setMsltscale(bool val);
    void	            setMsOleScale(double val);
    void	            setNorthDirection(double northdir);
    void	            setObscuredColor(Adesk::UInt16 val);
    void	            setObscuredLineType(Adesk::UInt8 val);
    void	            setOleStartUp(bool val);
    void	            setOrthomode(bool mode);
    void	            setPdfframe(Adesk::Int8 val);
    void	            setPdmode(Adesk::Int16 mode);
    void	            setPdsize(double size);
    void	            setPelevation(double elev);
    void	            setPextmax(const AcGePoint3d& max);
    void	            setPextmin(const AcGePoint3d& min);
    void	            setPickstyle(Adesk::Int16 style);
    void	            setPinsbase(const AcGePoint3d& base);
    void	            setPlimcheck(bool check);
    void	            setPlimmax(const AcGePoint2d& max);
    void	            setPlimmin(const AcGePoint2d& min);
    void	            setPlineEllipse(bool pline);
    void	            setPlinegen(bool gen);
    void	            setPlinewid(double width);
    void	            setPreviewType(Adesk::Int16 val);
    void	            setProjectName(const std::string& val);
    void	            setPsltscale(bool scale);
    void	            setPsolHeight(double height);
    void	            setPsolWidth(double width);
    void	            setPucs(const AcGePoint3d& ucsOrigin, const AcGeVector3d& ucsXDir, const AcGeVector3d& ucsYDir);
    void	            setPucsBase(const PyDbObjectId& ucsid);
    void	            setPucsname(const PyDbObjectId& ucsRecId);
    void	            setQtextmode(bool mode);
    void	            setRealWorldScale(const bool realWorldScale);
    void	            setRegenmode(bool mode);
    void				setRetainOriginalThumbnailBitmap(bool retain);
    void	            setSaveproxygraphics(Adesk::Int16 saveimg);
    void	            setSectionViewStyle(const PyDbObjectId& objId);
    //bool setSecurityParams(const SecurityParams* pSecParams,bool bSetDbMod = true);//TODO:
    //const SecurityParams* cloneSecurityParams();
    //static void disposeSecurityParams(const SecurityParams* pSecParams);
    void	            setShadedge(Adesk::Int16 mode);
    void	            setShadedif(Adesk::Int16 dif);
    void	            setShadowPlaneLocation(double val);
    void	            setShowHist(Adesk::UInt8 val);
    void	            setSketchinc(double inc);
    void	            setSkpoly(bool asPoly);
    void	            setSolidHist(Adesk::UInt8 val);
    void	            setSortEnts(Adesk::UInt8 sortEnts);
    void	            setSplframe(bool disp);
    void	            setSplinesegs(Adesk::Int16 segs);
    void	            setSplinetype(Adesk::Int16 type);
    void	            setStepSize(double stepSize);
    void	            setStepsPerSec(double stepsPerSec);
    void	            setStyleSheet(const std::string& val);
    void	            setSurftab1(Adesk::Int16 tab1);
    void	            setSurftab2(Adesk::Int16 tab2);
    void	            setSurftype(Adesk::Int16 type);
    void	            setSurfu(Adesk::Int16 v);
    void	            setSurfv(Adesk::Int16 v);
    void	            setTablestyle(const PyDbObjectId& objId);
    void	            setTextsize(double size);
    void	            setTextstyle(const PyDbObjectId& objId);
    void	            setThickness(double thickness);
    void	            setTilemode(bool mode);
    void	            setTimeZone(AcDb::TimeZone tz);//TODO: enum
    void	            setTimeZoneAsUtcOffset(double offset);
    void	            setTracewid(double width);
    void	            setTreedepth(Adesk::Int16 depth);
    void	            setTStackAlign(int val);
    void	            setTStackSize(int val);
    void	            setUcs(const AcGePoint3d& ucsOrigin, const AcGeVector3d& ucsXDir, const AcGeVector3d& ucsYDir);
    void	            setUcsBase(const PyDbObjectId& ucsid);
    void	            setUcsname(const PyDbObjectId& ucsRecId);
    void	            setUnitmode(Adesk::Int16 mode);
    void	            setUpdateThumbnail(Adesk::UInt8 val);
    void	            setUseri1(Adesk::Int16 val);
    void	            setUseri2(Adesk::Int16 val);
    void	            setUseri3(Adesk::Int16 val);
    void	            setUseri4(Adesk::Int16 val);
    void	            setUseri5(Adesk::Int16 val);
    void	            setUserr1(double val);
    void	            setUserr2(double val);
    void	            setUserr3(double val);
    void	            setUserr4(double val);
    void	            setUserr5(double val);
    void	            setUsrtimer(bool timer);
    void	            setVersionGuid(const std::string& pNewGuid);
    void	            setViewportScaleDefault(double newDefaultVPScale);
    void	            setVisretain(bool retain);
    void	            setWorldPucsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView orthoView);
    void	            setWorldUcsBaseOrigin(const AcGePoint3d& origin, AcDb::OrthographicView orthoView);
    void	            setWorldview(bool view);
    void	            setXclipFrame(Adesk::UInt8 disp);
    void	            setXrefEditEnabled(bool enable);
    Adesk::Int16	    shadedge() const;
    Adesk::Int16		shadedif() const;
    double				shadowPlaneLocation() const;
    Adesk::UInt8		showHist() const;
    double				sketchinc() const;
    bool				skpoly() const;
    Adesk::UInt8		solidHist() const;
    Adesk::UInt8		sortEnts() const;
    bool				splframe() const;
    Adesk::Int16		splinesegs() const;
    Adesk::Int16		splinetype() const;
    double				stepSize() const;
    double				stepsPerSec() const;
    Adesk::Int16		surftab1() const;
    Adesk::Int16		surftab2() const;
    Adesk::Int16		surftype() const;
    Adesk::Int16		surfu() const;
    Adesk::Int16		surfv() const;
    PyDbObjectId		tablestyle() const;
    PyDbObjectId		tableStyleDictionaryId() const;
    PyDbDate            tdcreate() const;
    PyDbDate            tdindwg() const;
    PyDbDate            tducreate() const;
    PyDbDate            tdupdate() const;
    PyDbDate            tdusrtimer() const;
    PyDbDate            tduupdate() const;
    double				textsize() const;
    PyDbObjectId		textstyle() const;
    PyDbObjectId		textStyleTableId() const;
    double				thickness() const;
    bool				tilemode() const;
    Adesk::UInt8		tileModeLightSynch() const;
    AcDb::TimeZone		timeZone() const;
    double				tracewid() const;
    PyDbTransactionManager transactionManager() const;
    Adesk::Int16		treedepth() const;
    int					tstackalign() const;
    int					tstacksize() const;
    PyDbObjectId		ucsBase() const;
    PyDbObjectId		ucsname() const;
    AcGePoint3d			ucsorg() const;
    PyDbObjectId		UCSTableId() const;
    AcGeVector3d		ucsxdir() const;
    AcGeVector3d		ucsydir() const;
    bool				undoRecording() const;
    Adesk::Int16		unitmode() const;
    void	updateDataLink(AcDb::UpdateDirection nDir, AcDb::UpdateOption nOption);
    void	updateExt(bool doBestFit);
    Adesk::UInt8	    updateThumbnail() const;
    Adesk::Int16	    useri1() const;
    Adesk::Int16	    useri2() const;
    Adesk::Int16	    useri3() const;
    Adesk::Int16	    useri4() const;
    Adesk::Int16	    useri5() const;
    double				userr1() const;
    double				userr2() const;
    double				userr3() const;
    double				userr4() const;
    double				userr5() const;
    bool				usrtimer() const;
    double				viewportScaleDefault() const;
    PyDbObjectId		viewportTableId() const;
    PyDbObjectId		viewTableId() const;
    bool				visretain() const;
    PyDbObjectId		visualStyleDictionaryId() const;
    void	            wblock1(PyDbDatabase& pOutputDb, const boost::python::list& outObjIds, const AcGePoint3d& basePoint, AcDb::DuplicateRecordCloning drc);
    PyDbDatabase	    wblock2(const boost::python::list& outObjIds, const AcGePoint3d& basePoint);
    PyDbDatabase	    wblock3(const PyDbObjectId& blockId);
    PyDbDatabase	    wblock4();

    void                abortDeepClone(PyDbIdMapping& idMap);

    void                deepCloneObjects1(const boost::python::list& objectIds,
        const PyDbObjectId& owner, PyDbIdMapping& idMap);

    void                deepCloneObjects2(const boost::python::list& objectIds,
        const PyDbObjectId& owner, PyDbIdMapping& idMap, bool deferXlation);

    void                wblockCloneObjects1(const boost::python::list& objectIds, const
        PyDbObjectId& owner, PyDbIdMapping& idMap, AcDb::DuplicateRecordCloning drc);

    void                wblockCloneObjects2(const boost::python::list& objectIds, const
        PyDbObjectId& owner, PyDbIdMapping& idMap, AcDb::DuplicateRecordCloning drc, bool deferXlation);

    AcGePoint3d			worldPucsBaseOrigin(AcDb::OrthographicView orthoView) const;
    AcGePoint3d			worldUcsBaseOrigin(AcDb::OrthographicView orthoView) const;
    bool				worldview() const;
    Adesk::UInt8		xclipFrame() const;
    PyDbObjectId		xrefBlockId() const;
    bool				xrefEditEnabled() const;
    //
    static std::string	className();
public:
    AcDbDatabase* impObj(const std::source_location& src = std::source_location::current()) const;
};
